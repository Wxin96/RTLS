#include "rtls_widget.h"
#include "ui_rtls_widget.h"
#include "stdio.h"
#include <string.h>
#include <QTime>
#include <QPainter>

#define TOF_REPORT_LEN  (64)

RTLS_Widget::RTLS_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RTLS_Widget)
{
    ui->setupUi(this);

    /*  通信部分  */
    // 通信套接字
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEdit_read->setText("成功和服务器建立连接！");
            }
            );

    connect(tcpSocket,&QTcpSocket::readyRead,this,&RTLS_Widget::newData);
    // 串口通信
    serial = new QSerialPort(this);
    connect(serial,&QSerialPort::readyRead,this,&RTLS_Widget::newData);
    connect(ui->SerialBox, SIGNAL(clicked()), this, SLOT(SerialPortDetect()));

    /* 基站坐标 */
    connect(ui->tableWidget_Anchor,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(slotItemChanged(QTableWidgetItem*)));


    /*  定位部分  */
    locationInit();

    /*  标签测距校正部分UI  */
    // 测距配置文件初始化
    QString rangingConfigPath = QCoreApplication::applicationDirPath() + "/config/rangingConfigs.ini";
    rangingDistConfig = new Config(rangingConfigPath);
    // 表格表项集合
    itemSet = new set<QTableWidgetItem*>();
    // 测距部分组件（需要使能 or 失能）
    rCComponent = new set<QWidget*>();
    // Tag ID下拉框 点击事件 =》 下拉框刷新
    connect(ui->tagSelect, SIGNAL(clicked()), this, SLOT(tagDropDownList_clicked()));
    // Anchor ID下拉框 点击事件 =》 下拉框刷新
    connect(ui->anchorSelect, SIGNAL(clicked()), this, SLOT(anchorDropDownList_clicked()));
    // Tag ID下拉框 当前选中序号改变
    connect(ui->tagSelect, SIGNAL(currentIndexChanged(int)), this, SLOT(rangingParamShow(int)));
    // 测距参数页面显示初始化
    rangingModuleInit();

    /*  菜单栏部分  */
    qMenuBar = new QMenuBar(this);
    // 模式菜单
    modeMenu = new QMenu("模式");
    simulationMode = new QAction("仿真模式");
    experimentMode = new QAction("实验模式");
    qMenuBar->addMenu(modeMenu);
    modeMenu->addAction(simulationMode);
    modeMenu->addAction(experimentMode);
    // 窗口菜单
    qMenuBar->addMenu(new QMenu("窗口"));
    // 菜单栏初始化
    connect(simulationMode, SIGNAL(toggled(bool)), this, SLOT(simulationToggled(bool)));
    connect(experimentMode, SIGNAL(toggled(bool)), this, SLOT(experimentToggled(bool)));
    menuBarInit();

    /*      标签定位测距验证      */
    trueLoc = new vec3d();
    memset(trueLoc->flag, 0, sizeof (char) * 3);    // 置0
    trueDist = new ta_dist();
    connect(ui->validateTagSelect, SIGNAL(clicked()), this, SLOT(validateTagDropDownList_clicked()));
    validateModuleInit();   // 校正模块初始化


    /*  Qt文件操作 */
    QString sFilePath = QCoreApplication::applicationDirPath() + "/config/trajConfig.txt";
    file = new QFile(sFilePath);
    if (!file->open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(this, "提示", "无法创建文件");
    }
    outStream = new QTextStream(file);
}

RTLS_Widget::~RTLS_Widget()
{
    outStream->flush();
    file->close();
    delete ui;
    delete tcpSocket;
    delete serial;
    delete rangingDistConfig;
    delete file;
    delete outStream;
    delete itemSet;
    delete rCComponent;
    delete trueLoc;
    delete trueDist;
}

/******************  定数据接收部分  ******************/
// TCP连接/断开
void RTLS_Widget::on_Button_connect_clicked()
{
    if(button_text == "Connect")
    {
        // 获取服务器IP和端口号
        QString ip =ui->lineEdit_IP->text();
        quint16 port = ui->lineEdit_Port->text().toUInt();

        // 主动和服务器建立连接
        tcpSocket->connectToHost(ip,port);

        // 更改按钮显示
        button_text = "Disconnect";
        ui->Button_connect->setText(button_text);
    }
    else
    {
        // 主动和对方断开连接
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        // 更改按钮显示
        button_text = "Connect";
        ui->Button_connect->setText(button_text);
        // textEdit_read显示已断开
        ui->textEdit_read->append("TCP连接已断开！");
    }

}

// 串口监测
void RTLS_Widget::SerialPortDetect()
{
    // 删除所有串口
    ui->SerialBox->clear();
    // 添加串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->SerialBox->addItem(serial.portName());
            serial.close();
        }
    }

}

// 串口连接/断开
void RTLS_Widget::on_SerialButton_clicked()
{
    if(ui->SerialButton->text() == QString("Connect"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->SerialBox->currentText());
        //打开串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200
        //设置数据位数
        serial->setDataBits(QSerialPort::Data8);//设置数据位8
        //设置校验位
        serial->setParity(QSerialPort::NoParity);
        //设置停止位
        serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制
        // 修改按钮文字
        ui->SerialButton->setText(QString("DisConnect"));
        // 连接信号槽
        connect(serial,&QSerialPort::readyRead,this,&RTLS_Widget::newData);
    }
    else
    {
        // 关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        // 修改按钮文字
        ui->SerialButton->setText(QString("Connect"));
    }
}

