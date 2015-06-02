#include "projectorygeneratorwindow.h"
#include "ui_projectorygeneratorwindow.h"

ProjectoryGeneratorWindow::ProjectoryGeneratorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectoryGeneratorWindow)
{
    ui->setupUi(this);
    ui->tableProgramData->setRowCount(1);
    ui->tableProgramData->setColumnCount(16);
    for( int i = 0 ; i < 16 ; i++)
        {
        ui->tableProgramData->setItem(0,i, new QTableWidgetItem);
        ui->tableProgramData->horizontalHeader()->resizeSection(i,40);
        //ui->tableProgramData->item(0,i)->setBackgroundColor(QColor::cyan());
        }
}

ProjectoryGeneratorWindow::~ProjectoryGeneratorWindow()
{
    delete ui;
}

void ProjectoryGeneratorWindow::on_pushButton_clicked()
{
    close();
}


void ProjectoryGeneratorWindow::on_pushButton_2_clicked()
{
    close();
}
