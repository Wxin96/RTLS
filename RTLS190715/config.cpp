#include "config.h"

Config::Config(QString qstrfilename)
{
    if (qstrfilename.isEmpty())
    {
        m_qstrFileName = QCoreApplication::applicationDirPath() + "/config/tempConfig.ini";
    }
    else
    {
        m_qstrFileName = qstrfilename;
    }
    m_psetting = new QSettings(m_qstrFileName, QSettings::IniFormat);
}
Config::~Config()
{
    delete m_psetting;
}
void Config::Set(QString qstrnodename,QString qstrkeyname,QVariant qvarvalue)
{
    m_psetting->setValue(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname), qvarvalue);
}
QVariant Config::Get(QString qstrnodename,QString qstrkeyname)
{
    return m_psetting->value(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
}

bool Config::contains(QString qstrnodename, QString qstrkeyname)
{
    return m_psetting->contains(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
}
