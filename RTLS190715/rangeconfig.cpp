#include "rangeconfig.h"

RangeConfig::RangeConfig(Environment env, int tagIdx, Config *config)
{
    // 初始化
    this->config = config;
    this->tagIdx = tagIdx;
    if (env == SIMULATION || env == EXPERIMENTATION) {
        this->envMode = env;
    } else {
        qWarning() << "输入env有误！此处使用默认值SIMULATION";
        this->envMode = SIMULATION;
    }
    setQStrNodeName();
    // 参数初始化
    k = new double[ANCHOR_NUM];
    b = new double[ANCHOR_NUM];
    recordIdx = new int[ANCHOR_NUM];
    anchorFlag = new bool[ANCHOR_NUM];
    memset(recordIdx,0,sizeof(int) * ANCHOR_NUM);
    memset(anchorFlag,0,sizeof(bool) * ANCHOR_NUM);
    readParaFromFile(); // 初始化从配置文件中读取配置
    // 中间量存储
    trueDist = new vector<double>[ANCHOR_NUM];
    measurement = new vector<double>[ANCHOR_NUM];
    // 测距数值
    dist = new double[ANCHOR_NUM];
    memset(dist, 0 , sizeof (double) * ANCHOR_NUM);
    // 基站和标签坐标
    tagLoc = new vec3d;
    memset(tagLoc->flag, 0, sizeof (char) * 3);
    trueAnchorDist = new double[ANCHOR_NUM];
    memset(trueAnchorDist, 0, sizeof (double) * ANCHOR_NUM);
}

RangeConfig::RangeConfig(Environment env, int tagIdx, Config *config, double filterParam)
{
    RangeConfig(env, tagIdx, config);
    this->filterParam = filterParam;
}

RangeConfig::~RangeConfig()
{
    delete [] k;
    delete [] b;
    delete [] trueDist;
    delete [] measurement;
    delete [] recordIdx;
    delete [] anchorFlag;
    delete [] dist;
    delete tagLoc;
    delete [] trueAnchorDist;
}

void RangeConfig::setEnvMode(Environment envMode)
{
    if (envMode != this->envMode) {
        // 1.改变标志
        this->envMode = envMode;
        // 2.改变节点名
        setQStrNodeName();
        // 3.重新读取k b
        readParaFromFile();
    }
}

Environment RangeConfig::getEnvMode()
{
    return this->envMode;
}

void RangeConfig::getSingleParamValue(int anchorIdx, double &k, double &b)
{
    k = this->k[anchorIdx];
    b = this->b[anchorIdx];
}

double RangeConfig::getSingleKValue(int anchorIdx)
{
    return k[anchorIdx];
}

double RangeConfig::getSingleBValue(int anchorIdx)
{
    return b[anchorIdx];
}

void RangeConfig::setSingleKValue(int anchorIdx, double k)
{
    this->k[anchorIdx] = k;
    writeSingleParamToFile(anchorIdx);
    qDebug() << "标签"<< tagIdx <<"对基站"<< anchorIdx <<"的k参数修改为" << k;
}

void RangeConfig::setSingleBValue(int anchorIdx, double b)
{
    this->b[anchorIdx] = b;
    writeSingleParamToFile(anchorIdx);
    qDebug() << "标签"<< tagIdx <<"对基站"<< anchorIdx <<"的b参数修改为" << b;
}

void RangeConfig::setSingleValue(int anchorIdx, double k, double b)
{
    this->k[anchorIdx] = k;
    this->b[anchorIdx] = b;
    writeSingleParamToFile(anchorIdx);
    qDebug() << "标签"<< tagIdx <<"对基站"<< anchorIdx <<"的k参数修改为" << k;
    qDebug() << "标签"<< tagIdx <<"对基站"<< anchorIdx <<"的k参数修改为" << k;
}

void RangeConfig::startRangeConfig(vector<int> anchorIdxs)
{
    // 0.初始判断
    if (anchorIdxs.size() <= 0) {
        qCritical("输入参数有误");
        throw invalid_argument("输入参数有误");
    }
    if (mearFlag) {
        qCritical("已在测距中");
        throw logic_error("已在测距中");
    }
    mearFlag = true;
    QString anchorsStr;
    // 1.遍历
    for(vector<int>::iterator iter = anchorIdxs.begin(); iter != anchorIdxs.end(); iter++) {
        anchorFlag[*iter] = true;
        anchorsStr += QString::number(*iter) + ", ";
    }
    qDebug() <<"标签"<<QString::number(tagIdx)<<"开始对基站"<< anchorsStr <<"测距矫正~";
}

void RangeConfig::startRangeConfig(unsigned char anchorFlag)
{
    // 0.初步判断
    if (anchorFlag == 0) {
        qCritical("输入参数有误");
        throw invalid_argument("输入参数有误");
    }
    if (mearFlag) {
        qCritical("已在测距中");
        throw logic_error("已在测距中");
    }
    mearFlag = true;
    QString anchorsStr;
    // 1.遍历
    int idx = 0;
    while (anchorFlag != 0) {
        if (anchorFlag & 1) {
            this->anchorFlag[idx] = true;
            anchorsStr += QString::number(idx) + ", ";
        }
        anchorFlag >>= 1;
        idx++;
    }
    qDebug() <<"标签"<<QString::number(tagIdx)<<"开始对基站"<< anchorsStr <<"测距矫正~";
}

