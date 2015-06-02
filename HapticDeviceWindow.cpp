#include "HapticDeviceWindow.h"
#include "ui_HapticDeviceWindow.h"

HapticDeviceWindow::HapticDeviceWindow(HControler *HapticControler, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HapticDeviceWindow)
{
    m_HapticControler = HapticControler;
    ui->setupUi(this);
    GetLastOptions(D_DEVICE1);
    GetLastOptions(D_DEVICE2);
    UpdateStatus(D_DEVICE1);
    UpdateStatus(D_DEVICE2);
}

HapticDeviceWindow::~HapticDeviceWindow()
{
    delete ui;
}



void HapticDeviceWindow::on_pushButton_Cancel_1_clicked()
{
    GetLastOptions(D_DEVICE1);
}

void HapticDeviceWindow::on_pushButton_Cancel_2_clicked()
{
    GetLastOptions(D_DEVICE2);
}

void HapticDeviceWindow::on_pushButton_Accept_1_clicked()
{
    SetCurrentOptions(D_DEVICE1);
}

void HapticDeviceWindow::on_pushButton_Accept_2_clicked()
{
    SetCurrentOptions(D_DEVICE2);
}

void HapticDeviceWindow::on_pushButton_Disconnected_1_clicked()
{
    m_HapticControler->DisconnetFromDevice(D_DEVICE1);
    UpdateStatus(D_DEVICE1);
}

void HapticDeviceWindow::on_pushButton_Connected_1_clicked()
{
    m_HapticControler->ConnectToDevice(D_DEVICE1);
    UpdateStatus(D_DEVICE1);
}

void HapticDeviceWindow::on_pushButton_Disconnected_2_clicked()
{
    m_HapticControler->DisconnetFromDevice(D_DEVICE2);
    UpdateStatus(D_DEVICE2);
}

void HapticDeviceWindow::on_pushButton_Connected_2_clicked()
{
    m_HapticControler->ConnectToDevice(D_DEVICE2);
    UpdateStatus(D_DEVICE2);
}

void HapticDeviceWindow::GetLastOptions(e_Device Device)
{
    if(Device == D_DEVICE1)
        {
        ui->lineEdit_MaxForce_1->setText(QString::number(m_HapticControler->GetMaxForce(D_DEVICE1)));
        ui->horizontalSlider_PointerSize_1->setValue(m_HapticControler->GetPointerSize(D_DEVICE1));
        }
    else if(Device == D_DEVICE2)
        {
        ui->lineEdit_MaxForce_2->setText(QString::number(m_HapticControler->GetMaxForce(D_DEVICE2)));
        ui->horizontalSlider_PointerSize_2->setValue(m_HapticControler->GetPointerSize(D_DEVICE2));
        }
}

void HapticDeviceWindow::SetCurrentOptions(e_Device Device)
{
    if(Device == D_DEVICE1)
        {
        m_HapticControler->SetMaxForce(ui->lineEdit_MaxForce_1->text().toDouble(),D_DEVICE1);
        m_HapticControler->SetPointerSize(ui->horizontalSlider_PointerSize_1->value(),D_DEVICE1);
        }
    else if(Device == D_DEVICE2)
        {
        m_HapticControler->SetMaxForce(ui->lineEdit_MaxForce_2->text().toDouble(),D_DEVICE2);
        m_HapticControler->SetPointerSize(ui->horizontalSlider_PointerSize_2->value(),D_DEVICE2);
        }
}

void HapticDeviceWindow::UpdateStatus(e_Device Device)
{
    if(m_HapticControler->GetStatus(Device) == true)
        {
        if(Device == D_DEVICE1)
            {
            ui->label_Status_1->setText("Connected");
            ui->pushButton_Connected_1->setEnabled(false);
            ui->pushButton_Disconnected_1->setEnabled(true);
            }
        if(Device == D_DEVICE2)
            {
            ui->label_Status_2->setText("Connected");
            ui->pushButton_Connected_2->setEnabled(false);
            ui->pushButton_Disconnected_2->setEnabled(true);
            }
        }
    else
        {
        if(Device == D_DEVICE1)
            {
            ui->label_Status_1->setText("Disconnected");
            ui->pushButton_Connected_1->setEnabled(true);
            ui->pushButton_Disconnected_1->setEnabled(false);
            }
        if(Device == D_DEVICE2)
            {
            ui->label_Status_2->setText("Disconnected");
            ui->pushButton_Connected_2->setEnabled(true);
            ui->pushButton_Disconnected_2->setEnabled(false);
            }
        }
}
