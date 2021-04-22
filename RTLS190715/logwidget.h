#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QMutex>
#include <QDateTime>

class LogWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief getInstance 单例模式
     * @return 日志对象指针
     */
    static LogWidget* getInstance();

    /**
     * @brief outputMessage 日志信息输出函数
     * @param type 参数，日志信息的级别
     * @param msg  参数，日志信息的内容
     */
    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

protected:
    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();
    /**
     * @brief printMessage 打印日志信息
     * @param msg 输入参数，日志信息
     */
    void printMessage(const QString& msg, int level);

private:
    static LogWidget *m_instance;  // 单例
    QTextEdit *m_textEdit;//日志输出多行文本框

signals:

public slots:

};

#endif // LOGWIDGET_H
