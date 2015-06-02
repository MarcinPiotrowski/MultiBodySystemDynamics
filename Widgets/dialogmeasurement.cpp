#include "dialogmeasurement.h"
#include "ui_dialogmeasurement.h"

DialogMeasurement::DialogMeasurement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMeasurement)
{
    ui->setupUi(this);
}

DialogMeasurement::~DialogMeasurement()
{
    delete ui;
}

void DialogMeasurement::SetMacro(QString Macro)
{
    ui->lineEdit_Macro->setText(Macro);
    ui->lineEdit_MacroRun->setText("CreateMeasures");
}

void DialogMeasurement::on_pushButton_Close_clicked()
{
    close();
}
