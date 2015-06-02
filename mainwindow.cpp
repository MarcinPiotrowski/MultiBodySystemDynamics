/* *******************
 * File name : MainWindow.cpp
 * Author : Marcin Piotrowski
 * Created : 11.04.2015    21:13
 * Brief : See MainWindow.h
 * *******************
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DHeaders.h"
#include <QDebug>
#include "COTrajectoryGenerator.h"


/*  Constructor
    *@class MainWindow
    *@param parent
    */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /** Create main object of the program **/
    KernelMain = new KMain(ui->glWidget);
    //KernelMain->SetSimulationWidget(ui->SimulationWidget);

    /** Connect signals to slots - sending parameters to KernelMain **/
     connect(ui->MultibodyObjectsWidget, SIGNAL(SendParametersToKernel(s_MBSParameters)),
             KernelMain,SLOT(GetParameters(s_MBSParameters)));                        /** Update Multibody System variables in glWidget **/
     connect(ui->SimulationWidget, SIGNAL(StartSimulation(double,double,double)),
             KernelMain, SLOT(PerformSingleSimulation(double,double,double)));                     /** Start single simulation **/
     connect(ui->SimulationWidget, SIGNAL(StartRealTimeSimulation(double,double)),
             KernelMain, SLOT(StartRealTimeSimulation(double,double)));               /** Start real-time simulation **/
     connect(ui->SimulationWidget, SIGNAL(StopRealTimeSimulation()),
             KernelMain, SLOT(StopRealTimeSimulation()));                             /** Stop real-time simulation **/
     connect(ui->SimulationWidget, SIGNAL(UpdatePostSimulation(int)),
             KernelMain, SLOT(UpdatePostSimulation(int)));                            /** Update post-simulation **/

     /** Connect signals to slots - getting parameters from KernelMain **/
     connect (KernelMain, SIGNAL(SendParameters(s_MBSParameters)),
              ui->MultibodyObjectsWidget, SLOT(UpdateParametersFromKernel(s_MBSParameters)));    /** Update Multibody System parameters in analysis Widget **/
     connect (KernelMain, SIGNAL(SendVariables(s_MBSVariables, double)),
              ui->MultibodyObjectsWidget, SLOT(UpdateVariablesFromKernel(s_MBSVariables)));                /** Update Multibody System variables in analysis Widget **/

     connect (KernelMain, SIGNAL(SendParameters(s_MBSParameters)),
              ui->SimulationWidget, SLOT(UpdateParametersFromKernel(s_MBSParameters)));

     connect (KernelMain, SIGNAL(SendVariables(s_MBSVariables, double)),
              ui->SimulationWidget, SLOT(UpdateVariablesFromKernel(s_MBSVariables)));

     connect (KernelMain, SIGNAL(SendVariables(s_MBSVariables, double)),
              this, SLOT(UpdatePlots(s_MBSVariables, double)));

     connect (KernelMain, SIGNAL(SendVariables(s_MBSVariables, double)),
              this, SLOT(UpdatePlots(s_MBSVariables,double)));

     connect (ui->glWidget, SIGNAL(OpenGLInitialized()),
              KernelMain, SLOT(SetupObjectsToRender()));

     connect (ui->MultibodyObjectsWidget, SIGNAL(Refresh()),
              KernelMain, SLOT(RefreshMultibodyObject()));

     connect(ui->SimulationWidget, SIGNAL(UpdateControlers(s_ControlersParameters)),
             KernelMain,SLOT(UpdateControler(s_ControlersParameters)));


     connect(KernelMain, SIGNAL(SendControlers(s_ControlersParameters)),
             ui->SimulationWidget,SLOT(UpdateControlersFromKernel(s_ControlersParameters)));
     // ui->SimulationWidget->SetControler( KernelMain->GetControler());


//     connect (ui->SimulationWidget, SIGNAL(SendControlerToKernel(COControler)),
//              KernelMain, SLOT(UpdateControler(COControler)));
//     connet (KernalMain, SIGNAL(SendControlerToWidget(COControler)),
//             ui->SimulationWidget, SLOT(UpdateControler(COControler)));

     /** Update Multibody System variables in analysis Widget **/
}

/*  Destructor
    *@class MainWindow
    */
MainWindow::~MainWindow()
{
    delete ui;
    delete KernelMain;
}

/*  Slot
    *@brief: Activated, when exit application by File->Exit.
    *@param: none
    */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/*  Slot
    *@brief: Activated, when Options is selected.
    *@param: none
    */
