#include "kalmanfilter.h"
#include <exception>
#include <iostream>

using namespace std;

KalmanFilter::KalmanFilter(int spatial_dimension, double delta_t, MatrixXd Q, MatrixXd R, MatrixXd P_init)
{
    // 0.验证
    if (Q.rows() != 2 * spatial_dimension || Q.cols() != 2 * spatial_dimension) throw invalid_argument("过程噪声协方差Q输入有误！");
    if (R.rows() != spatial_dimension || R.cols() != spatial_dimension) throw invalid_argument("观测噪声协方差R输入有误！");
    if (P_init.rows() != 2 * spatial_dimension || P_init.cols() != 2 * spatial_dimension) throw invalid_argument("估计协方差P输入有误！");

    // 1.初始化 Q R P 协方差矩阵、初始化维数
    this->dimension = spatial_dimension;
    this->Q = Q;
    this->R = R;
    this->P = P_init;

    // 2.状态转移矩阵初始化
    this->F = MatrixXd::Identity(2*spatial_dimension, 2*spatial_dimension);
    for (int i = 0; i < spatial_dimension; i++) this->F(i, i+spatial_dimension) = delta_t;


    // 3.观测矩阵初始化
    this->H = MatrixXd::Identity(spatial_dimension, 2*spatial_dimension);

    // 4.状态量初始化
    this->x = MatrixXd(2 * spatial_dimension, 1);

}


void KalmanFilter::predict()
{
    cout << "x size:" << x.size() << endl;
    cout << "F size:" << F.size() << endl;
    this->x = this->F * this->x;    // 求x_k,k-1 预测状态
    this->P = this->F * this->P * this->F.transpose() + this->Q;    // 求预测估计误差协方差矩阵 P_k,k-1
    this->z_pred = this->H * this->x;    // 对x_k,k-1的观测
}

void KalmanFilter::update(vec3d *location)
{
    MatrixXd z_true(3, 1);  // z的实际观测值, 以及初始化
    z_true(0, 0) = location->x;
    z_true(1, 0) = location->y;
    z_true(2, 0) = location->z;
    this->y = z_true - this->z_pred;    // 测量残差 y_k
    this->S = this->H * this->P * this->H.transpose() + this->R;    // 测量残差协方差 S_k
    this->K = this->P * this->H.transpose() * this->S.inverse();    // 求最优卡尔曼增益
    x = x + K * y;  // 求当前时刻x
    cout << "x size:" << x.size() << endl;

    P = (MatrixXd::Identity(2 * dimension, 2 * dimension) - K * H) * P;
}

void KalmanFilter::iteration(vec3d *location)
{
    cout << "Kalman滤波~" <<endl;
    predict();
    update(location);
    // 更新位置
    location->x = x(0, 0);
    location->y = x(1, 0);
    location->z = x(2, 0);

}


