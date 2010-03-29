/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created: Mon 29. Mar 21:05:16 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionDataClipboard;
    QAction *actionRefreshData;
    QAction *actionCheck_for_update;
    QAction *actionSettings;
    QWidget *centralWidget;
    QToolBox *toolBox;
    QWidget *page;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *pong2Edit;
    QLineEdit *bibleQuizEdit;
    QLineEdit *redSquareEdit;
    QLineEdit *spaceBubbleEdit;
    QLineEdit *towerDefenseEdit;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *pong2Edit3;
    QLineEdit *bibleQuizEdit3;
    QLineEdit *redSquareEdit3;
    QLineEdit *spaceBubbleEdit3;
    QLineEdit *towerDefenseEdit3;
    QGroupBox *groupBox_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *pong2Edit4;
    QLineEdit *bibleQuizEdit4;
    QLineEdit *redSquareEdit4;
    QLineEdit *spaceBubbleEdit4;
    QLineEdit *towerDefenseEdit4;
    QGroupBox *groupBox_5;
    QLineEdit *totals;
    QLineEdit *totals2;
    QLineEdit *totals3;
    QLineEdit *totals4;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *pong2Edit2;
    QLineEdit *bibleQuizEdit2;
    QLineEdit *redSquareEdit2;
    QLineEdit *spaceBubbleEdit2;
    QLineEdit *towerDefenseEdit2;
    QWidget *page_2;
    QGroupBox *groupBox_6;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *addressbookEdit1;
    QLineEdit *eventNotificationEdit1;
    QLineEdit *churchEdit1;
    QGroupBox *groupBox_7;
    QLineEdit *totalsDrupalEdit1;
    QMenuBar *menuBar;
    QMenu *menuExit;
    QMenu *menuHelp;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(368, 428);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionDataClipboard = new QAction(MainWindow);
        actionDataClipboard->setObjectName(QString::fromUtf8("actionDataClipboard"));
        actionRefreshData = new QAction(MainWindow);
        actionRefreshData->setObjectName(QString::fromUtf8("actionRefreshData"));
        actionCheck_for_update = new QAction(MainWindow);
        actionCheck_for_update->setObjectName(QString::fromUtf8("actionCheck_for_update"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 10, 351, 391));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 351, 337));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 81, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 69, 13));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 69, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 69, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 170, 69, 13));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 220, 69, 13));
        pong2Edit = new QLineEdit(groupBox);
        pong2Edit->setObjectName(QString::fromUtf8("pong2Edit"));
        pong2Edit->setGeometry(QRect(10, 40, 61, 20));
        pong2Edit->setReadOnly(true);
        bibleQuizEdit = new QLineEdit(groupBox);
        bibleQuizEdit->setObjectName(QString::fromUtf8("bibleQuizEdit"));
        bibleQuizEdit->setGeometry(QRect(10, 90, 61, 20));
        bibleQuizEdit->setReadOnly(true);
        redSquareEdit = new QLineEdit(groupBox);
        redSquareEdit->setObjectName(QString::fromUtf8("redSquareEdit"));
        redSquareEdit->setGeometry(QRect(10, 140, 61, 20));
        redSquareEdit->setReadOnly(true);
        spaceBubbleEdit = new QLineEdit(groupBox);
        spaceBubbleEdit->setObjectName(QString::fromUtf8("spaceBubbleEdit"));
        spaceBubbleEdit->setGeometry(QRect(10, 190, 61, 20));
        spaceBubbleEdit->setReadOnly(true);
        towerDefenseEdit = new QLineEdit(groupBox);
        towerDefenseEdit->setObjectName(QString::fromUtf8("towerDefenseEdit"));
        towerDefenseEdit->setGeometry(QRect(10, 240, 61, 20));
        towerDefenseEdit->setReadOnly(true);
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(180, 0, 81, 271));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 20, 101, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 70, 101, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 120, 91, 16));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 170, 91, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 220, 81, 16));
        pong2Edit3 = new QLineEdit(groupBox_2);
        pong2Edit3->setObjectName(QString::fromUtf8("pong2Edit3"));
        pong2Edit3->setGeometry(QRect(10, 40, 61, 20));
        pong2Edit3->setReadOnly(true);
        bibleQuizEdit3 = new QLineEdit(groupBox_2);
        bibleQuizEdit3->setObjectName(QString::fromUtf8("bibleQuizEdit3"));
        bibleQuizEdit3->setGeometry(QRect(10, 90, 61, 20));
        bibleQuizEdit3->setReadOnly(true);
        redSquareEdit3 = new QLineEdit(groupBox_2);
        redSquareEdit3->setObjectName(QString::fromUtf8("redSquareEdit3"));
        redSquareEdit3->setGeometry(QRect(10, 140, 61, 20));
        redSquareEdit3->setReadOnly(true);
        spaceBubbleEdit3 = new QLineEdit(groupBox_2);
        spaceBubbleEdit3->setObjectName(QString::fromUtf8("spaceBubbleEdit3"));
        spaceBubbleEdit3->setGeometry(QRect(10, 190, 61, 20));
        spaceBubbleEdit3->setReadOnly(true);
        towerDefenseEdit3 = new QLineEdit(groupBox_2);
        towerDefenseEdit3->setObjectName(QString::fromUtf8("towerDefenseEdit3"));
        towerDefenseEdit3->setGeometry(QRect(10, 240, 61, 20));
        towerDefenseEdit3->setReadOnly(true);
        groupBox_4 = new QGroupBox(page);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(270, 0, 81, 271));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 71, 16));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 70, 71, 16));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 120, 71, 16));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 170, 71, 16));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 220, 71, 16));
        pong2Edit4 = new QLineEdit(groupBox_4);
        pong2Edit4->setObjectName(QString::fromUtf8("pong2Edit4"));
        pong2Edit4->setGeometry(QRect(10, 40, 61, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pong2Edit4->setFont(font);
        pong2Edit4->setReadOnly(true);
        bibleQuizEdit4 = new QLineEdit(groupBox_4);
        bibleQuizEdit4->setObjectName(QString::fromUtf8("bibleQuizEdit4"));
        bibleQuizEdit4->setGeometry(QRect(10, 90, 61, 20));
        bibleQuizEdit4->setFont(font);
        bibleQuizEdit4->setReadOnly(true);
        redSquareEdit4 = new QLineEdit(groupBox_4);
        redSquareEdit4->setObjectName(QString::fromUtf8("redSquareEdit4"));
        redSquareEdit4->setGeometry(QRect(10, 140, 61, 20));
        redSquareEdit4->setFont(font);
        redSquareEdit4->setReadOnly(true);
        spaceBubbleEdit4 = new QLineEdit(groupBox_4);
        spaceBubbleEdit4->setObjectName(QString::fromUtf8("spaceBubbleEdit4"));
        spaceBubbleEdit4->setGeometry(QRect(10, 190, 61, 20));
        spaceBubbleEdit4->setFont(font);
        spaceBubbleEdit4->setReadOnly(true);
        towerDefenseEdit4 = new QLineEdit(groupBox_4);
        towerDefenseEdit4->setObjectName(QString::fromUtf8("towerDefenseEdit4"));
        towerDefenseEdit4->setGeometry(QRect(10, 240, 61, 20));
        towerDefenseEdit4->setFont(font);
        towerDefenseEdit4->setReadOnly(true);
        groupBox_5 = new QGroupBox(page);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 280, 351, 51));
        totals = new QLineEdit(groupBox_5);
        totals->setObjectName(QString::fromUtf8("totals"));
        totals->setGeometry(QRect(10, 20, 61, 20));
        totals->setFont(font);
        totals->setReadOnly(true);
        totals2 = new QLineEdit(groupBox_5);
        totals2->setObjectName(QString::fromUtf8("totals2"));
        totals2->setGeometry(QRect(100, 20, 61, 20));
        totals2->setFont(font);
        totals2->setReadOnly(true);
        totals3 = new QLineEdit(groupBox_5);
        totals3->setObjectName(QString::fromUtf8("totals3"));
        totals3->setGeometry(QRect(190, 20, 61, 20));
        totals3->setFont(font);
        totals3->setReadOnly(true);
        totals4 = new QLineEdit(groupBox_5);
        totals4->setObjectName(QString::fromUtf8("totals4"));
        totals4->setGeometry(QRect(280, 20, 61, 20));
        totals4->setFont(font);
        totals4->setReadOnly(true);
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(90, 0, 81, 271));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 79, 13));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 70, 79, 13));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 120, 79, 13));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 170, 79, 13));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 220, 79, 13));
        pong2Edit2 = new QLineEdit(groupBox_3);
        pong2Edit2->setObjectName(QString::fromUtf8("pong2Edit2"));
        pong2Edit2->setGeometry(QRect(10, 40, 61, 20));
        pong2Edit2->setReadOnly(true);
        bibleQuizEdit2 = new QLineEdit(groupBox_3);
        bibleQuizEdit2->setObjectName(QString::fromUtf8("bibleQuizEdit2"));
        bibleQuizEdit2->setGeometry(QRect(10, 90, 61, 20));
        bibleQuizEdit2->setReadOnly(true);
        redSquareEdit2 = new QLineEdit(groupBox_3);
        redSquareEdit2->setObjectName(QString::fromUtf8("redSquareEdit2"));
        redSquareEdit2->setGeometry(QRect(10, 140, 61, 20));
        redSquareEdit2->setReadOnly(true);
        spaceBubbleEdit2 = new QLineEdit(groupBox_3);
        spaceBubbleEdit2->setObjectName(QString::fromUtf8("spaceBubbleEdit2"));
        spaceBubbleEdit2->setGeometry(QRect(10, 190, 61, 20));
        spaceBubbleEdit2->setReadOnly(true);
        towerDefenseEdit2 = new QLineEdit(groupBox_3);
        towerDefenseEdit2->setObjectName(QString::fromUtf8("towerDefenseEdit2"));
        towerDefenseEdit2->setGeometry(QRect(10, 240, 61, 20));
        towerDefenseEdit2->setReadOnly(true);
        toolBox->addItem(page, QString::fromUtf8("Wii Downloads"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 98, 28));
        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 131, 271));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 20, 79, 13));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 70, 101, 16));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 120, 111, 16));
        addressbookEdit1 = new QLineEdit(groupBox_6);
        addressbookEdit1->setObjectName(QString::fromUtf8("addressbookEdit1"));
        addressbookEdit1->setGeometry(QRect(10, 40, 111, 20));
        addressbookEdit1->setReadOnly(true);
        eventNotificationEdit1 = new QLineEdit(groupBox_6);
        eventNotificationEdit1->setObjectName(QString::fromUtf8("eventNotificationEdit1"));
        eventNotificationEdit1->setGeometry(QRect(10, 90, 111, 20));
        eventNotificationEdit1->setReadOnly(true);
        churchEdit1 = new QLineEdit(groupBox_6);
        churchEdit1->setObjectName(QString::fromUtf8("churchEdit1"));
        churchEdit1->setGeometry(QRect(10, 140, 111, 20));
        churchEdit1->setReadOnly(true);
        groupBox_7 = new QGroupBox(page_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 280, 131, 51));
        totalsDrupalEdit1 = new QLineEdit(groupBox_7);
        totalsDrupalEdit1->setObjectName(QString::fromUtf8("totalsDrupalEdit1"));
        totalsDrupalEdit1->setGeometry(QRect(10, 20, 111, 20));
        totalsDrupalEdit1->setFont(font);
        totalsDrupalEdit1->setReadOnly(true);
        toolBox->addItem(page_2, QString::fromUtf8("Drupal Downloads"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 368, 20));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(pong2Edit, pong2Edit2);
        QWidget::setTabOrder(pong2Edit2, pong2Edit3);
        QWidget::setTabOrder(pong2Edit3, pong2Edit4);
        QWidget::setTabOrder(pong2Edit4, bibleQuizEdit);
        QWidget::setTabOrder(bibleQuizEdit, bibleQuizEdit2);
        QWidget::setTabOrder(bibleQuizEdit2, bibleQuizEdit3);
        QWidget::setTabOrder(bibleQuizEdit3, bibleQuizEdit4);
        QWidget::setTabOrder(bibleQuizEdit4, redSquareEdit);
        QWidget::setTabOrder(redSquareEdit, redSquareEdit2);
        QWidget::setTabOrder(redSquareEdit2, redSquareEdit3);
        QWidget::setTabOrder(redSquareEdit3, redSquareEdit4);
        QWidget::setTabOrder(redSquareEdit4, spaceBubbleEdit);
        QWidget::setTabOrder(spaceBubbleEdit, spaceBubbleEdit2);
        QWidget::setTabOrder(spaceBubbleEdit2, spaceBubbleEdit3);
        QWidget::setTabOrder(spaceBubbleEdit3, spaceBubbleEdit4);
        QWidget::setTabOrder(spaceBubbleEdit4, towerDefenseEdit);
        QWidget::setTabOrder(towerDefenseEdit, towerDefenseEdit2);
        QWidget::setTabOrder(towerDefenseEdit2, towerDefenseEdit3);
        QWidget::setTabOrder(towerDefenseEdit3, towerDefenseEdit4);
        QWidget::setTabOrder(towerDefenseEdit4, totals);
        QWidget::setTabOrder(totals, totals2);
        QWidget::setTabOrder(totals2, totals3);
        QWidget::setTabOrder(totals3, totals4);
        QWidget::setTabOrder(totals4, addressbookEdit1);
        QWidget::setTabOrder(addressbookEdit1, eventNotificationEdit1);
        QWidget::setTabOrder(eventNotificationEdit1, churchEdit1);
        QWidget::setTabOrder(churchEdit1, totalsDrupalEdit1);

        menuBar->addAction(menuExit->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuExit->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionCheck_for_update);
        menuEdit->addAction(actionRefreshData);
        menuEdit->addAction(actionDataClipboard);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSettings);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionDataClipboard->setText(QApplication::translate("MainWindow", "Data to Clipboard", 0, QApplication::UnicodeUTF8));
        actionRefreshData->setText(QApplication::translate("MainWindow", "Refresh Data", 0, QApplication::UnicodeUTF8));
        actionCheck_for_update->setText(QApplication::translate("MainWindow", "Check for update...", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "PlaatSoft", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Pong2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "RedSquare", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "BibleQuiz", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "SpaceBubble", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "TowerDefense", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Google Code", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Pong2", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "BibleQuiz", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "RedSquare", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "SpaceBubble", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "TowerDefense", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Totals", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Pong2", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "BibleQuiz", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "RedSquare", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "SpaceBubble", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "TowerDefense", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Totals", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "CodeMii", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Pong2", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "BibleQuiz", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "RedSquare", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "SpaceBubble", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "TowerDefense", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Wii Downloads", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "PlaatSoft", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Addressbook", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Event Notification", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Church Administration", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Totals", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Drupal Downloads", 0, QApplication::UnicodeUTF8));
        menuExit->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Actions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
