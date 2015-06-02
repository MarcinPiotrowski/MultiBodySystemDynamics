/********************************************************************************
** Form generated from reading UI file 'ControlerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLERWIDGET_H
#define UI_CONTROLERWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget_Kf;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget_Kvf;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_MaxSpeed;
    QLineEdit *lineEdit_MaxSpeed;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ControlerWidget)
    {
        if (ControlerWidget->objectName().isEmpty())
            ControlerWidget->setObjectName(QStringLiteral("ControlerWidget"));
        ControlerWidget->resize(401, 331);
        verticalLayout = new QVBoxLayout(ControlerWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(ControlerWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(ControlerWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(ControlerWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        tableWidget_2 = new QTableWidget(ControlerWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        horizontalLayout->addWidget(tableWidget_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tableWidget_Kf = new QTableWidget(ControlerWidget);
        tableWidget_Kf->setObjectName(QStringLiteral("tableWidget_Kf"));

        horizontalLayout_4->addWidget(tableWidget_Kf);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        tableWidget_Kvf = new QTableWidget(ControlerWidget);
        tableWidget_Kvf->setObjectName(QStringLiteral("tableWidget_Kvf"));

        horizontalLayout_4->addWidget(tableWidget_Kvf);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_MaxSpeed = new QLabel(ControlerWidget);
        label_MaxSpeed->setObjectName(QStringLiteral("label_MaxSpeed"));

        horizontalLayout_5->addWidget(label_MaxSpeed);

        lineEdit_MaxSpeed = new QLineEdit(ControlerWidget);
        lineEdit_MaxSpeed->setObjectName(QStringLiteral("lineEdit_MaxSpeed"));
        lineEdit_MaxSpeed->setMaximumSize(QSize(50, 100));

        horizontalLayout_5->addWidget(lineEdit_MaxSpeed);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(ControlerWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(ControlerWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ControlerWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ControlerWidget);

        QMetaObject::connectSlotsByName(ControlerWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlerWidget)
    {
        ControlerWidget->setWindowTitle(QApplication::translate("ControlerWidget", "Form", 0));
        label->setText(QApplication::translate("ControlerWidget", "Type:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ControlerWidget", "COT_PPLUS", 0)
         << QApplication::translate("ControlerWidget", "COT_PD", 0)
         << QApplication::translate("ControlerWidget", "COT_OPERATIONAL_SPACE_SPEC_PATH", 0)
         << QApplication::translate("ControlerWidget", "COT_OPERATIONAL_SPACE_NO_PATH", 0)
        );
        label_MaxSpeed->setText(QApplication::translate("ControlerWidget", "Max speed: ", 0));
        pushButton->setText(QApplication::translate("ControlerWidget", "Accept", 0));
        pushButton_2->setText(QApplication::translate("ControlerWidget", "OK", 0));
        pushButton_3->setText(QApplication::translate("ControlerWidget", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlerWidget: public Ui_ControlerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLERWIDGET_H
