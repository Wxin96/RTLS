#include "rtls_widget.h"
#include "trilateration.h"
#include "kalmanfilter.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <Eigen>
#include <exception>
#include "commoditytest.h"
#include "logwidget.h"

using Eigen::MatrixXd;

//QTEST_MAIN(CommodityTest);

/**
 * @brief 日志输出回调函数
 * @param type 参数，日志消息的级别
 * @param msg 参数，日志消息
 */
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    LogWidget::getInstance()->outputMessage(type, context, msg);
}


int main(int argc, char *argv[])
{
//    int spatial_dimension = 3;
//    double delta_t = 0.2;
//    MatrixXd Q = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension) * 0.001;
//    MatrixXd R = MatrixXd::Identity(spatial_dimension, spatial_dimension) * 0.0025;     // sd = 0.05
//    MatrixXd P_init = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension);

    MatrixXd matrix(3, 3);

    //注册日志消息回调函数
    qInstallMessageHandler(outputMessage);


    memset(dit_temp,0,sizeof(dit_temp));

    QApplication a(argc, argv);
    RTLS_Widget w;
    w.show();
    LogWidget::getInstance()->show();

    // 打印信息
    qDebug("This is a debug message.");
    qWarning("This is a warning message.");
    qCritical("This is a critical message.");

    // 防止内存泄漏
    for (int i = 0; i < 8; i++){
        if (distance[i].kf) {
            delete distance[i].kf;
        }
    }


    return a.exec();

//    test();
//    return 1;
}



