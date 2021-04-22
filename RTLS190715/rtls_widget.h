#ifndef RTLS_WIDGET_H
#define RTLS_WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "trilateration.h"
#include <QTableWidgetItem>
#include <QTimer>
#include "location.h"
#include "config.h"
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QMessageBox>
#include <math.h>

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
    void data_accept(QStringList dist_str);

private slots:
    void on_Button_connect_clicked();
    void newData();
    void deal_data(QStringList str_data_split);
    void slotItemChanged(QTableWidgetItem * item);
    void handleTimeout();  //超时处理函数

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void SerialPortDetect();

    void on_SerialButton_clicked();

    /*  标签测距校正  */
    // 标签下拉框
    void TagDropDownList_clicked();
    // 基站下拉框
    void AnchorDropDownList_clicked();

private:
    Ui::RTLS_Widget *ui;
    QTcpSocket *tcpSocket;  // 通信套接字
    QSerialPort *serial;    // 串口
    QTimer *timer;          // 定时器
    Config *config;         // 配置文件
    QFile *file;
    QTextStream *outStream;
    QString button_text = "Connect";
    Location w1;
    QStringList str_data_split; // 字符串分割为字符串列表
    int str_num;            // 读入数据帧数目
    int clock=0;
    int rangeFilterp[8][4];
    long idx = 0;
};



#endif // RTLS_WIDGET_H
