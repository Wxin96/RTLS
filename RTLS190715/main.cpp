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
    //注册日志消息回调函数
    qInstallMessageHandler(outputMessage);

    memset(dit_temp,0,sizeof(dit_temp));

    QApplication a(argc, argv);
    RTLS_Widget w;
    w.show();
    LogWidget::getInstance()->show();

    // 防止内存泄漏
    for (int i = 0; i < 8; i++){
        if (distance[i].kf) {
            delete distance[i].kf;
        }
    }

    return a.exec();
}



