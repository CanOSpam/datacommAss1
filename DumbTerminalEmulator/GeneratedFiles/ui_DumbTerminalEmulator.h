/********************************************************************************
** Form generated from reading UI file 'DumbTerminalEmulator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUMBTERMINALEMULATOR_H
#define UI_DUMBTERMINALEMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DumbTerminalEmulatorClass
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *action1200;
    QAction *action2400;
    QAction *action4800;
    QAction *action9600;
    QAction *action19200;
    QAction *action38400;
    QAction *action57600;
    QAction *action115200;
    QAction *actionCom_1;
    QAction *actionCom_2;
    QAction *actionCom_3;
    QAction *actionCom_4;
    QAction *actionEven;
    QAction *actionOdd;
    QAction *actionNone;
    QAction *actionOneStop;
    QAction *actionOneAndAHalfStop;
    QAction *actionTwoStop;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuBaud_Rate;
    QMenu *menuCom_Port;
    QMenu *menuParity;
    QMenu *menuStop_Bits;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DumbTerminalEmulatorClass)
    {
        if (DumbTerminalEmulatorClass->objectName().isEmpty())
            DumbTerminalEmulatorClass->setObjectName(QStringLiteral("DumbTerminalEmulatorClass"));
        DumbTerminalEmulatorClass->resize(593, 427);
        actionConnect = new QAction(DumbTerminalEmulatorClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(DumbTerminalEmulatorClass);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        action1200 = new QAction(DumbTerminalEmulatorClass);
        action1200->setObjectName(QStringLiteral("action1200"));
        action1200->setCheckable(true);
        action2400 = new QAction(DumbTerminalEmulatorClass);
        action2400->setObjectName(QStringLiteral("action2400"));
        action2400->setCheckable(true);
        action4800 = new QAction(DumbTerminalEmulatorClass);
        action4800->setObjectName(QStringLiteral("action4800"));
        action4800->setCheckable(true);
        action9600 = new QAction(DumbTerminalEmulatorClass);
        action9600->setObjectName(QStringLiteral("action9600"));
        action9600->setCheckable(true);
        action19200 = new QAction(DumbTerminalEmulatorClass);
        action19200->setObjectName(QStringLiteral("action19200"));
        action19200->setCheckable(true);
        action38400 = new QAction(DumbTerminalEmulatorClass);
        action38400->setObjectName(QStringLiteral("action38400"));
        action38400->setCheckable(true);
        action57600 = new QAction(DumbTerminalEmulatorClass);
        action57600->setObjectName(QStringLiteral("action57600"));
        action57600->setCheckable(true);
        action115200 = new QAction(DumbTerminalEmulatorClass);
        action115200->setObjectName(QStringLiteral("action115200"));
        action115200->setCheckable(true);
        actionCom_1 = new QAction(DumbTerminalEmulatorClass);
        actionCom_1->setObjectName(QStringLiteral("actionCom_1"));
        actionCom_1->setCheckable(true);
        actionCom_2 = new QAction(DumbTerminalEmulatorClass);
        actionCom_2->setObjectName(QStringLiteral("actionCom_2"));
        actionCom_2->setCheckable(true);
        actionCom_3 = new QAction(DumbTerminalEmulatorClass);
        actionCom_3->setObjectName(QStringLiteral("actionCom_3"));
        actionCom_3->setCheckable(true);
        actionCom_4 = new QAction(DumbTerminalEmulatorClass);
        actionCom_4->setObjectName(QStringLiteral("actionCom_4"));
        actionCom_4->setCheckable(true);
        actionEven = new QAction(DumbTerminalEmulatorClass);
        actionEven->setObjectName(QStringLiteral("actionEven"));
        actionEven->setCheckable(true);
        actionOdd = new QAction(DumbTerminalEmulatorClass);
        actionOdd->setObjectName(QStringLiteral("actionOdd"));
        actionOdd->setCheckable(true);
        actionNone = new QAction(DumbTerminalEmulatorClass);
        actionNone->setObjectName(QStringLiteral("actionNone"));
        actionNone->setCheckable(true);
        actionOneStop = new QAction(DumbTerminalEmulatorClass);
        actionOneStop->setObjectName(QStringLiteral("actionOneStop"));
        actionOneStop->setCheckable(true);
        actionOneAndAHalfStop = new QAction(DumbTerminalEmulatorClass);
        actionOneAndAHalfStop->setObjectName(QStringLiteral("actionOneAndAHalfStop"));
        actionOneAndAHalfStop->setCheckable(true);
        actionTwoStop = new QAction(DumbTerminalEmulatorClass);
        actionTwoStop->setObjectName(QStringLiteral("actionTwoStop"));
        actionTwoStop->setCheckable(true);
        centralWidget = new QWidget(DumbTerminalEmulatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DumbTerminalEmulatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DumbTerminalEmulatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuBaud_Rate = new QMenu(menuOptions);
        menuBaud_Rate->setObjectName(QStringLiteral("menuBaud_Rate"));
        menuCom_Port = new QMenu(menuOptions);
        menuCom_Port->setObjectName(QStringLiteral("menuCom_Port"));
        menuParity = new QMenu(menuOptions);
        menuParity->setObjectName(QStringLiteral("menuParity"));
        menuStop_Bits = new QMenu(menuOptions);
        menuStop_Bits->setObjectName(QStringLiteral("menuStop_Bits"));
        DumbTerminalEmulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DumbTerminalEmulatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DumbTerminalEmulatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DumbTerminalEmulatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DumbTerminalEmulatorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionConnect);
        menuFile->addAction(actionDisconnect);
        menuOptions->addAction(menuBaud_Rate->menuAction());
        menuOptions->addAction(menuCom_Port->menuAction());
        menuOptions->addAction(menuParity->menuAction());
        menuOptions->addAction(menuStop_Bits->menuAction());
        menuBaud_Rate->addAction(action1200);
        menuBaud_Rate->addAction(action2400);
        menuBaud_Rate->addAction(action4800);
        menuBaud_Rate->addAction(action9600);
        menuBaud_Rate->addAction(action19200);
        menuBaud_Rate->addAction(action38400);
        menuBaud_Rate->addAction(action57600);
        menuBaud_Rate->addAction(action115200);
        menuCom_Port->addAction(actionCom_1);
        menuCom_Port->addAction(actionCom_2);
        menuCom_Port->addAction(actionCom_3);
        menuCom_Port->addAction(actionCom_4);
        menuParity->addAction(actionEven);
        menuParity->addAction(actionOdd);
        menuParity->addAction(actionNone);
        menuStop_Bits->addAction(actionOneStop);
        menuStop_Bits->addAction(actionOneAndAHalfStop);
        menuStop_Bits->addAction(actionTwoStop);

        retranslateUi(DumbTerminalEmulatorClass);

        QMetaObject::connectSlotsByName(DumbTerminalEmulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *DumbTerminalEmulatorClass)
    {
        DumbTerminalEmulatorClass->setWindowTitle(QApplication::translate("DumbTerminalEmulatorClass", "DumbTerminalEmulator", 0));
        actionConnect->setText(QApplication::translate("DumbTerminalEmulatorClass", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("DumbTerminalEmulatorClass", "Disconnect", 0));
        action1200->setText(QApplication::translate("DumbTerminalEmulatorClass", "1200", 0));
        action2400->setText(QApplication::translate("DumbTerminalEmulatorClass", "2400", 0));
        action4800->setText(QApplication::translate("DumbTerminalEmulatorClass", "4800", 0));
        action9600->setText(QApplication::translate("DumbTerminalEmulatorClass", "9600", 0));
        action19200->setText(QApplication::translate("DumbTerminalEmulatorClass", "19200", 0));
        action38400->setText(QApplication::translate("DumbTerminalEmulatorClass", "38400", 0));
        action57600->setText(QApplication::translate("DumbTerminalEmulatorClass", "57600", 0));
        action115200->setText(QApplication::translate("DumbTerminalEmulatorClass", "115200", 0));
        actionCom_1->setText(QApplication::translate("DumbTerminalEmulatorClass", "Com 1", 0));
        actionCom_2->setText(QApplication::translate("DumbTerminalEmulatorClass", "Com 2", 0));
        actionCom_3->setText(QApplication::translate("DumbTerminalEmulatorClass", "Com 3", 0));
        actionCom_4->setText(QApplication::translate("DumbTerminalEmulatorClass", "Com 4", 0));
        actionEven->setText(QApplication::translate("DumbTerminalEmulatorClass", "Even", 0));
        actionOdd->setText(QApplication::translate("DumbTerminalEmulatorClass", "Odd", 0));
        actionNone->setText(QApplication::translate("DumbTerminalEmulatorClass", "None", 0));
        actionOneStop->setText(QApplication::translate("DumbTerminalEmulatorClass", "1 Stop", 0));
        actionOneAndAHalfStop->setText(QApplication::translate("DumbTerminalEmulatorClass", "1.5 Stop", 0));
        actionTwoStop->setText(QApplication::translate("DumbTerminalEmulatorClass", "2 Stop", 0));
        menuFile->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Connections", 0));
        menuOptions->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Options", 0));
        menuBaud_Rate->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Baud Rate", 0));
        menuCom_Port->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Com Port", 0));
        menuParity->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Parity", 0));
        menuStop_Bits->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Stop Bits", 0));
    } // retranslateUi

};

namespace Ui {
    class DumbTerminalEmulatorClass: public Ui_DumbTerminalEmulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMBTERMINALEMULATOR_H
