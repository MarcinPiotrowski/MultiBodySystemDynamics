/* *******************
 * File name : basepropertieswidget.cpp
 * Author : Marcin Piotrowski
 * Created : 2015-03-01    20:33
 * Brief : See basepropertieswidget.h.
 * *******************
 */

#include "basepropertieswidget.h"
#include "ui_basepropertieswidget.h"

/*  Constructor
    *@class BasePropertiesWidget
    *@param
    */
BasePropertiesWidget::BasePropertiesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BasePropertiesWidget)
{
    ui->setupUi(this);

}

/*  Destructor
    *@class BasePropertiesWidget
    */
BasePropertiesWidget::~BasePropertiesWidget()
{
    delete ui;
}

/*  Method
    *@brief: This method sets base properties.
    *@param Parameters: Parameters of the Multibody Object
    *@retval: None
    */
void BasePropertiesWidget::SetBaseProperties(s_MBSParameters Parameters)
{
    m_UnsavedParameters = Parameters;
    Setup();
}

/*  Method
    *@brief: This method returns Multibody Object parameters
    *@param
    *@retval
    */
s_MBSParameters BasePropertiesWidget::GetBaseProperties()
{
    return m_SavedParameters;
}

/*  Method
    *@brief: This method setup widget getting data from Multibody Object parameters
    *@param: None
    *@retval: None
    */
void BasePropertiesWidget::Setup()
{
    ui->lineEdit_x->setText(QString::number(m_UnsavedParameters.BaseParameters.Xposition));
    ui->lineEdit_y->setText(QString::number(m_UnsavedParameters.BaseParameters.Yposition));
    ui->lineEdit_z->setText(QString::number(m_UnsavedParameters.BaseParameters.Zposition));

    if(m_UnsavedParameters.BaseParameters.GraphicModel == GM_DEFUALT)
        {
        ui->radioButton_Default->setChecked(true);
        ui->radioButton_LoadedModel->setChecked(false);
        }
    else
        {
        ui->radioButton_Default->setChecked(false);
        ui->radioButton_LoadedModel->setChecked(true);

        QFileInfo fileInfo(m_UnsavedParameters.BaseParameters.ModelPath);
        QString fileName(fileInfo.fileName());
        ui->label_LoadedModelName->setText(fileName);
        ui->label_LoadedModelName->setToolTip(fileName);
        }
}

/*  Method
    *@brief: This method update parameters of the base.
    *@param: None
    *@retval: None
    */
void BasePropertiesWidget::UpdateUnsavedParameters()
{
    m_UnsavedParameters.BaseParameters.Xposition = ui->lineEdit_x->text().toDouble();
    m_UnsavedParameters.BaseParameters.Yposition = ui->lineEdit_y->text().toDouble();
    m_UnsavedParameters.BaseParameters.Zposition = ui->lineEdit_z->text().toDouble();
}

/* Slot
    *@brief: This slot update graphic model name.
    *@param: None
    *@retval: None
    */
void BasePropertiesWidget::on_radioButton_Default_clicked()
{
        ui->label_LoadedModelName->setText("--------");
        m_UnsavedParameters.BaseParameters.GraphicModel = GM_DEFUALT;
}

/*  Slot
    *@brief: This Slot loads 3D model path
    *@param: None
    *@retval: None
    */
void BasePropertiesWidget::on_radioButton_LoadedModel_clicked()
{
        QString fileName = QFileDialog::getOpenFileName(this, tr("Import OBJ model"),
                                                         "",
                                                         tr("Wavefront .obj (*.obj)"));

        if (fileName.length() == 0)
            {
            if(m_UnsavedParameters.BaseParameters.GraphicModel == GM_DEFUALT )
                {
                ui->radioButton_Default->setChecked(true);
                ui->radioButton_LoadedModel->setChecked(false);
                }
            }
        else
            {
            m_UnsavedParameters.BaseParameters.GraphicModel = GM_LOADED;
            QFileInfo fileInfo(fileName);
            QString fileName(fileInfo.absoluteFilePath());
            ui->label_LoadedModelName->setText(fileInfo.fileName());
            ui->label_LoadedModelName->setToolTip(fileInfo.fileName());
            m_UnsavedParameters.BaseParameters.ModelPath = fileName;
            }
}

/*  Slot
    *@brief: This slot save current parameters and close the widget.
    *@param: None
    */
void BasePropertiesWidget::on_pushButton_OK__clicked()
{
    UpdateUnsavedParameters();
    m_SavedParameters = m_UnsavedParameters;
    emit SendParameters(m_SavedParameters);
    close();
}

/*  Slot
    *@brief: This slot close the widget
    *@param: None
    */
void BasePropertiesWidget::on_pushButton_Cancel__clicked()
{
    close();
}

/*  Slot
    *@brief: This slot save current parameters.
    *@param: None
    */
void BasePropertiesWidget::on_pushButton_Apply__clicked()
{
    UpdateUnsavedParameters();
    m_SavedParameters = m_UnsavedParameters;
    emit SendParameters(m_SavedParameters);
}
