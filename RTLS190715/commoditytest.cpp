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
