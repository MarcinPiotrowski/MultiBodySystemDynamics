/* *******************
 * File name : multibodysysteminfowidget.h
 * Author : Marcin Piotrowski
 * Created : 17.04.2015    20:00
 * Brief :
 * *******************
 */


#ifndef MULTIBODYSYSTEMINFOWIDGET_H
#define MULTIBODYSYSTEMINFOWIDGET_H

#include <QWidget>
#include <DHeaders.h>
#include <QTimer>
#include <QList>
#include "linkspropertieswidget.h"
#include "basepropertieswidget.h"
#include "projectorygeneratorwindow.h"
#include "positioncontrolerwindow.h"
#include <QTableWidget>

namespace Ui {
class MultibodySystemInfoWidget;
}

class MultibodySystemInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultibodySystemInfoWidget(QWidget *parent = 0);
    ~MultibodySystemInfoWidget();

signals:
    void SendParametersToKernel(s_MBSParameters Parameters);
    void StartSimulation(double t0, double tk, double dt);
    void StartRealTimeSimulation(double Speed, double Step);
    void StopRealTimeSimulation();
    void UpdatePostSimulation(int Step);
    void Refresh();

private slots:
    void UpdateVariablesFromKernel(s_MBSVariables MBSVariables);

    void UpdateParametersFromKernel(s_MBSParameters MBSParameters);

    void on_pushButton_showDetails_clicked(bool checked);

    void on_pushButton_showJointAccelerations_clicked(bool checked);

    void on_toolButton_LinksProperties_clicked();

    void on_pushButton_showJointPositions_clicked();

    void on_pushButton_showJointVelocities_clicked();

    void GetParameters(s_MBSParameters Parameters);

    void on_toolButton_BaseProperties_clicked();

    void on_pushButton_showKineticEnergy_clicked();

    void on_pushButton_StartTrajectorySimulationSimulation_3_clicked();

    void on_pushButton_showPotentialEnergy_clicked();

    void on_pushButton_clicked();

private:
    Ui::MultibodySystemInfoWidget *ui;


    s_MBSParameters m_Parameters;
    LinksPropertiesWidget *LinksWidget;
    BasePropertiesWidget *BaseWidget;
    ProjectoryGeneratorWindow *projectoryGeneratorWindow;
    PositionControlerWindow *positionControlerWindow;
    QList<QTableWidget *> m_Tables;
};






#endif // MULTIBODYSYSTEMINFOWIDGET_H