QString RangeConfig::finishRangeConig()
{
    // 0.初始判断
    if (!mearFlag) {
        qCritical("不在测距中");
        throw logic_error("不在测距中");
    }
    mearFlag = false;
    QString anchorsStr;
    QString corrStr;
    int num = 0;
    int dataCnt = 0;
    // 1.更新K b
    // 2.更新配置参数
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (anchorFlag[i]) {
            dataCnt += calcSingleParam(i);     // 更改对象中k b
            corrStr += "基站" + QString::number(i) + "中k = " + QString::number(k[i]) + ", b = " + QString::number(b[i]) + "\r\n";
            anchorsStr.append( QString::number(i) + ", " );
            if (num == 0) num = recordIdx[i];
            recordIdx[i] = 0;  // 清零
        }
    }
    // 3.判断
    if (dataCnt) {
        qDebug() <<"标签"<< tagIdx <<"对基站"<< anchorsStr <<"测距矫正计算过程完成("<<num<<"对数据)," << corrStr;
        return corrStr;
    } else {
        qCritical() <<"标签"<< tagIdx <<"对基站"<< anchorsStr <<"测距矫正由于无数据，所以无法完成！("<<num<<"对数据)," << corrStr;
        throw logic_error("无数据，无法进行校正");
    }
}

void RangeConfig::saveRangeCorrection()
{
    QString anchorsStr;
    // 1.更新配置参数到配置文件
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (anchorFlag[i]) {
            writeSingleParamToFile(i);  // 更改配置中k b
            anchorFlag[i] = false;
            anchorsStr += QString::number(i) + ", ";
        }
    }
    qDebug() <<"标签"<< tagIdx <<"对基站"<< anchorsStr <<"测距矫正全部完成!";
}

void RangeConfig::abandonRangeCorrection()
{
    QString anchorsStr;
    // 1.恢复数据
    readParaFromFile();
    // 2.重置基站测距校正标志
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (anchorFlag[i]) {
            anchorFlag[i] = false;
            anchorsStr += QString::number(i) + ", ";
        }
    }
    qWarning() <<"标签"<< tagIdx <<"放弃对基站"<< anchorsStr <<"测距校正！";
}

void RangeConfig::setFilterParam(double filterParam)
{
    this->filterParam = filterParam;
}

double RangeConfig::getFilterParm()
{
    return this->filterParam;
}

double RangeConfig::getCurMearDist(int anchorIdx)
{
    return dist[anchorIdx];
}

/**
 * @brief RangeConfig::recordSingleMeasurement 此处只记录单对数据, 调用函数负责取平均值
 * @param anchorIdx
 * @param trueDist
 * @param mearDist
 */
void RangeConfig::recordSingleMeasurement(int anchorIdx, double trueDist, double mearDist)
{
    // 记录数据
    this->trueDist[anchorIdx].push_back(trueDist);
    measurement[anchorIdx].push_back(mearDist);
    recordIdx[anchorIdx]++;
    qDebug() << "标签" << tagIdx << "记录标签"<<anchorIdx<<"第" << recordIdx[anchorIdx] <<"数据," <<"其中trueDist="<< trueDist <<",mearDist=" << mearDist;
}

void RangeConfig::recordSingleMeasurement(int anchorIdx, double trueDist)
{
    recordSingleMeasurement(anchorIdx, trueDist, dist[anchorIdx]);
}

void RangeConfig::recordMultiRangingMearment(unsigned char anchorFlag)
{
    // 记录
    QString msg = "完成标签" + QString::number(tagIdx) + "对基站";
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if ( (1 << i) & anchorFlag ) {
            recordSingleMeasurement(i, trueAnchorDist[i], dist[i]);
            msg.append(QString::number(i) + ", ");
        }
    }
    msg.append("的多基站测距校正记录~");
    qDebug() << msg;
}

void RangeConfig::recordSingleRangingDist(int anchorIdx, double rangingDist)
{
    if (dist[anchorIdx] < 1) {
        dist[anchorIdx] = rangingDist;
    } else {
        dist[anchorIdx] = dist[anchorIdx] * (1 - filterParam) + rangingDist * filterParam;
    }
}

void RangeConfig::setAnchorGroup(vec3d *anchorGroup)
{
    this->anchorGroupLoc = anchorGroup;
}

void RangeConfig::setTagLoc(double x, double y, double z)
{
    if (std::abs(tagLoc->x - x) > std::numeric_limits<double>::epsilon() || getTagChangeFlag() > 0) { // x
        tagLoc->flag[0] = 1;
        tagLoc->x = x;
    } else {
        tagLoc->flag[0] = 0;
    }
    if (std::abs(tagLoc->y - y) > std::numeric_limits<double>::epsilon() || getTagChangeFlag() > 0) { // y
        tagLoc->flag[1] = 1;
        tagLoc->y = y;
    } else {
        tagLoc->flag[1] = 0;
    }
    if (std::abs(tagLoc->z - z) > std::numeric_limits<double>::epsilon() || getTagChangeFlag() > 0) { // z
        tagLoc->flag[2] = 1;
        tagLoc->z = z;
    } else {
        tagLoc->flag[2] = 0;
    }
}

