#include "rangeconfig.h"

RangeConfig::RangeConfig(environment mode, int tagIdx, Config *config)
{
    // 初始化
    this->config = config;
    this->tagIdx = tagIdx;
    if (mode == SIMULATION) this->qstrnodename = "Simulation-";
    else if (mode == EXPERIMENTATION) this->qstrnodename = "Experimentation-";
    this->qstrnodename += "Tag" + QString::number(tagIdx);
    // 参数初始化
    k = new double[ANCHOR_NUM];
    b = new double[ANCHOR_NUM];
    recordIdx = new int[ANCHOR_NUM];
    anchorFlag = new bool[ANCHOR_NUM];
    memset(recordIdx,0,sizeof(int) * ANCHOR_NUM);
    memset(anchorFlag,0,sizeof(bool) * ANCHOR_NUM);
    readParaFromFile(); // 初始化从配置文件中读取配置
    // 中间量存储
    truePos = new vector<double>[ANCHOR_NUM];
    measurement = new vector<double>[ANCHOR_NUM];
}

RangeConfig::~RangeConfig()
{
    delete [] k;
    delete [] b;
    delete [] truePos;
    delete [] measurement;
    delete [] recordIdx;
    delete [] anchorFlag;
}

void RangeConfig::getSingleParamValue(int anchorIdx, double &k, double &b)
{
    k = this->k[anchorIdx];
    b = this->b[anchorIdx];
}

void RangeConfig::setSingleKValue(int anchorIdx, double k)
{
    this->k[anchorIdx] = k;
    writeSingleParamToFile(anchorIdx);
}

void RangeConfig::setSingleBValue(int anchorIdx, double b)
{
    this->b[anchorIdx] = b;
    writeSingleParamToFile(anchorIdx);
}

void RangeConfig::setSingleValue(int anchorIdx, double k, double b)
{
    this->k[anchorIdx] = k;
    this->b[anchorIdx] = b;
    writeSingleParamToFile(anchorIdx);
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

void RangeConfig::finishRangeConig()
{
    // 0.初始判断
    if (!mearFlag) {
        qCritical("不在测距中");
        throw logic_error("不在测距中");
    }
    qDebug("");
    mearFlag = false;
    QString anchorsStr;
    int num = 0;
    // 1.更新K b
    // 2.更新配置参数
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (anchorFlag[i]) {
            calcSingleParam(i);     // 更改对象中k b
            writeSingleParamToFile(i);  // 更改配置中k b
            anchorFlag[i] = false;
            anchorsStr += QString::number(i) + ", ";
            if (num == 0) num = recordIdx[i];
            recordIdx[i] = 0;  // 清零
        }
    }
    qDebug() <<"标签"<< tagIdx <<"对基站"<< anchorsStr <<"测距矫正完成("<<num<<"对数据)!";
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
    truePos[anchorIdx].push_back(trueDist);
    measurement[anchorIdx].push_back(mearDist);
    recordIdx[anchorIdx]++;
    qDebug() << "标签" << tagIdx << "记录标签"<<anchorIdx<<"第" << recordIdx[anchorIdx] <<"数据," <<"其中trueDist="<< trueDist <<",mearDist=" << mearDist;
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

void RangeConfig::readParaFromFile()
{
    for (int i = 0; i < ANCHOR_NUM; i++) {
        if (readSingleParaFromFile(i, k[i], b[i])) {
            qDebug()<<"标签"<<tagIdx<<"读取基站"<<i<<"配置成功!";
        } else if (i) {
            k[i] = k[i-1];
            b[i] = b[i-1];
            qWarning()<<"标签"<<tagIdx<<"中基站"<<i<<"使用上一基站配置";
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

void RangeConfig::calcSingleParam(int anchorIdx)
{
    // 1.长度
    int len = static_cast<int>(truePos[anchorIdx].size());
    // 2.初始化矩阵
    VectorXd Y(len);
    MatrixXd A(len, 2);
    for (int i = 0; i < len; i++) {
        Y(i) = truePos[anchorIdx][i];
        A(i, 0) = 1;
        A(i, 1) = measurement[anchorIdx][i];
    }
    // 3.计算参数
    MatrixXd res = (A.transpose()*A).inverse()*A.transpose()*Y;
    b[anchorIdx] = res(0, 0);
    k[anchorIdx] = res(1, 0);
    qDebug() << "标签" << tagIdx << "更新基站" << anchorIdx <<"参数,k="<<k[anchorIdx]<<",b="<<b[anchorIdx];
    // 4.释放空间
    truePos[anchorIdx].clear();
    measurement[anchorIdx].clear();
}



