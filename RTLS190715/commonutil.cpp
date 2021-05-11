#include "commonutil.h"


bool CommonUtil::choiceWindow(QString msg)
{
    return choiceTFWindow(msg.append("是否保存修改？"));
}

bool CommonUtil::choiceWindow()
{
    return choiceWindow("");
}

bool CommonUtil::choiceTFWindow(QString msg)
{
    // 1.窗口
    QMessageBox Msg(QMessageBox::Question, QString("提示"), msg);  // 对话框提示
    // 2.添加按钮
    QAbstractButton *pYesBtn = dynamic_cast<QAbstractButton *> (Msg.addButton(QString("是"), QMessageBox::YesRole) );
    Msg.addButton(QString("否"), QMessageBox::NoRole);
    // 3.阻塞
    Msg.exec(); // 阻塞
    // 4.返回值
    if (Msg.clickedButton() == pYesBtn) {
        return true;
    } else {
        return false;
    }
}

bool CommonUtil::binaryChoice(QString msg, QString choice1, QString choice2)
{
    // 1.窗口
    QMessageBox Msg(QMessageBox::Question, QString("提示"), msg);  // 对话框提示
    // 2.添加按钮
    QAbstractButton *pYesBtn = dynamic_cast<QAbstractButton *> (Msg.addButton(choice1, QMessageBox::YesRole) );
    Msg.addButton(choice2, QMessageBox::NoRole);
    // 3.阻塞
    Msg.exec(); // 阻塞
    // 4.返回值
    if (Msg.clickedButton() == pYesBtn) {
        return true;
    } else {
        return false;
    }
}

bool CommonUtil::patternMatch(QString pattern, QString text)
{
    QRegExp rx(pattern);
    return rx.exactMatch(text);
}

bool CommonUtil::patternMatch(QString pattern, QStringList list)
{
    bool flag = true;
    foreach (const QString &str, list) {
        if (not patternMatch(pattern, str)) {
            qDebug() << str << "数据格式不对";
            QMessageBox::warning(nullptr, "警告", str + " 数据格式不对");
            flag =  false;
        }
    }
    return flag;
}

double CommonUtil::calcEuclidDist(vec3d *loc1, vec3d *loc2)
{
    return pow(
                pow(loc1->x - loc2->x, 2) + pow(loc1->y - loc2->y, 2) + pow(loc1->z - loc2->z, 2),
                0.5
               );
}

void CommonUtil::warningMegBox(QWidget *parent, const QString &context)
{
    QMessageBox::warning(parent, "警告", context);
}

void CommonUtil::dropDownListShow(QComboBox *comboBox, int cnt)
{
    // 0.预判断
    if (comboBox == nullptr) {
        qWarning() << "组合框为空指针，无法处理！";
        return;
    }
    // 1.根据情况处理
    if (comboBox->count() != cnt) {
        comboBox->clear();
        for (int i = 0; i < cnt; i++) {
            comboBox->addItem(QString::number(i));
        }
    }
}

// ipv4判断
bool CommonUtil::ipv4PatternMatch(QString ipv4, unsigned char *ip)
{
    // 0.预处理
    QStringList ipList = ipv4.trimmed().split(".");
    if (ipList.size() != 4) return false;
    // 1.正则 + 匹配
    for (int i = 0; i < 4; i++) {
        QString curStrNum = ipList.at(i);
        if (!patternMatch("^\\d{1,3}$", curStrNum) || patternMatch("^0\\d+", curStrNum)) {
            qWarning() << "ip正则匹配未通过! ==> " << curStrNum;
            return false;
        }
        int curNum = curStrNum.toInt();
        if (curNum >= 0 && curNum < 256) {
            ip[i] = static_cast<unsigned char>(curNum);
        } else {
            qWarning() << "ip数值范围不正确! ==> " << curStrNum;
            return false;
        }
    }
    return true;

}
