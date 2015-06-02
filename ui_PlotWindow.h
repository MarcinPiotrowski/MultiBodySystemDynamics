/********************************************************************************
** Form generated from reading UI file 'PlotWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWINDOW_H
#define UI_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_PlotControls;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_TimeScaleLength;
    QCheckBox *checkBox_AutoscaleY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_MinY;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_MaxY;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QCustomPlot *Plot;

    void setupUi(QWidget *PlotWindow)
    {
        if (PlotWindow->objectName().isEmpty())
            PlotWindow->setObjectName(QStringLiteral("PlotWindow"));
        PlotWindow->resize(893, 456);
        horizontalLayout = new QHBoxLayout(PlotWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_PlotControls = new QGroupBox(PlotWindow);
        groupBox_PlotControls->setObjectName(QStringLiteral("groupBox_PlotControls"));
        groupBox_PlotControls->setMaximumSize(QSize(200, 16777215));
        groupBox_PlotControls->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox_PlotControls);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        comboBox = new QComboBox(groupBox_PlotControls);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);

        comboBox_2 = new QComboBox(groupBox_PlotControls);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_5->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        comboBox_3 = new QComboBox(groupBox_PlotControls);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);
        comboBox_3->setMinimumSize(QSize(80, 0));

        horizontalLayout_6->addWidget(comboBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_6);

        groupBox = new QGroupBox(groupBox_PlotControls);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_TimeScaleLength = new QLineEdit(groupBox);
        lineEdit_TimeScaleLength->setObjectName(QStringLiteral("lineEdit_TimeScaleLength"));

        horizontalLayout_2->addWidget(lineEdit_TimeScaleLength);


        verticalLayout_2->addLayout(horizontalLayout_2);

        checkBox_AutoscaleY = new QCheckBox(groupBox);
        checkBox_AutoscaleY->setObjectName(QStringLiteral("checkBox_AutoscaleY"));

        verticalLayout_2->addWidget(checkBox_AutoscaleY);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_MinY = new QLineEdit(groupBox);
        lineEdit_MinY->setObjectName(QStringLiteral("lineEdit_MinY"));
        sizePolicy.setHeightForWidth(lineEdit_MinY->sizePolicy().hasHeightForWidth());
        lineEdit_MinY->setSizePolicy(sizePolicy);
        lineEdit_MinY->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(lineEdit_MinY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_MaxY = new QLineEdit(groupBox);
        lineEdit_MaxY->setObjectName(QStringLiteral("lineEdit_MaxY"));
        sizePolicy.setHeightForWidth(lineEdit_MaxY->sizePolicy().hasHeightForWidth());
        lineEdit_MaxY->setSizePolicy(sizePolicy);
        lineEdit_MaxY->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(lineEdit_MaxY);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox_PlotControls);

        Plot = new QCustomPlot(PlotWindow);
        Plot->setObjectName(QStringLiteral("Plot"));

        horizontalLayout->addWidget(Plot);


        retranslateUi(PlotWindow);

        QMetaObject::connectSlotsByName(PlotWindow);
    } // setupUi

    void retranslateUi(QWidget *PlotWindow)
    {
        PlotWindow->setWindowTitle(QApplication::translate("PlotWindow", "Form", 0));
        groupBox_PlotControls->setTitle(QApplication::translate("PlotWindow", "Plot Controls", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PlotWindow", "Joint Position", 0)
         << QApplication::translate("PlotWindow", "Joint Velocity", 0)
         << QApplication::translate("PlotWindow", "Joint Acceleration", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("PlotWindow", "1", 0)
         << QApplication::translate("PlotWindow", "2", 0)
         << QApplication::translate("PlotWindow", "3", 0)
         << QApplication::translate("PlotWindow", "4", 0)
         << QApplication::translate("PlotWindow", "5", 0)
         << QApplication::translate("PlotWindow", "6", 0)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("PlotWindow", "Strip chart", 0)
         << QApplication::translate("PlotWindow", "Scope chart", 0)
        );
        groupBox->setTitle(QApplication::translate("PlotWindow", "Scales", 0));
        label_3->setText(QApplication::translate("PlotWindow", "Time scale length", 0));
        checkBox_AutoscaleY->setText(QApplication::translate("PlotWindow", "Autoscale Y", 0));
        label->setText(QApplication::translate("PlotWindow", "Min", 0));
        label_2->setText(QApplication::translate("PlotWindow", "Max", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotWindow: public Ui_PlotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWINDOW_H
