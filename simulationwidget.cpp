#include "simulationwidget.h"
#include "ui_simulationwidget.h"
#include <QDebug>
#include <QScrollBar>
#include <QTableWidgetItem>



simulationwidget::simulationwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simulationwidget)
{
    ui->setupUi(this);

    ui->groupBox->setDisabled(true);
    ui->groupBox_Simulation->hide();
    ui->groupBox_RealTimeSimulation->hide();
    ui->groupBox_PostSimulation->hide();
    ui->groupBox_TrajectorySimulation->hide();
    ui->groupBox_PositionControl->hide();
    ui->groupBox_HapticControl->hide();

}

simulationwidget::~simulationwidget()
{
    delete ui;
}


void simulationwidget::UpdateParametersFromKernel(s_MBSParameters MBSParameters)
{
    ui->groupBox->setDisabled(false);


//    if(MBSParameters.AnalisysType = A_ANIMATION)
//        {
//        ui->pushButton_showRealTimeSimulation->setDisabled(true);
//        ui->pushButton_showSimulation->setDisabled(true);
//        ui->label_Simulation->setDisabled(true);
//        ui->label_RealTimeSimulation->setDisabled(true);
//        }


    ui->lineEdit_Speed->setText(" x " + QString::number(MBSParameters.SimulationSpeed));
    ui->lineEdit_RealTimeSimulationStep->setText(QString::number(MBSParameters.RealTimeSimulationStep));

    m_Parameters=MBSParameters;

}


//void simulationwidget::GetParameters(s_MBSParameters Parameters)
//{
//    m_Parameters = Parameters;
//    emit SendParametersToKernel(m_Parameters);
//}


void simulationwidget::on_pushButton_StartSimulation_clicked()
{
    emit StartSimulation(ui->lineEdit_StartTime->text().toDouble(),
                         ui->lineEdit_EndTime->text().toDouble(),
                         ui->lineEdit_Step->text().toDouble());
}

void simulationwidget::on_pushButton_StartRealTimeSimulation_clicked()
{
    emit StartRealTimeSimulation(ui->lineEdit_Speed->text().toDouble(),ui->lineEdit_RealTimeSimulationStep->text().toDouble());
    ui->pushButton_StartRealTimeSimulation->setDisabled(true);
    ui->pushButton_StopRealTimeSimulation->setEnabled(true);
}



void simulationwidget::on_pushButton_StopRealTimeSimulation_clicked()
{
    emit StopRealTimeSimulation();
    ui->pushButton_StartRealTimeSimulation->setEnabled(true);
    ui->pushButton_StopRealTimeSimulation->setDisabled(true);
}

void simulationwidget::on_horizontalSlider_PostSimulationTime_valueChanged(int value)
{
    emit UpdatePostSimulation(value);
}


void simulationwidget::on_pushButton_showSimulation_clicked()
{
    if(ui->groupBox_Simulation->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showSimulation->setIcon(ButtonIcon);
        ui->groupBox_Simulation->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showSimulation->setIcon(ButtonIcon);
        ui->groupBox_Simulation->show();
        }
}

void simulationwidget::on_pushButton_showRealTimeSimulation_clicked()
{
    if(ui->groupBox_RealTimeSimulation->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showRealTimeSimulation->setIcon(ButtonIcon);
        ui->groupBox_RealTimeSimulation->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showRealTimeSimulation->setIcon(ButtonIcon);
        ui->groupBox_RealTimeSimulation->show();
        }
}

void simulationwidget::on_pushButton_showPostSimulation_clicked()
{
    if(ui->groupBox_PostSimulation->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPostSimulation->setIcon(ButtonIcon);
        ui->groupBox_PostSimulation->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPostSimulation->setIcon(ButtonIcon);
        ui->groupBox_PostSimulation->show();
        }

}

void simulationwidget::on_pushButton_showTrajectorySimulation_clicked()
{
    if(ui->groupBox_TrajectorySimulation->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showTrajectorySimulation->setIcon(ButtonIcon);
        ui->groupBox_TrajectorySimulation->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showTrajectorySimulation->setIcon(ButtonIcon);
        ui->groupBox_TrajectorySimulation->show();
        }
}

void simulationwidget::on_pushButton_showPositionControl_clicked()
{
    if(ui->groupBox_PositionControl->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPositionControl->setIcon(ButtonIcon);
        ui->groupBox_PositionControl->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPositionControl->setIcon(ButtonIcon);
        ui->groupBox_PositionControl->show();
        }
}


void simulationwidget::on_pushButton_showHapticControl_clicked()
{
    if(ui->groupBox_HapticControl->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showHapticControl->setIcon(ButtonIcon);
        ui->groupBox_HapticControl->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showHapticControl->setIcon(ButtonIcon);
        ui->groupBox_HapticControl->show();
        }
}

void simulationwidget::on_checkBox_clicked()
{

}


void simulationwidget::on_pushButton_StartTrajectorySimulationSimulation_3_clicked()
{
    projectoryGeneratorWindow = new ProjectoryGeneratorWindow;
    projectoryGeneratorWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    projectoryGeneratorWindow->show();
}



void simulationwidget::on_pushButton_OpenControlerWindow_clicked()
{
    positionControlerWindow = new PositionControlerWindow;
    positionControlerWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    positionControlerWindow->show();
}

/*  Slot
    *@brief
    *@param
    */
void simulationwidget::UpdateVariablesFromKernel(s_MBSVariables Variables)
{
    // ui->groupBox->setDisabled(!State);
}


void simulationwidget::on_pushButton_OpenControlerWindow_2_clicked()
{
     m_ControlerWindow = new ControlerWidget();
     m_ControlerWindow->setAttribute(Qt::WA_DeleteOnClose, true);
     connect(m_ControlerWindow, SIGNAL(UpdateControler(s_ControlersParameters)),
             this, SLOT(GetUpdatedControlers(s_ControlersParameters)));
     m_ControlerWindow->SetControler(m_Controler);
     m_ControlerWindow->show();
}

void simulationwidget::SetControler(s_ControlersParameters Controler)
{
    m_Controler = Controler;
}


void simulationwidget::GetUpdatedControlers(s_ControlersParameters Controlers)
{
    m_Controler = Controlers;
    emit UpdateControlers(Controlers);
}

void simulationwidget::UpdateControlersFromKernel(s_ControlersParameters Controlers)
{
    m_Controler = Controlers;
}



