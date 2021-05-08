#include "commoditytest.h"

CommodityTest::CommodityTest(QObject *parent) : QObject(parent)
{

}


void CommodityTest::initTestCase()
{

}

void CommodityTest::case1_rangeConfig()
{
    QString path = QCoreApplication::applicationDirPath() + "/config/rangingConfigs.ini";
    Config *config = new Config(path);
    RangeConfig rangeConfig(SIMULATION, 0, config);
//    vector<int> anchorIdxs = {0, 1};
//    rangeConfig.startRangeConfig(anchorIdxs);
//    rangeConfig.recordSingleMeasurement(0, 1, 2.5);
//    rangeConfig.recordSingleMeasurement(1, 2.5, 1);
//    rangeConfig.recordSingleMeasurement(0, 2, 4.5);
//    rangeConfig.recordSingleMeasurement(1, 4.5, 2);
//    rangeConfig.recordSingleMeasurement(0, 3, 6.5);
//    rangeConfig.recordSingleMeasurement(1, 6.5, 3);
//    rangeConfig.recordSingleMeasurement(0, 4, 8.5);
//    rangeConfig.recordSingleMeasurement(1, 8.5, 4);
//    rangeConfig.finishRangeConig();
    qDebug() << rangeConfig.toString();
    delete config;
}

void CommodityTest::case2_chanNanTest()
{
    //vec3d* anchorArray, int *distanceArray, MatrixXd Q
    int distanceArray[4] = {1012, 4513, 8772, 7638};
    vec3d anchorArray[4];
    anchorArray[0].x = 10.013;  // A0
    anchorArray[0].y = 2.651;
    anchorArray[0].z = 3.622;

    anchorArray[1].x = 8.691;  // A1
    anchorArray[1].y = 5.812;
    anchorArray[1].z = 0.452;

    anchorArray[2].x = 1.032;  // A2
    anchorArray[2].y = 6.012;
    anchorArray[2].z = 3.152;

    anchorArray[3].x = 2.432;  // A3
    anchorArray[3].y = 0.489;
    anchorArray[3].z = 0.452;

    // Q初始化
    MatrixXd Q = MatrixXd::Identity(4, 4) * 0.0025; // sd = 0.05

    vec3d res = Chan(anchorArray, distanceArray, Q);
    qDebug() << res.x;
    qDebug() << res.y;
    qDebug() << res.z;
}
