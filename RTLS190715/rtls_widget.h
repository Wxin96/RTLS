#ifndef RTLS_WIDGET_H
#define RTLS_WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "trilateration.h"
#include <QTableWidgetItem>
#include <QTimer>
#include <QMenuBar>
#include <QMenu>
#include "location.h"
#include "config.h"
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QMessageBox>
#include <math.h>
#include "logwidget.h"
#include <iostream>
#include <set>
#include "commonutil.h"
#include "lightcontrol.h"

using std::set;
using namespace CommonUtil;

namespace Ui {
class RTLS_Widget;
}


class RTLS_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit RTLS_Widget(QWidget *parent = nullptr);
    ~RTLS_Widget();

signals:

private slots:
    /*  定数据接收部分  */
    void on_Button_connect_clicked();   // TCP连接/断开
    void SerialPortDetect();    // 串口检测
    void on_SerialButton_clicked(); // 串口连接/断开
    void newData(); // 新数据到来

    /*  菜单栏部分  */
    void simulationToggled(bool flag);   // [仿真] 菜单被点击
    void experimentToggled(bool flag);  // [实验] 菜单被点击

    /*  定位部分  */
    void slotItemChanged(QTableWidgetItem *item);   // 基站坐标变更
    void on_guiBtn_clicked();   // 图形化定位
    void on_locMethodComboBox_currentIndexChanged(int index);   // 定位方法改变
    void on_locFlagBtn_clicked();   // 单击 locFlagBtn 按钮
    void on_locReset_clicked(); // 定位重置

    /*  标签测距校正  */
    // 标签下拉框
    void tagDropDownList_clicked();
    // 基站下拉框
    void anchorDropDownList_clicked();
    // 测距参数显示
    void rangingParamShow(int tagIdx);
    // 双击测距表格单元格 槽
    void on_rangingParamTable_itemDoubleClicked(QTableWidgetItem *item);
    // 点击 手动修改 按钮
    void on_manualModify_clicked();
    // 表格中单个测距参数改变 =》 槽
    void on_rangingParamTable_itemChanged(QTableWidgetItem *item);
    // 单击 singleCorrect 按钮
    void on_singleCorrect_clicked();
    // 单击multiCorrect按钮
    void on_multiCorrect_clicked();
    // 单击singleRecord单基站校正记录按钮
    void on_singleRecord_clicked();
    // 单击multiRecord多基站记录按钮
    void on_multiRecord_clicked();
    // 单击multiRangingLocRead多基站测距-标签位置读入按钮
    void on_multiRangingLocRead_clicked();

    /*  标签定位测距验证  */
    // 验证，标签下拉框
    void validateTagDropDownList_clicked();
    // 单击 validateBtn 定位测距验证按钮
    void on_validateBtn_clicked();
    // 单击 validateReadTrueLocBtn 按钮
    void on_validateReadTrueLocBtn_clicked();
    // 定位测距验证位置表格中元素改变
    void on_validateLocTab_itemChanged(QTableWidgetItem *item);
    // 标签validateTagSelect选择的索引改变
    void on_validateTagSelect_currentIndexChanged(int index);

    /*  射灯跟随部分  */
    void on_followTagSelect_clicked();  // 射灯跟随部分点击标签选择
    void on_lightIplineEdit_editingFinished();  // 射灯跟随部分ip内容更改结束
    void on_lightConfigDisplayBtn_clicked();    // 射灯跟随部分配置信息显示
    void on_netCardSelect_clicked();    // 射灯跟随部分点击网卡选择
    void on_reflushNetBth_clicked();    // 刷新射灯网络
    void on_netCardSelect_currentIndexChanged(int index);   // 射灯使用网卡序号改变
    void on_netSelect_clicked();    // 射灯跟随部分点击网络号选择
    void on_netSelect_currentIndexChanged(int index);   // 射灯跟随部分点击网络号更改
    void on_subNetSelect_clicked(); // 射灯跟随部分点击子网络号选择
    void on_subNetSelect_currentIndexChanged(int index);    // 射灯跟随部分点击子网络号改变
    void on_universeSelect_clicked();   // 射灯跟随部分点击域点击
    void on_universeSelect_currentIndexChanged(int index);  // 射灯跟随部分点击域改变
    void on_channelSelect_clicked();    // 射灯跟随部分点击通道点击
    void on_channelSelect_currentIndexChanged(int index);   // 射灯跟随部分点击通道改变
    void on_channelValue_valueChanged(int value);   // 射灯跟随部分-滑块值改变
    void on_blackFeildBtn_clicked();    // 射灯跟随部分-黑场按钮
    void on_testLightNetBtn_clicked();  // 射灯跟随部分-测试通信连接
    void on_manuSendBtn_clicked();  // 射灯跟随部分-手动发送

