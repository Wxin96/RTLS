#include "lightcontrol.h"

LightControl::LightControl()
{
    // 0.数据分配空间
    targetIp = new unsigned char[4];    // ip
    channel = new unsigned char[CHANNEL_NUM];   // 一个域中512个通道
    lightLoc = new vec3d();
    followObjLoc = new vec3d();
    coordinateX = new vec3d();
    coordinateZ = new vec3d();
    R = new Matrix<double, SPATIAL_DIM, SPATIAL_DIM>();
    P = new Matrix<double, SPATIAL_DIM, 1>();
    timer = new QTimer();

    // 1.数据置零，初始化
    memset(targetIp, 0, sizeof(unsigned char) * 4); // 0.0.0.0为无效ip
    memset(channel, 0, sizeof(unsigned char) * CHANNEL_NUM);
    memset(this->lightLoc->flag, 0, sizeof (char) * 3); // 射灯坐标标志清零
    memset(this->coordinateX->flag, 0, sizeof (char) * 3); // 射灯坐标系X轴向量标志清零
    memset(this->coordinateZ->flag, 0, sizeof (char) * 3); // 射灯坐标系Z轴向量标志清零

    // 2.初始化灯光网络
    Init_Net();
    Set_RemoteIp(targetIp[0], targetIp[1], targetIp[2], targetIp[3]);

    // 3.定时器初始化
//    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));

}

LightControl::~LightControl()
{
    ExitClean();    // 释放资源
    delete [] targetIp;
    delete [] channel;
    delete lightLoc;
    delete followObjLoc;
    delete coordinateX;
    delete coordinateZ;
    delete R;
    delete P;
    delete timer;
}

void LightControl::setTargetIp(unsigned char *ip)
{
    if (ip == nullptr) {
        qCritical() << "ip为空指针!";
        throw std::invalid_argument("ip为空指针");
    }
    setTargetIp(ip[0], ip[1], ip[2], ip[3]);
}

void LightControl::setTargetIp(unsigned char ip1, unsigned char ip2, unsigned char ip3, unsigned char ip4)
{
    this->targetIp[0] = ip1;
    this->targetIp[1] = ip2;
    this->targetIp[2] = ip3;
    this->targetIp[3] = ip4;
    Set_RemoteIp(targetIp[0], targetIp[1], targetIp[2], targetIp[3]);
    qDebug() << displayIp();
}

void LightControl::clearTargetIp()
{
    memset(targetIp, 0, sizeof(unsigned char) * 4);
    qDebug() << "ip清空!";
    qDebug() << displayIp();
}

void LightControl::setNet(unsigned char net)
{
    if (net >= NET_NUM) {
        qCritical() << "灯光控制网络Net输入有误！ ==> " << net;
        throw std::invalid_argument(("灯光控制网络Net输入有误！ ==> " + std::to_string(net)));
    }
    this->net = net;
    qDebug() << "射灯通信设备网络号设置为：" << net;
}

unsigned char LightControl::getNet() const
{
    return net;
}

void LightControl::setSubNet(unsigned char subNet)
{
    if (subNet > SUBNET_NUM) {
        qCritical() << "灯光控制网络SubNet输入有误！ ==> " << subNet;
        throw std::invalid_argument("灯光控制网络SubNet输入有误！ ==> " + std::to_string(subNet));
    }
    this->subNet = subNet;
    qDebug() << "射灯通信设备子网络号设置为：" << subNet;
}

unsigned char LightControl::getSubNet() const
{
    return subNet;
}

void LightControl::setUniverse(unsigned char universe)
{
    if (universe > UNIVERSE_NUM) {
        qCritical() << "灯光控制网络Universe输入有误！ ==> " << universe;
        throw std::invalid_argument("灯光控制网络Universe输入有误！ ==> " + std::to_string(universe));
    }
    this->universe = universe;
    qDebug() << "射灯通信设备域设置为：" << universe;
}

unsigned char LightControl::getUniverse() const
{
    return universe;
}

void LightControl::setLightControlNet(unsigned char net, unsigned char subNet, unsigned char universe)
{
    setNet(net);
    setSubNet(subNet);
    setUniverse(universe);
}