void RangeConfig::calcTrueAnchorGroupDist()
{
    // 0.预判断
    if (anchorGroupLoc == nullptr) {
        qCritical() << "基站坐标为空，无法进行距离计算";
        throw logic_error("基站坐标为空，无法进行距离计算");
    }
    // 1.更新
    QString msg = "标签" + QString::number(tagIdx) + "测距为";
    for (int i = 0; i < ANCHOR_NUM; i++) {
        trueAnchorDist[i] = calcEuclidDist(tagLoc, &anchorGroupLoc[i]) * 1000;
        msg.append(QString::number(trueAnchorDist[i]) + ", ");
    }
    qDebug() << msg;
}

double RangeConfig::getSingleTrueAnchorDist(int idx)
{
    return trueAnchorDist[idx];
}

int RangeConfig::getTagChangeFlag()
{
    return tagLoc->flag[0] + tagLoc->flag[1] +tagLoc->flag[2];
}

void RangeConfig::clearTagChangeFlag()
{
    memset(tagLoc->flag, 0, sizeof (char) * 3);
}

QString RangeConfig::toString()
{
    QString kStr = "k: ", bStr = "b: ", res;
    for (int i = 0; i < ANCHOR_NUM; i++) {
        kStr += QString::number(k[i]) + ", ";
        bStr += QString::number(b[i]) + ", ";
    }
    res += kStr.remove(kStr.size() - 2, 2) + "   ";
    res += bStr.remove(bStr.size() - 2, 2);
    return res;
}

void RangeConfig::setQStrNodeName()
{
    if (this->envMode == SIMULATION) this->qstrnodename = "Simulation-Tag";
    else if (this->envMode == EXPERIMENTATION) this->qstrnodename = "Experimentation-Tag";
    this->qstrnodename += QString::number(tagIdx);
}

void RangeConfig::readParaFromFile()
{
    QString env;
    if (envMode == SIMULATION) env = "仿真模式下，";
    else if (envMode == EXPERIMENTATION) env = "实验模式下，";
    else env = "其他模式下，";
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (readSingleParaFromFile(i, k[i], b[i])) {
            qDebug()<< env <<"标签"<<tagIdx<<"读取基站"<<i<<"配置成功(k="<< k[i] << ",b=" << b[i] << ")!";
        } else if (i == 0) {
            k[i] = 1;
            b[i] = 0;
            qWarning()<< env <<"标签"<<tagIdx<<"中基站0，使用k=1, b=0配置";
        } else if (i) {
            k[i] = k[i-1];
            b[i] = b[i-1];
            qWarning()<< env <<"标签"<<tagIdx<<"中基站"<<i<<"使用上一基站配置";
        }
    }
}

bool RangeConfig::readSingleParaFromFile(int anchorIdx, double &kValue, double &bValue)
{
    QString k_Key = "k" + QString::number(anchorIdx), b_Key = "b" + QString::number(anchorIdx);
    if (config->contains(qstrnodename, k_Key) && config->contains(qstrnodename, b_Key)) {
        kValue = config->Get(qstrnodename, "k" + QString::number(anchorIdx)).toDouble();
        bValue = config->Get(qstrnodename, "b" + QString::number(anchorIdx)).toDouble();
        return true;
    } else {
        qWarning()<<"标签"<<tagIdx<<"中基站"<<anchorIdx<<"配置不存在!";
        return false;
    }
}

void RangeConfig::writeSingleParamToFile(int anchorIdx, double k, double b)
{
    this->config->Set(this->qstrnodename, "k" + QString::number(anchorIdx), k);
    this->config->Set(this->qstrnodename, "b" + QString::number(anchorIdx), b);
}

void RangeConfig::writeSingleParamToFile(int anchorIdx)
{
    this->writeSingleParamToFile(anchorIdx, this->k[anchorIdx], this->b[anchorIdx]);
}

int RangeConfig::calcSingleParam(int anchorIdx)
{
    // 1.长度
    int len = static_cast<int>(trueDist[anchorIdx].size());
    // 2.初始化矩阵
    VectorXd Y(len);
    MatrixXd A(len, 2);
    for (int i = 0; i < len; i++) {
        Y(i) = trueDist[anchorIdx][i];
        A(i, 0) = 1;
        A(i, 1) = measurement[anchorIdx][i];
    }
    // 3.计算参数
    MatrixXd res = (A.transpose()*A).inverse()*A.transpose()*Y;
    b[anchorIdx] = res(0, 0);
    k[anchorIdx] = res(1, 0);
    qDebug() << "标签" << tagIdx << "更新基站" << anchorIdx <<"参数,k="<<k[anchorIdx]<<",b="<<b[anchorIdx];
    // 4.释放空间
    trueDist[anchorIdx].clear();
    measurement[anchorIdx].clear();
    return len;
}



