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
    QGridLayout *gridLayout_8;
    QTabWidget *tabWidget2;
    QWidget *Positioning;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_Tag;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTableWidget *tableWidget_Anchor;
    QWidget *Ranging;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label_9;
    QCheckBox *checkBox;
    QComboBox *comboBox_3;
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
    QPushButton *pushButton_7;
    QLabel *label_12;
    QComboBox *comboBox_5;
    QLabel *label_11;
    QComboBox *comboBox_4;
    QPushButton *pushButton_8;
    QLabel *label_13;
    QComboBox *comboBox_6;
    QTextEdit *textEdit_2;
    QLabel *label_14;
    QComboBox *comboBox_7;
    QLabel *label_15;
    QComboBox *comboBox_8;
    QSlider *horizontalSlider;

    void setupUi(QWidget *RTLS_Widget)
    {
        if (RTLS_Widget->objectName().isEmpty())
            RTLS_Widget->setObjectName(QStringLiteral("RTLS_Widget"));
        RTLS_Widget->resize(780, 652);
        gridLayout_8 = new QGridLayout(RTLS_Widget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        tabWidget2 = new QTabWidget(RTLS_Widget);
        tabWidget2->setObjectName(QStringLiteral("tabWidget2"));
        Positioning = new QWidget();
        Positioning->setObjectName(QStringLiteral("Positioning"));
        gridLayout_3 = new QGridLayout(Positioning);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_Tag = new QTableWidget(Positioning);
        if (tableWidget_Tag->columnCount() < 4)
            tableWidget_Tag->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_Tag->rowCount() < 8)
            tableWidget_Tag->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Tag->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(0, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(1, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(1, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem20->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(2, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(2, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem24->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(3, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem28->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(4, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(4, 3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem32->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(5, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(5, 3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(6, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(6, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Tag->setItem(7, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        tableWidget_Tag->setItem(7, 3, __qtablewidgetitem43);
        tableWidget_Tag->setObjectName(QStringLiteral("tableWidget_Tag"));
        tableWidget_Tag->setMinimumSize(QSize(0, 175));

        gridLayout_3->addWidget(tableWidget_Tag, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Positioning);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(Positioning);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        tableWidget_Anchor = new QTableWidget(Positioning);
        if (tableWidget_Anchor->columnCount() < 4)
            tableWidget_Anchor->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_Anchor->setHorizontalHeaderItem(3, __qtablewidgetitem47);
        if (tableWidget_Anchor->rowCount() < 4)
            tableWidget_Anchor->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_Anchor->setVerticalHeaderItem(3, __qtablewidgetitem51);
        QFont font;
        font.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem52->setFont(font);
        __qtablewidgetitem52->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(0, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 2, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(0, 3, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem56->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(1, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(1, 3, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem60->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(2, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(2, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem64->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Anchor->setItem(3, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setTextAlignment(Qt::AlignCenter);
        tableWidget_Anchor->setItem(3, 3, __qtablewidgetitem67);
        tableWidget_Anchor->setObjectName(QStringLiteral("tableWidget_Anchor"));
        tableWidget_Anchor->setMinimumSize(QSize(0, 175));

        gridLayout_3->addWidget(tableWidget_Anchor, 1, 0, 1, 1);

        tabWidget2->addTab(Positioning, QString());
        Ranging = new QWidget();
        Ranging->setObjectName(QStringLiteral("Ranging"));
        gridLayout_6 = new QGridLayout(Ranging);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox = new QGroupBox(Ranging);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_5->addWidget(comboBox, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_5->addWidget(comboBox_2, 0, 3, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_5->addWidget(lineEdit, 1, 1, 1, 2);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_5->addWidget(pushButton_6, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_5->addWidget(lineEdit_2, 2, 1, 1, 2);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_5->addWidget(pushButton_5, 2, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 3, 1, 1, 2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_5->addWidget(pushButton_3, 3, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_5->addWidget(lineEdit_4, 4, 1, 1, 2);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_5->addWidget(pushButton_4, 4, 3, 1, 1);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_5->addWidget(textEdit, 5, 0, 1, 4);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(Ranging);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem70);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem72);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_7->addWidget(tableWidget, 1, 0, 1, 3);

        tableWidget_2 = new QTableWidget(groupBox_2);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem76);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem78);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_7->addWidget(tableWidget_2, 2, 0, 1, 3);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_7->addWidget(label_9, 0, 0, 1, 1);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(false);

        gridLayout_7->addWidget(checkBox, 0, 2, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_7->addWidget(comboBox_3, 0, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 1, 1, 1);

        tabWidget2->addTab(Ranging, QString());

        gridLayout_8->addWidget(tabWidget2, 1, 0, 1, 1);

        tabWidget1 = new QTabWidget(RTLS_Widget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setMaximumSize(QSize(16777215, 200));
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

        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_4->addWidget(pushButton_7, 0, 2, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_4->addWidget(label_12, 0, 3, 1, 1);

        comboBox_5 = new QComboBox(tab);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout_4->addWidget(comboBox_5, 0, 4, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        comboBox_4 = new QComboBox(tab);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_4->addWidget(comboBox_4, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_4->addWidget(pushButton_8, 1, 2, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_4->addWidget(label_13, 1, 3, 1, 1);

        comboBox_6 = new QComboBox(tab);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        gridLayout_4->addWidget(comboBox_6, 1, 4, 1, 1);

        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_4->addWidget(textEdit_2, 2, 0, 3, 3);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_4->addWidget(label_14, 2, 3, 1, 1);

        comboBox_7 = new QComboBox(tab);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout_4->addWidget(comboBox_7, 2, 4, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 3, 3, 2, 1);

        comboBox_8 = new QComboBox(tab);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));

        gridLayout_4->addWidget(comboBox_8, 3, 4, 1, 1);

        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider, 4, 4, 1, 1);

        tabWidget1->addTab(tab, QString());

        gridLayout_8->addWidget(tabWidget1, 0, 0, 1, 1);


        retranslateUi(RTLS_Widget);

        tabWidget2->setCurrentIndex(1);
        tabWidget1->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(RTLS_Widget);
    } // setupUi

    void retranslateUi(QWidget *RTLS_Widget)
    {
        RTLS_Widget->setWindowTitle(QApplication::translate("RTLS_Widget", "RTLS_Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Tag->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RTLS_Widget", "Tag ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Tag->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RTLS_Widget", "X(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Tag->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RTLS_Widget", "Y(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Tag->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RTLS_Widget", "Z(m)", nullptr));

        const bool __sortingEnabled = tableWidget_Tag->isSortingEnabled();
        tableWidget_Tag->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Tag->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("RTLS_Widget", "Tag 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Tag->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("RTLS_Widget", "Tag 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Tag->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("RTLS_Widget", "Tag 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Tag->item(3, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("RTLS_Widget", "Tag 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Tag->item(4, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("RTLS_Widget", "Tag 4", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Tag->item(5, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("RTLS_Widget", "Tag 5", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Tag->item(6, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("RTLS_Widget", "Tag 6", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Tag->item(7, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("RTLS_Widget", "Tag 7", nullptr));
        tableWidget_Tag->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("RTLS_Widget", "\345\233\276\345\275\242\345\214\226\347\225\214\351\235\242", nullptr));
        pushButton->setText(QApplication::translate("RTLS_Widget", "\350\257\273\345\217\226\345\237\272\347\253\231\345\235\220\346\240\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Anchor->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("RTLS_Widget", "Anchor ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Anchor->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("RTLS_Widget", "X(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Anchor->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("RTLS_Widget", "Y(m)", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Anchor->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("RTLS_Widget", "Z(m)", nullptr));

        const bool __sortingEnabled1 = tableWidget_Anchor->isSortingEnabled();
        tableWidget_Anchor->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_Anchor->item(0, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("RTLS_Widget", "Anchor 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_Anchor->item(0, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("RTLS_Widget", "-3", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_Anchor->item(0, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("RTLS_Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_Anchor->item(0, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("RTLS_Widget", "0.5", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_Anchor->item(1, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("RTLS_Widget", "Anchor 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_Anchor->item(1, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("RTLS_Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_Anchor->item(1, 2);
        ___qtablewidgetitem22->setText(QApplication::translate("RTLS_Widget", "-1", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_Anchor->item(1, 3);
        ___qtablewidgetitem23->setText(QApplication::translate("RTLS_Widget", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_Anchor->item(2, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("RTLS_Widget", "Anchor 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_Anchor->item(2, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_Anchor->item(2, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_Anchor->item(2, 3);
        ___qtablewidgetitem27->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_Anchor->item(3, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("RTLS_Widget", "Anchor 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_Anchor->item(3, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("RTLS_Widget", "-2", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_Anchor->item(3, 2);
        ___qtablewidgetitem30->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_Anchor->item(3, 3);
        ___qtablewidgetitem31->setText(QApplication::translate("RTLS_Widget", "3.2", nullptr));
        tableWidget_Anchor->setSortingEnabled(__sortingEnabled1);

        tabWidget2->setTabText(tabWidget2->indexOf(Positioning), QApplication::translate("RTLS_Widget", "Positioning", nullptr));
        groupBox->setTitle(QApplication::translate("RTLS_Widget", "Range Correction", nullptr));
        label_3->setText(QApplication::translate("RTLS_Widget", "Tag ID\357\274\232", nullptr));
        label_4->setText(QApplication::translate("RTLS_Widget", "Anchor ID\357\274\232", nullptr));
        label_7->setText(QApplication::translate("RTLS_Widget", "  K\357\274\232", nullptr));
        lineEdit->setText(QString());
        pushButton_6->setText(QApplication::translate("RTLS_Widget", "  \346\230\276\347\244\272", nullptr));
        label_8->setText(QApplication::translate("RTLS_Widget", "  b\357\274\232", nullptr));
        pushButton_5->setText(QApplication::translate("RTLS_Widget", "\346\211\213\345\212\250\344\277\256\346\224\271", nullptr));
        label_5->setText(QApplication::translate("RTLS_Widget", "  True\357\274\232", nullptr));
        pushButton_3->setText(QApplication::translate("RTLS_Widget", " \345\274\200\345\247\213\346\240\241\346\255\243", nullptr));
        label_6->setText(QApplication::translate("RTLS_Widget", "  Measured\357\274\232", nullptr));
        pushButton_4->setText(QApplication::translate("RTLS_Widget", "\350\256\260\345\275\225", nullptr));
        groupBox_2->setTitle(QApplication::translate("RTLS_Widget", " Tag  Range", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("RTLS_Widget", "x/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("RTLS_Widget", "y/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("RTLS_Widget", "z/m", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("RTLS_Widget", "\345\256\236\346\265\213\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("RTLS_Widget", "\347\234\237\345\256\236\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem37->setText(QApplication::translate("RTLS_Widget", "A0", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem38->setText(QApplication::translate("RTLS_Widget", "A1", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem39->setText(QApplication::translate("RTLS_Widget", "A2", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem40->setText(QApplication::translate("RTLS_Widget", "A3", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem41->setText(QApplication::translate("RTLS_Widget", "\345\256\236\346\265\213\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem42->setText(QApplication::translate("RTLS_Widget", "\347\234\237\345\256\236\350\267\235\347\246\273", nullptr));
        label_9->setText(QApplication::translate("RTLS_Widget", "Tag ID\357\274\232", nullptr));
        checkBox->setText(QApplication::translate("RTLS_Widget", "\345\267\262\347\237\245\347\234\237\345\256\236\344\275\215\347\275\256", nullptr));
        tabWidget2->setTabText(tabWidget2->indexOf(Ranging), QApplication::translate("RTLS_Widget", "Ranging", nullptr));
        lineEdit_Port->setText(QApplication::translate("RTLS_Widget", "12900", nullptr));
        label_2->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 \347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEdit_IP->setText(QApplication::translate("RTLS_Widget", "127.0.0.1", nullptr));
        Button_connect->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        label->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 IP\357\274\232", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Tcp), QApplication::translate("RTLS_Widget", "TCP", nullptr));
        SerialLabel->setText(QApplication::translate("RTLS_Widget", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        SerialButton->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Serial), QApplication::translate("RTLS_Widget", "Serial Port", nullptr));
        label_10->setText(QApplication::translate("RTLS_Widget", "\350\246\201\346\216\247\345\210\266 \350\256\276\345\244\207IP\357\274\232", nullptr));
        pushButton_7->setText(QApplication::translate("RTLS_Widget", "\350\277\220\350\241\214", nullptr));
        label_12->setText(QApplication::translate("RTLS_Widget", "Net( \347\275\221)\357\274\232", nullptr));
        label_11->setText(QApplication::translate("RTLS_Widget", "\351\200\211\346\213\251\347\275\221\345\215\241\357\274\232", nullptr));
        pushButton_8->setText(QApplication::translate("RTLS_Widget", "\351\273\221\345\234\272", nullptr));
        label_13->setText(QApplication::translate("RTLS_Widget", "SubNet(\345\255\220\347\275\221)\357\274\232", nullptr));
        label_14->setText(QApplication::translate("RTLS_Widget", "Universe(\345\237\237)\357\274\232", nullptr));
        label_15->setText(QApplication::translate("RTLS_Widget", "\351\200\232\351\201\223(Channel)\357\274\232", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(tab), QApplication::translate("RTLS_Widget", "\350\210\236\345\217\260\347\201\257\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTLS_Widget: public Ui_RTLS_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTLS_WIDGET_H