// 新数据到来
void RTLS_Widget::newData()
{
    QByteArray data;                // 读取数据
    QString str_data = data;        // 转换为字符串
    QTextCursor cursor;             // 控件滑动位置


    if (ui->Button_connect->text() != QString("Connect"))
    {
        data = tcpSocket->readAll();
        str_data = data;
        QStringList datas = str_data.split("\r\n");
        foreach(const QString &str, datas) {
            str_data_split.append(str);
        }
        str_data_split.removeLast();    // 删除最后一个空格
        str_num = str_data_split.count();
        // 打印
        if (str_num > 3){
            qWarning() << "data compression, str_num = " << str_data_split.count();
        }
        // 滑动到底并写值
        cursor = ui->textEdit_read->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit_read->setTextCursor(cursor);
        ui->textEdit_read->append(data);

    } else if (ui->SerialButton->text() == QString("DisConnect"))
    {
        data = serial->readAll();
        str_data = data;
        str_data_split = str_data.split("\n");
        str_data_split.removeLast();    // 删除最后一个空格
        str_num = str_data_split.count();

        // 滑动到底并写值
        cursor = ui->SerialTextBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->SerialTextBrowser->setTextCursor(cursor);
        ui->SerialTextBrowser->append(data);
    }

    // 处理数据
    dealNewData();
}

// [仿真] 菜单被点击
void RTLS_Widget::simulationToggled(bool flag)
{
    if (flag) setLocEnv(SIMULATION);
}

// [实验] 菜单被点击
void RTLS_Widget::experimentToggled(bool flag)
{
    if (flag) setLocEnv(EXPERIMENTATION);
}

/******************  定位部分  ******************/
// 获取表格内容, 基站更改时作用
void RTLS_Widget::slotItemChanged(QTableWidgetItem * item)
{
    // 读取行列
    int row = item->row();
    int column = item->column();
    qDebug("行：%d, 列： %d",item->row(),item->column());

    switch (column)
    {
        case 1:
            Anchor[row].x =  item->data(Qt::DisplayRole).toDouble();    // Qt::DisplayRole用于视图文本显示
            Anchor[row].flag[column-1] = 1;
            qDebug()<<Anchor[row].x;
        break;
        case 2:
            Anchor[row].y =  item->data(Qt::DisplayRole).toDouble();
            Anchor[row].flag[column-1] = 1;
            qDebug()<<Anchor[row].y;
        break;
        case 3:
            Anchor[row].z =  item->data(Qt::DisplayRole).toDouble();
            Anchor[row].flag[column-1] = 1;
            qDebug()<<Anchor[row].z;
        break;
    default:
        break;
    }
}


// 弹出定位图形化界面
void RTLS_Widget::on_guiBtn_clicked()
{
    w1.show();
}

// 定位方法改变
void RTLS_Widget::on_locMethodComboBox_currentIndexChanged(int index)
{
    locMethod = LocationMethod(index);
}

// 单击 locFlagBtn 按钮
void RTLS_Widget::on_locFlagBtn_clicked()
{
    if (locationFlag) { // true [停止定位]
        locationFlag = false;
        ui->locFlagBtn->setText("开始定位");
        ui->locFlagBtn->setStyleSheet("");
    } else {    // false [开始定位]
        locationFlag = true;
        ui->locFlagBtn->setText("停止定位");
        ui->locFlagBtn->setStyleSheet("background-color: rgb(255, 0, 0);");
    }
}

// 定位重置
void RTLS_Widget::on_locReset_clicked()
{
    // 1.卡尔曼滤波清零
    for (int i = 0; i < TAG_NUM; i++) {
        if (distance[i].kf != nullptr) {
            distance[i].kf->reset();
            qDebug() << "标签" << i << "定位缓存(卡尔曼数据)已清空~";
        }
    }
    // 2.表格清零
    ui->tableWidget_Tag->clearContents();
    qDebug() << "定位表格数据已清空~" ;
}

// 下拉框选择
void RTLS_Widget::dropDropDownList_clicked(QComboBox* curComboBox, int cnt)
{
    CommonUtil::dropDownListShow(curComboBox, cnt);
}

// 标签测距校正，标签下拉框
void RTLS_Widget::tagDropDownList_clicked()
{
    dropDropDownList_clicked(ui->tagSelect, TAG_NUM);
}

// 标签测距校正，基站下拉框
void RTLS_Widget::anchorDropDownList_clicked()
{
    dropDropDownList_clicked(ui->anchorSelect, ANCHOR_NUM);
}

void RTLS_Widget::rangingModuleInit()
{
    // 1.初始化下拉框
    tagDropDownList_clicked();  // 标签
    anchorDropDownList_clicked();   // 单次测距中基站
    // 2.设置为不可编辑
    ui->rangingParamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 3.rCComponent中添加组件
    rCComponent->insert(ui->tagSelect);
    rCComponent->insert(ui->manualModify);
    rCComponent->insert(ui->anchorSelect);
    rCComponent->insert(ui->singleCorrect);
    rCComponent->insert(ui->a0CheckBox);
    rCComponent->insert(ui->a1CheckBox);
    rCComponent->insert(ui->a2CheckBox);
    rCComponent->insert(ui->a3CheckBox);
    rCComponent->insert(ui->multiCorrect);
    // 4.显示
    rangingParamShow(ui->tagSelect->currentIndex());
}

void RTLS_Widget::rangingParamShow(int tagIdx)
{
    // 1.获取当前标签编号(方法中)
    // 2.获取标签配置参数
    if (distance[tagIdx].rangeConfig == nullptr) {
        distance[tagIdx].rangeConfig = new RangeConfig(this->locEnv, tagIdx, rangingDistConfig);
        distance[tagIdx].rangeConfig->setAnchorGroup(Anchor);
    }
    RangeConfig *curRangingConfig = distance[tagIdx].rangeConfig;
    // 3.参数显示
    for (int i = 0; i < ANCHOR_NUM; i++) {
        double k, b;
        curRangingConfig->getSingleParamValue(i, k, b);
        ui->rangingParamTable->setItem(0, i, new QTableWidgetItem(QString::number(k)));
        ui->rangingParamTable->setItem(1, i, new QTableWidgetItem(QString::number(b)));
    }
    qDebug() << "标签" << tagIdx << "参数显示完成";
    // 4.清除集合数据
    if (itemSet != nullptr) itemSet->clear();
}

