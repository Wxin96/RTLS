#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include "commonutil.h"
#include "FQ512NetShow.h"
#include "iostream"
#include <QObject>
#include <QThread>
#include <QTimer>
#include <Eigen>

// 基本配置
#define SPATIAL_DIM 3
#define CHANNEL_NUM 512
#define TAG_NUM 8
#define NET_NUM 128
#define SUBNET_NUM 16
#define UNIVERSE_NUM 16
#define LIGHT_CHANNEL_NUM 16

// 单个灯通道
#define X_COARSE_IDX 0       // X
#define X_TRIM_IDX 2
#define X_RANGE 540

#define Y_COARSE_IDX 1      // Y
#define Y_TRIM_IDX 3
#define Y_RANGE 270

#define LIGHT_SWITCH_IDX 15 // 灯开关
#define LIGHT_ON_VAL 202 // 点泡
#define LIGHT_OFF_VAL 102 // 关泡
#define LIGHT_RESET_VAL 252 // 复位

#define LIGHT_FREQUENCY_IDX 6   // 频闪 0闭光 1-50 241-255 开光 51-240 频闪

#define LIGHT_DIMMING_IDX 7 // 调光 0-255调光

using namespace Eigen;

/**
 * @brief The LightControl class（控制通讯网络与灯看成一体）
 * 控制单个灯，共16个通道
 */
class LightControl
{
public:
    explicit LightControl();
    ~LightControl();

    /*  通讯网络  */
    void setTargetIp(unsigned char *ip); // 设置灯控目标的ip
    void setTargetIp(unsigned char ip1,unsigned char ip2,unsigned char ip3,unsigned char ip4);
    void clearTargetIp();

    /*  灯控网络  */
    void setNet(unsigned char net); // Net
    unsigned char getNet() const;
    void setSubNet(unsigned char subNet);   // SubNet
    unsigned char getSubNet() const;
    void setUniverse(unsigned char universe); // Universe
    unsigned char getUniverse() const;
    void setLightControlNet(unsigned char netStr, unsigned char subNetStr, unsigned char universe);
    void setSendMode(unsigned char sendMode);   // SendMode
    unsigned char getSendMode() const;
    void setBroadcastMode(unsigned char broadcastMode); // BroadcastMode
    unsigned char getBroadcastMode() const;
    void reflushNetEnv();   // 刷新网络
    QStringList getNetCardMsg();    // 获取当前网卡信息
    unsigned char getNetCard() const;   // 获取当前网卡序号
    void setNetCard(unsigned char value);   // 设置当前网卡号


    /*  一个域中512通道  */
    void setSingleChannelValue(int idx, unsigned char value);   // 单个通道值设置
    unsigned char getSingleChannelValue(int idx) const;
    void setXChannel(unsigned char xHigh, unsigned char xLow);  // X通道
    void setYChannel(unsigned char yHigh, unsigned char yLow);  // Y通道
    void setXYChannel(unsigned char xHigh, unsigned char xLow, unsigned char yHigh, unsigned char yLow);
    void setLightOn(bool sendFlag); // 开灯
    void setLightOff(bool sendFlag);    // 关灯
    void setBlackField(bool sendFlag);  // 黑场
    void setLightReset(bool sendFlag);  // 重置

    /*  灯控坐标系  */
    void setLightLoc(double x, double y, double z); // 设置灯坐标
    void setLightXAixVector(double x, double y, double z);  // 设置灯坐标系x轴向量
    void setLightZAixVector(double x, double y, double z);  // 设置灯坐标系z轴向量

    /*  检查  */
    bool checkConnection(); // 检查是否已连接完毕，true已连接
    int checkReadiness();   // 检查是否已准备完毕， 1-成功，2-连接不成，3坐标系配置不成

    /*  跟随标签  */
    int followObject(vec3d *objLoc);    // 1-成功，2-配置文件有问题
    int followObject(double x, double y, double z);

    /* 信息显示 */
    QString displayMsg();
    QString displayIp();
    QString displayNetCard();
    QString diplayNet();
    QString displaySubNet();
    QString displayUniverse();
    QString displaySendMode();
    QString displayBroadcastMode();
    QString displayChannel(int startIdx, int endIdx);
    QString displayR();
    QString displayP();

    /*  发送消息  */
    void sendMsg();
    void sendMsgPeriodic(int period);
    void stopSendMsgPeriodic();


private:
    unsigned char *targetIp;  // 目标ip
    unsigned char netCard = 255;  // 网卡序号
    unsigned char net = 0;  // 网 范围：0~127
    unsigned char subNet = 0;   // 子网 范围：0~15
    unsigned char universe = 0; // 域 范围：0~15
    unsigned char sendMode = OUT_Update;
    unsigned char broadcastMode = Broadcast_ALLNET;
    unsigned char *channel;
    vec3d *lightLoc;
    vec3d *followObjLoc;
    vec3d *coordinateX; // X轴向量 Y = Z × X
    vec3d *coordinateZ; // Z轴向量
    Matrix<double, SPATIAL_DIM, SPATIAL_DIM> *R;  // 旋转矩阵
    Matrix<double, SPATIAL_DIM, 1> *P;    // 偏移矩阵
    QTimer *timer;  // 定时器线程

    /*  灯控坐标系  */
    void setRotateMat();    // 设置旋转矩阵
    void setOffsetMat();    // 设置偏移矩阵
    void calcLightCoordinateLoc(double x, double y, double z);  // 计算跟随物体在Light坐标系中坐标

    /*  状态判断  */
    bool checkXZVector();

private slots:
    void handleTimeout();

};

#endif // LIGHTCONTROL_H