void LightControl::setSendMode(unsigned char sendMode)
{
    if (sendMode == OUT_Update || sendMode == OUT_Temp) {
        this->sendMode = sendMode;
    } else {
        qCritical() << "发送模式SendMode输入有误！ ==> " << sendMode;
        throw std::invalid_argument("发送模式SendMode输入有误！ ==> " + std::to_string(sendMode));
    }
}

unsigned char LightControl::getSendMode() const
{
    return sendMode;
}

void LightControl::setBroadcastMode(unsigned char broadcastMode)
{
    if (broadcastMode == Broadcast_NO || broadcastMode == Broadcast_DEVICE_ALLPORT ||
            broadcastMode == Broadcast_SUBNET_ALLUNI ||broadcastMode == Broadcast_NET_ALLSUBNET ||
            broadcastMode ==Broadcast_ALLNET) {
        this->broadcastMode = broadcastMode;
    } else {
        qCritical() << "广播模式Broadcast输入有误！ ==> " << broadcastMode;
        throw std::invalid_argument("广播模式Broadcast输入有误！ ==> " + std::to_string(broadcastMode));
    }
}

unsigned char LightControl::getBroadcastMode() const
{
    return broadcastMode;
}

void LightControl::reflushNetEnv()
{
   // 刷新网络
    ExitClean();
    Init_Net();
}

QStringList LightControl::getNetCardMsg()
{
    // 1.初始化数据结构
    QStringList netCardList;
    // 2.获取网卡数目
    int netCardNum = Get_Sum_NetCardNum();
    for (unsigned char i = 0; i < netCardNum; i++) {
        char str[100];
        Get_NetCard_IpName(i, str);
        netCardList.append(QString(str));
    }
    return netCardList;
}

unsigned char LightControl::getNetCard() const
{
    return netCard;
}

void LightControl::setNetCard(unsigned char value)
{
    value = Set_Change_NetCard(value);
    this->netCard = value;
    qDebug() << "网卡序号设置为：" <<value;
}

void LightControl::setSingleChannelValue(int idx, unsigned char value)
{
    if (idx < 0 || idx >= 512) {
        qCritical() << "灯光控制网络Channel的索引idx输入有误！ ==> " << idx;
        throw std::invalid_argument("灯光控制网络Channel的索引idx输入有误！ ==> " + std::to_string(idx));
    }
    this->channel[idx] = value;
    qDebug() << "channel" << idx << " = " << value;
}

unsigned char LightControl::getSingleChannelValue(int idx) const
{
    return this->channel[idx];
}

void LightControl::setXChannel(unsigned char xHigh, unsigned char xLow)
{
    setSingleChannelValue(X_COARSE_IDX, xHigh);
    setSingleChannelValue(X_TRIM_IDX, xLow);
}

void LightControl::setYChannel(unsigned char yHigh, unsigned char yLow)
{
    setSingleChannelValue(Y_COARSE_IDX, yHigh);
    setSingleChannelValue(Y_TRIM_IDX, yLow);
}

void LightControl::setXYChannel(unsigned char xHigh, unsigned char xLow, unsigned char yHigh, unsigned char yLow)
{
    setXChannel(xHigh, xLow);
    setYChannel(yHigh, yLow);
}

void LightControl::setLightOn(bool sendFlag)
{
    // 1.点泡
    setSingleChannelValue(LIGHT_SWITCH_IDX, LIGHT_ON_VAL);
    // 2.频闪
    setSingleChannelValue(LIGHT_FREQUENCY_IDX, 255);
    // 3.调光
    setSingleChannelValue(LIGHT_DIMMING_IDX, 255);
    // 4.判断是否需要立即发送
    if (sendFlag) sendMsg();
}

void LightControl::setLightOff(bool sendFlag)
{
    // 1.关泡
    setSingleChannelValue(LIGHT_SWITCH_IDX, LIGHT_OFF_VAL);
    // 2.频闪
    setSingleChannelValue(LIGHT_FREQUENCY_IDX, 0);
    // 3.调光
    setSingleChannelValue(LIGHT_DIMMING_IDX, 0);
    // 4.判断是否需要立即发送
    if (sendFlag) sendMsg();
}