void RTLS_Widget::on_rangingParamTable_itemDoubleClicked(QTableWidgetItem *item)
{
    if (!ui->rangingParamTable->editTriggers()) {
        QMessageBox::warning(this, "warnning", "如需修改测距参数，请点击“手动修改”按钮！");
    }
}

void RTLS_Widget::on_manualModify_clicked()
{
    if (!ui->rangingParamTable->editTriggers()) {
        ui->manualModify->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->manualModify->setText("修改完毕");
        ui->rangingParamTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        enableOrDisableRCComponentExceptCurWidget(ui->manualModify, false);
    } else {
        ui->manualModify->setStyleSheet("");
        ui->manualModify->setText("手动修改");
        ui->rangingParamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        enableOrDisableRCComponentExceptCurWidget(ui->manualModify, true);

        int tagIdx = ui->tagSelect->currentIndex();
        // 根据按钮不同作不同处理
        if (choiceWindow()){
            for(set<QTableWidgetItem*>::iterator it = itemSet->begin(); it != itemSet->end(); it++){
               QTableWidgetItem *curItem = (*it);
               setParamToRangingConfig(tagIdx, curItem->row(), curItem->column(), curItem->text().toDouble());
            }
            qDebug() << "标签"<< tagIdx << "参数手动更新完成, 共修改了"<< itemSet->size() << "处参数";
        } else {
            rangingParamShow(tagIdx);
            qDebug() << "标签"<< tagIdx << "参数未改动";
        }
        // 清除集合
        itemSet->clear();
    }
}

void RTLS_Widget::on_rangingParamTable_itemChanged(QTableWidgetItem *item)
{
    if ( ui->rangingParamTable->editTriggers() ==  QAbstractItemView::DoubleClicked){
        itemSet->insert(item);
    }
}

void RTLS_Widget::on_singleCorrect_clicked()
{
    // 0.获取tagIdx
    int curTagIdx = ui->tagSelect->currentIndex();
    // A.分情况
    if (anchorFlag == 0 && ui->singleCorrect->text() == QString("开始校正")) {  // 开始校正
        // 1.更改按钮内容
        ui->singleCorrect->setText("结束校正");
        ui->singleCorrect->setStyleSheet("background-color: rgb(255, 0, 0);");
        // 2.失能其他测距相关按钮，使能记录按钮
        enableOrDisableRCComponentExceptCurWidget(ui->singleCorrect, false);
        ui->singleRecord->setDisabled(false);
        // 3.获取校正基站
        this->anchorFlag = static_cast<unsigned char>(1 << ui->anchorSelect->currentIndex());
        qDebug() << "开始对标签"<< ui->tagSelect->currentIndex() <<"的基站" << ui->anchorSelect->currentIndex() << "进行测距校正~";
        // 4.测距开始
        distance[curTagIdx].rangeConfig->startRangeConfig(this->anchorFlag);
    } else if ( (anchorFlag == 1 || anchorFlag == 2 || anchorFlag == 4 || anchorFlag == 8)
                && ui->singleCorrect->text() == QString("结束校正")) {  // 结束校正
        // TODO: 结束矫正中, 出现窗口,是否确定保存
        // 1.更改按钮内容
        ui->singleCorrect->setText("开始校正");
        ui->singleCorrect->setStyleSheet("");
        // 2.使能其他测距相关按钮，失能记录按钮
        enableOrDisableRCComponentExceptCurWidget(ui->singleCorrect, true);
        ui->singleRecord->setDisabled(true);
        // 3.结束基站校正
        try {
            QString corrMsg = distance[curTagIdx].rangeConfig->finishRangeConig();
            if (choiceWindow(corrMsg)) {
                distance[curTagIdx].rangeConfig->saveRangeCorrection();
                qDebug() << "结束对标签"<< ui->tagSelect->currentIndex() <<"的基站" << ui->anchorSelect->currentIndex() << "进行测距校正~";
            } else {
                distance[curTagIdx].rangeConfig->abandonRangeCorrection();
                qWarning() << "放弃对标签"<< ui->tagSelect->currentIndex() <<"的基站" << ui->anchorSelect->currentIndex() << "进行测距校正~";
            }
        } catch (logic_error &e) {
            distance[curTagIdx].rangeConfig->abandonRangeCorrection();
            CommonUtil::warningMegBox(this, "无数据，无法完成基站测距校正！");
            qWarning() << e.what();
            qWarning() << "放弃对标签"<< ui->tagSelect->currentIndex() <<"的基站" << ui->anchorSelect->currentIndex() << "进行测距校正~";
        }
        // 4.更新
        rangingParamShow(curTagIdx);
        this->anchorFlag = 0;
        ui->singleMearDist->clear();
        ui->singleTrueDist->clear();
    } else {
        qCritical() << "单基站测距出现错误！";
        QMessageBox::critical(this, "危险", "单基站测距出现错误！");
    }
}

