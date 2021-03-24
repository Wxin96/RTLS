#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <Eigen>

using Eigen::MatrixXd;

// 坐标结构体
struct vec3d{
    double	x;
    double	y;
    double	z;
    char flag[3];
};

class KalmanFilter
{
public:
    KalmanFilter(int spatial_dimension, double delta_t, MatrixXd Q, MatrixXd R, MatrixXd P_init);
    void iteration(vec3d *location);
private:
    // 矩阵 Q R P
    int dimension = 3;
    MatrixXd Q, R;  // 过程噪声-协方差矩阵，观测噪声协方差矩阵
    MatrixXd P;     // 后验、预测估计误差协方差矩阵（前后迭代，使用一个）
    MatrixXd x, z_pred;  // 状态量, 预测=》观测量
    MatrixXd F, H;  // 状态转移矩阵，观测矩阵
    MatrixXd y;     // 测量残差
    MatrixXd S;     // 测量残差协方差
    MatrixXd K;     // 最优卡尔曼增益

    void predict();
    void update(vec3d *location);
};

#endif // KALMANFILTER_H
