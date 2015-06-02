/********************************************************************************
** Form generated from reading UI file 'linkspropertieswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKSPROPERTIESWIDGET_H
#define UI_LINKSPROPERTIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinksPropertiesWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox_Links;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QLabel *label_4;
    QRadioButton *radioButton_Default;
    QRadioButton *radioButton_LoadedModel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_Mass;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Ixx;
    QLineEdit *lineEdit_Iyy;
    QLineEdit *lineEdit_Izz;
    QLabel *label_LoadedModelName;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Apply;

    void setupUi(QWidget *LinksPropertiesWidget)
    {
        if (LinksPropertiesWidget->objectName().isEmpty())
            LinksPropertiesWidget->setObjectName(QStringLiteral("LinksPropertiesWidget"));
        LinksPropertiesWidget->resize(257, 306);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Res/MBSD_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        LinksPropertiesWidget->setWindowIcon(icon);
        verticalLayout_5 = new QVBoxLayout(LinksPropertiesWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(LinksPropertiesWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        comboBox_Links = new QComboBox(LinksPropertiesWidget);
        comboBox_Links->setObjectName(QStringLiteral("comboBox_Links"));

        horizontalLayout_4->addWidget(comboBox_Links);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(LinksPropertiesWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 61, 16));
        radioButton_Default = new QRadioButton(groupBox);
        radioButton_Default->setObjectName(QStringLiteral("radioButton_Default"));
        radioButton_Default->setGeometry(QRect(21, 171, 58, 17));
        radioButton_LoadedModel = new QRadioButton(groupBox);
        radioButton_LoadedModel->setObjectName(QStringLiteral("radioButton_LoadedModel"));
        radioButton_LoadedModel->setGeometry(QRect(21, 194, 89, 17));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 171, 125));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_Mass = new QLineEdit(layoutWidget);
        lineEdit_Mass->setObjectName(QStringLiteral("lineEdit_Mass"));

        horizontalLayout_3->addWidget(lineEdit_Mass);


        verticalLayout_4->addLayout(horizontalLayout_3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_Ixx = new QLineEdit(layoutWidget);
        lineEdit_Ixx->setObjectName(QStringLiteral("lineEdit_Ixx"));

        verticalLayout_2->addWidget(lineEdit_Ixx);

        lineEdit_Iyy = new QLineEdit(layoutWidget);
        lineEdit_Iyy->setObjectName(QStringLiteral("lineEdit_Iyy"));

        verticalLayout_2->addWidget(lineEdit_Iyy);

        lineEdit_Izz = new QLineEdit(layoutWidget);
        lineEdit_Izz->setObjectName(QStringLiteral("lineEdit_Izz"));

        verticalLayout_2->addWidget(lineEdit_Izz);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        label_LoadedModelName = new QLabel(groupBox);
        label_LoadedModelName->setObjectName(QStringLiteral("label_LoadedModelName"));
        label_LoadedModelName->setGeometry(QRect(120, 192, 101, 21));

        verticalLayout_5->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_OK = new QPushButton(LinksPropertiesWidget);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));

        horizontalLayout->addWidget(pushButton_OK);

        pushButton_Cancel = new QPushButton(LinksPropertiesWidget);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        pushButton_Apply = new QPushButton(LinksPropertiesWidget);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);


        verticalLayout_5->addLayout(horizontalLayout);


        retranslateUi(LinksPropertiesWidget);

        QMetaObject::connectSlotsByName(LinksPropertiesWidget);
    } // setupUi

    void retranslateUi(QWidget *LinksPropertiesWidget)
    {
        LinksPropertiesWidget->setWindowTitle(QApplication::translate("LinksPropertiesWidget", "Link properties", 0));
        label->setText(QApplication::translate("LinksPropertiesWidget", "Link number", 0));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("LinksPropertiesWidget", "Graphics:", 0));
        radioButton_Default->setText(QApplication::translate("LinksPropertiesWidget", "Default", 0));
        radioButton_LoadedModel->setText(QApplication::translate("LinksPropertiesWidget", "Loaded model", 0));
        label_2->setText(QApplication::translate("LinksPropertiesWidget", "Mass:", 0));
        label_3->setText(QApplication::translate("LinksPropertiesWidget", "Mass interia tensor:", 0));
        label_5->setText(QApplication::translate("LinksPropertiesWidget", "I<sub>xx</sub>", 0));
        label_6->setText(QApplication::translate("LinksPropertiesWidget", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">yy</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("LinksPropertiesWidget", "<html><head/><body><p>I<span style=\" vertical-align:sub;\">zz</span></p></body></html>", 0));
        label_LoadedModelName->setText(QApplication::translate("LinksPropertiesWidget", "--------", 0));
        pushButton_OK->setText(QApplication::translate("LinksPropertiesWidget", "Ok", 0));
        pushButton_Cancel->setText(QApplication::translate("LinksPropertiesWidget", "Cancel", 0));
        pushButton_Apply->setText(QApplication::translate("LinksPropertiesWidget", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class LinksPropertiesWidget: public Ui_LinksPropertiesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKSPROPERTIESWIDGET_H
