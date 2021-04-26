/********************************************************************************
** Form generated from reading UI file 'rtls_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTLS_WIDGET_H
#define UI_RTLS_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_RTLS_Widget
{
public:
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget1;
    QWidget *Tcp;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Port;
    QLabel *label_2;
    QTextEdit *textEdit_read;
    QLineEdit *lineEdit_IP;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_connect;
    QLabel *label;
    QWidget *Serial;
    QGridLayout *gridLayout_2;
    QLabel *SerialLabel;
    QTextBrowser *SerialTextBrowser;
    QPushButton *SerialButton;
    MyComboBox *SerialBox;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_9;
    QFrame *line_2;
    QLabel *label_16;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_10;
    QLabel *label_11;
    QComboBox *comboBox_4;
    QPushButton *pushButton_8;
    QLabel *label_17;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_7;
    QLabel *label_12;
    QComboBox *comboBox_5;
    QLabel *label_18;
    QLineEdit *lineEdit_8;
    QLabel *label_13;
    QComboBox *comboBox_6;
    QTextEdit *textEdit_2;
    QLabel *label_14;
    QComboBox *comboBox_7;
    QLabel *label_15;
    QComboBox *comboBox_8;
    QSlider *horizontalSlider;
    QTabWidget *tabWidget2;
    QWidget *Positioning;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_Anchor;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget_Tag;
    QPushButton *pushButton;
    QWidget *Ranging;
    QGridLayout *gridLayout_8;
    MyComboBox *tagSelect;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *rangingParamTable;
    QLabel *label_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QLabel *label_4;
    MyComboBox *anchorSelect;
    QFrame *line_3;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *singleCorrect;
    QPushButton *singleRecord;
    QPushButton *manualModify;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_11;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_20;
    QLineEdit *lineEdit_9;
    QLabel *label_21;
    QLineEdit *lineEdit_10;
    QLabel *label_22;
    QLineEdit *lineEdit_11;
    QLabel *label_7;
    QPushButton *MutiCorrect;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_3;
    QCheckBox *checkBox_2;
    QFrame *line;
    QPushButton *MutiRecord;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QComboBox *comboBox_3;
    QCheckBox *checkBox;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *RTLS_Widget)
    {
        if (RTLS_Widget->objectName().isEmpty())
            RTLS_Widget->setObjectName(QStringLiteral("RTLS_Widget"));
        RTLS_Widget->resize(832, 736);
        gridLayout_6 = new QGridLayout(RTLS_Widget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidget1 = new QTabWidget(RTLS_Widget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setMaximumSize(QSize(16777215, 230));
        Tcp = new QWidget();
        Tcp->setObjectName(QStringLiteral("Tcp"));
        gridLayout = new QGridLayout(Tcp);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_Port = new QLineEdit(Tcp);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        gridLayout->addWidget(lineEdit_Port, 0, 3, 1, 1);

        label_2 = new QLabel(Tcp);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        textEdit_read = new QTextEdit(Tcp);
        textEdit_read->setObjectName(QStringLiteral("textEdit_read"));

        gridLayout->addWidget(textEdit_read, 1, 0, 1, 6);

        lineEdit_IP = new QLineEdit(Tcp);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        gridLayout->addWidget(lineEdit_IP, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        Button_connect = new QPushButton(Tcp);
        Button_connect->setObjectName(QStringLiteral("Button_connect"));

        gridLayout->addWidget(Button_connect, 0, 4, 1, 1);

        label = new QLabel(Tcp);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget1->addTab(Tcp, QString());
        Serial = new QWidget();
        Serial->setObjectName(QStringLiteral("Serial"));
        gridLayout_2 = new QGridLayout(Serial);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        SerialLabel = new QLabel(Serial);
        SerialLabel->setObjectName(QStringLiteral("SerialLabel"));
        SerialLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(SerialLabel, 0, 0, 1, 1);

        SerialTextBrowser = new QTextBrowser(Serial);
        SerialTextBrowser->setObjectName(QStringLiteral("SerialTextBrowser"));
        SerialTextBrowser->setEnabled(true);

        gridLayout_2->addWidget(SerialTextBrowser, 1, 0, 1, 4);

        SerialButton = new QPushButton(Serial);
        SerialButton->setObjectName(QStringLiteral("SerialButton"));

        gridLayout_2->addWidget(SerialButton, 0, 3, 1, 1);

        SerialBox = new MyComboBox(Serial);
        SerialBox->setObjectName(QStringLiteral("SerialBox"));

        gridLayout_2->addWidget(SerialBox, 0, 1, 1, 2);

        tabWidget1->addTab(Serial, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_4->addWidget(lineEdit_5, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_4->addWidget(pushButton_9, 0, 2, 1, 1);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 3, 8, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_4->addWidget(label_16, 0, 4, 1, 1);

        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_4->addWidget(lineEdit_6, 0, 5, 1, 1);

        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_4->addWidget(pushButton_10, 0, 6, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        comboBox_4 = new QComboBox(tab);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_4->addWidget(comboBox_4, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_4->addWidget(pushButton_8, 1, 2, 1, 1);

        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_4->addWidget(label_17, 1, 4, 1, 1);

        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_4->addWidget(lineEdit_7, 1, 5, 1, 1);

        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_4->addWidget(pushButton_7, 1, 6, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        comboBox_5 = new QComboBox(tab);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout_4->addWidget(comboBox_5, 2, 1, 1, 1);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_4->addWidget(label_18, 2, 4, 1, 1);

        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_4->addWidget(lineEdit_8, 2, 5, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_4->addWidget(label_13, 3, 0, 1, 1);

        comboBox_6 = new QComboBox(tab);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        gridLayout_4->addWidget(comboBox_6, 3, 1, 2, 1);

        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_4->addWidget(textEdit_2, 4, 4, 4, 3);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_4->addWidget(label_14, 5, 0, 1, 1);

        comboBox_7 = new QComboBox(tab);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout_4->addWidget(comboBox_7, 5, 1, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 6, 0, 1, 1);

        comboBox_8 = new QComboBox(tab);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));

        gridLayout_4->addWidget(comboBox_8, 6, 1, 1, 1);

        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider, 7, 1, 1, 1);

        tabWidget1->addTab(tab, QString());

        gridLayout_6->addWidget(tabWidget1, 0, 0, 1, 1);

        tabWidget2 = new QTabWidget(RTLS_Widget);
        tabWidget2->setObjectName(QStringLiteral("tabWidget2"));
        Positioning = new QWidget();
        Positioning->setObjectName(QStringLiteral("Positioning"));
        gridLayout_3 = new QGridLayout(Positioning);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_Anchor = new QTableWidget(Positioning);
        if (tableWidget_Anchor->columnCount() < 4)
            tableWidget_Anchor->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_Anchor->rowCount() < 4)
            tableWidget_Anchor->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QFont font;
        font.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        __qtablewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(2, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem20->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(3, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 3, __qtablewidgetitem23);
        tableWidget_Anchor->setObjectName(QStringLiteral("tableWidget_Anchor"));
        tableWidget_Anchor->setMinimumSize(QSize(0, 175));

        gridLayout_3->addWidget(tableWidget_Anchor, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Positioning);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        tableWidget_Tag = new QTableWidget(Positioning);
        if (tableWidget_Tag->columnCount() < 4)
            tableWidget_Tag->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        if (tableWidget_Tag->rowCount() < 8)
            tableWidget_Tag->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(5, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(6, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(7, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(0, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(1, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 3, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem44->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(2, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem48->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(3, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem52->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(4, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 2, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 3, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem56->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(5, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 3, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem60->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(6, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem64->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(7, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 3, __qtablewidgetitem67);
        tableWidget_Tag->setObjectName(QStringLiteral("tableWidget_Tag"));
        tableWidget_Tag->setMinimumSize(QSize(0, 175));

        gridLayout_3->addWidget(tableWidget_Tag, 1, 1, 1, 1);

        pushButton = new QPushButton(Positioning);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        tabWidget2->addTab(Positioning, QString());
        Ranging = new QWidget();
        Ranging->setObjectName(QStringLiteral("Ranging"));
        gridLayout_8 = new QGridLayout(Ranging);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        tagSelect = new MyComboBox(Ranging);
        tagSelect->setObjectName(QStringLiteral("tagSelect"));
        tagSelect->setMinimumSize(QSize(140, 0));

        gridLayout_8->addWidget(tagSelect, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        rangingParamTable = new QTableWidget(Ranging);
        if (rangingParamTable->columnCount() < 4)
            rangingParamTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        rangingParamTable->setHorizontalHeaderItem(0, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        rangingParamTable->setHorizontalHeaderItem(1, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        rangingParamTable->setHorizontalHeaderItem(2, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        rangingParamTable->setHorizontalHeaderItem(3, __qtablewidgetitem71);
        if (rangingParamTable->rowCount() < 2)
            rangingParamTable->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        rangingParamTable->setVerticalHeaderItem(0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        rangingParamTable->setVerticalHeaderItem(1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        rangingParamTable->setItem(0, 0, __qtablewidgetitem74);
        rangingParamTable->setObjectName(QStringLiteral("rangingParamTable"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rangingParamTable->sizePolicy().hasHeightForWidth());
        rangingParamTable->setSizePolicy(sizePolicy);
        rangingParamTable->setMinimumSize(QSize(350, 0));

        gridLayout_8->addWidget(rangingParamTable, 1, 0, 1, 4);

        label_3 = new QLabel(Ranging);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_8->addWidget(label_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(Ranging);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(370, 140));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_7->addWidget(label_4, 0, 0, 1, 1);

        anchorSelect = new MyComboBox(groupBox);
        anchorSelect->setObjectName(QStringLiteral("anchorSelect"));

        gridLayout_7->addWidget(anchorSelect, 0, 1, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_3, 1, 0, 1, 3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_7->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_7->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_7->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_7->addWidget(lineEdit_4, 3, 1, 1, 1);

        singleCorrect = new QPushButton(groupBox);
        singleCorrect->setObjectName(QStringLiteral("singleCorrect"));

        gridLayout_7->addWidget(singleCorrect, 0, 2, 1, 1);

        singleRecord = new QPushButton(groupBox);
        singleRecord->setObjectName(QStringLiteral("singleRecord"));
        singleRecord->setEnabled(false);

        gridLayout_7->addWidget(singleRecord, 2, 2, 1, 1);


        gridLayout_8->addWidget(groupBox, 0, 4, 2, 1);

        manualModify = new QPushButton(Ranging);
        manualModify->setObjectName(QStringLiteral("manualModify"));

        gridLayout_8->addWidget(manualModify, 0, 3, 1, 1);

        groupBox_2 = new QGroupBox(Ranging);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_11 = new QGridLayout(groupBox_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        gridLayout_11->addWidget(checkBox_5, 0, 4, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        gridLayout_11->addWidget(checkBox_4, 0, 3, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        gridLayout_11->addWidget(checkBox_3, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        QFont font1;
        font1.setPointSize(11);
        label_20->setFont(font1);

        gridLayout_5->addWidget(label_20, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(lineEdit_9, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout_5->addWidget(label_21, 1, 0, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        sizePolicy2.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(lineEdit_10, 1, 1, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        gridLayout_5->addWidget(label_22, 2, 0, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy2.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(lineEdit_11, 2, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 2, 0, 2, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_11->addWidget(label_7, 0, 0, 1, 1);

        MutiCorrect = new QPushButton(groupBox_2);
        MutiCorrect->setObjectName(QStringLiteral("MutiCorrect"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(50);
        sizePolicy3.setHeightForWidth(MutiCorrect->sizePolicy().hasHeightForWidth());
        MutiCorrect->setSizePolicy(sizePolicy3);
        MutiCorrect->setMaximumSize(QSize(84, 16777215));

        gridLayout_11->addWidget(MutiCorrect, 0, 5, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_10 = new QGridLayout(groupBox_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        tableWidget_3 = new QTableWidget(groupBox_4);
        if (tableWidget_3->columnCount() < 4)
            tableWidget_3->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem78);
        if (tableWidget_3->rowCount() < 1)
            tableWidget_3->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem79);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy4);

        gridLayout_10->addWidget(tableWidget_3, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 2, 2, 2, 3);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);
        checkBox_2->setTristate(false);

        gridLayout_11->addWidget(checkBox_2, 0, 1, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_11->addWidget(line, 1, 0, 1, 6);

        MutiRecord = new QPushButton(groupBox_2);
        MutiRecord->setObjectName(QStringLiteral("MutiRecord"));
        MutiRecord->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(MutiRecord->sizePolicy().hasHeightForWidth());
        MutiRecord->setSizePolicy(sizePolicy5);
        MutiRecord->setMinimumSize(QSize(0, 30));
        MutiRecord->setMaximumSize(QSize(84, 16777215));

        gridLayout_11->addWidget(MutiRecord, 2, 5, 2, 1);


        gridLayout_8->addWidget(groupBox_2, 2, 0, 1, 5);

        tabWidget2->addTab(Ranging, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_9->addWidget(comboBox_3, 0, 1, 1, 2);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(false);

        gridLayout_9->addWidget(checkBox, 0, 3, 1, 1);

        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem82);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem84);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_9->addWidget(tableWidget, 1, 0, 1, 2);

        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem88);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem90);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_9->addWidget(tableWidget_2, 1, 2, 1, 2);

        tabWidget2->addTab(tab_2, QString());

        gridLayout_6->addWidget(tabWidget2, 1, 0, 1, 1);


        retranslateUi(RTLS_Widget);

        tabWidget1->setCurrentIndex(2);
        tabWidget2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RTLS_Widget);
    } // setupUi

    void retranslateUi(QWidget *RTLS_Widget)
    {
        RTLS_Widget->setWindowTitle(QApplication::translate("RTLS_Widget", "RTLS_Widget", nullptr));
        lineEdit_Port->setText(QApplication::translate("RTLS_Widget", "12900", nullptr));
        label_2->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 \347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEdit_IP->setText(QApplication::translate("RTLS_Widget", "127.0.0.1", nullptr));
        Button_connect->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        label->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 IP\357\274\232", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Tcp), QApplication::translate("RTLS_Widget", "\345\237\272\347\253\231TCP\351\200\232\344\277\241", nullptr));
        SerialLabel->setText(QApplication::translate("RTLS_Widget", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        SerialButton->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Serial), QApplication::translate("RTLS_Widget", "\345\237\272\347\253\231\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        label_10->setText(QApplication::translate("RTLS_Widget", "\350\246\201\346\216\247\345\210\266 \350\256\276\345\244\207IP\357\274\232", nullptr));
        lineEdit_5->setText(QString());
        pushButton_9->setText(QApplication::translate("RTLS_Widget", " \346\265\213\350\257\225", nullptr));
        label_16->setText(QApplication::translate("RTLS_Widget", "\345\260\204\347\201\257\344\275\215\347\275\256\357\274\232", nullptr));
        lineEdit_6->setText(QApplication::translate("RTLS_Widget", "\346\240\274\345\274\217\357\274\232x,y,z", nullptr));
        pushButton_10->setText(QApplication::translate("RTLS_Widget", "\350\257\273\345\217\226\351\205\215\347\275\256", nullptr));
        label_11->setText(QApplication::translate("RTLS_Widget", "\351\200\211\346\213\251\347\275\221\345\215\241\357\274\232", nullptr));
        pushButton_8->setText(QApplication::translate("RTLS_Widget", "\351\273\221\345\234\272", nullptr));
        label_17->setText(QApplication::translate("RTLS_Widget", "\345\260\204\347\201\257x\350\275\264\345\220\221\351\207\217\357\274\232", nullptr));
        lineEdit_7->setText(QApplication::translate("RTLS_Widget", "\346\240\274\345\274\217\357\274\232x,y,z", nullptr));
        pushButton_7->setText(QApplication::translate("RTLS_Widget", "\350\277\220\350\241\214", nullptr));
        label_12->setText(QApplication::translate("RTLS_Widget", "Net( \347\275\221)\357\274\232", nullptr));
        label_18->setText(QApplication::translate("RTLS_Widget", "\345\260\204\347\201\257z\350\275\264\345\220\221\351\207\217\357\274\232", nullptr));
        lineEdit_8->setText(QApplication::translate("RTLS_Widget", "\346\240\274\345\274\217\357\274\232x,y,z", nullptr));
        label_13->setText(QApplication::translate("RTLS_Widget", "SubNet(\345\255\220\347\275\221)\357\274\232", nullptr));
        label_14->setText(QApplication::translate("RTLS_Widget", "Universe(\345\237\237)\357\274\232", nullptr));
        label_15->setText(QApplication::translate("RTLS_Widget", "\351\200\232\351\201\223(Channel)\357\274\232", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(tab), QApplication::translate("RTLS_Widget", "\345\260\204\347\201\257\351\200\232\344\277\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Anchor->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RTLS_Widget", "Anchor ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Anchor->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RTLS_Widget", "X(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Anchor->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RTLS_Widget", "Y(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Anchor->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RTLS_Widget", "Z(m)", nullptr));

        const bool __sortingEnabled = tableWidget_Anchor->isSortingEnabled();
        tableWidget_Anchor->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Anchor->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("RTLS_Widget", "Anchor 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Anchor->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("RTLS_Widget", "10.013", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Anchor->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("RTLS_Widget", "2.651", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Anchor->item(0, 3);
        ___qtablewidgetitem7->setText(QApplication::translate("RTLS_Widget", "3.622", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Anchor->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("RTLS_Widget", "Anchor 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Anchor->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("RTLS_Widget", "8.691", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Anchor->item(1, 2);
        ___qtablewidgetitem10->setText(QApplication::translate("RTLS_Widget", "5.812", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Anchor->item(1, 3);
        ___qtablewidgetitem11->setText(QApplication::translate("RTLS_Widget", "0.452", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Anchor->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("RTLS_Widget", "Anchor 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Anchor->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("RTLS_Widget", "1.032", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Anchor->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("RTLS_Widget", "6.012", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Anchor->item(2, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("RTLS_Widget", "3.152", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_Anchor->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("RTLS_Widget", "Anchor 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_Anchor->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("RTLS_Widget", "2.432", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_Anchor->item(3, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("RTLS_Widget", "0.489", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_Anchor->item(3, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("RTLS_Widget", "0.452", nullptr));
        tableWidget_Anchor->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("RTLS_Widget", "\345\233\276\345\275\242\345\214\226\347\225\214\351\235\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_Tag->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("RTLS_Widget", "Tag ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_Tag->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("RTLS_Widget", "X(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_Tag->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("RTLS_Widget", "Y(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_Tag->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("RTLS_Widget", "Z(m)", nullptr));

        const bool __sortingEnabled1 = tableWidget_Tag->isSortingEnabled();
        tableWidget_Tag->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_Tag->item(0, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("RTLS_Widget", "Tag 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_Tag->item(1, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("RTLS_Widget", "Tag 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_Tag->item(2, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("RTLS_Widget", "Tag 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_Tag->item(3, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("RTLS_Widget", "Tag 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_Tag->item(4, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("RTLS_Widget", "Tag 4", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_Tag->item(5, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("RTLS_Widget", "Tag 5", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_Tag->item(6, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("RTLS_Widget", "Tag 6", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_Tag->item(7, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("RTLS_Widget", "Tag 7", nullptr));
        tableWidget_Tag->setSortingEnabled(__sortingEnabled1);

        pushButton->setText(QApplication::translate("RTLS_Widget", "\350\257\273\345\217\226\345\237\272\347\253\231\345\235\220\346\240\207", nullptr));
        tabWidget2->setTabText(tabWidget2->indexOf(Positioning), QApplication::translate("RTLS_Widget", "\345\256\232\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = rangingParamTable->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("RTLS_Widget", "A0", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = rangingParamTable->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("RTLS_Widget", "A1", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = rangingParamTable->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("RTLS_Widget", "A2", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = rangingParamTable->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QApplication::translate("RTLS_Widget", "A3", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = rangingParamTable->verticalHeaderItem(0);
        ___qtablewidgetitem36->setText(QApplication::translate("RTLS_Widget", "K", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = rangingParamTable->verticalHeaderItem(1);
        ___qtablewidgetitem37->setText(QApplication::translate("RTLS_Widget", "b", nullptr));

        const bool __sortingEnabled2 = rangingParamTable->isSortingEnabled();
        rangingParamTable->setSortingEnabled(false);
        rangingParamTable->setSortingEnabled(__sortingEnabled2);

        label_3->setText(QApplication::translate("RTLS_Widget", "Tag ID\357\274\232", nullptr));
        groupBox->setTitle(QApplication::translate("RTLS_Widget", "\345\215\225\345\237\272\347\253\231\346\240\241\346\255\243", nullptr));
        label_4->setText(QApplication::translate("RTLS_Widget", "Anchor ID\357\274\232", nullptr));
        label_5->setText(QApplication::translate("RTLS_Widget", "\347\234\237\345\256\236\350\267\235\347\246\273\357\274\232", nullptr));
        label_6->setText(QApplication::translate("RTLS_Widget", "\346\265\213\347\232\204\350\267\235\347\246\273\357\274\232", nullptr));
        singleCorrect->setText(QApplication::translate("RTLS_Widget", " \345\274\200\345\247\213\346\240\241\346\255\243", nullptr));
        singleRecord->setText(QApplication::translate("RTLS_Widget", "\350\256\260\345\275\225", nullptr));
        manualModify->setText(QApplication::translate("RTLS_Widget", "\346\211\213\345\212\250\344\277\256\346\224\271", nullptr));
        groupBox_2->setTitle(QApplication::translate("RTLS_Widget", "\345\244\232\345\237\272\347\253\231\346\240\241\346\255\243", nullptr));
        checkBox_5->setText(QApplication::translate("RTLS_Widget", " A3", nullptr));
        checkBox_4->setText(QApplication::translate("RTLS_Widget", " A2", nullptr));
        checkBox_3->setText(QApplication::translate("RTLS_Widget", " A1", nullptr));
        groupBox_3->setTitle(QApplication::translate("RTLS_Widget", "\346\240\207\347\255\276\344\275\215\347\275\256\357\274\232", nullptr));
        label_20->setText(QApplication::translate("RTLS_Widget", "  x:", nullptr));
        label_21->setText(QApplication::translate("RTLS_Widget", "  y:", nullptr));
        label_22->setText(QApplication::translate("RTLS_Widget", "  z:", nullptr));
        label_7->setText(QApplication::translate("RTLS_Widget", "  \347\237\253\346\255\243\345\237\272\347\253\231\357\274\232", nullptr));
        MutiCorrect->setText(QApplication::translate("RTLS_Widget", " \345\274\200\345\247\213\346\240\241\346\255\243", nullptr));
        groupBox_4->setTitle(QApplication::translate("RTLS_Widget", "\345\237\272\347\253\231\346\265\213\350\267\235\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("RTLS_Widget", "A0", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("RTLS_Widget", "A1", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("RTLS_Widget", "A2", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("RTLS_Widget", "A3", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem42->setText(QApplication::translate("RTLS_Widget", "\346\265\213\347\232\204\350\267\235\347\246\273", nullptr));
        checkBox_2->setText(QApplication::translate("RTLS_Widget", " A0", nullptr));
        MutiRecord->setText(QApplication::translate("RTLS_Widget", "\350\256\260\345\275\225", nullptr));
        tabWidget2->setTabText(tabWidget2->indexOf(Ranging), QApplication::translate("RTLS_Widget", "\346\265\213\350\267\235\346\240\241\346\255\243", nullptr));
        label_9->setText(QApplication::translate("RTLS_Widget", "     Tag ID\357\274\232", nullptr));
        checkBox->setText(QApplication::translate("RTLS_Widget", "\345\267\262\347\237\245\347\234\237\345\256\236\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QApplication::translate("RTLS_Widget", "x/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QApplication::translate("RTLS_Widget", "y/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QApplication::translate("RTLS_Widget", "z/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem46->setText(QApplication::translate("RTLS_Widget", "\345\256\236\346\265\213\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem47->setText(QApplication::translate("RTLS_Widget", "\347\234\237\345\256\236\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem48->setText(QApplication::translate("RTLS_Widget", "A0", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem49->setText(QApplication::translate("RTLS_Widget", "A1", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem50->setText(QApplication::translate("RTLS_Widget", "A2", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem51->setText(QApplication::translate("RTLS_Widget", "A3", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem52->setText(QApplication::translate("RTLS_Widget", "\345\256\236\346\265\213\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem53->setText(QApplication::translate("RTLS_Widget", "\347\234\237\345\256\236\350\267\235\347\246\273", nullptr));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_2), QApplication::translate("RTLS_Widget", " \351\252\214\350\257\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTLS_Widget: public Ui_RTLS_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTLS_WIDGET_H
