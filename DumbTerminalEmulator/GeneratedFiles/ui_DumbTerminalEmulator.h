/********************************************************************************
** Form generated from reading UI file 'DumbTerminalEmulator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DumbTerminalEmulatorClass)
    {
        if (DumbTerminalEmulatorClass->objectName().isEmpty())
            DumbTerminalEmulatorClass->setObjectName(QStringLiteral("DumbTerminalEmulatorClass"));
        DumbTerminalEmulatorClass->resize(589, 427);
        actionConnect = new QAction(DumbTerminalEmulatorClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        centralWidget = new QWidget(DumbTerminalEmulatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DumbTerminalEmulatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DumbTerminalEmulatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        DumbTerminalEmulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DumbTerminalEmulatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DumbTerminalEmulatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DumbTerminalEmulatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DumbTerminalEmulatorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionConnect);

        retranslateUi(DumbTerminalEmulatorClass);

        QMetaObject::connectSlotsByName(DumbTerminalEmulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *DumbTerminalEmulatorClass)
    {
        DumbTerminalEmulatorClass->setWindowTitle(QApplication::translate("DumbTerminalEmulatorClass", "DumbTerminalEmulator", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("DumbTerminalEmulatorClass", "Connect", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("DumbTerminalEmulatorClass", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DumbTerminalEmulatorClass: public Ui_DumbTerminalEmulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMBTERMINALEMULATOR_H
