/* *******************
 * File name : KMain.h
 * Author : Marcin Piotrowski
 * Created : 14.04.2015    19:39
 * Brief : This is main file of the application.
 * *******************
 */

#ifndef KMAIN
#define KMAIN

#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QThread>
#include <QList>
#include "GLoadedObject.h"
#include "GObject.h"
#include "GPrimitiveObject.h"
#include "GRender.h"
#include "MBObject.h"
#include "DynamicsAlgorithms.h"
#include "programoptions.h"
#include "HControler.h"
#include "COControler.h"

using namespace std;

/*  Struct
    *@brief: This sctruct contain otpions of event loop.
    */
struct EventLoopStates
{
    bool m_HapticControlerInitialized;
    bool m_RealTimeSimulation;
    bool m_RealTimeForceControl;
};

class KMain: public QObject
{
    Q_OBJECT

private:

    GRender *m_Render;                              // Main rendering object
    GPrimitiveObject* mPrimitiveObjects[3];         // Primitive objects to render
    GLoadedObject* mLoadedObjects[2];               // Loaded objects to render
    QList<MBObject *> m_MultibodyObjects;           // Manipulators
    MBObject manipulator;                           // Old attribute, should be deleted
    GLoadedObject* Hand;                            // Pointer of Novint Falcon
    HControler* m_HapticControler;                  // Haptic Controler object
    EventLoopStates m_EventLoopStates;              // Event loop options
    COControler m_Controler;                        // Manipulators controler
    QList<DAlgorithms *> FD_alg;                    // Object for Algorithms
    QTimer *timer;                                  // Timer to check computation time
    QTimer *m_EventLoopTimer;                       // Timer to run event loop function
    QElapsedTimer *m_ElapsedTimer;                  // Elapsed time of computation
    qint64 m_TimerAccumulator;                      // Elapsed time of computation
    ProgramOptions m_ProgramOptions;                // Program Options
    int m_NumberOfManipulators;                     // Total number of loaded manipulators
    double m_LastTime;                              // Last numerical analisys time
    double m_CurrentTime;                           // Current numerical analisys time
    double m_TimeStep;                              // Timestep of numerical analisys

    void InitializeOptions();



signals:

    void SendVariables(s_MBSVariables MBSVariables, double Time);
    void SendParameters(s_MBSParameters MBSParameters);
    void SendMeasureCommand(const QString &Command);
    void SendControlers(s_ControlersParameters Parameters);

public slots:

    void GetParameters(s_MBSParameters Parameters);
    void PerformSingleSimulation(double t0, double tk, double dt);
    void StartRealTimeSimulation(double Speed, double Step);
    void UpdatePostSimulation(int Step);
    void StopRealTimeSimulation();
    void UpdateMultibodySystem();
    void SetupObjectsToRender();
    void UpdateOptions(ProgramOptions Options);
    void RealTimeSimulationRoutine();
    void EventLoop();
    void UpdateControler(s_ControlersParameters Parameters);
    void RefreshMultibodyObject();

public:

    ProgramOptions GetOptions();
    KMain(GRender *RenderWidget);
    ~KMain();
    void Init(int argc, char *argv);
    void SetupRC();
    void Draw();
    void cleanup();
    void SetupObjects();
    void SetBackgroundColor(GLfloat* color);
    void SetBackgroundColorR(int R);
    void SetBackgroundColorG(int G);
    void SetBackgroundColorB(int B);
    void SetLinesColors(int R, int G, int B);
    void AddManipulator(const char* filename);
    void AddManipulatorSimulated(const char* filename,const char* filenameResults);
    void ChangeScene(double SWidth, double SDepth, double LWidth, double LDepth);
    QString GenerateMeasureCommand(const char* filename);
    HControler* GetHapticControlerPointer();
    s_ControlersParameters GetControler();

};


#endif // KMAIN
