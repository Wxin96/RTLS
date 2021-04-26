#ifndef RANGECONFIG_H
#define RANGECONFIG_H

#include "config.h"
#include <iostream>
#include <Eigen>

// 基站数目
#ifndef ANCHOR_NUM
#define ANCHOR_NUM 4
#endif

// 拟合需要的最多数据长度
#define MAX_TEST_NUM 20

//using namespace std;
using std::vector;
using std::invalid_argument;
using std::logic_error;
using namespace Eigen;

// 定位模式
enum environment {SIMULATION, EXPERIMENTATION};


/**
 * @brief The RangeConfig class
 * 单个标签的基站组的K，b参数配置，计算K，b
 */
class RangeConfig
{
public:
   // TODO: 配置文件类，定义处命名，标签一个配置，一个文件
    explicit RangeConfig(environment mode, int tagIdx, Config *config);
    explicit RangeConfig(environment mode, int tagIdx, Config *config, double filterParam);
    ~RangeConfig();


    // 获取对应anchor的k、b值
    void getSingleParamValue(int anchorIdx, double &k, double &b);
    
    // 修改对应anchor的k、b值
    void setSingleKValue(int anchorIdx, double k);
    void setSingleBValue(int anchorIdx, double b);
    void setSingleValue(int anchorIdx, double k, double b);

    // 开始配置参数
    void startRangeConfig(vector<int> anchorIdxs);
    void finishRangeConig();

    // 指数滤波参数
    void setFilterParam(double filterParam);
    double getFilterParm();

    // 记录
    void recordSingleMeasurement(int anchorIdx, double trueDist, double mearDist);
    void recordSingleRangingDist(int anchorIdx, double rangingDist);

    // 显示配置状态
    QString toString();

private:
    // 当前参数id
    int tagIdx;

    // 参数存储本地
    Config *config;

    // 节点名
    QString qstrnodename;

    // 测距参数配置
    double *k;   // K
    double *b;   // b
    bool *anchorFlag;
    double *dist;   // 四个基站测距

    // 测量K，b
    double filterParam = 0.7;
    bool mearFlag = false;
    int *recordIdx;     // 每个基站测距数目统计数组
    vector<double> *truePos;
    vector<double> *measurement;

    // 从文件中读取、写入配置
    void readParaFromFile();
//    void writeParaToFile();   // 所有参数都写入,暂不需要
    bool readSingleParaFromFile(int anchorIdx, double &k, double &b);
    void writeSingleParamToFile(int anchorIdx, double k, double b);
    void writeSingleParamToFile(int anchorIdx);

    // 单个计算 k b
    void calcSingleParam(int anchorIdx);

};

#endif // RANGECONFIG_H
