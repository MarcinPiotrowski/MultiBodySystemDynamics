#include "linkspropertieswidget.h"
#include "ui_linkspropertieswidget.h"

LinksPropertiesWidget::LinksPropertiesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LinksPropertiesWidget),
    m_LastIndex(-1)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Dialog );
}

LinksPropertiesWidget::~LinksPropertiesWidget()
{
    delete ui;
}

void LinksPropertiesWidget::on_pushButton_OK_clicked()
{
    m_LastIndex = ui->comboBox_Links->currentIndex();
    UpdateUnsavedParameters();
    m_SavedParameters = m_UnsavedParameters;
    emit SendParameters(m_SavedParameters);

    close();
}

void LinksPropertiesWidget::on_pushButton_Cancel_clicked()
{
    close();
}

void LinksPropertiesWidget::on_pushButton_Apply_clicked()
{
    m_LastIndex = ui->comboBox_Links->currentIndex();
    UpdateUnsavedParameters();
    m_SavedParameters = m_UnsavedParameters;
    emit SendParameters(m_SavedParameters);
}

void LinksPropertiesWidget::SetLinksProperties(s_MBSParameters Parameters)
{

    m_UnsavedParameters = Parameters;
    Setup();
}

void LinksPropertiesWidget::UpdateUnsavedParameters()
{
    QString str;
    str = ui->lineEdit_Mass->text();
    QStringList list1 = str.split("  kg");


    m_UnsavedParameters.LinkParameters[m_LastIndex].Mass = list1.takeAt(0).toDouble();

    str = ui->lineEdit_Ixx->text();
    list1 = str.split("  kg-m^2");
    m_UnsavedParameters.LinkParameters[m_LastIndex].Ixx = list1.takeAt(0).toDouble();

    str = ui->lineEdit_Iyy->text();
    list1 = str.split("  kg-m^2");
    m_UnsavedParameters.LinkParameters[m_LastIndex].Iyy = list1.takeAt(0).toDouble();

    str = ui->lineEdit_Izz->text();
    list1 = str.split("  kg-m^2");
    m_UnsavedParameters.LinkParameters[m_LastIndex].Izz = list1.takeAt(0).toDouble();
}

void LinksPropertiesWidget::Setup()
{
    ui->comboBox_Links->clear();
    for(int i = 0 ; i < m_UnsavedParameters.NumberOfJoints ; i++)
        ui->comboBox_Links->addItem("Link " + QString::number(i));

    ui->lineEdit_Mass->setText(QString::number(m_UnsavedParameters.LinkParameters[0].Mass) + "  kg");
    ui->lineEdit_Ixx->setText(QString::number(m_UnsavedParameters.LinkParameters[0].Ixx) + "  kg-m^2");
    ui->lineEdit_Iyy->setText(QString::number(m_UnsavedParameters.LinkParameters[0].Iyy) + "  kg-m^2");
    ui->lineEdit_Izz->setText(QString::number(m_UnsavedParameters.LinkParameters[0].Izz) + "  kg-m^2");
    if(m_UnsavedParameters.LinkParameters[0].GraphicModel == GM_DEFUALT)
        {
        ui->radioButton_Default->setChecked(true);
        ui->radioButton_LoadedModel->setChecked(false);
        }
    else
        {
        ui->radioButton_Default->setChecked(false);
        ui->radioButton_LoadedModel->setChecked(true);
        }
}

s_MBSParameters LinksPropertiesWidget::GetLinksProperties()
{
    return m_SavedParameters;
}

void LinksPropertiesWidget::on_comboBox_Links_currentIndexChanged(int index)
{
    if(m_LastIndex != -1)
        UpdateUnsavedParameters();
    m_LastIndex = index;
    ui->lineEdit_Mass->setText(QString::number(m_UnsavedParameters.LinkParameters[index].Mass) + "  kg");
    ui->lineEdit_Ixx->setText(QString::number(m_UnsavedParameters.LinkParameters[index].Ixx) + "  kg-m^2");
    ui->lineEdit_Iyy->setText(QString::number(m_UnsavedParameters.LinkParameters[index].Iyy) + "  kg-m^2");
    ui->lineEdit_Izz->setText(QString::number(m_UnsavedParameters.LinkParameters[index].Izz) + "  kg-m^2");
    if(m_UnsavedParameters.LinkParameters[index].GraphicModel == GM_DEFUALT)
        {
        ui->radioButton_Default->setChecked(true);
        ui->radioButton_LoadedModel->setChecked(false);
        ui->label_LoadedModelName->setText("--------");
        }
    else
        {
        ui->radioButton_Default->setChecked(false);
        ui->radioButton_LoadedModel->setChecked(true);

        QFileInfo fileInfo(m_UnsavedParameters.LinkParameters[ui->comboBox_Links->currentIndex()].ModelPath);
        QString fileName(fileInfo.fileName());
        ui->label_LoadedModelName->setText(fileName);
        ui->label_LoadedModelName->setToolTip(fileName);
        }
}

void LinksPropertiesWidget::on_radioButton_LoadedModel_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import OBJ model"),
                                                     "",
                                                     tr("Wavefront .obj (*.obj)"));
    if (fileName.length() == 0)
        {
        if(m_UnsavedParameters.LinkParameters[ui->comboBox_Links->currentIndex()].GraphicModel == GM_DEFUALT )
            {
            ui->radioButton_Default->setChecked(true);
            ui->radioButton_LoadedModel->setChecked(false);
            }
        }
    else
        {
        m_UnsavedParameters.LinkParameters[ui->comboBox_Links->currentIndex()].GraphicModel = GM_LOADED;
        QFileInfo fileInfo(fileName);
        QString fileName(fileInfo.absoluteFilePath());
       // QString fileName(fileInfo.fileName());
        ui->label_LoadedModelName->setText(fileInfo.fileName());
        ui->label_LoadedModelName->setToolTip(fileInfo.fileName());
        m_UnsavedParameters.LinkParameters[ui->comboBox_Links->currentIndex()].ModelPath = fileName;
        }
}


void LinksPropertiesWidget::on_radioButton_Default_clicked()
{
    ui->label_LoadedModelName->setText("--------");
    m_UnsavedParameters.LinkParameters[ui->comboBox_Links->currentIndex()].GraphicModel = GM_DEFUALT;
}
