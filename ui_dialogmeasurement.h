/********************************************************************************
** Form generated from reading UI file 'dialogmeasurement.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMEASUREMENT_H
#define UI_DIALOGMEASUREMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMeasurement
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Macro;
    QLabel *label_2;
    QLineEdit *lineEdit_MacroRun;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Close;

    void setupUi(QDialog *DialogMeasurement)
    {
        if (DialogMeasurement->objectName().isEmpty())
            DialogMeasurement->setObjectName(QStringLiteral("DialogMeasurement"));
        DialogMeasurement->resize(466, 133);
        verticalLayout = new QVBoxLayout(DialogMeasurement);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogMeasurement);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_Macro = new QLineEdit(DialogMeasurement);
        lineEdit_Macro->setObjectName(QStringLiteral("lineEdit_Macro"));

        verticalLayout->addWidget(lineEdit_Macro);

        label_2 = new QLabel(DialogMeasurement);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_MacroRun = new QLineEdit(DialogMeasurement);
        lineEdit_MacroRun->setObjectName(QStringLiteral("lineEdit_MacroRun"));

        verticalLayout->addWidget(lineEdit_MacroRun);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Close = new QPushButton(DialogMeasurement);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));

        horizontalLayout->addWidget(pushButton_Close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogMeasurement);

        QMetaObject::connectSlotsByName(DialogMeasurement);
    } // setupUi

    void retranslateUi(QDialog *DialogMeasurement)
    {
        DialogMeasurement->setWindowTitle(QApplication::translate("DialogMeasurement", "Dialog", 0));
        label->setText(QApplication::translate("DialogMeasurement", "Copy line below and paste it to ADAMS command window to create macro:", 0));
        label_2->setText(QApplication::translate("DialogMeasurement", "After that, copy line below and paste it to ADAMS command window to run macro:", 0));
        pushButton_Close->setText(QApplication::translate("DialogMeasurement", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogMeasurement: public Ui_DialogMeasurement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMEASUREMENT_H