void MainWindow::on_actionOptions_triggered()
{
    optionsWidget = new OptionsWidget();                                // Create Options Window.
    optionsWidget->setAttribute(Qt::WA_DeleteOnClose, true);            // Delete on close.
    connect (optionsWidget, SIGNAL(AcceptOptions(ProgramOptions)),      // When options will be changed, update
             KernelMain, SLOT(UpdateOptions(ProgramOptions)));          // them in Kernel Main.
    optionsWidget->LoadOptions(KernelMain->GetOptions());               // Load to Options Window last saved options.
    optionsWidget->show();                                              // Show Options Window.
}


/*  Slot
    *@brief: Activated, when importing ADAMS model.
    *@param: none
    */
void MainWindow::on_actionImport_ADAMS_model_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import ADAMS model"),
                                                     "",
                                                     tr("ADAMS model file (*.adm)"));
    if(fileName.length() != 0)
        KernelMain->AddManipulator(fileName.toUtf8().constData());
}

/*  Slot
    *@brief: Activated, when user want to import ADAMS model, that has been simulated in ADAMS.
    *@param: none
    */
void MainWindow::on_actionImport_ADAMS_Pre_simulated_model_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import ADAMS model"),
                                                     "",
                                                     tr("ADAMS model file (*.adm)"));

    QString fileNameResults = QFileDialog::getOpenFileName(this, tr("Import Results"),
                                                     "");
    if( (fileName.length() != 0) &&(fileNameResults.length() != 0))
        KernelMain->AddManipulatorSimulated(fileName.toUtf8().constData(),fileNameResults.toUtf8().constData());
}

/*  Slot
    *@brief: Activated, when user wants to generete ADAMS command to run script generating measurements automatically.
    *@param: none
    */
void MainWindow::on_actionGenerate_ADAMS_Measure_Command_triggered()
{
    QString fileNameResults = QFileDialog::getOpenFileName(this, tr("Import ADAMS model"),
                                                     "",
                                                     tr("ADAMS model file (*.adm)"));
    QString Macro;
    if( (fileNameResults.length() != 0))
        Macro = KernelMain->GenerateMeasureCommand(fileNameResults.toUtf8().constData());

    dialogMeasurement = new DialogMeasurement;
    dialogMeasurement->SetMacro(Macro);
    dialogMeasurement->show();
}

/*  Slot
    *@brief Activated, when user wants to save model in .mbo file.
    *@param none
    */
void MainWindow::on_actionSave_As_triggered()
{
    
}

void MainWindow::on_actionHaptic_Devices_Support_triggered()
{
    m_HapticDeviceWindow = new HapticDeviceWindow(KernelMain->GetHapticControlerPointer());
    m_HapticDeviceWindow->setAttribute(Qt::WA_DeleteOnClose, true);
   // connect (optionsWidget, SIGNAL(AcceptOptions(ProgramOptions)),      // When options will be changed, update
   //          KernelMain, SLOT(UpdateOptions(ProgramOptions)));          // them in Kernel Main.
    // optionsWidget->LoadOptions(KernelMain->GetOptions());               // Load to Options Window last saved options.
    m_HapticDeviceWindow->show();                                              // Show Options Window.
}


void MainWindow::on_actionCreate_new_plot_triggered()
{
    int Index;
    m_PlotWindowList.append(new PlotWindow);
    Index = m_PlotWindowList.length() - 1;
    m_PlotWindowList.at(Index)->setAttribute(Qt::WA_DeleteOnClose, false);
    m_PlotWindowList.at(Index)->show();


}

void MainWindow::UpdatePlots(s_MBSVariables Variables, double Time)
{
    double Data;
    for(int i = 0 ; i < m_PlotWindowList.length() ; i++)
        {
        Data = SelectDataFromVariables(Variables,
                                 m_PlotWindowList.at(i)->GetDataType(),
                                 m_PlotWindowList.at(i)->GetDataTypeNumber());
        m_PlotWindowList.at(i)->AddData(Time,Data);
        qDebug() << "Nr " << i << "  time: " << Time << "   Data: " << Data;
        }
}

double MainWindow::SelectDataFromVariables(s_MBSVariables Variables, PW_DataType DataType, int DataTypeNumber)
{
    double Data;
    switch (DataType)
        {
        case DT_JOINTS_POSITIONS:
            {
            Data = Variables.JointsPositions[DataTypeNumber];
            break;
            }
        case DT_JOINTS_VELOCIETIES:
            {
             Data = Variables.JointsVelocities[DataTypeNumber];
            break;
            }
        case DT_JOINTS_ACCELERATIONS:
            {
            Data = Variables.JointsAccelerations[DataTypeNumber];
            break;
            }
        default:
            break;
        }
    return Data;

}
