#ifndef COMMONUTIL_H
#define COMMONUTIL_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QMessageBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <math.h>

// 坐标结构体
struct vec3d{
    double	x;
    double	y;
    double	z;
    char flag[3];   // 基站x y z坐标确认
};

namespace CommonUtil {
    /* 窗口 */
    bool choiceWindow(void);    // 选择是否窗口
    bool choiceWindow(QString);
    bool choiceTFWindow(QString);
    bool binaryChoice(QString msg, QString choice1, QString choice2);
    void warningMegBox(QWidget* parent, const QString &context);    // warning小窗口
    void dropDownListShow(QComboBox *comboBox, int cnt);

    /* 正则匹配 */
    bool patternMatch(QString pattern, QString text);
    bool patternMatch(QString pattern, QStringList list);
    bool ipv4PatternMatch(QString ipv4, unsigned char *ip); // ipv4判断

    /* 欧式距离计算 */
    double calcEuclidDist(vec3d *loc1, vec3d *loc2);
}

#endif // COMMONUTIL_H
