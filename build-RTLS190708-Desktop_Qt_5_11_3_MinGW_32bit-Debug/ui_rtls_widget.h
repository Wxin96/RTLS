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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget2;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_Anchor;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget_Tag;
    QPushButton *pushButton;
    QTabWidget *tabWidget1;
    QWidget *Tcp;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_read;
    QLabel *label_2;
    QPushButton *Button_connect;
    QLineEdit *lineEdit_IP;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Port;
    QWidget *Serial;
    QGridLayout *gridLayout_2;
    QLabel *SerialLabel;
    QTextBrowser *SerialTextBrowser;
    QPushButton *SerialButton;
    MyComboBox *SerialBox;

    void setupUi(QWidget *RTLS_Widget)
    {
        if (RTLS_Widget->objectName().isEmpty())
            RTLS_Widget->setObjectName(QStringLiteral("RTLS_Widget"));
        RTLS_Widget->resize(780, 652);
        gridLayout_4 = new QGridLayout(RTLS_Widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget2 = new QTabWidget(RTLS_Widget);
        tabWidget2->setObjectName(QStringLiteral("tabWidget2"));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_Anchor = new QTableWidget(widget);
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

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        tableWidget_Tag = new QTableWidget(widget);
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

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        tabWidget2->addTab(widget, QString());

        gridLayout_4->addWidget(tabWidget2, 1, 0, 1, 1);

        tabWidget1 = new QTabWidget(RTLS_Widget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setMaximumSize(QSize(16777215, 200));
        Tcp = new QWidget();
        Tcp->setObjectName(QStringLiteral("Tcp"));
        gridLayout = new QGridLayout(Tcp);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit_read = new QTextEdit(Tcp);
        textEdit_read->setObjectName(QStringLiteral("textEdit_read"));

        gridLayout->addWidget(textEdit_read, 1, 0, 1, 6);

        label_2 = new QLabel(Tcp);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        Button_connect = new QPushButton(Tcp);
        Button_connect->setObjectName(QStringLiteral("Button_connect"));

        gridLayout->addWidget(Button_connect, 0, 4, 1, 1);

        lineEdit_IP = new QLineEdit(Tcp);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        gridLayout->addWidget(lineEdit_IP, 0, 1, 1, 1);

        label = new QLabel(Tcp);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        lineEdit_Port = new QLineEdit(Tcp);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        gridLayout->addWidget(lineEdit_Port, 0, 3, 1, 1);

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

        gridLayout_4->addWidget(tabWidget1, 0, 0, 1, 1);


        retranslateUi(RTLS_Widget);

        tabWidget2->setCurrentIndex(0);
        tabWidget1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RTLS_Widget);
    } // setupUi

    void retranslateUi(QWidget *RTLS_Widget)
    {
        RTLS_Widget->setWindowTitle(QApplication::translate("RTLS_Widget", "RTLS_Widget", nullptr));
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
        ___qtablewidgetitem5->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Anchor->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("RTLS_Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Anchor->item(0, 3);
        ___qtablewidgetitem7->setText(QApplication::translate("RTLS_Widget", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Anchor->item(1, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("RTLS_Widget", "Anchor 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Anchor->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("RTLS_Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Anchor->item(1, 2);
        ___qtablewidgetitem10->setText(QApplication::translate("RTLS_Widget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Anchor->item(1, 3);
        ___qtablewidgetitem11->setText(QApplication::translate("RTLS_Widget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Anchor->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("RTLS_Widget", "Anchor 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Anchor->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("RTLS_Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Anchor->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("RTLS_Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Anchor->item(2, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("RTLS_Widget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_Anchor->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("RTLS_Widget", "Anchor 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_Anchor->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("RTLS_Widget", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_Anchor->item(3, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("RTLS_Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_Anchor->item(3, 3);
        ___qtablewidgetitem19->setText(QApplication::translate("RTLS_Widget", "3", nullptr));
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
        tabWidget2->setTabText(tabWidget2->indexOf(widget), QApplication::translate("RTLS_Widget", "Table", nullptr));
        label_2->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 \347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        Button_connect->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        lineEdit_IP->setText(QApplication::translate("RTLS_Widget", "127.0.0.1", nullptr));
        label->setText(QApplication::translate("RTLS_Widget", "\346\234\215\345\212\241\345\231\250 IP\357\274\232", nullptr));
        lineEdit_Port->setText(QApplication::translate("RTLS_Widget", "12900", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Tcp), QApplication::translate("RTLS_Widget", "TCP", nullptr));
        SerialLabel->setText(QApplication::translate("RTLS_Widget", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        SerialButton->setText(QApplication::translate("RTLS_Widget", "Connect", nullptr));
        tabWidget1->setTabText(tabWidget1->indexOf(Serial), QApplication::translate("RTLS_Widget", "Serial Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTLS_Widget: public Ui_RTLS_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTLS_WIDGET_H