void RTLS_Widget::on_multiCorrect_clicked()
{
    // 0.获取tagIdx
    int curTagIdx = ui->tagSelect->currentIndex();
    // A.分情况
    if (anchorFlag == 0 && ui->multiCorrect->text() == QString("开始校正")) {  // 开始校正
        // 1.获取校正基站
        QString anchorIcd = "基站";
        if (ui->a0CheckBox->checkState() == Qt::Checked) {
            anchorFlag |= 1;
            anchorIcd.push_back("0, ");
        }
        if (ui->a1CheckBox->checkState() == Qt::Checked) {
            anchorFlag |= 2;
            anchorIcd.push_back("1, ");
        }
        if (ui->a2CheckBox->checkState() == Qt::Checked) {
            anchorFlag |= 4;
            anchorIcd.push_back("2, ");
        }
        if (ui->a3CheckBox->checkState() == Qt::Checked) {
            anchorFlag |= 8;
            anchorIcd.push_back("3, ");
        }
        if (anchorFlag == 0) {
            qDebug() << "当前无选中基站需要校正";
            QMessageBox::warning(this, "提示", "当前无选中基站需要校正");
            return;
        }
        qDebug() << "开始对标签"<< ui->tagSelect->currentIndex() <<"的基站" << anchorIcd<< "进行测距校正~";
        // 2.更改按钮内容
        ui->multiCorrect->setText("结束校正");
        ui->multiCorrect->setStyleSheet("background-color: rgb(255, 0, 0);");
        // 3.失能其他测距相关按钮，使能记录按钮
        enableOrDisableRCComponentExceptCurWidget(ui->multiCorrect, false);
        ui->multiRecord->setDisabled(false);
        ui->multiRangingLocRead->setDisabled(false);
        // 4.开始校正
        distance[curTagIdx].rangeConfig->startRangeConfig(anchorFlag);
    } else if ( anchorFlag != 0 && ui->multiCorrect->text() == QString("结束校正")) {  // 结束校正
        // 1.更改按钮内容
        ui->multiCorrect->setText("开始校正");
        ui->multiCorrect->setStyleSheet("");
        // 2.使能其他测距相关按钮，失能记录按钮
        enableOrDisableRCComponentExceptCurWidget(ui->multiCorrect, true);
        ui->multiRecord->setDisabled(true);
        ui->multiRangingLocRead->setDisabled(true);
        // 3.结束基站校正
        // TODO:无数情况
        try {
            QString corrMsg = distance[curTagIdx].rangeConfig->finishRangeConig();

            if (choiceWindow(corrMsg)) {
                distance[curTagIdx].rangeConfig->saveRangeCorrection();
                qDebug() << "结束对标签"<< ui->tagSelect->currentIndex() <<"的基站" << QString::number(anchorFlag, 2) << "进行测距校正~";
            } else {
                distance[curTagIdx].rangeConfig->abandonRangeCorrection();
                qWarning() << "放弃对标签"<< ui->tagSelect->currentIndex() <<"的基站" << QString::number(anchorFlag, 2) << "进行测距校正~";
            }
        } catch (logic_error &e) {
            distance[curTagIdx].rangeConfig->abandonRangeCorrection();
            CommonUtil::warningMegBox(this, "无数据，无法完成基站测距校正！");
            qWarning() << e.what();
            qWarning() << "放弃对标签"<< ui->tagSelect->currentIndex() <<"的基站" << QString::number(anchorFlag, 2) << "进行测距校正~";
        }
        // 4.表格更新显示
        rangingParamShow(curTagIdx);
        this->anchorFlag = 0;
        ui->multiMearTable->clear();
        distance[curTagIdx].rangeConfig->setTagLoc(0, 0, 0);
        distance[curTagIdx].rangeConfig->clearTagChangeFlag();
        qDebug() << "当前TagFlag为："<< distance[curTagIdx].rangeConfig->getTagChangeFlag();
    } else {
        qCritical() << "多基站测距出现错误！";
        QMessageBox::critical(this, "危险", "多基站测距出现错误！");
    }
}

void RTLS_Widget::on_singleRecord_clicked(){
    // 0.预判断
    QString trueStrNum = ui->singleTrueDist->text().trimmed();  // 去除前后空格
    // a.是否为空
    if (ui->singleMearDist->text().isEmpty()) {
        qWarning() << "标签无测距数据，请检查下位机数据！";
        QMessageBox::warning(this, "警告", "标签无测距数据，请检查下位机数据！");
        return;
    }
    if (trueStrNum.isEmpty()) {
        qWarning() << "当前测距校正中真实值为空，无法进行记录!";
        QMessageBox::warning(this, "警告",  "当前测距校正中真实值为空，无法进行记录!");
        return;
    }
    // b.是否为一个数 (正则表达式)
    if (not patternMatch("^(\\d+)|(\\d+)(\\.\\d+)$", trueStrNum)) {
        qWarning() << "输入值有误！";
        QMessageBox::warning(this, "警告",  "输入值有误!");
        return;
    }

    // 1.获取数据
    int curTagIdx = ui->tagSelect->currentIndex();
    int curAnchorIdx = ui->anchorSelect->currentIndex();
    // 2.获取真实值
    double trueDist = ui->singleTrueDist->text().toDouble();
    if (trueDist == 0.0) {
        qWarning() << "真实距离为0，输入有误！";
        QMessageBox::warning(this, "警告", "真实距离为0，输入有误！");
        return;
    }
    // 3.记录
    distance[curTagIdx].rangeConfig->recordSingleMeasurement(curAnchorIdx, trueDist);
    // 4.清除数据
    ui->singleTrueDist->clear();
    ui->singleMearDist->clear();
}

void RTLS_Widget::on_multiRecord_clicked()
{
    // 0.预判断
    int curTagIdx = ui->tagSelect->currentIndex();
    if (ui->multiMearTable->item(0, 0) == nullptr || ui->multiMearTable->item(0, 0)->text().isEmpty()) {
        qWarning() << "标签无测距数据，请检查下位机数据！";
        QMessageBox::warning(this, "警告", "标签无测距数据，请检查下位机数据！");
        return;
    }
    qDebug() << "当前TagFlag为："<< distance[curTagIdx].rangeConfig->getTagChangeFlag();
    if (distance[curTagIdx].rangeConfig->getTagChangeFlag() <= 0 ) {
        qWarning() << "标签坐标未有效输入，请重新输入标签坐标！";
        QMessageBox::warning(this, "警告", "标签坐标未有效输入，请重新输入标签坐标！");
        return;
    }
    // 1.遍历
    distance[curTagIdx].rangeConfig->recordMultiRangingMearment(anchorFlag);
    // 2.清除标记
    distance[curTagIdx].rangeConfig->clearTagChangeFlag();
    // 3.更新
    ui->multiMearTable->clear();
}

// 单击multiRangingLocRead多基站测距-标签位置读入按钮
void RTLS_Widget::on_multiRangingLocRead_clicked()
{
    // 0.预处理
    QString xStr = ui->rcc_x_loc->text().trimmed();
    QString yStr = ui->rcc_y_loc->text().trimmed();
    QString zStr = ui->rcc_z_loc->text().trimmed();
    QStringList locList;
    locList.append(xStr);
    locList.append(yStr);
    locList.append(zStr);
    // a.非空判断
    foreach(const QString &str, locList) {
        if (str.isEmpty()) {
            qWarning() << "当前测距校正中坐标存在空值，无法进行记录!";
            QMessageBox::warning(this, "警告",  "当前测距校正中坐标存在空值，无法进行记录值!");
            return;
        }
    }
    // b.正则表达式匹配
    if (not patternMatch("^(-?\\d+)|(-?\\d+)(\\.\\d+)$", locList)) {
        qWarning() << "输入值有误！";
        QMessageBox::warning(this, "警告",  "输入值有误!");
        return;
    }
    // 1.获取数据
    int curTagIdx = ui->tagSelect->currentIndex();
    distance[curTagIdx].rangeConfig->setTagLoc(xStr.toDouble(), yStr.toDouble(), zStr.toDouble());
    distance[curTagIdx].rangeConfig->calcTrueAnchorGroupDist();
    // 2.更新表格
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if ( (1 << i) & anchorFlag ) {
            double distValue = distance[curTagIdx].rangeConfig->getSingleTrueAnchorDist(i);
            ui->multiMearTable->setItem(1, i, new QTableWidgetItem(QString::number(distValue)));
        }
    }

}

// 验证，标签下拉框
void RTLS_Widget::validateTagDropDownList_clicked() // 验证，标签下拉框
{
    CommonUtil::dropDownListShow(ui->validateTagSelect, TAG_NUM);
}

// 单击 validateBtn 定位测距验证按钮
void RTLS_Widget::on_validateBtn_clicked()
{
    if (validateFlag) { // true
        validateFlag = false;
        ui->validateTagSelect->setDisabled(false);
        ui->validateReadTrueLocBtn->setDisabled(true);
        ui->validateBtn->setText("开始验证");
        ui->validateBtn->setStyleSheet("");
    } else {    // false [开始] 按下
        validateFlag = true;
        ui->validateTagSelect->setDisabled(true);
        ui->validateReadTrueLocBtn->setDisabled(false);
        ui->validateBtn->setText("结束验证");
        ui->validateBtn->setStyleSheet("background-color: rgb(255, 0, 0);");
        // 开始定位按钮未打开
        if (!locationFlag && CommonUtil::choiceTFWindow("未开始定位，是否打开定位？")) {
            on_locFlagBtn_clicked();
        }
    }

}

// 单击 validateReadTrueLocBtn 按钮
void RTLS_Widget::on_validateReadTrueLocBtn_clicked()
{
    if (readTrueLocFlag) {  // true
        readTrueLocFlag = false;
        ui->validateReadTrueLocBtn->setText("读取真实位置");
        ui->validateReadTrueLocBtn->setStyleSheet("");
    } else {    // false [读取] 按下
        readTrueLocFlag = true;
        ui->validateReadTrueLocBtn->setText("结束真实位置读取");
        ui->validateReadTrueLocBtn->setStyleSheet("background-color: rgb(255, 0, 0);");
        on_validateLocTab_itemChanged(ui->validateLocTab->item(1, 0));
        on_validateLocTab_itemChanged(ui->validateLocTab->item(1, 1));
        on_validateLocTab_itemChanged(ui->validateLocTab->item(1, 2));
    }
}

void RTLS_Widget::on_validateLocTab_itemChanged(QTableWidgetItem *item)
{
    // 0.预处理
    if (item == nullptr) {
        qWarning() << "空指针异常！";
        return;
    }
    if (item->row() != 1) {
        return;
    }
    // 1.判断是否合法
    double *locPointer;
    char *flag;
    switch (item->column()) {
    case 0:
        locPointer = &(trueLoc->x);
        flag = &(trueLoc->flag[0]);
        break;
    case 1:
        locPointer = &(trueLoc->y);
        flag = &(trueLoc->flag[1]);
        break;
    case 2:
        locPointer = &(trueLoc->z);
        flag = &(trueLoc->flag[2]);
        break;
    default:
        qCritical() << "validateLocTab表格索引存在问题!";
        throw std::domain_error("validateLocTab表格索引存在问题!");
    }
    if (CommonUtil::patternMatch("^(-?\\d+)|(-?\\d+)(\\.\\d+)$", item->text().trimmed())) {
        *locPointer = item->text().trimmed().toDouble();
        *flag = 1;
        qDebug() << "测距定位验证中,真实位置修改成功~";
        updateTrueDist();   // 真实位置更新
    } else {    // 不合法,维持原样
        item->setText(QString::number(*locPointer));
        qWarning() << "测距定位验证中输入位置不合法,真实位置修改失败!";
        CommonUtil::warningMegBox(this, "测距定位验证中输入位置不合法,真实位置修改失败!");
    }
}

// 标签validateTagSelect选择的索引改变
void RTLS_Widget::on_validateTagSelect_currentIndexChanged(int index)
{
    // 0.清空位置标志
    memset(trueLoc->flag, 0, sizeof(char) * 3);
    trueLoc->x = trueLoc->y = trueLoc->z = 0;
    trueDist->t_a0 = trueDist->t_a1 = trueDist->t_a2 = trueDist->t_a1 = 0;
    // 1.清空表格内容
    ui->validateLocTab->clearContents();
    ui->validateDistTab->clearContents();
    // 2.检验读取位置是否关闭
    if (readTrueLocFlag) on_validateReadTrueLocBtn_clicked();
}

// 菜单栏初始化
void RTLS_Widget::menuBarInit()
{
    // 1.设置 仿真 和 实验 为可选中状态
    simulationMode->setCheckable(true);
    experimentMode->setCheckable(true);
    // 2.选择模式
    if (CommonUtil::binaryChoice("请选择模式？", "仿真模式", "实验模式")) {
        setLocEnv(SIMULATION);
    } else {
        setLocEnv(EXPERIMENTATION);
    }
}

