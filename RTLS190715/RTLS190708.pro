#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T09:44:59
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RTLS190708
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        kalmanfilter.cpp \
        location.cpp \
        main.cpp \
        mycombobox.cpp \
        ranging.cpp \
        rtls_widget.cpp \
        trilateration.cpp

HEADERS += \
        kalmanfilter.h \
        location.h \
        mycombobox.h \
        ranging.h \
        rtls_widget.h \
        trilateration.h
INCLUDEPATH += \
            D:\Soft\eigen-3.3.9\Eigen

FORMS += \
        rtls_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
