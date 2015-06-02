/********************************************************************************
** Form generated from reading UI file 'positioncontrolerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONCONTROLERWINDOW_H
#define UI_POSITIONCONTROLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PositionControlerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_13;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_A1_minus;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_A1_plus;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_A2_minus;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_A2_plus;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_A3_minus;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_A3_plus;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_A4_minus;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_A4_plus;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_A5_minus;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_A5_plus;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_A6_minus;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_A6_plus;

    void setupUi(QWidget *PositionControlerWindow)
    {
        if (PositionControlerWindow->objectName().isEmpty())
            PositionControlerWindow->setObjectName(QStringLiteral("PositionControlerWindow"));
        PositionControlerWindow->resize(235, 451);
        verticalLayout = new QVBoxLayout(PositionControlerWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(PositionControlerWindow);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font;
        font.setPointSize(13);
        comboBox->setFont(font);

        verticalLayout->addWidget(comboBox);

        comboBox_2 = new QComboBox(PositionControlerWindow);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setFont(font);

        verticalLayout->addWidget(comboBox_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(PositionControlerWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font1;
        font1.setPointSize(16);
        label_7->setFont(font1);

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        horizontalSlider = new QSlider(PositionControlerWindow);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimumSize(QSize(80, 0));
        horizontalSlider->setMaximumSize(QSize(80, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider);

        lineEdit = new QLineEdit(PositionControlerWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(40, 0));
        lineEdit->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_7->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PositionControlerWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton_A1_minus = new QPushButton(PositionControlerWindow);
        pushButton_A1_minus->setObjectName(QStringLiteral("pushButton_A1_minus"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_A1_minus->sizePolicy().hasHeightForWidth());
        pushButton_A1_minus->setSizePolicy(sizePolicy1);
        pushButton_A1_minus->setMinimumSize(QSize(50, 50));
        pushButton_A1_minus->setMaximumSize(QSize(50, 50));
        QFont font2;
        font2.setPointSize(26);
        pushButton_A1_minus->setFont(font2);

        horizontalLayout->addWidget(pushButton_A1_minus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_A1_plus = new QPushButton(PositionControlerWindow);
        pushButton_A1_plus->setObjectName(QStringLiteral("pushButton_A1_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A1_plus->sizePolicy().hasHeightForWidth());
        pushButton_A1_plus->setSizePolicy(sizePolicy1);
        pushButton_A1_plus->setMinimumSize(QSize(50, 50));
        pushButton_A1_plus->setMaximumSize(QSize(50, 50));
        QFont font3;
        font3.setPointSize(20);
        pushButton_A1_plus->setFont(font3);

        horizontalLayout->addWidget(pushButton_A1_plus);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(PositionControlerWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        pushButton_A2_minus = new QPushButton(PositionControlerWindow);
        pushButton_A2_minus->setObjectName(QStringLiteral("pushButton_A2_minus"));
        sizePolicy1.setHeightForWidth(pushButton_A2_minus->sizePolicy().hasHeightForWidth());
        pushButton_A2_minus->setSizePolicy(sizePolicy1);
        pushButton_A2_minus->setMinimumSize(QSize(50, 50));
        pushButton_A2_minus->setMaximumSize(QSize(50, 50));
        pushButton_A2_minus->setFont(font2);

        horizontalLayout_2->addWidget(pushButton_A2_minus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_A2_plus = new QPushButton(PositionControlerWindow);
        pushButton_A2_plus->setObjectName(QStringLiteral("pushButton_A2_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A2_plus->sizePolicy().hasHeightForWidth());
        pushButton_A2_plus->setSizePolicy(sizePolicy1);
        pushButton_A2_plus->setMinimumSize(QSize(50, 50));
        pushButton_A2_plus->setMaximumSize(QSize(50, 50));
        pushButton_A2_plus->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_A2_plus);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(PositionControlerWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButton_A3_minus = new QPushButton(PositionControlerWindow);
        pushButton_A3_minus->setObjectName(QStringLiteral("pushButton_A3_minus"));
        sizePolicy1.setHeightForWidth(pushButton_A3_minus->sizePolicy().hasHeightForWidth());
        pushButton_A3_minus->setSizePolicy(sizePolicy1);
        pushButton_A3_minus->setMinimumSize(QSize(50, 50));
        pushButton_A3_minus->setMaximumSize(QSize(50, 50));
        pushButton_A3_minus->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_A3_minus);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_A3_plus = new QPushButton(PositionControlerWindow);
        pushButton_A3_plus->setObjectName(QStringLiteral("pushButton_A3_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A3_plus->sizePolicy().hasHeightForWidth());
        pushButton_A3_plus->setSizePolicy(sizePolicy1);
        pushButton_A3_plus->setMinimumSize(QSize(50, 50));
        pushButton_A3_plus->setMaximumSize(QSize(50, 50));
        pushButton_A3_plus->setFont(font3);

        horizontalLayout_3->addWidget(pushButton_A3_plus);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(PositionControlerWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        pushButton_A4_minus = new QPushButton(PositionControlerWindow);
        pushButton_A4_minus->setObjectName(QStringLiteral("pushButton_A4_minus"));
        sizePolicy1.setHeightForWidth(pushButton_A4_minus->sizePolicy().hasHeightForWidth());
        pushButton_A4_minus->setSizePolicy(sizePolicy1);
        pushButton_A4_minus->setMinimumSize(QSize(50, 50));
        pushButton_A4_minus->setMaximumSize(QSize(50, 50));
        pushButton_A4_minus->setFont(font2);

        horizontalLayout_4->addWidget(pushButton_A4_minus);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_A4_plus = new QPushButton(PositionControlerWindow);
        pushButton_A4_plus->setObjectName(QStringLiteral("pushButton_A4_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A4_plus->sizePolicy().hasHeightForWidth());
        pushButton_A4_plus->setSizePolicy(sizePolicy1);
        pushButton_A4_plus->setMinimumSize(QSize(50, 50));
        pushButton_A4_plus->setMaximumSize(QSize(50, 50));
        pushButton_A4_plus->setFont(font3);

        horizontalLayout_4->addWidget(pushButton_A4_plus);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(PositionControlerWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        pushButton_A5_minus = new QPushButton(PositionControlerWindow);
        pushButton_A5_minus->setObjectName(QStringLiteral("pushButton_A5_minus"));
        sizePolicy1.setHeightForWidth(pushButton_A5_minus->sizePolicy().hasHeightForWidth());
        pushButton_A5_minus->setSizePolicy(sizePolicy1);
        pushButton_A5_minus->setMinimumSize(QSize(50, 50));
        pushButton_A5_minus->setMaximumSize(QSize(50, 50));
        pushButton_A5_minus->setFont(font2);

        horizontalLayout_5->addWidget(pushButton_A5_minus);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton_A5_plus = new QPushButton(PositionControlerWindow);
        pushButton_A5_plus->setObjectName(QStringLiteral("pushButton_A5_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A5_plus->sizePolicy().hasHeightForWidth());
        pushButton_A5_plus->setSizePolicy(sizePolicy1);
        pushButton_A5_plus->setMinimumSize(QSize(50, 50));
        pushButton_A5_plus->setMaximumSize(QSize(50, 50));
        pushButton_A5_plus->setFont(font3);

        horizontalLayout_5->addWidget(pushButton_A5_plus);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(PositionControlerWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        pushButton_A6_minus = new QPushButton(PositionControlerWindow);
        pushButton_A6_minus->setObjectName(QStringLiteral("pushButton_A6_minus"));
        sizePolicy1.setHeightForWidth(pushButton_A6_minus->sizePolicy().hasHeightForWidth());
        pushButton_A6_minus->setSizePolicy(sizePolicy1);
        pushButton_A6_minus->setMinimumSize(QSize(50, 50));
        pushButton_A6_minus->setMaximumSize(QSize(50, 50));
        pushButton_A6_minus->setFont(font2);

        horizontalLayout_6->addWidget(pushButton_A6_minus);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        pushButton_A6_plus = new QPushButton(PositionControlerWindow);
        pushButton_A6_plus->setObjectName(QStringLiteral("pushButton_A6_plus"));
        sizePolicy1.setHeightForWidth(pushButton_A6_plus->sizePolicy().hasHeightForWidth());
        pushButton_A6_plus->setSizePolicy(sizePolicy1);
        pushButton_A6_plus->setMinimumSize(QSize(50, 50));
        pushButton_A6_plus->setMaximumSize(QSize(50, 50));
        pushButton_A6_plus->setFont(font3);

        horizontalLayout_6->addWidget(pushButton_A6_plus);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(PositionControlerWindow);

        QMetaObject::connectSlotsByName(PositionControlerWindow);
    } // setupUi

    void retranslateUi(QWidget *PositionControlerWindow)
    {
        PositionControlerWindow->setWindowTitle(QApplication::translate("PositionControlerWindow", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PositionControlerWindow", "Strict control", 0)
         << QApplication::translate("PositionControlerWindow", "Simulation control", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("PositionControlerWindow", "Global Frame", 0)
        );
        label_7->setText(QApplication::translate("PositionControlerWindow", "Speed", 0));
        label->setText(QApplication::translate("PositionControlerWindow", "Axis 1", 0));
        pushButton_A1_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A1_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
        label_2->setText(QApplication::translate("PositionControlerWindow", "Axis 2", 0));
        pushButton_A2_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A2_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
        label_3->setText(QApplication::translate("PositionControlerWindow", "Axis 3", 0));
        pushButton_A3_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A3_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
        label_4->setText(QApplication::translate("PositionControlerWindow", "Axis 4", 0));
        pushButton_A4_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A4_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
        label_5->setText(QApplication::translate("PositionControlerWindow", "Axis 5", 0));
        pushButton_A5_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A5_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
        label_6->setText(QApplication::translate("PositionControlerWindow", "Axis 6", 0));
        pushButton_A6_minus->setText(QApplication::translate("PositionControlerWindow", "-", 0));
        pushButton_A6_plus->setText(QApplication::translate("PositionControlerWindow", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class PositionControlerWindow: public Ui_PositionControlerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONCONTROLERWINDOW_H