// 设置环境
void RTLS_Widget::setLocEnv(Environment env)
{
    // 1.判断与当前环境是否相等
    if (locEnv != env) {
        // 改变状态
        locEnv = env;
        // a.停止定位
        if (locationFlag) on_locFlagBtn_clicked();
        // b.清空定位缓存
        on_locReset_clicked();
        // c.参数重新获取
        resetRangingConfigParam();
        // d.显示界面刷新
        rangingParamShow(ui->tagSelect->currentIndex());
    }
    // 2.判断对应模式
    if (env == SIMULATION) {
        simulationMode->setChecked(true);
        simulationMode->setDisabled(true);
        experimentMode->setChecked(false);
        experimentMode->setDisabled(false);
        ui->modeLabel->setText(" 仿真模式");
        qDebug() << "切换为仿真模式~";
    } else if (env == EXPERIMENTATION) {
        experimentMode->setChecked(true);
        experimentMode->setDisabled(true);
        simulationMode->setChecked(false);
        simulationMode->setDisabled(false);
        ui->modeLabel->setText(" 实验模式");
        qDebug() << "切换为实验模式~";
    } else {
        qCritical() << "不存在这种模式!";
        throw invalid_argument("模式输入参数有误!");
    }
}

// 重置文件环境参数[k b]
void RTLS_Widget::resetRangingConfigParam()
{
    for (int i = 0; i < TAG_NUM; i++) {
        if (distance[i].rangeConfig != nullptr) {
            if (distance[i].rangeConfig->getEnvMode() != this->locEnv) distance[i].rangeConfig->setEnvMode(this->locEnv);
        }
    }
}

// 定位初始化
void RTLS_Widget::locationInit()
{
    // 1.基站坐标初始化
    anchorLocationInit();
    // 2.定位方法初始化
    on_locMethodComboBox_currentIndexChanged(ui->locMethodComboBox->currentIndex());
}

// 基站坐标初始化
void RTLS_Widget::anchorLocationInit()
{
    for (int i = 0; i < 4; i++)
    {
        Anchor[i].x = ui->tableWidget_Anchor->item(i,1)->data(Qt::DisplayRole).toDouble();
        Anchor[i].y = ui->tableWidget_Anchor->item(i,2)->data(Qt::DisplayRole).toDouble();
        Anchor[i].z = ui->tableWidget_Anchor->item(i,3)->data(Qt::DisplayRole).toDouble();
        Anchor[i].flag[0]=1;
        Anchor[i].flag[1]=1;
        Anchor[i].flag[2]=1;
    }
}


// 处理接收到数据
void RTLS_Widget::dealNewData()
{
    while (not str_data_split.isEmpty()) {
        /*** 0.数据预处理 ***/
        int length = str_data_split[0].length();    // 数据帧长度

        // 判断长度和mc
        if(length >= TOF_REPORT_LEN) {
            QString header = str_data_split[0].mid(0, 2);
            //"mc" 包含校正后的数据
            if(not header.contains("mc")) continue;
        }
        else {
            continue;
        }

        char type, c;
        unsigned char mask;
        int range[4], lnum, seq, rangetime, aid, tid; // lnum: unit raw range计数值；rseq：range sequence number计数值；rangetime：如果 MID=ma，代表 TX/RX 天线延迟
        int x_true, y_true, z_true; // 真实位置
        // m%c %x %x %x %x %x %x %x %x %c%d:%d %d %d %d\n
        int num = sscanf(str_data_split[0].toUtf8().constData(),
                         "m%c %x %x %x %x %x %x %x %x %c%d:%d %d %d %d\n",
                         &type, &mask, &range[0], &range[1], &range[2], &range[3],
                         &lnum, &seq, &rangetime, &c, &tid, &aid, &x_true, &y_true, &z_true);
        // 虚拟真实位置
        Tag[7].x = static_cast<double>(x_true) / 1000;
        Tag[7].y = static_cast<double>(y_true) / 1000;
        Tag[7].z = static_cast<double>(z_true) / 1000;
        ui->tableWidget_Tag->setItem(7,0,new QTableWidgetItem( QString::number(Tag[7].x,10,5)));
        ui->tableWidget_Tag->setItem(7,1,new QTableWidgetItem( QString::number(Tag[7].y,10,5)));
        ui->tableWidget_Tag->setItem(7,2,new QTableWidgetItem( QString::number(Tag[7].z,10,5)));

        // 本次测距中，对应标签的有效数据
        distance[tid].anchorFlag = mask;
        distance[tid].t_a0 = range[0];
        distance[tid].t_a1 = range[1];
        distance[tid].t_a2 = range[2];
        distance[tid].t_a3 = range[3];
        // 校正参数
        if (distance[tid].rangeConfig == nullptr) {
            distance[tid].rangeConfig = new RangeConfig(this->locEnv, tid, rangingDistConfig);
        }

        /*** 1.测距校正(校正时，不进行定位和验证) ***/
        if (anchorFlag == 1 || anchorFlag == 2 || anchorFlag == 4 || anchorFlag == 8) {
            singleAnchorCorrection();
        } else if (anchorFlag != 0) {
            multiAnchorCorrection();
        } else if(locationFlag) {
            /*** 2.位置估计 ***/
            locationUpdate(tid, locMethod);
            /*** 3.定位测距验证 ***/
            if (validateFlag && tid == ui->validateTagSelect->currentIndex()) {
                validating();
            }
        }
        /*** 4.数据更新 ***/
        str_data_split.removeFirst();   // 删除第一个元素
    }
}