void LightControl::setBlackField(bool sendFlag)
{
    // 1.清0
    memset(channel, 0, sizeof(unsigned char) * CHANNEL_NUM);
    // 2.判断是否需要立即发送
    if (sendFlag) sendMsg();
}

void LightControl::setLightReset(bool sendFlag)
{
    // 1.复位
    setSingleChannelValue(LIGHT_SWITCH_IDX, LIGHT_RESET_VAL);
    // 2.判断是否需要立即发送
    if (sendFlag) sendMsg();
}

void LightControl::setLightLoc(double x, double y, double z)
{
    // 1.设置射灯坐标
    this->lightLoc->x = x;
    this->lightLoc->y = y;
    this->lightLoc->z = z;
    memset(this->lightLoc->flag, 1, sizeof (char) * 3);
    // 2.设置偏移量
    setOffsetMat();
}

void LightControl::setLightXAixVector(double x, double y, double z)
{
    // 1.设置坐标
    this->coordinateX->x = x;
    this->coordinateX->y = y;
    this->coordinateX->z = z;
    memset(this->coordinateX->flag, 1, sizeof (char) * 3);
    // 2.是否可以求旋转坐标
    if (checkXZVector()) setRotateMat();
}

void LightControl::setLightZAixVector(double x, double y, double z)
{
    // 1.设置坐标
    this->coordinateZ->x = x;
    this->coordinateZ->y = y;
    this->coordinateZ->z = z;
    // 2.是否可以求旋转坐标
    if (checkXZVector()) setRotateMat();
}

bool LightControl::checkConnection()
{
    int time = 0;
    unsigned char res = 0;
    while (time < 6) {
        // 1.广播消息
        Send_FQ512Net_Poll();
        time++;
        // 2.等待
        QThread::msleep(3);
        // 3.结果
        res = IsHaveFQ512NetDevice();
    }
    qDebug() <<"connect结果为： " << res;
    return  res == 1;
}

QString LightControl::displayMsg()
{
    QString msg;
    msg += displayIp() + "\r\n";
    msg += displayNetCard() + "\r\n";
    msg += diplayNet() + "\r\n";
    msg += displaySubNet() + "\r\n";
    msg += displayUniverse() + "\r\n";
    msg += displaySendMode() + "\r\n";
    msg += displayBroadcastMode() + "\r\n";
    msg += displayChannel(0, LIGHT_CHANNEL_NUM -1) + "\r\n";
    return msg;
}

QString LightControl::displayIp()
{
    QString ipMsg = "灯光通信设备ip为";
    for (int i = 0; i < 4; i++) {
        ipMsg += QString::number(targetIp[i]);
        if (i != 3) ipMsg += ".";
        else ipMsg += "!";
    }
    return ipMsg;
}

QString LightControl::displayNetCard()
{
    this->netCard = Get_CurSel_NetCardIndex();
    if (this->netCard == 255) {
        return "未选择网卡";
    }
    QString netCardMSg = "当前网卡序号为：" + QString::number(this->netCard) + ", 网卡信息为：";
    char str[100];
    Get_NetCard_IpName(this->netCard, str);
    netCardMSg.append(str);
    return  netCardMSg;
}

QString LightControl::diplayNet()
{
    return "当前射灯网络号（Net）为：" + QString::number(this->net);
}

QString LightControl::displaySubNet()
{
    return "当前射灯子网络号（SubNet）为：" + QString::number(this->subNet);
}

QString LightControl::displayUniverse()
{
    return "当前射灯域号（Universe）为：" + QString::number(this->universe);
}

QString LightControl::displaySendMode()
{
    switch (this->sendMode) {
    case OUT_Update:
        return "当前灯控网络发送模式为：立即发送模式";
    case OUT_Temp:
        return "当前灯控网络发送模式为：缓存发送模式";
    default:
        return "当前灯控网络发送模式设置出现问题";
    }
}

