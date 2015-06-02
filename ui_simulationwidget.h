/********************************************************************************
** Form generated from reading UI file 'simulationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONWIDGET_H
#define UI_SIMULATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simulationwidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_36;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *pushButton_showSimulation;
    QLabel *label_Simulation;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_Simulation;
    QVBoxLayout *verticalLayout_40;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_39;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_37;
    QLineEdit *lineEdit_StartTime;
    QLineEdit *lineEdit_EndTime;
    QLineEdit *lineEdit_Step;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_StartSimulation;
    QVBoxLayout *verticalLayout_41;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *pushButton_showRealTimeSimulation;
    QLabel *label_RealTimeSimulation;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *groupBox_RealTimeSimulation;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_11;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_15;
    QLineEdit *lineEdit_Speed;
    QLineEdit *lineEdit_RealTimeSimulationStep;
    QHBoxLayout *horizontalLayout_32;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButton_StartRealTimeSimulation;
    QPushButton *pushButton_StopRealTimeSimulation;
    QVBoxLayout *verticalLayout_38;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *pushButton_showTrajectorySimulation;
    QLabel *label_TrajectorySimulation;
    QSpacerItem *horizontalSpacer_17;
    QGroupBox *groupBox_TrajectorySimulation;
    QVBoxLayout *verticalLayout_42;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_23;
    QLineEdit *lineEdit_Speed_2;
    QLineEdit *lineEdit_RealTimeSimulationStep_2;
    QHBoxLayout *horizontalLayout_33;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *pushButton_StartTrajectorySimulationSimulation_3;
    QPushButton *pushButton_StartTrajectorySimulationSimulation_4;
    QHBoxLayout *horizontalLayout_31;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_StartTrajectorySimulationSimulation_2;
    QPushButton *pushButton_StartTrajectorySimulationSimulation;
    QVBoxLayout *verticalLayout_65;
    QHBoxLayout *horizontalLayout_51;
    QPushButton *pushButton_showPositionControl;
    QLabel *label_PositionControl;
    QSpacerItem *horizontalSpacer_40;
    QGroupBox *groupBox_PositionControl;
    QVBoxLayout *verticalLayout_66;
    QHBoxLayout *horizontalLayout_53;
    QSpacerItem *horizontalSpacer_41;
    QSpacerItem *horizontalSpacer_42;
    QPushButton *pushButton_OpenControlerWindow;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_43;
    QPushButton *pushButton_OpenControlerWindow_2;
    QVBoxLayout *verticalLayout_69;
    QHBoxLayout *horizontalLayout_55;
    QPushButton *pushButton_showHapticControl;
    QLabel *label_HapticControl;
    QSpacerItem *horizontalSpacer_46;
    QGroupBox *groupBox_HapticControl;
    QVBoxLayout *verticalLayout_70;
    QHBoxLayout *horizontalLayout_56;
    QSpacerItem *horizontalSpacer_47;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_43;
    QHBoxLayout *horizontalLayout_34;
    QPushButton *pushButton_showPostSimulation;
    QLabel *label_PostSimulation;
    QSpacerItem *horizontalSpacer_19;
    QGroupBox *groupBox_PostSimulation;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_15;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_22;
    QLineEdit *lineEdit_PostSimulationSpeed;
    QSlider *horizontalSlider_PostSimulationTime;
    QHBoxLayout *horizontalLayout_35;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_StartRealTimeSimulation_3;
    QPushButton *pushButton_StopRealTimeSimulation_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *simulationwidget)
    {
        if (simulationwidget->objectName().isEmpty())
            simulationwidget->setObjectName(QStringLiteral("simulationwidget"));
        simulationwidget->resize(264, 601);
        verticalLayout_5 = new QVBoxLayout(simulationwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scrollArea = new QScrollArea(simulationwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -207, 230, 834));
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
        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        pushButton_showSimulation = new QPushButton(groupBox);
        pushButton_showSimulation->setObjectName(QStringLiteral("pushButton_showSimulation"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_showSimulation->sizePolicy().hasHeightForWidth());
        pushButton_showSimulation->setSizePolicy(sizePolicy1);
        pushButton_showSimulation->setMinimumSize(QSize(16, 16));
        pushButton_showSimulation->setMaximumSize(QSize(16, 16));
        QIcon icon;
        QString iconThemeName = QStringLiteral("5");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/Res/Images/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_showSimulation->setIcon(icon);
        pushButton_showSimulation->setFlat(true);

        horizontalLayout_25->addWidget(pushButton_showSimulation);

        label_Simulation = new QLabel(groupBox);
        label_Simulation->setObjectName(QStringLiteral("label_Simulation"));

        horizontalLayout_25->addWidget(label_Simulation);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_13);


        verticalLayout_36->addLayout(horizontalLayout_25);

        groupBox_Simulation = new QGroupBox(groupBox);
        groupBox_Simulation->setObjectName(QStringLiteral("groupBox_Simulation"));
        verticalLayout_40 = new QVBoxLayout(groupBox_Simulation);
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        label = new QLabel(groupBox_Simulation);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_39->addWidget(label);

        label_2 = new QLabel(groupBox_Simulation);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_39->addWidget(label_2);

        label_8 = new QLabel(groupBox_Simulation);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_39->addWidget(label_8);


        horizontalLayout_26->addLayout(verticalLayout_39);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        lineEdit_StartTime = new QLineEdit(groupBox_Simulation);
        lineEdit_StartTime->setObjectName(QStringLiteral("lineEdit_StartTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_StartTime->sizePolicy().hasHeightForWidth());
        lineEdit_StartTime->setSizePolicy(sizePolicy2);
        lineEdit_StartTime->setMinimumSize(QSize(0, 0));
        lineEdit_StartTime->setMaximumSize(QSize(7000, 7000));

        verticalLayout_37->addWidget(lineEdit_StartTime);

        lineEdit_EndTime = new QLineEdit(groupBox_Simulation);
        lineEdit_EndTime->setObjectName(QStringLiteral("lineEdit_EndTime"));
        sizePolicy2.setHeightForWidth(lineEdit_EndTime->sizePolicy().hasHeightForWidth());
        lineEdit_EndTime->setSizePolicy(sizePolicy2);
        lineEdit_EndTime->setMinimumSize(QSize(0, 0));
        lineEdit_EndTime->setMaximumSize(QSize(7000, 7000));

        verticalLayout_37->addWidget(lineEdit_EndTime);

        lineEdit_Step = new QLineEdit(groupBox_Simulation);
        lineEdit_Step->setObjectName(QStringLiteral("lineEdit_Step"));
        sizePolicy2.setHeightForWidth(lineEdit_Step->sizePolicy().hasHeightForWidth());
        lineEdit_Step->setSizePolicy(sizePolicy2);
        lineEdit_Step->setMinimumSize(QSize(0, 0));
        lineEdit_Step->setMaximumSize(QSize(7000, 7000));

        verticalLayout_37->addWidget(lineEdit_Step);


        horizontalLayout_26->addLayout(verticalLayout_37);


        verticalLayout_40->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalSpacer_14 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_14);

        pushButton_StartSimulation = new QPushButton(groupBox_Simulation);
        pushButton_StartSimulation->setObjectName(QStringLiteral("pushButton_StartSimulation"));

        horizontalLayout_27->addWidget(pushButton_StartSimulation);


        verticalLayout_40->addLayout(horizontalLayout_27);


        verticalLayout_36->addWidget(groupBox_Simulation);


        verticalLayout_4->addLayout(verticalLayout_36);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        pushButton_showRealTimeSimulation = new QPushButton(groupBox);
        pushButton_showRealTimeSimulation->setObjectName(QStringLiteral("pushButton_showRealTimeSimulation"));
        sizePolicy1.setHeightForWidth(pushButton_showRealTimeSimulation->sizePolicy().hasHeightForWidth());
        pushButton_showRealTimeSimulation->setSizePolicy(sizePolicy1);
        pushButton_showRealTimeSimulation->setMinimumSize(QSize(16, 16));
        pushButton_showRealTimeSimulation->setMaximumSize(QSize(16, 16));
        pushButton_showRealTimeSimulation->setIcon(icon);
        pushButton_showRealTimeSimulation->setFlat(true);

        horizontalLayout_30->addWidget(pushButton_showRealTimeSimulation);

        label_RealTimeSimulation = new QLabel(groupBox);
        label_RealTimeSimulation->setObjectName(QStringLiteral("label_RealTimeSimulation"));

        horizontalLayout_30->addWidget(label_RealTimeSimulation);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_15);


        verticalLayout_41->addLayout(horizontalLayout_30);

        groupBox_RealTimeSimulation = new QGroupBox(groupBox);
        groupBox_RealTimeSimulation->setObjectName(QStringLiteral("groupBox_RealTimeSimulation"));
        verticalLayout_16 = new QVBoxLayout(groupBox_RealTimeSimulation);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_11 = new QLabel(groupBox_RealTimeSimulation);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_14->addWidget(label_11);

        label_12 = new QLabel(groupBox_RealTimeSimulation);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_14->addWidget(label_12);


        horizontalLayout_9->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        lineEdit_Speed = new QLineEdit(groupBox_RealTimeSimulation);
        lineEdit_Speed->setObjectName(QStringLiteral("lineEdit_Speed"));
        sizePolicy2.setHeightForWidth(lineEdit_Speed->sizePolicy().hasHeightForWidth());
        lineEdit_Speed->setSizePolicy(sizePolicy2);
        lineEdit_Speed->setMinimumSize(QSize(0, 0));
        lineEdit_Speed->setMaximumSize(QSize(7000, 7000));

        verticalLayout_15->addWidget(lineEdit_Speed);

        lineEdit_RealTimeSimulationStep = new QLineEdit(groupBox_RealTimeSimulation);
        lineEdit_RealTimeSimulationStep->setObjectName(QStringLiteral("lineEdit_RealTimeSimulationStep"));
        sizePolicy2.setHeightForWidth(lineEdit_RealTimeSimulationStep->sizePolicy().hasHeightForWidth());
        lineEdit_RealTimeSimulationStep->setSizePolicy(sizePolicy2);
        lineEdit_RealTimeSimulationStep->setMinimumSize(QSize(0, 0));
        lineEdit_RealTimeSimulationStep->setMaximumSize(QSize(7000, 7000));

        verticalLayout_15->addWidget(lineEdit_RealTimeSimulationStep);


        horizontalLayout_9->addLayout(verticalLayout_15);


        verticalLayout_16->addLayout(horizontalLayout_9);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalSpacer_16 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_16);

        pushButton_StartRealTimeSimulation = new QPushButton(groupBox_RealTimeSimulation);
        pushButton_StartRealTimeSimulation->setObjectName(QStringLiteral("pushButton_StartRealTimeSimulation"));

        horizontalLayout_32->addWidget(pushButton_StartRealTimeSimulation);

        pushButton_StopRealTimeSimulation = new QPushButton(groupBox_RealTimeSimulation);
        pushButton_StopRealTimeSimulation->setObjectName(QStringLiteral("pushButton_StopRealTimeSimulation"));

        horizontalLayout_32->addWidget(pushButton_StopRealTimeSimulation);


        verticalLayout_16->addLayout(horizontalLayout_32);


        verticalLayout_41->addWidget(groupBox_RealTimeSimulation);


        verticalLayout_4->addLayout(verticalLayout_41);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        pushButton_showTrajectorySimulation = new QPushButton(groupBox);
        pushButton_showTrajectorySimulation->setObjectName(QStringLiteral("pushButton_showTrajectorySimulation"));
        sizePolicy1.setHeightForWidth(pushButton_showTrajectorySimulation->sizePolicy().hasHeightForWidth());
        pushButton_showTrajectorySimulation->setSizePolicy(sizePolicy1);
        pushButton_showTrajectorySimulation->setMinimumSize(QSize(16, 16));
        pushButton_showTrajectorySimulation->setMaximumSize(QSize(16, 16));
        pushButton_showTrajectorySimulation->setIcon(icon);
        pushButton_showTrajectorySimulation->setFlat(true);

        horizontalLayout_28->addWidget(pushButton_showTrajectorySimulation);

        label_TrajectorySimulation = new QLabel(groupBox);
        label_TrajectorySimulation->setObjectName(QStringLiteral("label_TrajectorySimulation"));

        horizontalLayout_28->addWidget(label_TrajectorySimulation);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_17);


        verticalLayout_38->addLayout(horizontalLayout_28);

        groupBox_TrajectorySimulation = new QGroupBox(groupBox);
        groupBox_TrajectorySimulation->setObjectName(QStringLiteral("groupBox_TrajectorySimulation"));
        verticalLayout_42 = new QVBoxLayout(groupBox_TrajectorySimulation);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_13 = new QLabel(groupBox_TrajectorySimulation);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_19->addWidget(label_13);

        label_14 = new QLabel(groupBox_TrajectorySimulation);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_19->addWidget(label_14);


        horizontalLayout_13->addLayout(verticalLayout_19);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        lineEdit_Speed_2 = new QLineEdit(groupBox_TrajectorySimulation);
        lineEdit_Speed_2->setObjectName(QStringLiteral("lineEdit_Speed_2"));
        sizePolicy2.setHeightForWidth(lineEdit_Speed_2->sizePolicy().hasHeightForWidth());
        lineEdit_Speed_2->setSizePolicy(sizePolicy2);
        lineEdit_Speed_2->setMinimumSize(QSize(0, 0));
        lineEdit_Speed_2->setMaximumSize(QSize(7000, 7000));

        verticalLayout_23->addWidget(lineEdit_Speed_2);

        lineEdit_RealTimeSimulationStep_2 = new QLineEdit(groupBox_TrajectorySimulation);
        lineEdit_RealTimeSimulationStep_2->setObjectName(QStringLiteral("lineEdit_RealTimeSimulationStep_2"));
        sizePolicy2.setHeightForWidth(lineEdit_RealTimeSimulationStep_2->sizePolicy().hasHeightForWidth());
        lineEdit_RealTimeSimulationStep_2->setSizePolicy(sizePolicy2);
        lineEdit_RealTimeSimulationStep_2->setMinimumSize(QSize(0, 0));
        lineEdit_RealTimeSimulationStep_2->setMaximumSize(QSize(7000, 7000));

        verticalLayout_23->addWidget(lineEdit_RealTimeSimulationStep_2);


        horizontalLayout_13->addLayout(verticalLayout_23);


        verticalLayout_42->addLayout(horizontalLayout_13);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        horizontalSpacer_22 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_22);

        horizontalSpacer_23 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_23);

        pushButton_StartTrajectorySimulationSimulation_3 = new QPushButton(groupBox_TrajectorySimulation);
        pushButton_StartTrajectorySimulationSimulation_3->setObjectName(QStringLiteral("pushButton_StartTrajectorySimulationSimulation_3"));

        horizontalLayout_33->addWidget(pushButton_StartTrajectorySimulationSimulation_3);

        pushButton_StartTrajectorySimulationSimulation_4 = new QPushButton(groupBox_TrajectorySimulation);
        pushButton_StartTrajectorySimulationSimulation_4->setObjectName(QStringLiteral("pushButton_StartTrajectorySimulationSimulation_4"));

        horizontalLayout_33->addWidget(pushButton_StartTrajectorySimulationSimulation_4);


        verticalLayout_42->addLayout(horizontalLayout_33);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        horizontalSpacer_18 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_18);

        horizontalSpacer_21 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_21);

        pushButton_StartTrajectorySimulationSimulation_2 = new QPushButton(groupBox_TrajectorySimulation);
        pushButton_StartTrajectorySimulationSimulation_2->setObjectName(QStringLiteral("pushButton_StartTrajectorySimulationSimulation_2"));

        horizontalLayout_31->addWidget(pushButton_StartTrajectorySimulationSimulation_2);

        pushButton_StartTrajectorySimulationSimulation = new QPushButton(groupBox_TrajectorySimulation);
        pushButton_StartTrajectorySimulationSimulation->setObjectName(QStringLiteral("pushButton_StartTrajectorySimulationSimulation"));

        horizontalLayout_31->addWidget(pushButton_StartTrajectorySimulationSimulation);


        verticalLayout_42->addLayout(horizontalLayout_31);


        verticalLayout_38->addWidget(groupBox_TrajectorySimulation);


        verticalLayout_4->addLayout(verticalLayout_38);

        verticalLayout_65 = new QVBoxLayout();
        verticalLayout_65->setObjectName(QStringLiteral("verticalLayout_65"));
        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        pushButton_showPositionControl = new QPushButton(groupBox);
        pushButton_showPositionControl->setObjectName(QStringLiteral("pushButton_showPositionControl"));
        sizePolicy1.setHeightForWidth(pushButton_showPositionControl->sizePolicy().hasHeightForWidth());
        pushButton_showPositionControl->setSizePolicy(sizePolicy1);
        pushButton_showPositionControl->setMinimumSize(QSize(16, 16));
        pushButton_showPositionControl->setMaximumSize(QSize(16, 16));
        pushButton_showPositionControl->setIcon(icon);
        pushButton_showPositionControl->setFlat(true);

        horizontalLayout_51->addWidget(pushButton_showPositionControl);

        label_PositionControl = new QLabel(groupBox);
        label_PositionControl->setObjectName(QStringLiteral("label_PositionControl"));

        horizontalLayout_51->addWidget(label_PositionControl);

        horizontalSpacer_40 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_51->addItem(horizontalSpacer_40);


        verticalLayout_65->addLayout(horizontalLayout_51);

        groupBox_PositionControl = new QGroupBox(groupBox);
        groupBox_PositionControl->setObjectName(QStringLiteral("groupBox_PositionControl"));
        verticalLayout_66 = new QVBoxLayout(groupBox_PositionControl);
        verticalLayout_66->setObjectName(QStringLiteral("verticalLayout_66"));
        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setObjectName(QStringLiteral("horizontalLayout_53"));
        horizontalSpacer_41 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_41);

        horizontalSpacer_42 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_42);

        pushButton_OpenControlerWindow = new QPushButton(groupBox_PositionControl);
        pushButton_OpenControlerWindow->setObjectName(QStringLiteral("pushButton_OpenControlerWindow"));

        horizontalLayout_53->addWidget(pushButton_OpenControlerWindow);


        verticalLayout_66->addLayout(horizontalLayout_53);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_43 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_43);

        pushButton_OpenControlerWindow_2 = new QPushButton(groupBox_PositionControl);
        pushButton_OpenControlerWindow_2->setObjectName(QStringLiteral("pushButton_OpenControlerWindow_2"));

        horizontalLayout->addWidget(pushButton_OpenControlerWindow_2);


        verticalLayout_66->addLayout(horizontalLayout);


        verticalLayout_65->addWidget(groupBox_PositionControl);


        verticalLayout_4->addLayout(verticalLayout_65);

        verticalLayout_69 = new QVBoxLayout();
        verticalLayout_69->setObjectName(QStringLiteral("verticalLayout_69"));
        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setObjectName(QStringLiteral("horizontalLayout_55"));
        pushButton_showHapticControl = new QPushButton(groupBox);
        pushButton_showHapticControl->setObjectName(QStringLiteral("pushButton_showHapticControl"));
        sizePolicy1.setHeightForWidth(pushButton_showHapticControl->sizePolicy().hasHeightForWidth());
        pushButton_showHapticControl->setSizePolicy(sizePolicy1);
        pushButton_showHapticControl->setMinimumSize(QSize(16, 16));
        pushButton_showHapticControl->setMaximumSize(QSize(16, 16));
        pushButton_showHapticControl->setIcon(icon);
        pushButton_showHapticControl->setFlat(true);

        horizontalLayout_55->addWidget(pushButton_showHapticControl);

        label_HapticControl = new QLabel(groupBox);
        label_HapticControl->setObjectName(QStringLiteral("label_HapticControl"));

        horizontalLayout_55->addWidget(label_HapticControl);

        horizontalSpacer_46 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_46);


        verticalLayout_69->addLayout(horizontalLayout_55);

        groupBox_HapticControl = new QGroupBox(groupBox);
        groupBox_HapticControl->setObjectName(QStringLiteral("groupBox_HapticControl"));
        verticalLayout_70 = new QVBoxLayout(groupBox_HapticControl);
        verticalLayout_70->setObjectName(QStringLiteral("verticalLayout_70"));
        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setObjectName(QStringLiteral("horizontalLayout_56"));
        horizontalSpacer_47 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_47);

        checkBox = new QCheckBox(groupBox_HapticControl);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_56->addWidget(checkBox);


        verticalLayout_70->addLayout(horizontalLayout_56);


        verticalLayout_69->addWidget(groupBox_HapticControl);


        verticalLayout_4->addLayout(verticalLayout_69);

        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        pushButton_showPostSimulation = new QPushButton(groupBox);
        pushButton_showPostSimulation->setObjectName(QStringLiteral("pushButton_showPostSimulation"));
        sizePolicy1.setHeightForWidth(pushButton_showPostSimulation->sizePolicy().hasHeightForWidth());
        pushButton_showPostSimulation->setSizePolicy(sizePolicy1);
        pushButton_showPostSimulation->setMinimumSize(QSize(16, 16));
        pushButton_showPostSimulation->setMaximumSize(QSize(16, 16));
        pushButton_showPostSimulation->setIcon(icon);
        pushButton_showPostSimulation->setFlat(true);

        horizontalLayout_34->addWidget(pushButton_showPostSimulation);

        label_PostSimulation = new QLabel(groupBox);
        label_PostSimulation->setObjectName(QStringLiteral("label_PostSimulation"));

        horizontalLayout_34->addWidget(label_PostSimulation);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_19);


        verticalLayout_43->addLayout(horizontalLayout_34);

        groupBox_PostSimulation = new QGroupBox(groupBox);
        groupBox_PostSimulation->setObjectName(QStringLiteral("groupBox_PostSimulation"));
        verticalLayout_20 = new QVBoxLayout(groupBox_PostSimulation);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_15 = new QLabel(groupBox_PostSimulation);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_21->addWidget(label_15);

        label_16 = new QLabel(groupBox_PostSimulation);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_21->addWidget(label_16);


        horizontalLayout_11->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        lineEdit_PostSimulationSpeed = new QLineEdit(groupBox_PostSimulation);
        lineEdit_PostSimulationSpeed->setObjectName(QStringLiteral("lineEdit_PostSimulationSpeed"));
        sizePolicy2.setHeightForWidth(lineEdit_PostSimulationSpeed->sizePolicy().hasHeightForWidth());
        lineEdit_PostSimulationSpeed->setSizePolicy(sizePolicy2);
        lineEdit_PostSimulationSpeed->setMinimumSize(QSize(0, 0));
        lineEdit_PostSimulationSpeed->setMaximumSize(QSize(7000, 7000));

        verticalLayout_22->addWidget(lineEdit_PostSimulationSpeed);

        horizontalSlider_PostSimulationTime = new QSlider(groupBox_PostSimulation);
        horizontalSlider_PostSimulationTime->setObjectName(QStringLiteral("horizontalSlider_PostSimulationTime"));
        horizontalSlider_PostSimulationTime->setMaximum(1000);
        horizontalSlider_PostSimulationTime->setOrientation(Qt::Horizontal);

        verticalLayout_22->addWidget(horizontalSlider_PostSimulationTime);


        horizontalLayout_11->addLayout(verticalLayout_22);


        verticalLayout_20->addLayout(horizontalLayout_11);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        horizontalSpacer_20 = new QSpacerItem(154, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_20);

        pushButton_StartRealTimeSimulation_3 = new QPushButton(groupBox_PostSimulation);
        pushButton_StartRealTimeSimulation_3->setObjectName(QStringLiteral("pushButton_StartRealTimeSimulation_3"));

        horizontalLayout_35->addWidget(pushButton_StartRealTimeSimulation_3);

        pushButton_StopRealTimeSimulation_3 = new QPushButton(groupBox_PostSimulation);
        pushButton_StopRealTimeSimulation_3->setObjectName(QStringLiteral("pushButton_StopRealTimeSimulation_3"));

        horizontalLayout_35->addWidget(pushButton_StopRealTimeSimulation_3);


        verticalLayout_20->addLayout(horizontalLayout_35);


        verticalLayout_43->addWidget(groupBox_PostSimulation);


        verticalLayout_4->addLayout(verticalLayout_43);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_13->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        retranslateUi(simulationwidget);

        QMetaObject::connectSlotsByName(simulationwidget);
    } // setupUi

    void retranslateUi(QWidget *simulationwidget)
    {
        simulationwidget->setWindowTitle(QApplication::translate("simulationwidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("simulationwidget", "Dynamic analysis", 0));
        pushButton_showSimulation->setText(QString());
        label_Simulation->setText(QApplication::translate("simulationwidget", "Single Simulation", 0));
        groupBox_Simulation->setTitle(QString());
        label->setText(QApplication::translate("simulationwidget", "Start time", 0));
        label_2->setText(QApplication::translate("simulationwidget", "End time", 0));
        label_8->setText(QApplication::translate("simulationwidget", "Step", 0));
        pushButton_StartSimulation->setText(QApplication::translate("simulationwidget", "Start", 0));
        pushButton_showRealTimeSimulation->setText(QString());
        label_RealTimeSimulation->setText(QApplication::translate("simulationwidget", "Real-Time Simulation", 0));
        groupBox_RealTimeSimulation->setTitle(QString());
        label_11->setText(QApplication::translate("simulationwidget", "Speed", 0));
        label_12->setText(QApplication::translate("simulationwidget", "Step", 0));
        pushButton_StartRealTimeSimulation->setText(QApplication::translate("simulationwidget", "Start", 0));
        pushButton_StopRealTimeSimulation->setText(QApplication::translate("simulationwidget", "Stop", 0));
        pushButton_showTrajectorySimulation->setText(QString());
        label_TrajectorySimulation->setText(QApplication::translate("simulationwidget", "Trajectory Simulation", 0));
        groupBox_TrajectorySimulation->setTitle(QString());
        label_13->setText(QApplication::translate("simulationwidget", "Current program", 0));
        label_14->setText(QApplication::translate("simulationwidget", "Current time", 0));
        pushButton_StartTrajectorySimulationSimulation_3->setText(QApplication::translate("simulationwidget", "Programs", 0));
        pushButton_StartTrajectorySimulationSimulation_4->setText(QApplication::translate("simulationwidget", "Move to start", 0));
        pushButton_StartTrajectorySimulationSimulation_2->setText(QApplication::translate("simulationwidget", "Start", 0));
        pushButton_StartTrajectorySimulationSimulation->setText(QApplication::translate("simulationwidget", "Stop", 0));
        pushButton_showPositionControl->setText(QString());
        label_PositionControl->setText(QApplication::translate("simulationwidget", "Position Control", 0));
        groupBox_PositionControl->setTitle(QString());
        pushButton_OpenControlerWindow->setText(QApplication::translate("simulationwidget", "Open Controler Window", 0));
        pushButton_OpenControlerWindow_2->setText(QApplication::translate("simulationwidget", "Open Controler Window 2", 0));
        pushButton_showHapticControl->setText(QString());
        label_HapticControl->setText(QApplication::translate("simulationwidget", "Haptic Control", 0));
        groupBox_HapticControl->setTitle(QString());
        checkBox->setText(QApplication::translate("simulationwidget", "Enable Haptic Pointer", 0));
        pushButton_showPostSimulation->setText(QString());
        label_PostSimulation->setText(QApplication::translate("simulationwidget", "Post simulation", 0));
        groupBox_PostSimulation->setTitle(QString());
        label_15->setText(QApplication::translate("simulationwidget", "Speed", 0));
        label_16->setText(QApplication::translate("simulationwidget", "Time", 0));
        pushButton_StartRealTimeSimulation_3->setText(QApplication::translate("simulationwidget", "Start", 0));
        pushButton_StopRealTimeSimulation_3->setText(QApplication::translate("simulationwidget", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class simulationwidget: public Ui_simulationwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONWIDGET_H
