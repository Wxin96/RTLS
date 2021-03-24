#include "rtls_widget.h"
#include "trilateration.h"
#include "kalmanfilter.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <Eigen>
#include <exception>

using Eigen::MatrixXd;

int main(int argc, char *argv[])
{
//    int spatial_dimension = 3;
//    double delta_t = 0.2;
//    MatrixXd Q = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension) * 0.001;
//    MatrixXd R = MatrixXd::Identity(spatial_dimension, spatial_dimension) * 0.0025;     // sd = 0.05
//    MatrixXd P_init = MatrixXd::Identity(2 * spatial_dimension, 2 * spatial_dimension);
//    KalmanFilter kf_init(spatial_dimension, delta_t, Q, R, P_init);




    memset(dit_temp,0,sizeof(dit_temp));

    QApplication a(argc, argv);
    RTLS_Widget w;
    w.show();

    // 防止内存泄漏
    for (int i = 0; i < 8; i++){
        if (distance[i].kf) {
            delete distance[i].kf;
        }
    }


    return a.exec();
//    return 1;
}