QString LightControl::displayBroadcastMode()
{
    switch (this->broadcastMode){
    case Broadcast_NO:  // 单域，512个端口
        return "当前灯控网络广播模式为：无广播，只控制单个DMX域";
    case Broadcast_DEVICE_ALLPORT:  // 单个设备绑定的域，有绑定4个域的
        return "当前灯控网络广播模式为：对设备的所有DMX域端口广播";
    case Broadcast_SUBNET_ALLUNI:   // 单个subnet，16个域
        return "当前灯控网络广播模式为：对FQ512Net的SubNet子网内广播";
    case Broadcast_NET_ALLSUBNET:   // 单个net，16个subnet
        return  "当前灯控网络广播模式为：对FQ512Net的Net大网广播";
    case Broadcast_ALLNET:  // 128个Net网络
        return "当前灯控网络广播模式为：对FQ512Net全部设备广播";
    default:
        return "当前灯控网络广播模式设置出现问题";
    }
}

QString LightControl::displayChannel(int startIdx, int endIdx)
{
    if (startIdx >=0 && startIdx < CHANNEL_NUM && endIdx >= 0 && endIdx < CHANNEL_NUM && startIdx <= endIdx) {
        QString channelMsg;
        for (int i =startIdx; i <= endIdx; i++) {
            channelMsg += "channel" + QString::number(i) + " = " + QString::number(this->channel[i]) + ", ";
            if (i == endIdx) channelMsg.remove(channelMsg.length() - 2, 2);
        }
        return channelMsg;
    } else {
        qWarning() << "灯光DMX通道范围有问题！  " << startIdx << "-" << endIdx;
        return "灯光DMX通道范围有问题！  " + QString::number(startIdx) + "-" + QString::number(endIdx);
    }
}

void LightControl::setRotateMat()
{
    // 0.预判断
    if (!checkXZVector()) {
        qCritical() << "不满足条件，目前无法求旋转矩阵";
        throw std::logic_error("不满足条件，目前无法求旋转矩阵");
    }
    // 1.求y轴向量 (Y = Z × X)
    Matrix<double, SPATIAL_DIM, 1> xVector; // X
    Matrix<double, SPATIAL_DIM, 1> zVector; // Y
    // a.求x
    xVector(0, 0) = this->coordinateX->x;
    xVector(1, 0) = this->coordinateX->y;
    xVector(2, 0) = this->coordinateX->z;
    xVector.normalize();
    zVector(0, 0) = this->coordinateZ->x;
    zVector(1, 0) = this->coordinateZ->y;
    zVector(2, 0) = this->coordinateZ->z;
    zVector.normalize();
    Matrix<double, SPATIAL_DIM, 1> yVector = zVector.cross(xVector);    // Z
    // 2.计算旋转矩阵
    for (int i = 0; i < SPATIAL_DIM; i++) {
        (*R)(i, 0) = xVector(i, 0);
        (*R)(i, 1) = yVector(i, 0);
        (*R)(i, 2) = zVector(i, 0);
    }
    std::stringstream ss;
    ss << (*R);
    qDebug() << "旋转矩阵设置成功，R = " << QString::fromStdString(ss.str());
}

void LightControl::setOffsetMat()
{
    (*P)(0, 0) = this->lightLoc->x;
    (*P)(1, 0) = this->lightLoc->x;
    (*P)(2, 0) = this->lightLoc->x;
    qDebug() << "偏移矩阵设置成功，P = " << (P);
}

void LightControl::sendMsg()
{
    Send_FQ512Net_DmxPacket(this->net, this->subNet, this->universe, this->sendMode, this->broadcastMode, this->channel);
    qDebug() << "send~~~";
}

void LightControl::sendMsgPeriodic(int period)
{
    timer->start(period);
}

void LightControl::stopSendMsgPeriodic()
{
    timer->stop();
}

bool LightControl::checkXZVector()
{
    int flag = coordinateX->flag[0] + coordinateX->flag[1] + coordinateX->flag[2];
    if (flag != 3) {
        qWarning() << "X轴向量标志不对！ ==> flag = " << flag;
        return false;
    }
    flag = coordinateZ->flag[0] + coordinateZ->flag[1] + coordinateZ->flag[2];
    if (flag != 3) {
        qWarning() << "Z轴向量标志不对！ ==> flag = " << flag;
        return false;
    }
    return true;
}

void LightControl::handleTimeout()
{
    sendMsg();
    qDebug() << "send!";
}



