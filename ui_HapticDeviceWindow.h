/********************************************************************************
** Form generated from reading UI file 'HapticDeviceWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAPTICDEVICEWINDOW_H
#define UI_HAPTICDEVICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
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

class Ui_HapticDeviceWindow
{
public:
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_Device_1;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_MaxForce_1;
    QLineEdit *lineEdit_MaxForce_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_PointerSize_1;
    QSlider *horizontalSlider_PointerSize_1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_1;
    QLabel *label_Status_1;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Cancel_1;
    QPushButton *pushButton_Accept_1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Disconnected_1;
    QPushButton *pushButton_Connected_1;
    QGroupBox *groupBox_Device_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_MaxForce_2;
    QLineEdit *lineEdit_MaxForce_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_PointerSize_2;
    QSlider *horizontalSlider_PointerSize_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label_Status_2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Cancel_2;
    QPushButton *pushButton_Accept_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Disconnected_2;
    QPushButton *pushButton_Connected_2;

    void setupUi(QWidget *HapticDeviceWindow)
    {
        if (HapticDeviceWindow->objectName().isEmpty())
            HapticDeviceWindow->setObjectName(QStringLiteral("HapticDeviceWindow"));
        HapticDeviceWindow->resize(427, 178);
        horizontalLayout_11 = new QHBoxLayout(HapticDeviceWindow);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox_Device_1 = new QGroupBox(HapticDeviceWindow);
        groupBox_Device_1->setObjectName(QStringLiteral("groupBox_Device_1"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_Device_1);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_MaxForce_1 = new QLabel(groupBox_Device_1);
        label_MaxForce_1->setObjectName(QStringLiteral("label_MaxForce_1"));

        horizontalLayout->addWidget(label_MaxForce_1);

        lineEdit_MaxForce_1 = new QLineEdit(groupBox_Device_1);
        lineEdit_MaxForce_1->setObjectName(QStringLiteral("lineEdit_MaxForce_1"));

        horizontalLayout->addWidget(lineEdit_MaxForce_1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_PointerSize_1 = new QLabel(groupBox_Device_1);
        label_PointerSize_1->setObjectName(QStringLiteral("label_PointerSize_1"));

        horizontalLayout_2->addWidget(label_PointerSize_1);

        horizontalSlider_PointerSize_1 = new QSlider(groupBox_Device_1);
        horizontalSlider_PointerSize_1->setObjectName(QStringLiteral("horizontalSlider_PointerSize_1"));
        horizontalSlider_PointerSize_1->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_PointerSize_1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_1 = new QLabel(groupBox_Device_1);
        label_1->setObjectName(QStringLiteral("label_1"));

        horizontalLayout_7->addWidget(label_1);

        label_Status_1 = new QLabel(groupBox_Device_1);
        label_Status_1->setObjectName(QStringLiteral("label_Status_1"));

        horizontalLayout_7->addWidget(label_Status_1);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        pushButton_Cancel_1 = new QPushButton(groupBox_Device_1);
        pushButton_Cancel_1->setObjectName(QStringLiteral("pushButton_Cancel_1"));

        horizontalLayout_12->addWidget(pushButton_Cancel_1);

        pushButton_Accept_1 = new QPushButton(groupBox_Device_1);
        pushButton_Accept_1->setObjectName(QStringLiteral("pushButton_Accept_1"));

        horizontalLayout_12->addWidget(pushButton_Accept_1);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_Disconnected_1 = new QPushButton(groupBox_Device_1);
        pushButton_Disconnected_1->setObjectName(QStringLiteral("pushButton_Disconnected_1"));

        horizontalLayout_3->addWidget(pushButton_Disconnected_1);

        pushButton_Connected_1 = new QPushButton(groupBox_Device_1);
        pushButton_Connected_1->setObjectName(QStringLiteral("pushButton_Connected_1"));

        horizontalLayout_3->addWidget(pushButton_Connected_1);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_9->addLayout(verticalLayout);


        horizontalLayout_11->addWidget(groupBox_Device_1);

        groupBox_Device_2 = new QGroupBox(HapticDeviceWindow);
        groupBox_Device_2->setObjectName(QStringLiteral("groupBox_Device_2"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_Device_2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_MaxForce_2 = new QLabel(groupBox_Device_2);
        label_MaxForce_2->setObjectName(QStringLiteral("label_MaxForce_2"));

        horizontalLayout_4->addWidget(label_MaxForce_2);

        lineEdit_MaxForce_2 = new QLineEdit(groupBox_Device_2);
        lineEdit_MaxForce_2->setObjectName(QStringLiteral("lineEdit_MaxForce_2"));

        horizontalLayout_4->addWidget(lineEdit_MaxForce_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_PointerSize_2 = new QLabel(groupBox_Device_2);
        label_PointerSize_2->setObjectName(QStringLiteral("label_PointerSize_2"));

        horizontalLayout_5->addWidget(label_PointerSize_2);

        horizontalSlider_PointerSize_2 = new QSlider(groupBox_Device_2);
        horizontalSlider_PointerSize_2->setObjectName(QStringLiteral("horizontalSlider_PointerSize_2"));
        horizontalSlider_PointerSize_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_PointerSize_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(groupBox_Device_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_8->addWidget(label_2);

        label_Status_2 = new QLabel(groupBox_Device_2);
        label_Status_2->setObjectName(QStringLiteral("label_Status_2"));

        horizontalLayout_8->addWidget(label_Status_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);

        pushButton_Cancel_2 = new QPushButton(groupBox_Device_2);
        pushButton_Cancel_2->setObjectName(QStringLiteral("pushButton_Cancel_2"));

        horizontalLayout_13->addWidget(pushButton_Cancel_2);

        pushButton_Accept_2 = new QPushButton(groupBox_Device_2);
        pushButton_Accept_2->setObjectName(QStringLiteral("pushButton_Accept_2"));

        horizontalLayout_13->addWidget(pushButton_Accept_2);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButton_Disconnected_2 = new QPushButton(groupBox_Device_2);
        pushButton_Disconnected_2->setObjectName(QStringLiteral("pushButton_Disconnected_2"));

        horizontalLayout_6->addWidget(pushButton_Disconnected_2);

        pushButton_Connected_2 = new QPushButton(groupBox_Device_2);
        pushButton_Connected_2->setObjectName(QStringLiteral("pushButton_Connected_2"));

        horizontalLayout_6->addWidget(pushButton_Connected_2);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_10->addLayout(verticalLayout_2);


        horizontalLayout_11->addWidget(groupBox_Device_2);


        retranslateUi(HapticDeviceWindow);

        QMetaObject::connectSlotsByName(HapticDeviceWindow);
    } // setupUi

    void retranslateUi(QWidget *HapticDeviceWindow)
    {
        HapticDeviceWindow->setWindowTitle(QApplication::translate("HapticDeviceWindow", "Form", 0));
        groupBox_Device_1->setTitle(QApplication::translate("HapticDeviceWindow", "Device 1", 0));
        label_MaxForce_1->setText(QApplication::translate("HapticDeviceWindow", "Max Force", 0));
        label_PointerSize_1->setText(QApplication::translate("HapticDeviceWindow", "Pointer Size", 0));
        label_1->setText(QApplication::translate("HapticDeviceWindow", "Status:", 0));
        label_Status_1->setText(QApplication::translate("HapticDeviceWindow", "Disconnected", 0));
        pushButton_Cancel_1->setText(QApplication::translate("HapticDeviceWindow", "Cancel", 0));
        pushButton_Accept_1->setText(QApplication::translate("HapticDeviceWindow", "Accept", 0));
        pushButton_Disconnected_1->setText(QApplication::translate("HapticDeviceWindow", "Disconnect", 0));
        pushButton_Connected_1->setText(QApplication::translate("HapticDeviceWindow", "Connect", 0));
        groupBox_Device_2->setTitle(QApplication::translate("HapticDeviceWindow", "Device 2", 0));
        label_MaxForce_2->setText(QApplication::translate("HapticDeviceWindow", "Max Force", 0));
        label_PointerSize_2->setText(QApplication::translate("HapticDeviceWindow", "Pointer Size", 0));
        label_2->setText(QApplication::translate("HapticDeviceWindow", "Status:", 0));
        label_Status_2->setText(QApplication::translate("HapticDeviceWindow", "Disconnected", 0));
        pushButton_Cancel_2->setText(QApplication::translate("HapticDeviceWindow", "Cancel", 0));
        pushButton_Accept_2->setText(QApplication::translate("HapticDeviceWindow", "Accept", 0));
        pushButton_Disconnected_2->setText(QApplication::translate("HapticDeviceWindow", "Disconnect", 0));
        pushButton_Connected_2->setText(QApplication::translate("HapticDeviceWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class HapticDeviceWindow: public Ui_HapticDeviceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAPTICDEVICEWINDOW_H
