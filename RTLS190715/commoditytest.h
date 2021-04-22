#ifndef COMMODITYTEST_H
#define COMMODITYTEST_H

#include <QObject>
#include <QTest>
#include "rangeconfig.h"
#include "config.h"
#include "logwidget.h"

class CommodityTest : public QObject
{
    Q_OBJECT
public:
    explicit CommodityTest(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void initTestCase();
    void case1_rangeConfig();

};

#endif // COMMODITYTEST_H
