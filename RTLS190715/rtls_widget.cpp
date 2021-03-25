#include "rtls_widget.h"
#include "ui_rtls_widget.h"
#include "stdio.h"
#include <string.h>
#include <QTime>
#include <QPainter>

//#define TOF_REPORT_LEN  (107)
#define TOF_REPORT_LEN  (64)


RTLS_Widget::RTLS_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RTLS_Widget)
{
    ui->setupUi(this);

    // 定时器
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    timer->start(1);  // 单位：10ms


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

    // 表格
    connect(ui->tableWidget_Anchor,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(slotItemChanged(QTableWidgetItem*)));

}

RTLS_Widget::~RTLS_Widget()
{
    delete ui;
}

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

// 定时器执行
void RTLS_Widget:: handleTimeout()
{
    if((not str_data_split.isEmpty())&&(clock%(50/str_num) == 0))
    {
        int length; // 数据帧长度

        length = str_data_split[0].length();

        // 判断长度和mc
        if(length >= TOF_REPORT_LEN)
        {
            QString header = str_data_split[0].mid(0, 2);

            //"mc" 包含校正后的数据
            if(not header.contains("mc"))
            {
                return;
            }

        }
        else {
            return;
        }

        // TOF报告
        QByteArray tofReport = str_data_split[0].toUtf8();

        int aid, tid, range[4], lnum, seq, mask,temperature,voltage,current,electric,total_elec,rest_elec;
        int rangetime;
        char c, type,power;

        int num = sscanf(tofReport.constData(),
                         "m%c %x %x %x %x %x %x %x %x %c%d:%d power_%c %d %d %d %d %d %d\n",
                         &type, &mask, &range[0], &range[1], &range[2], &range[3],
                         &lnum, &seq, &rangetime, &c, &tid, &aid,&power,&temperature,
                         &voltage, &current, &electric, &total_elec, &rest_elec);

        if(mask==0x0f)
        {
//            distance[tid].t_a0 = int(range[0]*1.0028 - 566.97);
//            distance[tid].t_a1 = int(range[1]*1.0028 - 566.97);
//            distance[tid].t_a2 = int(range[2]*1.0028 - 566.97);
//            distance[tid].t_a3 = int(range[3]*1.0028 - 566.97);
            distance[tid].t_a0 = range[0];
            distance[tid].t_a1 = range[1];
            distance[tid].t_a2 = range[2];
            distance[tid].t_a3 = range[3];

            distance[tid].flag = 1<<tid;
            dist_flag |= distance[tid].flag;
        }

        str_data_split.removeFirst();   // 删去第一个元素
    }

    int i = 0;  // for
    char A0_flag, A1_flag, A2_flag;
    int averageNum = 18;

    A0_flag = Anchor[0].flag[0] + Anchor[0].flag[1] + Anchor[0].flag[2];
    A1_flag = Anchor[1].flag[0] + Anchor[1].flag[1] + Anchor[1].flag[2];
    A2_flag = Anchor[2].flag[0] + Anchor[2].flag[1] + Anchor[2].flag[2];


    if(A0_flag==3 && A1_flag==3 && A2_flag==3 && dist_flag != 0)
    {
        int result = 0;
        int Range_deca[4] = {0};
        for (i=0;i<8;i++)
        {
            if(dist_flag%2 ==1)
            {
                if(dit_temp[i][0].t_a0==0 && dit_temp[i][0].t_a1==0&& dit_temp[i][0].t_a2==0)
                {
                    dit_temp[i][0].t_a0 = distance[i].t_a0;
                    dit_temp[i][0].t_a1 = distance[i].t_a1;
                    dit_temp[i][0].t_a2 = distance[i].t_a2;
                    dit_temp[i][0].t_a3 = distance[i].t_a3;
                    rangeFilterp[i][0] = distance[i].t_a0;; //tag to A0 distance
                    rangeFilterp[i][1] = distance[i].t_a1;; //tag to A1 distance
                    rangeFilterp[i][2] = distance[i].t_a2;;; //tag to A2 distance
                    rangeFilterp[i][3] = distance[i].t_a3;;; //tag to A3 distance
                    for (int j=0;j<averageNum-1;j++) //10个，一个已赋值
                    {
                        dit_temp[i][j+1].t_a0 = dit_temp[i][j].t_a0;
                        dit_temp[i][j+1].t_a1 = dit_temp[i][j].t_a1;
                        dit_temp[i][j+1].t_a2 = dit_temp[i][j].t_a2;
                        dit_temp[i][j+1].t_a3 = dit_temp[i][j].t_a3;
                    }
                }
                else
                {
                    // 移位
                    for (int j=averageNum-1;j>0;j--)
                    {
                        dit_temp[i][j].t_a0 = dit_temp[i][j-1].t_a0;
                        dit_temp[i][j].t_a1 = dit_temp[i][j-1].t_a1;
                        dit_temp[i][j].t_a2 = dit_temp[i][j-1].t_a2;
                        dit_temp[i][j].t_a3 = dit_temp[i][j-1].t_a3;
                    }

                    dit_temp[i][0].t_a0 = distance[i].t_a0;
                    dit_temp[i][0].t_a1 = distance[i].t_a1;
                    dit_temp[i][0].t_a2 = distance[i].t_a2;
                    dit_temp[i][0].t_a3 = distance[i].t_a3;
                }


                // 取平均值
                for (int j=0;j<averageNum;j++)
                {
                    Range_deca[0] += dit_temp[i][j].t_a0;
                    Range_deca[1] += dit_temp[i][j].t_a1;
                    Range_deca[2] += dit_temp[i][j].t_a2;
                    Range_deca[3] += dit_temp[i][j].t_a3;

                }

                rangeFilterp[i][0] = int(0.3*Range_deca[0]/averageNum + 0.7*rangeFilterp[i][0]); //tag to A0 distance
                rangeFilterp[i][1] = int(0.3*Range_deca[1]/averageNum + 0.7*rangeFilterp[i][1]); //tag to A1 distance
                rangeFilterp[i][2] = int(0.3*Range_deca[2]/averageNum + 0.7*rangeFilterp[i][2]);; //tag to A2 distance
                rangeFilterp[i][3] = int(0.3*Range_deca[3]/averageNum + 0.7*rangeFilterp[i][3]);; //tag to A3 distance
                Range_deca[0] = rangeFilterp[i][0];
                Range_deca[1] = rangeFilterp[i][1];
                Range_deca[2] = rangeFilterp[i][2];
                Range_deca[3] = rangeFilterp[i][3];
                // Kalman滤波初始化
                if (!distance[i].kf) {
                    int spatial_dimension = 3;
                    double delta_t = 0.2;
                    MatrixXd Q = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension) * 0.0008;
                    MatrixXd R = MatrixXd::Identity(spatial_dimension, spatial_dimension) * 0.0025;     // sd = 0.05
                    MatrixXd P_init = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension);
                    distance[i].kf = new KalmanFilter(spatial_dimension, delta_t, Q, R, P_init);
                }
                // Q初始化
                MatrixXd Q = MatrixXd::Identity(4, 4) * 0.0025; // sd = 0.05

                GetLocation(T_T_K, &Tag[i], &Anchor[0], &Range_deca[0], distance[i].kf, Q, 0.005, 0.001, 200);
                // 判断
                if(result != -1)
                {
                    ui->tableWidget_Tag->setItem(i,1,new QTableWidgetItem( QString::number(Tag[i].x,10,5)));
                    ui->tableWidget_Tag->setItem(i,2,new QTableWidgetItem( QString::number(Tag[i].y,10,5)));
                    ui->tableWidget_Tag->setItem(i,3,new QTableWidgetItem( QString::number(Tag[i].z,10,5)));

                }

            }
            dist_flag = dist_flag>>1;
        }
    }

    // 清零
    dist_flag =0;

    // 定时器时钟
    if(clock == 99)
        clock=0;
    else
        clock++;

}

// TODO: 根据不同的通信写判断
void RTLS_Widget::newData()
{
    QByteArray data;                // 读取数据
    QString str_data = data;        // 转换为字符串
    QTextCursor cursor;             // 控件滑动位置


    if (ui->Button_connect->text() != QString("Connect"))
    {
        data = tcpSocket->readAll();
        str_data = data;
        str_data_split = str_data.split("\n");
        str_data_split.removeLast();    // 删除最后一个空格
        str_num = str_data_split.count();

        // 滑动到底并写值
        cursor = ui->textEdit_read->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit_read->setTextCursor(cursor);
        ui->textEdit_read->append(data);

    }
    else if (ui->SerialButton->text() == QString("DisConnect"))
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
}

void RTLS_Widget:: deal_data(QStringList str_data_split)
{
    char i; // 计数变量
    int length; // 数据帧长度

    for (i=0;i<str_data_split.count();i++)
    {
//        ui->textEdit_read->append(str_data_split[i]);
        length = str_data_split[i].length();
//        qDebug()<<length;

        // 判断长度和mc
        if(length >= TOF_REPORT_LEN)
        {
            QString header = str_data_split[i].mid(0, 2);

            //"mc" 包含校正后的数据
            if(not header.contains("mc"))
            {
                return;
            }
//            qDebug()<<"含有mc";

        }
        else {
            return;
        }

        // TOF报告
        QByteArray tofReport = str_data_split[i].toUtf8();

        int aid, tid, range[4], lnum, seq, mask,temperature,voltage,current,electric,total_elec,rest_elec;
        int rangetime;
        char c, type,power;

        int num = sscanf(tofReport.constData(),
                         "m%c %x %x %x %x %x %x %x %x %c%d:%d power_%c %d %d %d %d %d %d\n",
                         &type, &mask, &range[0], &range[1], &range[2], &range[3], &lnum, &seq, &rangetime, &c, &tid, &aid,&power,&temperature,&voltage,&current,&electric,&total_elec,&rest_elec);
//        qDebug()<<num;

        if(mask==0x0f)
        {
//            distance[tid].t_a0 = int(range[0]*1.0094 - 561.1);
//            distance[tid].t_a1 = int(range[1]*1.0094 - 561.1);
//            distance[tid].t_a2 = int(range[2]*1.0094 - 561.1);
//            distance[tid].t_a3 = int(range[3]*1.0094 - 561.1);

            distance[tid].t_a0 = range[0];
            distance[tid].t_a1 = range[1];
            distance[tid].t_a2 = range[2];
            distance[tid].t_a3 = range[3];

            distance[tid].flag = 1<<tid;
            dist_flag |= distance[tid].flag;

//            qDebug("Tid:%d,%d,%d,%d,%d",tid,distance[tid].t_a0,distance[tid].t_a1,distance[tid].t_a2,distance[tid].t_a3);
        }



//        qDebug("%d",distance[tid].flag);

//        qDebug()<<distance[tid].t_a0;

    }


}

void RTLS_Widget::on_pushButton_clicked()
{
    int i = 0;
    for (i=0;i<4;i++)
    {
        Anchor[i].x = ui->tableWidget_Anchor->item(i,1)->data(Qt::DisplayRole).toDouble();
        Anchor[i].y = ui->tableWidget_Anchor->item(i,2)->data(Qt::DisplayRole).toDouble();
        Anchor[i].z = ui->tableWidget_Anchor->item(i,3)->data(Qt::DisplayRole).toDouble();
        Anchor[i].flag[0]=1;
        Anchor[i].flag[1]=1;
        Anchor[i].flag[2]=1;
    }
}


// 弹出图形化界面
void RTLS_Widget::on_pushButton_2_clicked()
{
    w1.show();
}

