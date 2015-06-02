/********************************************************************************
** Form generated from reading UI file 'multibodysysteminfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIBODYSYSTEMINFOWIDGET_H
#define UI_MULTIBODYSYSTEMINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultibodySystemInfoWidget
{
public:
    QHBoxLayout *horizontalLayout_14;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_showDetails;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *_LabelMBSName;
    QLabel *_LabelNumberofJoints;
    QLabel *_LabelBaseProperties;
    QLabel *_LabelLinksProperties;
    QVBoxLayout *verticalLayout;
    QLabel *MBSName;
    QLabel *NumberOfJoints;
    QToolButton *toolButton_BaseProperties;
    QToolButton *toolButton_LinksProperties;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_showJointPositions;
    QLabel *label_jointPositions;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_JointsPositions;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableJointPositions;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_showJointVelocities;
    QLabel *label_jointVelocities;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_JointsVelocities;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableJointVelocities;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_showJointAccelerations;
    QLabel *label_jointAccelerations;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_JointAccelerations;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableJointAcceleration;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_showKineticEnergy;
    QLabel *label_KineticEnergy;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_KineticEnergy;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_12;
    QTableWidget *table_KineticEnergy;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_showPotentialEnergy;
    QLabel *label_PotentialEnergy;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_PotentialEnergy;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_13;
    QTableWidget *table_PotentialEnergy;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MultibodySystemInfoWidget)
    {
        if (MultibodySystemInfoWidget->objectName().isEmpty())
            MultibodySystemInfoWidget->setObjectName(QStringLiteral("MultibodySystemInfoWidget"));
        MultibodySystemInfoWidget->resize(268, 392);
        horizontalLayout_14 = new QHBoxLayout(MultibodySystemInfoWidget);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        scrollArea = new QScrollArea(MultibodySystemInfoWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 231, 891));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        verticalLayout_13 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_9->addWidget(comboBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_showDetails = new QPushButton(groupBox);
        pushButton_showDetails->setObjectName(QStringLiteral("pushButton_showDetails"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_showDetails->sizePolicy().hasHeightForWidth());
        pushButton_showDetails->setSizePolicy(sizePolicy1);
        pushButton_showDetails->setMinimumSize(QSize(16, 16));
        pushButton_showDetails->setMaximumSize(QSize(16, 16));
        QIcon icon;
        QString iconThemeName = QStringLiteral("5");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/Res/Images/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_showDetails->setIcon(icon);
        pushButton_showDetails->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_showDetails);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        _LabelMBSName = new QLabel(groupBox_2);
        _LabelMBSName->setObjectName(QStringLiteral("_LabelMBSName"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_LabelMBSName->sizePolicy().hasHeightForWidth());
        _LabelMBSName->setSizePolicy(sizePolicy2);
        _LabelMBSName->setMinimumSize(QSize(85, 0));
        _LabelMBSName->setMaximumSize(QSize(85, 16777215));

        verticalLayout_2->addWidget(_LabelMBSName);

        _LabelNumberofJoints = new QLabel(groupBox_2);
        _LabelNumberofJoints->setObjectName(QStringLiteral("_LabelNumberofJoints"));
        sizePolicy2.setHeightForWidth(_LabelNumberofJoints->sizePolicy().hasHeightForWidth());
        _LabelNumberofJoints->setSizePolicy(sizePolicy2);
        _LabelNumberofJoints->setMinimumSize(QSize(85, 0));
        _LabelNumberofJoints->setMaximumSize(QSize(85, 16777215));

        verticalLayout_2->addWidget(_LabelNumberofJoints);

        _LabelBaseProperties = new QLabel(groupBox_2);
        _LabelBaseProperties->setObjectName(QStringLiteral("_LabelBaseProperties"));
        sizePolicy2.setHeightForWidth(_LabelBaseProperties->sizePolicy().hasHeightForWidth());
        _LabelBaseProperties->setSizePolicy(sizePolicy2);
        _LabelBaseProperties->setMinimumSize(QSize(85, 0));
        _LabelBaseProperties->setMaximumSize(QSize(85, 16777215));

        verticalLayout_2->addWidget(_LabelBaseProperties);

        _LabelLinksProperties = new QLabel(groupBox_2);
        _LabelLinksProperties->setObjectName(QStringLiteral("_LabelLinksProperties"));
        sizePolicy2.setHeightForWidth(_LabelLinksProperties->sizePolicy().hasHeightForWidth());
        _LabelLinksProperties->setSizePolicy(sizePolicy2);
        _LabelLinksProperties->setMinimumSize(QSize(85, 0));
        _LabelLinksProperties->setMaximumSize(QSize(85, 16777215));

        verticalLayout_2->addWidget(_LabelLinksProperties);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        MBSName = new QLabel(groupBox_2);
        MBSName->setObjectName(QStringLiteral("MBSName"));
        sizePolicy2.setHeightForWidth(MBSName->sizePolicy().hasHeightForWidth());
        MBSName->setSizePolicy(sizePolicy2);
        MBSName->setMinimumSize(QSize(60, 0));
        MBSName->setMaximumSize(QSize(60, 16777215));

        verticalLayout->addWidget(MBSName);

        NumberOfJoints = new QLabel(groupBox_2);
        NumberOfJoints->setObjectName(QStringLiteral("NumberOfJoints"));

        verticalLayout->addWidget(NumberOfJoints);

        toolButton_BaseProperties = new QToolButton(groupBox_2);
        toolButton_BaseProperties->setObjectName(QStringLiteral("toolButton_BaseProperties"));
        sizePolicy1.setHeightForWidth(toolButton_BaseProperties->sizePolicy().hasHeightForWidth());
        toolButton_BaseProperties->setSizePolicy(sizePolicy1);
        toolButton_BaseProperties->setMinimumSize(QSize(20, 15));
        toolButton_BaseProperties->setMaximumSize(QSize(10, 15));

        verticalLayout->addWidget(toolButton_BaseProperties);

        toolButton_LinksProperties = new QToolButton(groupBox_2);
        toolButton_LinksProperties->setObjectName(QStringLiteral("toolButton_LinksProperties"));
        sizePolicy1.setHeightForWidth(toolButton_LinksProperties->sizePolicy().hasHeightForWidth());
        toolButton_LinksProperties->setSizePolicy(sizePolicy1);
        toolButton_LinksProperties->setMinimumSize(QSize(20, 15));
        toolButton_LinksProperties->setMaximumSize(QSize(20, 20));

        verticalLayout->addWidget(toolButton_LinksProperties);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_showJointPositions = new QPushButton(groupBox);
        pushButton_showJointPositions->setObjectName(QStringLiteral("pushButton_showJointPositions"));
        sizePolicy1.setHeightForWidth(pushButton_showJointPositions->sizePolicy().hasHeightForWidth());
        pushButton_showJointPositions->setSizePolicy(sizePolicy1);
        pushButton_showJointPositions->setMinimumSize(QSize(16, 16));
        pushButton_showJointPositions->setMaximumSize(QSize(16, 16));
        pushButton_showJointPositions->setIcon(icon);
        pushButton_showJointPositions->setFlat(true);

        horizontalLayout_6->addWidget(pushButton_showJointPositions);

        label_jointPositions = new QLabel(groupBox);
        label_jointPositions->setObjectName(QStringLiteral("label_jointPositions"));

        horizontalLayout_6->addWidget(label_jointPositions);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_6);

        groupBox_JointsPositions = new QGroupBox(groupBox);
        groupBox_JointsPositions->setObjectName(QStringLiteral("groupBox_JointsPositions"));
        verticalLayout_10 = new QVBoxLayout(groupBox_JointsPositions);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_10->addLayout(horizontalLayout_3);

        tableJointPositions = new QTableWidget(groupBox_JointsPositions);
        tableJointPositions->setObjectName(QStringLiteral("tableJointPositions"));
        sizePolicy1.setHeightForWidth(tableJointPositions->sizePolicy().hasHeightForWidth());
        tableJointPositions->setSizePolicy(sizePolicy1);
        tableJointPositions->setMinimumSize(QSize(140, 0));
        tableJointPositions->setMaximumSize(QSize(140, 16777215));

        verticalLayout_10->addWidget(tableJointPositions);


        verticalLayout_9->addWidget(groupBox_JointsPositions);


        verticalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_showJointVelocities = new QPushButton(groupBox);
        pushButton_showJointVelocities->setObjectName(QStringLiteral("pushButton_showJointVelocities"));
        sizePolicy1.setHeightForWidth(pushButton_showJointVelocities->sizePolicy().hasHeightForWidth());
        pushButton_showJointVelocities->setSizePolicy(sizePolicy1);
        pushButton_showJointVelocities->setMinimumSize(QSize(16, 16));
        pushButton_showJointVelocities->setMaximumSize(QSize(16, 16));
        pushButton_showJointVelocities->setIcon(icon);
        pushButton_showJointVelocities->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_showJointVelocities);

        label_jointVelocities = new QLabel(groupBox);
        label_jointVelocities->setObjectName(QStringLiteral("label_jointVelocities"));

        horizontalLayout_7->addWidget(label_jointVelocities);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_11->addLayout(horizontalLayout_7);

        groupBox_JointsVelocities = new QGroupBox(groupBox);
        groupBox_JointsVelocities->setObjectName(QStringLiteral("groupBox_JointsVelocities"));
        verticalLayout_12 = new QVBoxLayout(groupBox_JointsVelocities);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_12->addLayout(horizontalLayout_8);

        tableJointVelocities = new QTableWidget(groupBox_JointsVelocities);
        tableJointVelocities->setObjectName(QStringLiteral("tableJointVelocities"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableJointVelocities->sizePolicy().hasHeightForWidth());
        tableJointVelocities->setSizePolicy(sizePolicy3);
        tableJointVelocities->setMinimumSize(QSize(120, 0));
        tableJointVelocities->setMaximumSize(QSize(120, 16777215));

        verticalLayout_12->addWidget(tableJointVelocities);


        verticalLayout_11->addWidget(groupBox_JointsVelocities);


        verticalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_showJointAccelerations = new QPushButton(groupBox);
        pushButton_showJointAccelerations->setObjectName(QStringLiteral("pushButton_showJointAccelerations"));
        sizePolicy1.setHeightForWidth(pushButton_showJointAccelerations->sizePolicy().hasHeightForWidth());
        pushButton_showJointAccelerations->setSizePolicy(sizePolicy1);
        pushButton_showJointAccelerations->setMinimumSize(QSize(16, 16));
        pushButton_showJointAccelerations->setMaximumSize(QSize(16, 16));
        pushButton_showJointAccelerations->setIcon(icon);
        pushButton_showJointAccelerations->setFlat(true);

        horizontalLayout_5->addWidget(pushButton_showJointAccelerations);

        label_jointAccelerations = new QLabel(groupBox);
        label_jointAccelerations->setObjectName(QStringLiteral("label_jointAccelerations"));

        horizontalLayout_5->addWidget(label_jointAccelerations);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        groupBox_JointAccelerations = new QGroupBox(groupBox);
        groupBox_JointAccelerations->setObjectName(QStringLiteral("groupBox_JointAccelerations"));
        verticalLayout_8 = new QVBoxLayout(groupBox_JointAccelerations);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout_8->addLayout(horizontalLayout_2);

        tableJointAcceleration = new QTableWidget(groupBox_JointAccelerations);
        tableJointAcceleration->setObjectName(QStringLiteral("tableJointAcceleration"));
        sizePolicy3.setHeightForWidth(tableJointAcceleration->sizePolicy().hasHeightForWidth());
        tableJointAcceleration->setSizePolicy(sizePolicy3);
        tableJointAcceleration->setMinimumSize(QSize(120, 0));
        tableJointAcceleration->setMaximumSize(QSize(120, 16777215));

        verticalLayout_8->addWidget(tableJointAcceleration);


        verticalLayout_7->addWidget(groupBox_JointAccelerations);


        verticalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_showKineticEnergy = new QPushButton(groupBox);
        pushButton_showKineticEnergy->setObjectName(QStringLiteral("pushButton_showKineticEnergy"));
        sizePolicy1.setHeightForWidth(pushButton_showKineticEnergy->sizePolicy().hasHeightForWidth());
        pushButton_showKineticEnergy->setSizePolicy(sizePolicy1);
        pushButton_showKineticEnergy->setMinimumSize(QSize(16, 16));
        pushButton_showKineticEnergy->setMaximumSize(QSize(16, 16));
        pushButton_showKineticEnergy->setIcon(icon);
        pushButton_showKineticEnergy->setFlat(true);

        horizontalLayout_10->addWidget(pushButton_showKineticEnergy);

        label_KineticEnergy = new QLabel(groupBox);
        label_KineticEnergy->setObjectName(QStringLiteral("label_KineticEnergy"));

        horizontalLayout_10->addWidget(label_KineticEnergy);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_17->addLayout(horizontalLayout_10);

        groupBox_KineticEnergy = new QGroupBox(groupBox);
        groupBox_KineticEnergy->setObjectName(QStringLiteral("groupBox_KineticEnergy"));
        verticalLayout_18 = new QVBoxLayout(groupBox_KineticEnergy);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));

        verticalLayout_18->addLayout(horizontalLayout_12);

        table_KineticEnergy = new QTableWidget(groupBox_KineticEnergy);
        table_KineticEnergy->setObjectName(QStringLiteral("table_KineticEnergy"));
        sizePolicy3.setHeightForWidth(table_KineticEnergy->sizePolicy().hasHeightForWidth());
        table_KineticEnergy->setSizePolicy(sizePolicy3);
        table_KineticEnergy->setMinimumSize(QSize(120, 0));
        table_KineticEnergy->setMaximumSize(QSize(120, 16777215));

        verticalLayout_18->addWidget(table_KineticEnergy);


        verticalLayout_17->addWidget(groupBox_KineticEnergy);


        verticalLayout_4->addLayout(verticalLayout_17);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton_showPotentialEnergy = new QPushButton(groupBox);
        pushButton_showPotentialEnergy->setObjectName(QStringLiteral("pushButton_showPotentialEnergy"));
        sizePolicy1.setHeightForWidth(pushButton_showPotentialEnergy->sizePolicy().hasHeightForWidth());
        pushButton_showPotentialEnergy->setSizePolicy(sizePolicy1);
        pushButton_showPotentialEnergy->setMinimumSize(QSize(16, 16));
        pushButton_showPotentialEnergy->setMaximumSize(QSize(16, 16));
        pushButton_showPotentialEnergy->setIcon(icon);
        pushButton_showPotentialEnergy->setFlat(true);

        horizontalLayout_11->addWidget(pushButton_showPotentialEnergy);

        label_PotentialEnergy = new QLabel(groupBox);
        label_PotentialEnergy->setObjectName(QStringLiteral("label_PotentialEnergy"));

        horizontalLayout_11->addWidget(label_PotentialEnergy);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);


        verticalLayout_19->addLayout(horizontalLayout_11);

        groupBox_PotentialEnergy = new QGroupBox(groupBox);
        groupBox_PotentialEnergy->setObjectName(QStringLiteral("groupBox_PotentialEnergy"));
        verticalLayout_20 = new QVBoxLayout(groupBox_PotentialEnergy);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));

        verticalLayout_20->addLayout(horizontalLayout_13);

        table_PotentialEnergy = new QTableWidget(groupBox_PotentialEnergy);
        table_PotentialEnergy->setObjectName(QStringLiteral("table_PotentialEnergy"));
        sizePolicy3.setHeightForWidth(table_PotentialEnergy->sizePolicy().hasHeightForWidth());
        table_PotentialEnergy->setSizePolicy(sizePolicy3);
        table_PotentialEnergy->setMinimumSize(QSize(120, 0));
        table_PotentialEnergy->setMaximumSize(QSize(120, 16777215));

        verticalLayout_20->addWidget(table_PotentialEnergy);


        verticalLayout_19->addWidget(groupBox_PotentialEnergy);


        verticalLayout_4->addLayout(verticalLayout_19);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_13->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_14->addWidget(scrollArea);


        retranslateUi(MultibodySystemInfoWidget);

        QMetaObject::connectSlotsByName(MultibodySystemInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *MultibodySystemInfoWidget)
    {
        MultibodySystemInfoWidget->setWindowTitle(QApplication::translate("MultibodySystemInfoWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("MultibodySystemInfoWidget", "Model", 0));
        pushButton->setText(QApplication::translate("MultibodySystemInfoWidget", "Refresh", 0));
        pushButton_showDetails->setText(QString());
        label_3->setText(QApplication::translate("MultibodySystemInfoWidget", "Details", 0));
        groupBox_2->setTitle(QString());
        _LabelMBSName->setText(QApplication::translate("MultibodySystemInfoWidget", "System name:", 0));
        _LabelNumberofJoints->setText(QApplication::translate("MultibodySystemInfoWidget", "Number of Joints:", 0));
        _LabelBaseProperties->setText(QApplication::translate("MultibodySystemInfoWidget", "Base properties", 0));
        _LabelLinksProperties->setText(QApplication::translate("MultibodySystemInfoWidget", "Links properties", 0));
        MBSName->setText(QApplication::translate("MultibodySystemInfoWidget", "None", 0));
        NumberOfJoints->setText(QApplication::translate("MultibodySystemInfoWidget", "-", 0));
        toolButton_BaseProperties->setText(QApplication::translate("MultibodySystemInfoWidget", "...", 0));
        toolButton_LinksProperties->setText(QApplication::translate("MultibodySystemInfoWidget", "...", 0));
        pushButton_showJointPositions->setText(QString());
        label_jointPositions->setText(QApplication::translate("MultibodySystemInfoWidget", "Joints Positions", 0));
        groupBox_JointsPositions->setTitle(QString());
        pushButton_showJointVelocities->setText(QString());
        label_jointVelocities->setText(QApplication::translate("MultibodySystemInfoWidget", "Joints Velocities", 0));
        groupBox_JointsVelocities->setTitle(QString());
        pushButton_showJointAccelerations->setText(QString());
        label_jointAccelerations->setText(QApplication::translate("MultibodySystemInfoWidget", "Joints Accelerations", 0));
        groupBox_JointAccelerations->setTitle(QString());
        pushButton_showKineticEnergy->setText(QString());
        label_KineticEnergy->setText(QApplication::translate("MultibodySystemInfoWidget", "Kinetic Energy", 0));
        groupBox_KineticEnergy->setTitle(QString());
        pushButton_showPotentialEnergy->setText(QString());
        label_PotentialEnergy->setText(QApplication::translate("MultibodySystemInfoWidget", "Kinetic Energy", 0));
        groupBox_PotentialEnergy->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MultibodySystemInfoWidget: public Ui_MultibodySystemInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIBODYSYSTEMINFOWIDGET_H
