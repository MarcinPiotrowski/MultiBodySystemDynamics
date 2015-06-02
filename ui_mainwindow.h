/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "grender.h"
#include "multibodysysteminfowidget.h"
#include "simulationwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOptions;
    QAction *actionExit;
    QAction *actionImport_ADAMS_model;
    QAction *actionImport_ADAMS_Pre_simulated_model;
    QAction *actionGenerate_ADAMS_Measure_Command;
    QAction *actionAbout_MBSD;
    QAction *actionHaptic_Devices_Support;
    QAction *actionSave_As;
    QAction *actionCreate_new_plot;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    MultibodySystemInfoWidget *MultibodyObjectsWidget;
    GRender *glWidget;
    simulationwidget *SimulationWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuHelp;
    QMenu *menuPlot;
    QMenu *menuAaaaaa;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1524, 841);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Res/MBSD_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionImport_ADAMS_model = new QAction(MainWindow);
        actionImport_ADAMS_model->setObjectName(QStringLiteral("actionImport_ADAMS_model"));
        actionImport_ADAMS_Pre_simulated_model = new QAction(MainWindow);
        actionImport_ADAMS_Pre_simulated_model->setObjectName(QStringLiteral("actionImport_ADAMS_Pre_simulated_model"));
        actionGenerate_ADAMS_Measure_Command = new QAction(MainWindow);
        actionGenerate_ADAMS_Measure_Command->setObjectName(QStringLiteral("actionGenerate_ADAMS_Measure_Command"));
        actionAbout_MBSD = new QAction(MainWindow);
        actionAbout_MBSD->setObjectName(QStringLiteral("actionAbout_MBSD"));
        actionHaptic_Devices_Support = new QAction(MainWindow);
        actionHaptic_Devices_Support->setObjectName(QStringLiteral("actionHaptic_Devices_Support"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionCreate_new_plot = new QAction(MainWindow);
        actionCreate_new_plot->setObjectName(QStringLiteral("actionCreate_new_plot"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MultibodyObjectsWidget = new MultibodySystemInfoWidget(centralWidget);
        MultibodyObjectsWidget->setObjectName(QStringLiteral("MultibodyObjectsWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MultibodyObjectsWidget->sizePolicy().hasHeightForWidth());
        MultibodyObjectsWidget->setSizePolicy(sizePolicy);
        MultibodyObjectsWidget->setMinimumSize(QSize(250, 0));
        MultibodyObjectsWidget->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(MultibodyObjectsWidget);

        glWidget = new GRender(centralWidget);
        glWidget->setObjectName(QStringLiteral("glWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(glWidget->sizePolicy().hasHeightForWidth());
        glWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(glWidget);

        SimulationWidget = new simulationwidget(centralWidget);
        SimulationWidget->setObjectName(QStringLiteral("SimulationWidget"));
        sizePolicy.setHeightForWidth(SimulationWidget->sizePolicy().hasHeightForWidth());
        SimulationWidget->setSizePolicy(sizePolicy);
        SimulationWidget->setMinimumSize(QSize(250, 0));
        SimulationWidget->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(SimulationWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1524, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuPlot = new QMenu(menuBar);
        menuPlot->setObjectName(QStringLiteral("menuPlot"));
        menuAaaaaa = new QMenu(menuBar);
        menuAaaaaa->setObjectName(QStringLiteral("menuAaaaaa"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuPlot->menuAction());
        menuBar->addAction(menuAaaaaa->menuAction());
        menuFile->addAction(actionImport_ADAMS_model);
        menuFile->addAction(actionImport_ADAMS_Pre_simulated_model);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuTools->addAction(actionGenerate_ADAMS_Measure_Command);
        menuTools->addAction(actionHaptic_Devices_Support);
        menuTools->addAction(actionOptions);
        menuHelp->addAction(actionAbout_MBSD);
        menuPlot->addAction(actionCreate_new_plot);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Multibody System Dynamics", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionImport_ADAMS_model->setText(QApplication::translate("MainWindow", "Import ADAMS model", 0));
        actionImport_ADAMS_Pre_simulated_model->setText(QApplication::translate("MainWindow", "Import ADAMS pre-simulated model", 0));
        actionGenerate_ADAMS_Measure_Command->setText(QApplication::translate("MainWindow", "Generate ADAMS Measure Command", 0));
        actionAbout_MBSD->setText(QApplication::translate("MainWindow", "About MBSD...", 0));
        actionHaptic_Devices_Support->setText(QApplication::translate("MainWindow", "Haptic Devices Support", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionCreate_new_plot->setText(QApplication::translate("MainWindow", "Create new plot", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuPlot->setTitle(QApplication::translate("MainWindow", "Plot", 0));
        menuAaaaaa->setTitle(QApplication::translate("MainWindow", "aaaaaa", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
