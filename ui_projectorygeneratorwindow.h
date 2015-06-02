/********************************************************************************
** Form generated from reading UI file 'projectorygeneratorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTORYGENERATORWINDOW_H
#define UI_PROJECTORYGENERATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectoryGeneratorWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tablePrograms;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableProgramData;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;

    void setupUi(QWidget *ProjectoryGeneratorWindow)
    {
        if (ProjectoryGeneratorWindow->objectName().isEmpty())
            ProjectoryGeneratorWindow->setObjectName(QStringLiteral("ProjectoryGeneratorWindow"));
        ProjectoryGeneratorWindow->resize(1100, 464);
        layoutWidget = new QWidget(ProjectoryGeneratorWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 379, 285, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        label = new QLabel(ProjectoryGeneratorWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 45, 16));
        label_2 = new QLabel(ProjectoryGeneratorWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(223, 11, 65, 16));
        scrollArea = new QScrollArea(ProjectoryGeneratorWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(11, 30, 150, 212));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(100, 85));
        scrollArea->setMaximumSize(QSize(150, 1000));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 148, 210));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tablePrograms = new QTableWidget(scrollAreaWidgetContents);
        tablePrograms->setObjectName(QStringLiteral("tablePrograms"));

        horizontalLayout_3->addWidget(tablePrograms);

        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(ProjectoryGeneratorWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 248, 204, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        scrollArea_2 = new QScrollArea(ProjectoryGeneratorWindow);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(223, 30, 871, 271));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 869, 269));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableProgramData = new QTableWidget(scrollAreaWidgetContents_3);
        tableProgramData->setObjectName(QStringLiteral("tableProgramData"));

        verticalLayout_3->addWidget(tableProgramData);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        widget1 = new QWidget(ProjectoryGeneratorWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(220, 330, 204, 25));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_7 = new QPushButton(widget1);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_4->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(widget1);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_4->addWidget(pushButton_6);

        layoutWidget->raise();
        label->raise();
        label_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        scrollArea_2->raise();

        retranslateUi(ProjectoryGeneratorWindow);

        QMetaObject::connectSlotsByName(ProjectoryGeneratorWindow);
    } // setupUi

    void retranslateUi(QWidget *ProjectoryGeneratorWindow)
    {
        ProjectoryGeneratorWindow->setWindowTitle(QApplication::translate("ProjectoryGeneratorWindow", "Form", 0));
        pushButton_2->setText(QApplication::translate("ProjectoryGeneratorWindow", "Cancel", 0));
        pushButton_3->setText(QApplication::translate("ProjectoryGeneratorWindow", "Accept", 0));
        pushButton->setText(QApplication::translate("ProjectoryGeneratorWindow", "OK", 0));
        label->setText(QApplication::translate("ProjectoryGeneratorWindow", "Programs", 0));
        label_2->setText(QApplication::translate("ProjectoryGeneratorWindow", "Program data", 0));
        pushButton_5->setText(QApplication::translate("ProjectoryGeneratorWindow", "Delete", 0));
        pushButton_4->setText(QApplication::translate("ProjectoryGeneratorWindow", "Add", 0));
        pushButton_7->setText(QApplication::translate("ProjectoryGeneratorWindow", "Delete row", 0));
        pushButton_6->setText(QApplication::translate("ProjectoryGeneratorWindow", "Add row", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectoryGeneratorWindow: public Ui_ProjectoryGeneratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTORYGENERATORWINDOW_H
