/* *******************
 * File name : KMain.cpp
 * Author : Marcin Piotrowski
 * Created : 14.04.2015    19:40
 * Brief : See KMain.h
 * *******************
 */

#include "kmain.h"
#include <QThread>
#include <armadillo>

using namespace arma;

int Step;


/*  Constructor
    *@class KMain
    *@param: RenderWidget - widget, where every object is rendered.
    */
KMain::KMain(GRender *RenderWidget)
{
    InitializeOptions();
    m_Render = RenderWidget;
    SetupObjects();
    m_TimerAccumulator = 0;
    m_EventLoopTimer = new QTimer;
    connect(m_EventLoopTimer, SIGNAL(timeout()), this, SLOT(EventLoop()));
    m_EventLoopTimer->start(100);
    m_EventLoopStates.m_HapticControlerInitialized = false;
    m_EventLoopStates.m_RealTimeSimulation = false;
    timer = new QTimer(this);
    m_ElapsedTimer = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(RealTimeSimulationRoutine()));
}

/*  Destructor
    *@class KMain
    */
KMain::~KMain()
{
}

/*  Method
    *@brief Unused function
    */
void KMain::SetupObjects()
{
}

/*  Slot
    *@brief: This slot runs after OpenGL is initialized.
    *@param: none
    */
void KMain::SetupObjectsToRender()
{
    mPrimitiveObjects[0] = new GPrimitiveObject();
    GLfloat floorColor[] = {m_ProgramOptions.m_LinesColors[0], m_ProgramOptions.m_LinesColors[1],
                            m_ProgramOptions.m_LinesColors[2], 1.0};
    GLfloat floorAmbient[] = {0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat floorSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    mPrimitiveObjects[0]->SetFloor(m_ProgramOptions.SceneWidth, m_ProgramOptions.SceneDepth,
                                   m_ProgramOptions.LineWidth, m_ProgramOptions.LineDepth);
    mPrimitiveObjects[0]->SetDiffuseColor(floorColor);
    mPrimitiveObjects[0]->SetAmbientColor(floorAmbient);
    mPrimitiveObjects[0]->SetSpecularColor(floorSpecular);
    mPrimitiveObjects[0]->EnableShading(false);

    m_Render->AddRenderingObject(mPrimitiveObjects[0],1);

    mLoadedObjects[0] = new GLoadedObject();
    mLoadedObjects[0]->SetModelPath("block.obj");
    mLoadedObjects[0]->SetGPosition(0.75,0.25,0);
    m_Render->AddRenderingObject(mLoadedObjects[0],1);

    m_HapticControler = new HControler;
    m_Render->AddRenderingObject(m_HapticControler,1);
}

/*  Method
    *@brief: This function adds new manipulator.
    *@param filename: Path to ADM file
    *@retval: None
    */
void KMain::AddManipulator(const char *filename)
{
    /** Load and initialize manipulator **/
    m_MultibodyObjects.append(new MBObject);
    FD_alg.append(new DAlgorithms);
    int Index = m_MultibodyObjects.length() - 1;
    m_MultibodyObjects.at(Index)->LoadADAMSFile(filename);
    m_MultibodyObjects.at(Index)->SetMarkersRefferenceToJointFrame();
    m_MultibodyObjects.at(Index)->CalculateTransformationMatrices();
    m_MultibodyObjects.at(Index)->ReCalculateInertiaMatrices();
    m_MultibodyObjects.at(Index)->GeneratePrimitives();
    m_MultibodyObjects.at(Index)->EnableGravity(false);
    m_MultibodyObjects.at(Index)->SaveInitialValues();
    m_MultibodyObjects.at(Index)->SaveMultibodyObjectToFile(QString("aa"));

    /** Initialize Algorithm object **/
    FD_alg.at(Index)->Initialize(m_MultibodyObjects.at(Index));
    FD_alg.at(Index)->EnableCountingGlobalPositions(true);
    FD_alg.at(Index)->FD_AB(m_MultibodyObjects.at(Index));
    FD_alg.at(Index)->CountParameters(m_MultibodyObjects.at(Index));
    FD_alg.at(Index)->ID(m_MultibodyObjects.at(Index));

    /** Initialize controler **/
    vec KP, KV, KF, KVF;
    int M = m_MultibodyObjects.at(Index)->GetNumberOfLinks();
    KP.resize(M);
    KV.resize(M);
    KF.resize(M);
    KVF.resize(M);

    KP << 500 << 500 << 500 << 1 << 1 << 0;
    KV << 50 << 50 << 50 << 0.1 << 0.1 << 0.00001;

    KF << 1 << 1 << 1 << 1 << 1 << 1;
    KVF << 1 << 1 << 1 << 1 << 1 << 1;

    m_Controler.SetControler(COT_OPERATIONAl_SPACE_NO_PATH,M);
    m_Controler.SetK(KP,KV);
    m_Controler.SetKf(KF);
    m_Controler.SetKvf(KVF);
    SendControlers(m_Controler.GetParameters());

    /** Add manipulator to render **/
    m_Render->AddRenderingObject(m_MultibodyObjects.at(Index),1);

    Step = 0;

    emit SendParameters(m_MultibodyObjects.at(Index)->GetParameters());
    emit SendVariables(m_MultibodyObjects.at(Index)->GetVariables(), 0);
}

/*  Method
    *@brief: This function adds manipulator previously simulated in ADAMS
    *@param: filename - ADM file path
    *@param: filenameResults - path to ADAMS results
    *@retval: None
    */
void KMain::AddManipulatorSimulated(const char* filename,const char* filenameResults)
{
    m_NumberOfManipulators=1;
    manipulator.LoadADAMSFileKinematic(filename);
    manipulator.LoadResultsSet(filenameResults);
    manipulator.SetCurrentStep(0);
    manipulator.GeneratePrimitives();


    emit SendParameters(manipulator.GetParameters());
    emit SendVariables(manipulator.GetVariables(),0);
}

/*  Slot
    *@brief: This slot gets Parameters of multibody object.
    *@param: Parameters - parameters of manipulator.
    *@retval: None
    */
void KMain::GetParameters(s_MBSParameters Parameters)
{
    m_MultibodyObjects.at(0)->SetParameters(Parameters);
    m_MultibodyObjects.at(0)->UpdateParameters();
    m_Render->UpdateRenderingObject(m_MultibodyObjects.at(0));
}

/*  Method
    *@brief: This function perform single simulation (from time t0 to tk with step dt).
    *@param t0: Initial time
    *@param tk: Final time
    *@param dt: step
    *@retval: None
    */
void KMain::PerformSingleSimulation(double t0, double tk, double dt)
{
    QElapsedTimer tim4;
    QTime myTimer;
    myTimer.start();

    double t = t0;

    tim4.start();
    while(t<tk)
    {
        /** RK4 Algorithm **/

        /** Save q and qd before counting **/
        for( int i = 0 ; i < m_MultibodyObjects.length(); i++)
            FD_alg.at(i)->FD_RK(m_MultibodyObjects.at(i),dt,t);
        t+=dt;
    }

    qDebug() << "Simulation time: " << tim4.elapsed();

    emit SendVariables(m_MultibodyObjects.at(0)->GetVariables(),0);
}

/*  Method
    *@brief: This method starts real-time simulation
    *@param Speed: speed of simulation
    *@retval Step: step of simulation (in seconds)
    */
void KMain::StartRealTimeSimulation(double Speed, double Step)
{
    s_MBSParameters Parameters = m_MultibodyObjects.at(0)->GetParameters();
    Parameters.SimulationSpeed = Speed;
    Parameters.RealTimeSimulationStep = Step;
    m_TimeStep = Step;
    double m_RealTimeSimulationTiming = 1;
    m_MultibodyObjects.at(0)->SetParameters(Parameters);
    m_CurrentTime = 0;
    m_LastTime = 0;

    timer->start(m_RealTimeSimulationTiming);
    m_ElapsedTimer->start();
}

/*  Method
    *@brief: This method performs real-time simulation
    *@param: None
    *@retval: None
    */
void KMain::RealTimeSimulationRoutine()
{
    m_CurrentTime=(m_TimerAccumulator+m_ElapsedTimer->elapsed()*m_MultibodyObjects.at(0)->GetParameters().SimulationSpeed)/1000.0;

    /** Simulation loop **/
    while (m_LastTime < m_CurrentTime)
        {

        for( int i = 0 ; i < m_MultibodyObjects.length(); i++)
            {
            /** Get positions and velocities **/
            vec6 o1, o2, o3;
            o1 = m_MultibodyObjects.at(i)->GetJointsPositions();
            o2 = m_MultibodyObjects.at(i)->GetJointsVelocities();
            o3 = m_MultibodyObjects.at(i)->GetJointsAcceleration();
            FD_alg.at(i)->FD_RK(m_MultibodyObjects.at(i),m_TimeStep,m_TimeStep);
            o1 << o1(0) << o1(1) << o1(2)<< o1(3) << 0.2 << -0.2;
            o2 << o2(0) << o2(1) << o2(2) << o2(3) << 0 << 0;
            o3 << o3(0) << o3(1) << o3(2) << o3(3) << 0 << 0;
            m_MultibodyObjects.at(i)->SetJointsPositionsAndVelocities(o1,o2);
            m_MultibodyObjects.at(i)->SetJointsAcceleration(o3);

            /** Counting dynamic parameters is not as important as perforiming numerical simulation, so it is
             *  counted in low-frequency loop **/
            if(Step ==1)
                {
                FD_alg.at(0)->CountParameters(m_MultibodyObjects.at(0));
                Step = 0;
                }
            else
                Step++;

            switch(m_Controler.GetParameters().Type)
                {
                case COT_PPLUS:
                    {
                    FD_alg.at(i)->FD_RK(m_MultibodyObjects.at(i),m_TimeStep,m_TimeStep);
                    vec Positions;
                    vec6 zerovec;
                    vec Velocities;
                    vec6 PositionsSet;
                    PositionsSet = m_HapticControler->GetPositionsAndOrientations(D_DEVICE1);
                    vec6 PositionsJoints;
                    vec6 VelocitiesSet;
                    VelocitiesSet.fill(0);
                    Positions = m_MultibodyObjects.at(i)->GetJointsPositions()(0,0,size(6,1));
                    Velocities = m_MultibodyObjects.at(i)->GetJointsVelocities()(0,0,size(6,1));
                    PositionsJoints = FD_alg.at(i)->IK(m_MultibodyObjects.at(i),PositionsSet);
                    m_MultibodyObjects.at(i)->SetTorques(m_Controler.GetTorques(Positions,Velocities,
                                                                           PositionsJoints,VelocitiesSet,m_MultibodyObjects.at(i)));
                    break;
                    }
                case COT_OPERATIONAl_SPACE_NO_PATH:
                    {
                    FD_alg.at(i)->FD_RK(m_MultibodyObjects.at(i),m_TimeStep,m_TimeStep);
                    vec6 VelocitiesSet;
                    VelocitiesSet.fill(0);
                    vec6 PositionsSet;
                    PositionsSet = m_HapticControler->GetPositionsAndOrientations(D_DEVICE1);
                    vec6 Velocities;
                    Velocities = m_MultibodyObjects.at(i)->GetJacobian() * m_MultibodyObjects.at(i)->GetJointsVelocities();
                    vec6 Positions;
                    Positions(0,0,size(3,1)) = m_MultibodyObjects.at(i)->GetGraberPosition();
                    Positions(3,0,size(3,1)) = m_MultibodyObjects.at(i)->GetGraberOrientation();
                    PositionsSet(3) = 0;
                    PositionsSet(4) = 0;
                    PositionsSet(5) = 0;

                     m_MultibodyObjects.at(i)->SetTorques(m_Controler.GetTorques(Positions,Velocities,
                                                                       PositionsSet,VelocitiesSet,m_MultibodyObjects.at(i)));

                    break;
                    }
                default:
                    break;
                }
            }
        emit SendVariables(m_MultibodyObjects.at(0)->GetVariables(), m_LastTime);
        m_LastTime+=m_TimeStep;
        }

    /** Counting position of grabber, for testing only **/
    /**
    vec3 rij[6];
    vec3 hij[6];
    mat33 previous_mat;

    vec3 j_S;
     j_S << 0 << 0 << 1;
    for(int i = 0 ; i < 6 ; i++)
        {
        if (i == 0)
            {
            rij[i] = vec3(previous_mat * m_MultibodyObjects.at(0)->Base->m_JtoITranslationVector);
            previous_mat = mat33(m_MultibodyObjects.at(0)->Base->m_ItoJRotationMatrix*RotZ(m_MultibodyObjects.at(0)->Joints[0].GetJointAngle()));
            hij[i] =  previous_mat*j_S;
            }
        else
            {
            rij[i] = vec3(previous_mat*(m_MultibodyObjects.at(0)->Links[i-1].m_JtoITranslationVector));
            previous_mat = mat33(previous_mat * m_MultibodyObjects.at(0)->Links[i-1].m_ItoJRotationMatrix *RotZ(m_MultibodyObjects.at(0)->Joints[i].GetJointAngle()));
            hij[i] =  previous_mat*j_S;
            }
        }

    vec3 KPosition;
    KPosition.fill(0);
    for(int i = 0 ; i < 6 ; i++)
        KPosition += rij[i];

    vec3 KOrientation = X213AnglesFromRotMat(previous_mat);

   //  qDebug() << "Korientation:" <<  KOrientation(0) << KOrientation(1) << KOrientation(2);
   **/
}

/*  Method
    *@brief: This function stops real-time simulation.
    *@param: None
    *@retval: None
    */
void KMain::StopRealTimeSimulation()
{
    timer->stop();
    m_TimerAccumulator += m_ElapsedTimer->elapsed();
    m_ElapsedTimer->invalidate();
}

/*  Method
    *@brief: For future use.
    *@param
    *@retval
    */
void KMain::UpdateMultibodySystem()
{
}

/*  Method
    *@brief: This function update post-simulation.
    *@param Step: Current step of post-simulation
    *@retval: None
    */
void KMain::UpdatePostSimulation(int Step)
{
    manipulator.SetCurrentStep(Step);
}

QString KMain::GenerateMeasureCommand(const char* filename)
{
    return "Nothing";
}

/*  Slot
    *@brief: Activated, when user changed the program options.
    *@param: Options - options of the program
    */
void KMain::UpdateOptions(ProgramOptions Options)
{
    m_ProgramOptions = Options;
    m_Render->SetBackgroundColorR(Options.m_ClearColors[0]);
    m_Render->SetBackgroundColorG(Options.m_ClearColors[1]);
    m_Render->SetBackgroundColorB(Options.m_ClearColors[2]);
    GLfloat LinesColors[4];
    for( int i = 0 ; i < 3 ; i++)
        LinesColors[i] = Options.m_LinesColors[i];
    LinesColors[3] = 1.0;
    mPrimitiveObjects[0]->SetAmbientColor(LinesColors);
    mPrimitiveObjects[0]->SetFloor(Options.SceneWidth,Options.SceneDepth,
                                   Options.LineWidth, Options.LineDepth);
    m_Render->UpdateRenderingObject(mPrimitiveObjects[0]);
    m_Render->update();
}

/*  Methid
    *@brief: This function return Program options
    *@param
    *@retval
    */
ProgramOptions KMain::GetOptions()
{
    return m_ProgramOptions;
}

/*  Method
    *@brief: This method set default options
    *@param
    *@retval
    */
void KMain::InitializeOptions()
{
    /** Initilize Clear Colors and Lines Colors **/
    for(int i = 0 ; i < 3 ; i ++)
        {
        m_ProgramOptions.m_ClearColors[i] = 254;
        m_ProgramOptions.m_LinesColors[i] = 0;
       }

    /** Initialize Scene dimension**/
   m_ProgramOptions.SceneDepth = 3;
   m_ProgramOptions.SceneWidth = 3;
   m_ProgramOptions.LineDepth = 0.5;
   m_ProgramOptions.LineWidth = 0.5;
}

/*  Method
    *@brief: This method return pointer to haptic controler
    *@param
    *@retval
    */
HControler* KMain::GetHapticControlerPointer()
{
    return m_HapticControler;
}

/*  Method
    *@brief: For future use
    *@param
    *@retval
    */
void KMain::EventLoop()
{
    if (m_HapticControler->GetStatus(D_DEVICE1))
        {
        /** Check if Haptic pointer is near Graber **/
        }
}

/*  Method
    *@brief: This function update controller.
    *@param: Parameters - parameters of the controller
    *@retval: None
    */
void KMain::UpdateControler(s_ControlersParameters Parameters)
{
    m_Controler.SetControlerType(Parameters.Type);
    m_Controler.SetKp(Parameters.m_KpDiag);
    m_Controler.SetKv(Parameters.m_KvDiag);
    m_Controler.SetKf(Parameters.m_KfDiag);
    m_Controler.SetKvf(Parameters.m_KvfDiag);
    m_Controler.SetMaxV(Parameters.m_MaxV);
}

s_ControlersParameters KMain::GetControler()
{
    return m_Controler.GetParameters();
}

/*  Slot
    *@brief: This slot refresh multibody system (sets initial valuses).
    *@param: None
    *@retval: None
    */
void KMain::RefreshMultibodyObject()
{
    m_MultibodyObjects.at(0)->Refresh();
    FD_alg.at(0)->FD_AB(m_MultibodyObjects.at(0));
}
