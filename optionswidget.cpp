#include "optionswidget.h"
#include "ui_optionswidget.h"
#include "GRender.h"

OptionsWidget::OptionsWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWidget)
{
    ui->setupUi(this);
    updateBackgroundColorBox();
    updateLinesColorBox();


    connect(ui->horizontalSlider_R, SIGNAL(valueChanged(int)),this,SLOT(updateBackgroundColorBox()));
    connect(ui->horizontalSlider_G, SIGNAL(valueChanged(int)),this,SLOT(updateBackgroundColorBox()));
    connect(ui->horizontalSlider_B, SIGNAL(valueChanged(int)),this,SLOT(updateBackgroundColorBox()));
    connect(ui->horizontalSlider_R_Line, SIGNAL(valueChanged(int)),this,SLOT(updateLinesColorBox()));
    connect(ui->horizontalSlider_G_Line, SIGNAL(valueChanged(int)),this,SLOT(updateLinesColorBox()));
    connect(ui->horizontalSlider_B_Line, SIGNAL(valueChanged(int)),this,SLOT(updateLinesColorBox()));
}

void OptionsWidget::LoadOptions(ProgramOptions Options)
{
    UnsavedOptions = Options;
    ui->horizontalSlider_R->setValue( UnsavedOptions.m_ClearColors[0]);
    ui->horizontalSlider_G->setValue( UnsavedOptions.m_ClearColors[1]);
    ui->horizontalSlider_B->setValue( UnsavedOptions.m_ClearColors[2]);
    ui->horizontalSlider_R_Line->setValue( UnsavedOptions.m_LinesColors[0]);
    ui->horizontalSlider_G_Line->setValue( UnsavedOptions.m_LinesColors[1]);
    ui->horizontalSlider_B_Line->setValue( UnsavedOptions.m_LinesColors[2]);
    ui->lineEdit_SceneWidth->setText(QString::number(UnsavedOptions.SceneWidth));
    ui->lineEdit_SceneDepth->setText(QString::number(UnsavedOptions.SceneDepth));
    ui->lineEdit_LineWidth->setText(QString::number(UnsavedOptions.LineWidth));
    ui->lineEdit_LineDepth->setText(QString::number(UnsavedOptions.LineDepth));
}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::on_horizontalSlider_R_valueChanged(int value)
{
    UnsavedOptions.m_ClearColors[0] = value;

}

void OptionsWidget::on_horizontalSlider_G_valueChanged(int value)
{
    UnsavedOptions.m_ClearColors[1] = value;

}

void OptionsWidget::on_horizontalSlider_B_valueChanged(int value)
{
    UnsavedOptions.m_ClearColors[2] = value;
}

void OptionsWidget::on_horizontalSlider_R_Line_valueChanged(int value)
{
    UnsavedOptions.m_LinesColors[0] = value;
}

void OptionsWidget::on_horizontalSlider_G_Line_valueChanged(int value)
{
    UnsavedOptions.m_LinesColors[1] = value;
}


void OptionsWidget::on_horizontalSlider_B_Line_valueChanged(int value)
{
    UnsavedOptions.m_LinesColors[2] = value;
}

void OptionsWidget::updateBackgroundColorBox()
{
    ui->BackgroundColorBox->setStyleSheet("background-color:rgb("
      +QString::number(ui->horizontalSlider_R->value()) + ", "
      +QString::number(ui->horizontalSlider_G->value()) + ", "
      +QString::number(ui->horizontalSlider_B->value()) + ")"
      + ";border-style: outset; border-width: 1px; border-color: black;");
}

void OptionsWidget::updateLinesColorBox()
{
    ui->LinesColorBox->setStyleSheet("background-color:rgb("
      +QString::number(ui->horizontalSlider_R_Line->value()) + ", "
      +QString::number(ui->horizontalSlider_G_Line->value()) + ", "
      +QString::number(ui->horizontalSlider_B_Line->value())+")"
      + ";border-style: outset; border-width: 1px; border-color: black;");
}

void OptionsWidget::on_pushButton_OK_clicked()
{
    SaveSceneOptions();
    SavedOptions = UnsavedOptions;
    emit AcceptOptions(SavedOptions);
    close();
}

void OptionsWidget::on_pushButton_Cancel_clicked()
{
    close();
}

void OptionsWidget::on_pushButton_Apply_clicked()
{
    SavedOptions = UnsavedOptions;
    emit AcceptOptions(SavedOptions);
}

void OptionsWidget::SaveSceneOptions()
{
    UnsavedOptions.LineDepth = ui->lineEdit_LineDepth->text().toDouble();
    UnsavedOptions.LineWidth = ui->lineEdit_LineWidth->text().toDouble();
    UnsavedOptions.SceneDepth = ui->lineEdit_SceneDepth->text().toDouble();
    UnsavedOptions.SceneWidth = ui->lineEdit_SceneWidth->text().toDouble();
}


