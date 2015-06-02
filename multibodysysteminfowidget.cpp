/* *******************
 * File name : multibodysysteminfowidget.cpp
 * Author : Marcin Piotrowski
 * Created : 17.04.2015    19:59
 * Brief : See multibodysysteminfowidget.h
 * *******************
 */


#include "multibodysysteminfowidget.h"
#include "ui_multibodysysteminfowidget.h"
#include <QDebug>
#include <QScrollBar>
#include <QTableWidgetItem>



MultibodySystemInfoWidget::MultibodySystemInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultibodySystemInfoWidget)
{
    ui->setupUi(this);

   //TD ui->pushButton_showDetails->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
   //TD ui->pushButton_showDetails->setStyleSheet ("text-align:left");

    ui->groupBox->setDisabled(true);
    ui->groupBox_JointsPositions->hide();
    ui->groupBox_JointsVelocities->hide();
    ui->groupBox_JointAccelerations->hide();
    ui->groupBox_2->hide();
    ui->groupBox_KineticEnergy->hide();
    ui->groupBox_PotentialEnergy->hide();

    m_Tables.append(ui->tableJointPositions);
    m_Tables.append(ui->tableJointVelocities);
    m_Tables.append(ui->tableJointAcceleration);
    m_Tables.append(ui->table_KineticEnergy);
    m_Tables.append(ui->table_PotentialEnergy);


    for( int i = 0 ; i < m_Tables.length() ; i++)
        {
        m_Tables.at(i)->setFrameStyle(QFrame::NoFrame);
        m_Tables.at(i)->verticalHeader()->setVisible(false);
        m_Tables.at(i)->horizontalHeader()->setVisible(false);
        m_Tables.at(i)->setShowGrid(false);
        m_Tables.at(i)->setStyleSheet("background-color: rgba(255,255,255,0);");
        m_Tables.at(i)->setSelectionMode(QAbstractItemView::NoSelection);
        m_Tables.at(i)->setFocusPolicy(Qt::NoFocus);
        m_Tables.at(i)->verticalScrollBar()->setDisabled(true);
        m_Tables.at(i)->verticalScrollBar()->hide();
        m_Tables.at(i)->horizontalScrollBar()->setDisabled(true);
        m_Tables.at(i)->horizontalScrollBar()->hide();
        }
}



MultibodySystemInfoWidget::~MultibodySystemInfoWidget()
{
    delete ui;
}


void MultibodySystemInfoWidget::UpdateParametersFromKernel(s_MBSParameters MBSParameters)
{
    ui->groupBox->setDisabled(false);
    ui->MBSName->setText(MBSParameters.Name);
    ui->MBSName->setToolTip(MBSParameters.Name);
    ui->NumberOfJoints->setText(QString::number(MBSParameters.NumberOfJoints));

//    if(MBSParameters.AnalisysType = A_ANIMATION)
//        {
//        ui->pushButton_showRealTimeSimulation->setDisabled(true);
//        ui->pushButton_showSimulation->setDisabled(true);
//        ui->label_Simulation->setDisabled(true);
//        ui->label_RealTimeSimulation->setDisabled(true);
//        }

    ui->tableJointPositions->setRowCount(MBSParameters.NumberOfJoints);
    ui->tableJointPositions->setColumnCount(2);
    ui->tableJointVelocities->setRowCount(MBSParameters.NumberOfJoints);
    ui->tableJointVelocities->setColumnCount(2);
    ui->tableJointAcceleration->setRowCount(MBSParameters.NumberOfJoints);
    ui->tableJointAcceleration->setColumnCount(2);
    ui->table_KineticEnergy->setRowCount(MBSParameters.NumberOfJoints+1);
    ui->table_KineticEnergy->setColumnCount(2);
    ui->table_PotentialEnergy->setRowCount(MBSParameters.NumberOfJoints+1);
    ui->table_PotentialEnergy->setColumnCount(2);

    /** Create table of joints positions, velocities and accelerations **/
    QString text = "Joint ";
    for( int i = 0 ; i < MBSParameters.NumberOfJoints ; i++)
    {
       ui->tableJointPositions->setItem(i, 0, new QTableWidgetItem);
       ui->tableJointPositions->setItem(i, 1, new QTableWidgetItem);
       ui->tableJointPositions->item(i,0)->setText(text + QString::number( i ) + ":");

       ui->tableJointVelocities->setItem(i, 0, new QTableWidgetItem);
       ui->tableJointVelocities->setItem(i, 1, new QTableWidgetItem);
       ui->tableJointVelocities->item(i,0)->setText(text + QString::number( i ) + ":");

       ui->tableJointAcceleration->setItem(i, 0, new QTableWidgetItem);
       ui->tableJointAcceleration->setItem(i, 1, new QTableWidgetItem);
       ui->tableJointAcceleration->item(i,0)->setText(text + QString::number( i ) + ":");

       ui->table_KineticEnergy->setItem(i, 0, new QTableWidgetItem);
       ui->table_KineticEnergy->setItem(i, 1, new QTableWidgetItem);
       ui->table_KineticEnergy->item(i,0)->setText(text + QString::number( i ) + ":");

       ui->table_PotentialEnergy->setItem(i, 0, new QTableWidgetItem);
       ui->table_PotentialEnergy->setItem(i, 1, new QTableWidgetItem);
       ui->table_PotentialEnergy->item(i,0)->setText(text + QString::number( i ) + ":");
    }

    ui->table_KineticEnergy->setItem(6, 0, new QTableWidgetItem);
    ui->table_KineticEnergy->setItem(6, 1, new QTableWidgetItem);
    ui->table_KineticEnergy->item(6,0)->setText("Total:");

    ui->table_PotentialEnergy->setItem(6, 0, new QTableWidgetItem);
    ui->table_PotentialEnergy->setItem(6, 1, new QTableWidgetItem);
    ui->table_PotentialEnergy->item(6,0)->setText("Total:");

    for (int i = 0; i < MBSParameters.NumberOfJoints; i++)
        {
        ui->tableJointPositions->verticalHeader()->resizeSection(i, 20);
        ui->tableJointVelocities->verticalHeader()->resizeSection(i, 20);
        ui->tableJointAcceleration->verticalHeader()->resizeSection(i, 20);
        ui->table_KineticEnergy->verticalHeader()->resizeSection(i, 20);
        ui->table_PotentialEnergy->verticalHeader()->resizeSection(i, 20);
        }

    // ui->table_KineticEnergy->verticalHeader()->resizeSection(7, 20);

    ui->tableJointPositions->horizontalHeader()->resizeSection(0,50);
    ui->tableJointVelocities->horizontalHeader()->resizeSection(0,50);
    ui->tableJointAcceleration->horizontalHeader()->resizeSection(0,50);
    ui->table_KineticEnergy->horizontalHeader()->resizeSection(0,50);
    ui->table_PotentialEnergy->horizontalHeader()->resizeSection(0,50);
    ui->tableJointPositions->horizontalHeader()->resizeSection(1,60);
    ui->tableJointVelocities->horizontalHeader()->resizeSection(1,60);
    ui->tableJointAcceleration->horizontalHeader()->resizeSection(1,60);
    ui->table_KineticEnergy->horizontalHeader()->resizeSection(1,60);
    ui->table_PotentialEnergy->horizontalHeader()->resizeSection(1,60);

    ui->tableJointPositions->setMinimumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->tableJointVelocities->setMinimumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->tableJointAcceleration->setMinimumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->table_KineticEnergy->setMinimumHeight( (MBSParameters.NumberOfJoints+1)*20+15);
    ui->table_PotentialEnergy->setMinimumHeight( (MBSParameters.NumberOfJoints+1)*20+15);
    ui->tableJointPositions->setMaximumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->tableJointVelocities->setMaximumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->tableJointAcceleration->setMaximumHeight(MBSParameters.NumberOfJoints*20+15);
    ui->table_KineticEnergy->setMaximumHeight( (MBSParameters.NumberOfJoints+1)*20+15);
    ui->table_PotentialEnergy->setMaximumHeight( (MBSParameters.NumberOfJoints+1)*20+15);


    m_Parameters=MBSParameters;

}

void MultibodySystemInfoWidget::UpdateVariablesFromKernel(s_MBSVariables MBSVariables)
{
    for( int i = 0 ; i < ui->tableJointAcceleration->rowCount() ; i++)
        {
        ui->tableJointPositions->item(i,1)->setText(QString::number(MBSVariables.JointsPositions[i]));
        ui->tableJointVelocities->item(i,1)->setText(QString::number(MBSVariables.JointsVelocities[i]));
        ui->tableJointAcceleration->item(i,1)->setText(QString::number(MBSVariables.JointsAccelerations[i]));
        ui->table_KineticEnergy->item(i,1)->setText(QString::number(MBSVariables.KineticEnergies[i]));
        ui->table_PotentialEnergy->item(i,1)->setText(QString::number(MBSVariables.PotentialEnergy[i]));
        }
    ui->table_KineticEnergy->item(ui->table_KineticEnergy->rowCount()-1,1)->setText(QString::number(MBSVariables.TotalKineticEnergy));
    ui->table_PotentialEnergy->item(ui->table_PotentialEnergy->rowCount()-1,1)->setText(QString::number(MBSVariables.TotalPotentialEnergy));
}



void MultibodySystemInfoWidget::on_toolButton_LinksProperties_clicked()
{
    LinksWidget = new LinksPropertiesWidget;
    LinksWidget->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(LinksWidget,SIGNAL(SendParameters(s_MBSParameters)),
            this, SLOT(GetParameters(s_MBSParameters)));
    LinksWidget->show();
    LinksWidget->SetLinksProperties(m_Parameters);
}


void MultibodySystemInfoWidget::on_toolButton_BaseProperties_clicked()
{
    BaseWidget = new BasePropertiesWidget;
    BaseWidget->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(BaseWidget,SIGNAL(SendParameters(s_MBSParameters)),
            this, SLOT(GetParameters(s_MBSParameters)));
    BaseWidget->show();
    BaseWidget->SetBaseProperties(m_Parameters);

}

void MultibodySystemInfoWidget::GetParameters(s_MBSParameters Parameters)
{
    m_Parameters = Parameters;
    emit SendParametersToKernel(m_Parameters);
}






void MultibodySystemInfoWidget::on_pushButton_showDetails_clicked(bool checked)
{
    if(ui->groupBox_2->isVisible())
    {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showDetails->setIcon(ButtonIcon);
        ui->groupBox_2->hide();
    }
    else
    {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showDetails->setIcon(ButtonIcon);
        ui->groupBox_2->show();
    }
}

void MultibodySystemInfoWidget::on_pushButton_showJointPositions_clicked()
{
    if(ui->groupBox_JointsPositions->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointPositions->setIcon(ButtonIcon);
        ui->groupBox_JointsPositions->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointPositions->setIcon(ButtonIcon);
        ui->groupBox_JointsPositions->show();
        }
}

void MultibodySystemInfoWidget::on_pushButton_showJointVelocities_clicked()
{
    if(ui->groupBox_JointsVelocities->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointVelocities->setIcon(ButtonIcon);
        ui->groupBox_JointsVelocities->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointVelocities->setIcon(ButtonIcon);
        ui->groupBox_JointsVelocities->show();
        }

}

void MultibodySystemInfoWidget::on_pushButton_showJointAccelerations_clicked(bool checked)
{
    if(ui->groupBox_JointAccelerations->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointAccelerations->setIcon(ButtonIcon);
        ui->groupBox_JointAccelerations->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showJointAccelerations->setIcon(ButtonIcon);
        ui->groupBox_JointAccelerations->show();
        }
}


void MultibodySystemInfoWidget::on_pushButton_showKineticEnergy_clicked()
{
    if(ui->groupBox_KineticEnergy->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showKineticEnergy->setIcon(ButtonIcon);
        ui->groupBox_KineticEnergy->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showKineticEnergy->setIcon(ButtonIcon);
        ui->groupBox_KineticEnergy->show();
        }
}

void MultibodySystemInfoWidget::on_pushButton_showPotentialEnergy_clicked()
{
    if(ui->groupBox_PotentialEnergy->isVisible())
        {
        QPixmap pixmap(":/Res/Images/arrow.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPotentialEnergy->setIcon(ButtonIcon);
        ui->groupBox_PotentialEnergy->hide();
        }
    else
        {
        QPixmap pixmap(":/Res/Images/arrow_down.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton_showPotentialEnergy->setIcon(ButtonIcon);
        ui->groupBox_PotentialEnergy->show();
        }
}

void MultibodySystemInfoWidget::on_pushButton_StartTrajectorySimulationSimulation_3_clicked()
{
    projectoryGeneratorWindow = new ProjectoryGeneratorWindow;
    projectoryGeneratorWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    projectoryGeneratorWindow->show();
}




void MultibodySystemInfoWidget::on_pushButton_clicked()
{
    emit Refresh();
}