private:
    Ui::RTLS_Widget *ui;
    QTcpSocket *tcpSocket;  // 通信套接字
    QSerialPort *serial;    // 串口
    Config *rangingDistConfig;         // 配置文件
    QFile *file;
    QTextStream *outStream;
    QString button_text = "Connect";
    Location w1;
    QStringList str_data_split; // 字符串分割为字符串列表
    int str_num;            // 读入数据帧数目
    int rangeFilterp[8][4];
    long idx = 0;

    /*** 窗口菜单栏 ***/
    /* 数据结构 */
    QMenuBar *qMenuBar; // 菜单栏
    QMenu *modeMenu;    // 模式菜单
    QAction *simulationMode;
    QAction *experimentMode;
    QMenu *viewMenu;    // 视图菜单
    Environment locEnv; // 定位环境
    /* 方法 */
    void menuBarInit(); // 菜单栏初始化
    void setLocEnv(Environment env);    // 设置环境
    void resetRangingConfigParam(); // 重置文件环境参数[k b]

    /*** 定位部分 ***/
    /* 数据结构 */
    LocationMethod locMethod;
    bool locationFlag = false;

    /* 方法 */
    void locationInit();    // 定位初始化
    void anchorLocationInit();  // 基站坐标初始化


    /*** 数据处理、定位 ***/
    void dealNewData(); // 处理接收到的数据
    void locationUpdate(int tagIdx, LocationMethod method);    // 位置更新

    /*** 测距校正 ***/
    /* 数据结构 */
    unsigned char anchorFlag = 0;
    set<QTableWidgetItem*> *itemSet;    // 手动改动改动表格记录
    set<QWidget*> *rCComponent;  // 测距相关组件（需要反转）

    /* 方法 */
    void rangingModuleInit();    // 测距参数显示初始化
    void setParamToRangingConfig(int tagIdx, int row, int col, double value);  // 将参数保存到对象中
    double recordSingleRanging(int tagIdx, unsigned char anchorFlag, int &anchorIdx);
    void singleAnchorCorrection();  // 单个基站测距参数校正
    void multiAnchorCorrection();   // 多个基站测距参数校正
    void enableOrDisableRCComponentExceptCurWidget(QWidget *curWidget, bool state); // 测距按钮避免冲突

    /*** 标签定位测距验证 ***/
    /* 数据结构 */
    bool validateFlag = false;
    bool readTrueLocFlag = false;
    vec3d *trueLoc; // 真实位置
    ta_dist *trueDist;  // 真实距离

    /* 方法 */
    void validateModuleInit();  // 验证部分初始化
    void validating();  // 验证函数
    void validating(int tagIdx, bool trueLosFlag);
    void updateTrueDist();  // 更新真实距离函数

    /*** 射灯跟随部分 ***/
    /* 数据结构 */
    LightControl *lightControl;

    /* 方法 */
    void followModuleInit();    // 射灯跟随部分初始化


    /***     其他     ***/
    void dropDropDownList_clicked(QComboBox* curComboBox, int cnt); // 下拉框通用函数
};



#endif // RTLS_WIDGET_H
