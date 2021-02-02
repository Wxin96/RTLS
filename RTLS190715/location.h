#ifndef LOCATION_H
#define LOCATION_H

#include <QWidget>
#include <QTimer>
#include <QCheckBox>
#include "trilateration.h"


class Location : public QWidget
{
    Q_OBJECT
public:
    explicit Location(QWidget *parent = nullptr);

signals:

public slots:
    void handleTimeout();  //超时处理函数
    void QCheckBox_toggled();

private:
    QTimer *timer;
    QCheckBox *Cbox_t[8];
    void paintEvent(QPaintEvent *);
    void paint_xy(int width,int height);
    void paint_grid(int width,int height, int xn,int yn);
    void paint_point(double x, double y, int id, bool flag);
    void paint_anchor();
    void paint_tag();
    void paint_rect();

    // 标签显示标志位
    unsigned char tag_flag = 0;
    // 圆心
    int Ox;
    int Oy;
};

#endif // LOCATION_H