// 测距更新
void RTLS_Widget::locationUpdate(int tagIdx, LocationMethod method)
{
    char A0_flag, A1_flag, A2_flag;
    int averageNum = 1;

    A0_flag = Anchor[0].flag[0] + Anchor[0].flag[1] + Anchor[0].flag[2];
    A1_flag = Anchor[1].flag[0] + Anchor[1].flag[1] + Anchor[1].flag[2];
    A2_flag = Anchor[2].flag[0] + Anchor[2].flag[1] + Anchor[2].flag[2];


    if(A0_flag==3 && A1_flag==3 && A2_flag==3){
        int result = 0;
        int Range_deca[4] = {0};
        if(dit_temp[tagIdx][0].t_a0==0 && dit_temp[tagIdx][0].t_a1==0&& dit_temp[tagIdx][0].t_a2==0)
        {
            dit_temp[tagIdx][0].t_a0 = distance[tagIdx].t_a0;
            dit_temp[tagIdx][0].t_a1 = distance[tagIdx].t_a1;
            dit_temp[tagIdx][0].t_a2 = distance[tagIdx].t_a2;
            dit_temp[tagIdx][0].t_a3 = distance[tagIdx].t_a3;
            rangeFilterp[tagIdx][0] = distance[tagIdx].t_a0; //tag to A0 distance
            rangeFilterp[tagIdx][1] = distance[tagIdx].t_a1; //tag to A1 distance
            rangeFilterp[tagIdx][2] = distance[tagIdx].t_a2; //tag to A2 distance
            rangeFilterp[tagIdx][3] = distance[tagIdx].t_a3; //tag to A3 distance
            for (int j=0;j<averageNum-1;j++) //10个，一个已赋值
            {
                dit_temp[tagIdx][j+1].t_a0 = dit_temp[tagIdx][j].t_a0;
                dit_temp[tagIdx][j+1].t_a1 = dit_temp[tagIdx][j].t_a1;
                dit_temp[tagIdx][j+1].t_a2 = dit_temp[tagIdx][j].t_a2;
                dit_temp[tagIdx][j+1].t_a3 = dit_temp[tagIdx][j].t_a3;
            }
        }
        else {
            // 移位
            for (int j=averageNum-1;j>0;j--)
            {
                dit_temp[tagIdx][j].t_a0 = dit_temp[tagIdx][j-1].t_a0;
                dit_temp[tagIdx][j].t_a1 = dit_temp[tagIdx][j-1].t_a1;
                dit_temp[tagIdx][j].t_a2 = dit_temp[tagIdx][j-1].t_a2;
                dit_temp[tagIdx][j].t_a3 = dit_temp[tagIdx][j-1].t_a3;
            }

            dit_temp[tagIdx][0].t_a0 = distance[tagIdx].t_a0;
            dit_temp[tagIdx][0].t_a1 = distance[tagIdx].t_a1;
            dit_temp[tagIdx][0].t_a2 = distance[tagIdx].t_a2;
            dit_temp[tagIdx][0].t_a3 = distance[tagIdx].t_a3;
        }

        // 取平均值
        for (int j=0;j<averageNum;j++)
        {
            Range_deca[0] += dit_temp[tagIdx][j].t_a0;
            Range_deca[1] += dit_temp[tagIdx][j].t_a1;
            Range_deca[2] += dit_temp[tagIdx][j].t_a2;
            Range_deca[3] += dit_temp[tagIdx][j].t_a3;

        }


        for (int i = 0; i < ANCHOR_NUM; i++) {
            rangeFilterp[tagIdx][i] = int(0.6*Range_deca[i]/averageNum + 0.4*rangeFilterp[tagIdx][i]);
            Range_deca[i] = static_cast<int>(rangeFilterp[tagIdx][i] * distance[tagIdx].rangeConfig->getSingleKValue(i) + distance[tagIdx].rangeConfig->getSingleBValue(i));
        }
        // Kalman滤波初始化
        if (!distance[tagIdx].kf) {
            int spatial_dimension = 3;
            double delta_t = 0.2;
            MatrixXd Q = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension) * 0.0001; //0.0008
            MatrixXd R = MatrixXd::Identity(spatial_dimension, spatial_dimension) * 0.0025;     // sd = 0.05
            MatrixXd P_init = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension);
            distance[tagIdx].kf = new KalmanFilter(spatial_dimension, delta_t, Q, R, P_init);
        }
        // Q初始化
        MatrixXd Q = MatrixXd::Identity(4, 4) * 0.0025; // sd = 0.05

        GetLocation(method, &Tag[tagIdx], &Anchor[0], &Range_deca[0], distance[tagIdx].kf, Q, 0.005, 0.001, 200);

        // 判断
        if(result != -1)
        {
            ui->tableWidget_Tag->setItem(tagIdx,0,new QTableWidgetItem( QString::number(Tag[tagIdx].x,10,5)));
            ui->tableWidget_Tag->setItem(tagIdx,1,new QTableWidgetItem( QString::number(Tag[tagIdx].y,10,5)));
            ui->tableWidget_Tag->setItem(tagIdx,2,new QTableWidgetItem( QString::number(Tag[tagIdx].z,10,5)));

        }

        double error = sqrt((pow(Tag[0].x - Tag[7].x, 2) + pow(Tag[0].y - Tag[7].y, 2) + pow(Tag[0].z - Tag[7].z, 2))/3);
        qDebug() << "error = " << error;
    }

}



// 将表格修改存入
void RTLS_Widget::setParamToRangingConfig(int tagIdx, int row, int col, double value)
{
    if (row == 0) { //  k
        distance[tagIdx].rangeConfig->setSingleKValue(col, value);
    } else if (row == 1) {  // b
        distance[tagIdx].rangeConfig->setSingleBValue(col, value);
    }

}

double RTLS_Widget::recordSingleRanging(int tagIdx, unsigned char anchorFlag, int &anchorIdx)
{
    // 1.初始化参数
    int curDistance = 0;
    // 2. 读取参数
    switch (anchorFlag) {
        case 1:
            anchorIdx = 0;
            curDistance = distance[tagIdx].t_a0;
        break;
        case 2:
            anchorIdx = 1;
            curDistance = distance[tagIdx].t_a1;
        break;
        case 4:
            anchorIdx = 2;
            curDistance = distance[tagIdx].t_a2;
        break;
        case 8:
            anchorIdx = 3;
            curDistance = distance[tagIdx].t_a3;
        break;
    default: qCritical() << "单基站测距校正无法对应！";
        throw logic_error("单基站测距校正无法对应");
    }
    // 3.判断是否有数
    if (anchorFlag & this->anchorFlag) {
        // a.记录
        distance[tagIdx].rangeConfig->recordSingleRangingDist(anchorIdx, curDistance);
        // b.显示
        return distance[tagIdx].rangeConfig->getCurMearDist(anchorIdx);
    } else {
        // a.警告
        qWarning() << "标签"<< tagIdx << "没有对基站" << anchorIdx << "的测距";
        throw logic_error("没有对应测距");
    }
}

