/********************************************************************************
** Form generated from reading UI file 'optionswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWIDGET_H
#define UI_OPTIONSWIDGET_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_display;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_R;
    QLabel *label_G;
    QLabel *label_B;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_R;
    QSlider *horizontalSlider_G;
    QSlider *horizontalSlider_B;
    QLabel *BackgroundColorBox;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_R_3;
    QLabel *label_G_3;
    QLabel *label_B_3;
    QVBoxLayout *verticalLayout_8;
    QSlider *horizontalSlider_R_Line;
    QSlider *horizontalSlider_G_Line;
    QSlider *horizontalSlider_B_Line;
    QLabel *LinesColorBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_SceneWidth;
    QLineEdit *lineEdit_SceneDepth;
    QLineEdit *lineEdit_LineWidth;
    QLineEdit *lineEdit_LineDepth;
    QWidget *tab_others;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Apply;

    void setupUi(QWidget *OptionsWidget)
    {
        if (OptionsWidget->objectName().isEmpty())
            OptionsWidget->setObjectName(QStringLiteral("OptionsWidget"));
        OptionsWidget->resize(640, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Res/MBSD_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsWidget->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(OptionsWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(OptionsWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabBarAutoHide(false);
        tab_display = new QWidget();
        tab_display->setObjectName(QStringLiteral("tab_display"));
        groupBox = new QGroupBox(tab_display);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 181, 106));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_R = new QLabel(groupBox);
        label_R->setObjectName(QStringLiteral("label_R"));

        verticalLayout_2->addWidget(label_R);

        label_G = new QLabel(groupBox);
        label_G->setObjectName(QStringLiteral("label_G"));

        verticalLayout_2->addWidget(label_G);

        label_B = new QLabel(groupBox);
        label_B->setObjectName(QStringLiteral("label_B"));

        verticalLayout_2->addWidget(label_B);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSlider_R = new QSlider(groupBox);
        horizontalSlider_R->setObjectName(QStringLiteral("horizontalSlider_R"));
        horizontalSlider_R->setMaximum(254);
        horizontalSlider_R->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_R);

        horizontalSlider_G = new QSlider(groupBox);
        horizontalSlider_G->setObjectName(QStringLiteral("horizontalSlider_G"));
        horizontalSlider_G->setMaximum(254);
        horizontalSlider_G->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_G);

        horizontalSlider_B = new QSlider(groupBox);
        horizontalSlider_B->setObjectName(QStringLiteral("horizontalSlider_B"));
        horizontalSlider_B->setMaximum(254);
        horizontalSlider_B->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_B);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        BackgroundColorBox = new QLabel(groupBox);
        BackgroundColorBox->setObjectName(QStringLiteral("BackgroundColorBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BackgroundColorBox->sizePolicy().hasHeightForWidth());
        BackgroundColorBox->setSizePolicy(sizePolicy);
        BackgroundColorBox->setMinimumSize(QSize(50, 50));
        BackgroundColorBox->setMaximumSize(QSize(50, 50));
        BackgroundColorBox->setStyleSheet(QLatin1String("background-color:rgb(0, 255, 127); border-style: outset; border-width: 1px;\n"
"     border-color: black;"));

        horizontalLayout_3->addWidget(BackgroundColorBox);

        groupBox_3 = new QGroupBox(tab_display);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 30, 181, 106));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_R_3 = new QLabel(groupBox_3);
        label_R_3->setObjectName(QStringLiteral("label_R_3"));

        verticalLayout_7->addWidget(label_R_3);

        label_G_3 = new QLabel(groupBox_3);
        label_G_3->setObjectName(QStringLiteral("label_G_3"));

        verticalLayout_7->addWidget(label_G_3);

        label_B_3 = new QLabel(groupBox_3);
        label_B_3->setObjectName(QStringLiteral("label_B_3"));

        verticalLayout_7->addWidget(label_B_3);


        horizontalLayout_7->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalSlider_R_Line = new QSlider(groupBox_3);
        horizontalSlider_R_Line->setObjectName(QStringLiteral("horizontalSlider_R_Line"));
        horizontalSlider_R_Line->setMaximum(254);
        horizontalSlider_R_Line->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider_R_Line);

        horizontalSlider_G_Line = new QSlider(groupBox_3);
        horizontalSlider_G_Line->setObjectName(QStringLiteral("horizontalSlider_G_Line"));
        horizontalSlider_G_Line->setMaximum(254);
        horizontalSlider_G_Line->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider_G_Line);

        horizontalSlider_B_Line = new QSlider(groupBox_3);
        horizontalSlider_B_Line->setObjectName(QStringLiteral("horizontalSlider_B_Line"));
        horizontalSlider_B_Line->setMaximum(254);
        horizontalSlider_B_Line->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider_B_Line);


        horizontalLayout_7->addLayout(verticalLayout_8);


        horizontalLayout_6->addLayout(horizontalLayout_7);

        LinesColorBox = new QLabel(groupBox_3);
        LinesColorBox->setObjectName(QStringLiteral("LinesColorBox"));
        sizePolicy.setHeightForWidth(LinesColorBox->sizePolicy().hasHeightForWidth());
        LinesColorBox->setSizePolicy(sizePolicy);
        LinesColorBox->setMinimumSize(QSize(50, 50));
        LinesColorBox->setMaximumSize(QSize(50, 50));
        LinesColorBox->setStyleSheet(QLatin1String("background-color:rgb(0, 255, 127); border-style: outset; border-width: 1px;\n"
"     border-color: black;"));

        horizontalLayout_6->addWidget(LinesColorBox);

        label = new QLabel(tab_display);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 70, 41, 41));
        groupBox_2 = new QGroupBox(tab_display);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 150, 171, 141));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 151, 102));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_SceneWidth = new QLineEdit(layoutWidget);
        lineEdit_SceneWidth->setObjectName(QStringLiteral("lineEdit_SceneWidth"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_SceneWidth->sizePolicy().hasHeightForWidth());
        lineEdit_SceneWidth->setSizePolicy(sizePolicy1);
        lineEdit_SceneWidth->setMinimumSize(QSize(50, 0));
        lineEdit_SceneWidth->setMaximumSize(QSize(50, 50));

        verticalLayout_5->addWidget(lineEdit_SceneWidth);

        lineEdit_SceneDepth = new QLineEdit(layoutWidget);
        lineEdit_SceneDepth->setObjectName(QStringLiteral("lineEdit_SceneDepth"));
        sizePolicy1.setHeightForWidth(lineEdit_SceneDepth->sizePolicy().hasHeightForWidth());
        lineEdit_SceneDepth->setSizePolicy(sizePolicy1);
        lineEdit_SceneDepth->setMinimumSize(QSize(50, 0));
        lineEdit_SceneDepth->setMaximumSize(QSize(50, 16777215));

        verticalLayout_5->addWidget(lineEdit_SceneDepth);

        lineEdit_LineWidth = new QLineEdit(layoutWidget);
        lineEdit_LineWidth->setObjectName(QStringLiteral("lineEdit_LineWidth"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_LineWidth->sizePolicy().hasHeightForWidth());
        lineEdit_LineWidth->setSizePolicy(sizePolicy2);
        lineEdit_LineWidth->setMinimumSize(QSize(50, 0));
        lineEdit_LineWidth->setMaximumSize(QSize(50, 16777215));

        verticalLayout_5->addWidget(lineEdit_LineWidth);

        lineEdit_LineDepth = new QLineEdit(layoutWidget);
        lineEdit_LineDepth->setObjectName(QStringLiteral("lineEdit_LineDepth"));
        sizePolicy2.setHeightForWidth(lineEdit_LineDepth->sizePolicy().hasHeightForWidth());
        lineEdit_LineDepth->setSizePolicy(sizePolicy2);
        lineEdit_LineDepth->setMinimumSize(QSize(50, 0));
        lineEdit_LineDepth->setMaximumSize(QSize(50, 16777215));

        verticalLayout_5->addWidget(lineEdit_LineDepth);


        horizontalLayout_4->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_display, QString());
        tab_others = new QWidget();
        tab_others->setObjectName(QStringLiteral("tab_others"));
        tabWidget->addTab(tab_others, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_OK = new QPushButton(OptionsWidget);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        pushButton_Cancel = new QPushButton(OptionsWidget);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_Apply = new QPushButton(OptionsWidget);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(OptionsWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OptionsWidget);
    } // setupUi

    void retranslateUi(QWidget *OptionsWidget)
    {
        OptionsWidget->setWindowTitle(QApplication::translate("OptionsWidget", "Options", 0));
        groupBox->setTitle(QApplication::translate("OptionsWidget", "Background color", 0));
        label_R->setText(QApplication::translate("OptionsWidget", "R", 0));
        label_G->setText(QApplication::translate("OptionsWidget", "G", 0));
        label_B->setText(QApplication::translate("OptionsWidget", "B", 0));
        BackgroundColorBox->setText(QString());
        groupBox_3->setTitle(QApplication::translate("OptionsWidget", "Lines color", 0));
        label_R_3->setText(QApplication::translate("OptionsWidget", "R", 0));
        label_G_3->setText(QApplication::translate("OptionsWidget", "G", 0));
        label_B_3->setText(QApplication::translate("OptionsWidget", "B", 0));
        LinesColorBox->setText(QString());
        label->setText(QString());
        groupBox_2->setTitle(QApplication::translate("OptionsWidget", "Scene options", 0));
        label_2->setText(QApplication::translate("OptionsWidget", "Scene width:", 0));
        label_3->setText(QApplication::translate("OptionsWidget", "Scene depth:", 0));
        label_4->setText(QApplication::translate("OptionsWidget", "Line width space:", 0));
        label_5->setText(QApplication::translate("OptionsWidget", "Line depth space:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_display), QApplication::translate("OptionsWidget", "Display", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_others), QApplication::translate("OptionsWidget", "Others", 0));
        pushButton_OK->setText(QApplication::translate("OptionsWidget", "Ok", 0));
        pushButton_Cancel->setText(QApplication::translate("OptionsWidget", "Cancel", 0));
        pushButton_Apply->setText(QApplication::translate("OptionsWidget", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionsWidget: public Ui_OptionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWIDGET_H
