#include "logwidget.h"

LogWidget *LogWidget::m_instance = nullptr;

LogWidget *LogWidget::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new LogWidget();
    }
    return m_instance;
}

void LogWidget::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    int level = 0;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        level = 1;
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        level = 2;
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
        level = 3;
        break;
    }
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text, -9).arg(context_info).arg(msg, -50).arg(current_date);

    printMessage(message, level);
    mutex.unlock();
}

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    // textEdit
    m_textEdit = new QTextEdit(this);
    m_textEdit->setReadOnly(true);
    // QHBox
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_textEdit);
    // QWidget
    this->setLayout(layout);
    this->resize(600, 200);
}

LogWidget::~LogWidget()
{

}

void LogWidget::printMessage(const QString &msg, int level)
{
    if (level >= 1) {
        m_textEdit->setTextColor(Qt::red);
    } else {
        m_textEdit->setTextColor(Qt::black);
    }
    m_textEdit->append(msg);
}