// 标签的单基站测距校正
void RTLS_Widget::singleAnchorCorrection()
{
    // 0.读取参数
    int curTagIdx = ui->tagSelect->currentIndex();
    int anchorIdx = 0;
    try {
        double curMearDist = recordSingleRanging(curTagIdx, this->anchorFlag, anchorIdx);
        ui->singleMearDist->setText(QString::number(curMearDist));
    } catch (logic_error &e) {
        qWarning() << "标签"<< curTagIdx << "没有对基站" << anchorIdx << "的测距";
    }
}

// 多个基站测距参数校正
void RTLS_Widget::multiAnchorCorrection()
{
    // 0.读取参数
    int curTagIdx = ui->tagSelect->currentIndex();
    int anchorIdx = 0;
    unsigned char curAnchorFlag = 1;
    do {
        if (curAnchorFlag & this->anchorFlag) {
            try {
                double curMearDist = recordSingleRanging(curTagIdx, curAnchorFlag, anchorIdx);
                ui->multiMearTable->setItem(0, anchorIdx, new QTableWidgetItem(QString::number(curMearDist)));
            } catch (logic_error &e) {
                qWarning() << "标签"<< curTagIdx << "没有对基站" << anchorIdx << "的测距";
            }
        }
        curAnchorFlag <<= 1;
    } while (curAnchorFlag <= 8);
}

// 测距校正中使能或失能其他组件
void RTLS_Widget::enableOrDisableRCComponentExceptCurWidget(QWidget *curWidget, bool state)
{
    for (set<QWidget*>::iterator iter = rCComponent->begin(); iter != rCComponent->end(); iter++) {
        if ((*iter) != curWidget) {
            (*iter)->setDisabled(!state);
        }
    }
}

// 验证部分初始化
void RTLS_Widget::validateModuleInit()
{
    // 1.初始化部件
    validateTagDropDownList_clicked();
}

// 验证
void RTLS_Widget::validating()
{
    validating(ui->validateTagSelect->currentIndex(), readTrueLocFlag);
}

// 验证
void RTLS_Widget::validating(int tagIdx, bool trueLosFlag)
{
    // 0.预处理
    if (tagIdx < 0 || tagIdx >= TAG_NUM) {
        throw invalid_argument("输入参数有误！");
    }
    // 1.显示测量位置
    ui->validateLocTab->setItem(0, 0, new QTableWidgetItem(QString::number(Tag[tagIdx].x)));
    ui->validateLocTab->setItem(0, 1, new QTableWidgetItem(QString::number(Tag[tagIdx].y)));
    ui->validateLocTab->setItem(0, 2, new QTableWidgetItem(QString::number(Tag[tagIdx].z)));
    // 2.显示测距距离
    ui->validateDistTab->setItem(0, 0, new QTableWidgetItem(QString::number(distance[tagIdx].t_a0)));
    ui->validateDistTab->setItem(0, 1, new QTableWidgetItem(QString::number(distance[tagIdx].t_a1)));
    ui->validateDistTab->setItem(0, 2, new QTableWidgetItem(QString::number(distance[tagIdx].t_a2)));
    ui->validateDistTab->setItem(0, 3, new QTableWidgetItem(QString::number(distance[tagIdx].t_a3)));
    // 3.检查是否存在真实距离, 显示距离差
    if (trueLosFlag && trueLoc->flag[0] + trueLoc->flag[1] + trueLoc->flag[2] == 3) {
        ui->validateDistTab->setItem(2, 0, new QTableWidgetItem(QString::number(distance[tagIdx].t_a0 - trueDist->t_a0))); // A0
        ui->validateDistTab->setItem(2, 1, new QTableWidgetItem(QString::number(distance[tagIdx].t_a1 - trueDist->t_a1))); // A1
        ui->validateDistTab->setItem(2, 2, new QTableWidgetItem(QString::number(distance[tagIdx].t_a2 - trueDist->t_a2))); // A2
        ui->validateDistTab->setItem(2, 3, new QTableWidgetItem(QString::number(distance[tagIdx].t_a3 - trueDist->t_a3))); // A3
    }
}

// 更新真实距离函数
void RTLS_Widget::updateTrueDist()
{
    if (trueLoc->flag[0] + trueLoc->flag[1] + trueLoc->flag[2] == 3 && readTrueLocFlag) {
        trueDist->t_a0 = static_cast<int>(CommonUtil::calcEuclidDist(trueLoc, &Anchor[0]) * 1000);  // A0
        ui->validateDistTab->setItem(1, 0, new QTableWidgetItem(QString::number(trueDist->t_a0)));
        trueDist->t_a1 = static_cast<int>(CommonUtil::calcEuclidDist(trueLoc, &Anchor[1]) * 1000);  // A1
        ui->validateDistTab->setItem(1, 1, new QTableWidgetItem(QString::number(trueDist->t_a1)));
        trueDist->t_a2 = static_cast<int>(CommonUtil::calcEuclidDist(trueLoc, &Anchor[2]) * 1000);  // A2
        ui->validateDistTab->setItem(1, 2, new QTableWidgetItem(QString::number(trueDist->t_a2)));
        trueDist->t_a3 = static_cast<int>(CommonUtil::calcEuclidDist(trueLoc, &Anchor[3]) * 1000);  // A3
        ui->validateDistTab->setItem(1, 3, new QTableWidgetItem(QString::number(trueDist->t_a3)));
    } else {
        qWarning() << "真实位置trueLoc的flag不满足条件或未对真实位置进行读取!";
    }
}
