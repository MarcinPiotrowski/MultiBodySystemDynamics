/* *******************
 * File name : MainWindow.h
 * Author : Marcin Piotrowski
 * Created : 15.04.2015    19:53
 * Brief : This is the main window of the application. It containts other windows, like
 *         window rendering scene, window to display Multibody System information, menubar etc.
 * *******************
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QFileDialog>
#include "GRender.h"
#include "optionswidget.h"
#include "programoptions.h"
#include "linkspropertieswidget.h"
#include "dialogmeasurement.h"
#include "KMain.h"
#include "HapticDeviceWindow.h"
#include "PlotWindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    KMain *KernelMain;                          // Main object of the program
    Ui::MainWindow *ui;                         // User interface
    OptionsWidget* optionsWidget;               // Options Widget
    ProgramOptions options;                     // Struct containing all program options
    DialogMeasurement* dialogMeasurement;       /* Window containing information about script in ADAMS
                                                   to create measurements automatically */
    HapticDeviceWindow *m_HapticDeviceWindow;
    QList<PlotWindow *> m_PlotWindowList;


    double SelectDataFromVariables(s_MBSVariables Variables, PW_DataType DataType, int DataTypeNumber);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void test2();

private slots:
    void on_actionExit_triggered();
    void on_actionOptions_triggered();
    void on_actionImport_ADAMS_model_triggered();
    void on_actionImport_ADAMS_Pre_simulated_model_triggered();
    void on_actionGenerate_ADAMS_Measure_Command_triggered();
    void on_actionSave_As_triggered();
    void on_actionHaptic_Devices_Support_triggered();
    void on_actionCreate_new_plot_triggered();
    void UpdatePlots(s_MBSVariables, double);
};

#endif // MAINWINDOW_H
