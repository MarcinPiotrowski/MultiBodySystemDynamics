#ifndef SIMULATIONWIDGET_H
#define SIMULATIONWIDGET_H

#include <QWidget>
#include <DHeaders.h>
#include <QTimer>
#include <QList>
#include "linkspropertieswidget.h"
#include "basepropertieswidget.h"
#include "projectorygeneratorwindow.h"
#include "positioncontrolerwindow.h"
#include <QTableWidget>
#include "ControlerWidget.h"

namespace Ui {
class simulationwidget;
}

class simulationwidget : public QWidget
{
    Q_OBJECT

public:
    explicit simulationwidget(QWidget *parent = 0);
    ~simulationwidget();
    void SetControler(s_ControlersParameters Controler);


signals:
    void SendParametersToKernel(s_MBSParameters Parameters);
    void StartSimulation(double t0, double tk, double dt);
    void StartRealTimeSimulation(double Speed, double Step);
    void StopRealTimeSimulation();
    void UpdatePostSimulation(int Step);
    void UpdateControlers(s_ControlersParameters);


private slots:
    void UpdateParametersFromKernel(s_MBSParameters MBSParameters);

   // void GetParameters(s_MBSParameters MBSParameters);

    //void GetVariables(s_MBSVariables Variables);

    void UpdateVariablesFromKernel(s_MBSVariables Variables);


    void on_pushButton_showSimulation_clicked();

    void on_pushButton_StartSimulation_clicked();

    void on_pushButton_StartRealTimeSimulation_clicked();

    void on_pushButton_showRealTimeSimulation_clicked();

    void on_pushButton_StopRealTimeSimulation_clicked();

    void on_horizontalSlider_PostSimulationTime_valueChanged(int value);

    void on_pushButton_showPostSimulation_clicked();

    void on_pushButton_showTrajectorySimulation_clicked();

    void on_pushButton_StartTrajectorySimulationSimulation_3_clicked();

    void on_pushButton_showPositionControl_clicked();

    void on_pushButton_OpenControlerWindow_clicked();

    void on_checkBox_clicked();

    void on_pushButton_showHapticControl_clicked();

    void on_pushButton_OpenControlerWindow_2_clicked();

    void GetUpdatedControlers(s_ControlersParameters Controlers);

    void UpdateControlersFromKernel(s_ControlersParameters Controlers);

private:

    s_MBSParameters m_Parameters;

    Ui::simulationwidget *ui;
    LinksPropertiesWidget *LinksWidget;
    BasePropertiesWidget *BaseWidget;
    ProjectoryGeneratorWindow *projectoryGeneratorWindow;
    PositionControlerWindow *positionControlerWindow;
    QList<QTableWidget *> m_Tables;
    ControlerWidget *m_ControlerWindow;

    s_ControlersParameters m_Controler;
};

#endif // SIMULATIONWIDGET_H
