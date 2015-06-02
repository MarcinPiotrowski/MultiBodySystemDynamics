/********************************************************************************
** Form generated from reading UI file 'basepropertieswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEPROPERTIESWIDGET_H
#define UI_BASEPROPERTIESWIDGET_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasePropertiesWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label_4;
    QRadioButton *radioButton_Default;
    QRadioButton *radioButton_LoadedModel;
    QLabel *label_LoadedModelName;
    QLabel *label_BasePosition;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_x;
    QLabel *label_y;
    QLabel *label_z;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QLineEdit *lineEdit_z;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_OK_;
    QPushButton *pushButton_Cancel_;
    QPushButton *pushButton_Apply_;

    void setupUi(QWidget *BasePropertiesWidget)
    {
        if (BasePropertiesWidget->objectName().isEmpty())
            BasePropertiesWidget->setObjectName(QStringLiteral("BasePropertiesWidget"));
        BasePropertiesWidget->resize(257, 286);
        verticalLayout = new QVBoxLayout(BasePropertiesWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BasePropertiesWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 128, 61, 16));
        radioButton_Default = new QRadioButton(groupBox);
        radioButton_Default->setObjectName(QStringLiteral("radioButton_Default"));
        radioButton_Default->setGeometry(QRect(21, 149, 58, 17));
        radioButton_LoadedModel = new QRadioButton(groupBox);
        radioButton_LoadedModel->setObjectName(QStringLiteral("radioButton_LoadedModel"));
        radioButton_LoadedModel->setGeometry(QRect(21, 172, 89, 17));
        label_LoadedModelName = new QLabel(groupBox);
        label_LoadedModelName->setObjectName(QStringLiteral("label_LoadedModelName"));
        label_LoadedModelName->setGeometry(QRect(120, 170, 101, 21));
        label_BasePosition = new QLabel(groupBox);
        label_BasePosition->setObjectName(QStringLiteral("label_BasePosition"));
        label_BasePosition->setGeometry(QRect(10, 20, 81, 20));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 50, 71, 71));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_x = new QLabel(layoutWidget_2);
        label_x->setObjectName(QStringLiteral("label_x"));
        QFont font;
        font.setPointSize(12);
        label_x->setFont(font);

        verticalLayout_3->addWidget(label_x);

        label_y = new QLabel(layoutWidget_2);
        label_y->setObjectName(QStringLiteral("label_y"));
        label_y->setFont(font);

        verticalLayout_3->addWidget(label_y);

        label_z = new QLabel(layoutWidget_2);
        label_z->setObjectName(QStringLiteral("label_z"));
        label_z->setFont(font);

        verticalLayout_3->addWidget(label_z);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_x = new QLineEdit(layoutWidget_2);
        lineEdit_x->setObjectName(QStringLiteral("lineEdit_x"));

        verticalLayout_2->addWidget(lineEdit_x);

        lineEdit_y = new QLineEdit(layoutWidget_2);
        lineEdit_y->setObjectName(QStringLiteral("lineEdit_y"));

        verticalLayout_2->addWidget(lineEdit_y);

        lineEdit_z = new QLineEdit(layoutWidget_2);
        lineEdit_z->setObjectName(QStringLiteral("lineEdit_z"));

        verticalLayout_2->addWidget(lineEdit_z);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_OK_ = new QPushButton(BasePropertiesWidget);
        pushButton_OK_->setObjectName(QStringLiteral("pushButton_OK_"));

        horizontalLayout_2->addWidget(pushButton_OK_);

        pushButton_Cancel_ = new QPushButton(BasePropertiesWidget);
        pushButton_Cancel_->setObjectName(QStringLiteral("pushButton_Cancel_"));

        horizontalLayout_2->addWidget(pushButton_Cancel_);

        pushButton_Apply_ = new QPushButton(BasePropertiesWidget);
        pushButton_Apply_->setObjectName(QStringLiteral("pushButton_Apply_"));

        horizontalLayout_2->addWidget(pushButton_Apply_);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BasePropertiesWidget);

        QMetaObject::connectSlotsByName(BasePropertiesWidget);
    } // setupUi

    void retranslateUi(QWidget *BasePropertiesWidget)
    {
        BasePropertiesWidget->setWindowTitle(QApplication::translate("BasePropertiesWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("BasePropertiesWidget", "Base", 0));
        label_4->setText(QApplication::translate("BasePropertiesWidget", "Graphics:", 0));
        radioButton_Default->setText(QApplication::translate("BasePropertiesWidget", "Default", 0));
        radioButton_LoadedModel->setText(QApplication::translate("BasePropertiesWidget", "Loaded model", 0));
        label_LoadedModelName->setText(QApplication::translate("BasePropertiesWidget", "--------", 0));
        label_BasePosition->setText(QApplication::translate("BasePropertiesWidget", "Base position:", 0));
        label_x->setText(QApplication::translate("BasePropertiesWidget", "<html><head/><body><p>x</p></body></html>", 0));
        label_y->setText(QApplication::translate("BasePropertiesWidget", "<html><head/><body><p>y</p></body></html>", 0));
        label_z->setText(QApplication::translate("BasePropertiesWidget", "<html><head/><body><p>z</p></body></html>", 0));
        pushButton_OK_->setText(QApplication::translate("BasePropertiesWidget", "Ok", 0));
        pushButton_Cancel_->setText(QApplication::translate("BasePropertiesWidget", "Cancel", 0));
        pushButton_Apply_->setText(QApplication::translate("BasePropertiesWidget", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class BasePropertiesWidget: public Ui_BasePropertiesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEPROPERTIESWIDGET_H
