#ifndef RANGECONFIG_H
#define RANGECONFIG_H

#include "config.h"
#include "commonutil.h"
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
using namespace CommonUtil;

// 定位模式
enum Environment {SIMULATION, EXPERIMENTATION};


/**
 * @brief The RangeConfig class
 * 单个标签的基站组的K，b参数配置，计算K，b
 */
class RangeConfig
{
public:
   // TODO: 配置文件类，定义处命名，标签一个配置，一个文件
    explicit RangeConfig(Environment env, int tagIdx, Config *config);
    explicit RangeConfig(Environment mode, int tagIdx, Config *config, double filterParam);
    ~RangeConfig();

    // 重新配置环境
    void setEnvMode(Environment envMode);
    Environment getEnvMode();

    // 获取对应anchor的k、b值
    void getSingleParamValue(int anchorIdx, double &k, double &b);
    double getSingleKValue(int anchorIdx);
    double getSingleBValue(int anchorIdx);
    
    // 修改对应anchor的k、b值
    void setSingleKValue(int anchorIdx, double k);
    void setSingleBValue(int anchorIdx, double b);
    void setSingleValue(int anchorIdx, double k, double b);

    // 开始配置参数
    void startRangeConfig(vector<int> anchorIdxs);
    void startRangeConfig(unsigned char anchorFlag);
    QString finishRangeConig();
    void saveRangeCorrection();
    void abandonRangeCorrection();

    // 指数滤波参数
    void setFilterParam(double filterParam);
    double getFilterParm();

    // 获取当前测量值
    double getCurMearDist(int anchorIdx);

    // 记录
    void recordSingleMeasurement(int anchorIdx, double trueAnchorDist, double mearDist);
    void recordSingleMeasurement(int anchorIdx, double trueAnchorDist);
    void recordMultiRangingMearment(unsigned char anchorFlag);
    void recordSingleRangingDist(int anchorIdx, double rangingDist);

    // 标签和基站位置
    void setAnchorGroup(vec3d *anchorGroup);    // 设置基站数组
    void setTagLoc(double x, double y, double z);   // 设置标签真实位置
    void calcTrueAnchorGroupDist(); // 计算基站组距离
    double getSingleTrueAnchorDist(int idx);    // 获取单个基站距离
    int getTagChangeFlag();     // 获取标签改变标志
    void clearTagChangeFlag();  // 清除标签改变标志


    // 显示配置状态
    QString toString();

private:
    // 当前参数id
    int tagIdx;

    // 环境模式
    Environment envMode;

    // 参数存储本地
    Config *config;

    // 节点名
    QString qstrnodename;

    // 测距参数配置
    double *k;   // K
    double *b;   // b
    bool *anchorFlag;
    double *dist;   // 四个基站测距 单位：mm

    // 测量K，b
    double filterParam = 0.3;
    bool mearFlag = false;
    int *recordIdx;     // 每个基站测距数目统计数组
    vector<double> *trueDist;   // 单位：mm
    vector<double> *measurement;    // 单位：mm

    // 设置节点名
    void setQStrNodeName();

    // 从文件中读取、写入配置
    void readParaFromFile();
//    void writeParaToFile();   // 所有参数都写入,暂不需要
    bool readSingleParaFromFile(int anchorIdx, double &k, double &b);
    void writeSingleParamToFile(int anchorIdx, double k, double b);
    void writeSingleParamToFile(int anchorIdx);

    // 单个计算 k b
    int calcSingleParam(int anchorIdx);

    // 基站组、标签位置参数
    vec3d *anchorGroupLoc = nullptr;  // 传入基站数据地址 单位：m
    vec3d *tagLoc;  // 堆中新建 单位：m
    double *trueAnchorDist; // 真实距离 单位：mm


};

#endif // RANGECONFIG_H
