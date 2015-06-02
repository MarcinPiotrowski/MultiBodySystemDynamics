/* *******************
 * File name : HControler.cpp
 * Author : Marcin Piotrowski
 * Created : 2015.04.05    16:47
 * Brief : See HControler.h
 * *******************
 */

#include "HControler.h"

/*  Constructor
    *@class HControler
    *@param None
    */
HControler::HControler()
{
    m_Device = new HDevice[2];          // Create new devices
    m_MovementType = MT_POSITION;       // Set movement type to position

    /** Create Pointers, Pointer Frame and Pointers History Objects **/
    m_Pointer = new GLoadedObject[2];
    m_PointerWorkspace = new GLoadedObject[2];
    m_HistoryPointer = new GLoadedObject[2];
    for(int i = 0 ; i < 2 ; i++)
        {
        m_Pointer[i].SetModelPath("BasicSphere.obj");
        m_Pointer[i].SetRandomColors();
        m_Pointer[i].SetScale(0.1, 0.1, 0.1);
        }
    for(int i = 0 ; i < 2 ; i++)
        {
        m_HistoryPointer[i].SetModelPath("BasicSphere.obj");
        m_HistoryPointer[i].SetRandomColors();
        m_HistoryPointer[i].SetScale(0.01, 0.01, 0.01);
        }
    for(int i = 0 ; i < 2 ; i++)
        {
        m_PointerWorkspace[i].SetModelPath("PointerFrame.obj");
        m_PointerWorkspace[i].SetRandomColors();
        m_PointerWorkspace[i].SetDiffuseColor(0,0,0,1);
        }

    /** Set workspace dimensions **/
    SetWorkspace(D_DEVICE1,0.1);
    SetWorkspace(D_DEVICE2,0.1);

    /** Set history parameters **/
    m_MaxHistoryLength = 50;
    m_DataHistory = new vec3[m_MaxHistoryLength];
    m_DataHistoryLength = 0;
    m_CurrentHistoryIndex = 0;
    /** Set orientation and position **/
    m_SetOrientation << 0 << 0 << 0;
    m_SetPosition << 0 << 0 << 0;
    /** Calculate how pointer history will disappear **/
    m_LogScale = new double [m_MaxHistoryLength];
    CalculateLogScale();
}

/*  Destructor
    *@class HControler
    */
HControler::~HControler()
{
}

void HControler::SetForces(vec3 Forces, e_Device Device)
{
    m_Device[Device].SetForces(Forces);
}

vec3 HControler::GetPositions(e_Device Device)
{
    return m_Device[Device].GetPosition();
}

void HControler::ConnectToDevice(e_Device Device)
{
    m_Device[Device].Initialize();
}

void HControler::DisconnetFromDevice(e_Device Device)
{
    m_Device[Device].Uninitialize();
}

double HControler::GetMaxForce(e_Device Device)
{
    return m_Device[Device].GetMaxForce();
}

void HControler::SetMaxForce(double Force, e_Device Device)
{
    m_Device[Device].SetMaxForce(Force);
}

void HControler::SetPointerSize(int Size, e_Device Device)
{
    m_PointerSize[Device] = Size;
    float Scale = 0.1*Size/100.0;
    m_Pointer[D_DEVICE1].SetScale(Scale,Scale,Scale);
}

int HControler::GetPointerSize(e_Device Device)
{
    return m_PointerSize[Device];
}

bool HControler::GetStatus(e_Device Device)
{
    return m_Device[Device].IsInitialized();
}

 vec6 HControler::GetPositionsAndOrientations(e_Device Device)
 {
     vec6 RetVec;

    if (m_MovementType == MT_POSITION)
        {
         RetVec << GetGlobalPositions(Device)(0) <<
                   GetGlobalPositions(Device)(1) <<
                   GetGlobalPositions(Device)(2) <<
                   GetOrientationSet(Device)(1) <<
                   GetOrientationSet(Device)(0) <<
                   GetOrientationSet(Device)(2) ;
         }

     else if (m_MovementType == MT_ORIETNATION)
        {
        RetVec << GetPositionSet(Device)(0) <<
                  GetPositionSet(Device)(1) <<
                  GetPositionSet(Device)(2) <<
                  GetOrientationAngles(Device)(1) <<
                  GetOrientationAngles(Device)(0) <<
                  GetOrientationAngles(Device)(2) ;
        }
    return RetVec;
 }

 /*  Method
     *@brief: This function draws pointer, pointer frame and pointer history
     *@param: See Draw in GObject class
     *@retval: None
     */
void HControler::Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline)
{   
    if(m_Device[D_DEVICE1].IsInitialized() == true)
       {
        /** Drawing Pointer and PointerWorkspace **/
       m_Pointer[D_DEVICE1].SetGPosition(m_Device[D_DEVICE1].GetGlobalPosition());
       m_Pointer[D_DEVICE1].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);
       m_PointerWorkspace[D_DEVICE1].SetGPosition(m_Device[D_DEVICE1].GetZeroPosition());
       m_PointerWorkspace[D_DEVICE1].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);

       /** Drawing data history **/
       int SizeCounter = m_MaxHistoryLength-1;

       if (m_DataHistoryLength != m_MaxHistoryLength)
           m_DataHistoryLength++;
       else
           for(int i = m_CurrentHistoryIndex ; i < m_MaxHistoryLength ; i++)
           {
           m_HistoryPointer[D_DEVICE1].SetGPosition(m_DataHistory[i]);
           m_HistoryPointer[D_DEVICE1].SetScale(0.01*m_LogScale[SizeCounter], 0.01*m_LogScale[SizeCounter], 0.01*m_LogScale[SizeCounter]);

           SizeCounter--;
           m_HistoryPointer[D_DEVICE1].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);

           }

       for(int i = 0 ; i < m_CurrentHistoryIndex ; i++)
            {
           m_HistoryPointer[D_DEVICE1].SetGPosition(m_DataHistory[i]);
           m_HistoryPointer[D_DEVICE1].SetScale(0.01*m_LogScale[SizeCounter], 0.01*m_LogScale[SizeCounter], 0.01*m_LogScale[SizeCounter]);
           SizeCounter--;
           m_HistoryPointer[D_DEVICE1].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);

            }

       m_DataHistory[m_CurrentHistoryIndex] = m_Device[D_DEVICE1].GetGlobalPosition();

       if(m_CurrentHistoryIndex == m_MaxHistoryLength - 1)
           m_CurrentHistoryIndex = 0;
       else
            m_CurrentHistoryIndex++;

       /** Checking if new button was pressed/realesed **/
       CheckButtonStates();

        }

    /** Draw second device **/
    if(m_Device[D_DEVICE2].IsInitialized() == true)
       {
       m_Pointer[D_DEVICE2].SetGPosition(m_Device[D_DEVICE2].GetPosition());
       m_Pointer[D_DEVICE2].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);
       }
}

/*  Method
    *@brief: See InitializeToRender method in GObject class.
    */
void HControler::InitializeToRender()
{
     m_Pointer[D_DEVICE1].LoadGraphicObject();
     m_Pointer[D_DEVICE2].LoadGraphicObject();
     m_PointerWorkspace[D_DEVICE1].LoadGraphicObject();
     m_PointerWorkspace[D_DEVICE2].LoadGraphicObject();
     m_HistoryPointer[D_DEVICE1].LoadGraphicObject();
     m_HistoryPointer[D_DEVICE2].LoadGraphicObject();
}

/*  Method
    *@brief: This method checks if pointer is in centre.
    *@param: Device - device handle
    *@param: Eps - accuracy
    *@retval: None
    */
bool HControler::IsInCenter(e_Device Device, double Eps)
{
    vec3 Position = m_Device[Device].GetPosition();

    if ( (Position(0)*Position(0)+Position(1)*Position(1)+Position(2)*Position(2)) )
        return norm(Position) < Eps ? true : false ;
}

/*  Method
    *@brief: This method moves device to center
    *@param: Device - device handle
    *@retval: K - coefficient
    */
void HControler::GoToCenter(e_Device Device, double K)
{
    vec3 Forces;
    Forces = m_Device[Device].GetPosition();
    m_Device[Device].SetMaxForce(100);
    m_Device[Device].SetForces(-Forces * K);
}

/*  Method
    *@brief: This method move frame and workspace of the device.
    *@param: Device - device handle
    *@param: K - coefficient
    *@param: Eps - accuracy
    *@retval
    */
void HControler::MoveWorkspace(e_Device Device, double K, double Eps)
{
    vec3 Forces;
    Forces = m_Device[Device].GetPosition();
    m_Device[Device].SetMaxForce(100);
    m_Device[Device].SetForces(-Forces * K);
    double C = 0.1;
    vec3 xd;
    xd = m_Device[Device].GetPosition();
    if(norm(m_Device[Device].GetPosition()) > Eps)
        m_Device[Device].SetZeroPosition( m_Device[Device].GetZeroPosition()+xd*0.2);
}

/*  Method
    *@brief: This method set size of workspace
    *@param: Device - device handle
    *@param: Workspace - size of workspace
    *@retval
    */
void HControler::SetWorkspace(e_Device Device, double Workspace)
{
    m_WorspaceSize[Device] = Workspace;
    m_PointerWorkspace[Device].SetScale(0.001*Workspace, 0.001*Workspace, 0.001*Workspace);
    m_Device[Device].SetWorkspace(Workspace);
}

/*  Method
    *@brief: This method returns global position of the pointer (so current haptic position + zero position)
    *@param: Device - device handle
    *@retval: vec3 - Global position
    */
vec3 HControler::GetGlobalPositions(e_Device Device)
{
    return m_Device[Device].GetGlobalPosition();
}

/*  Method
    *@brief: This method return buttons state
    *@param: Device - device handle
    *@retval: s_HButtons - buttons state
    */
s_HButtons HControler::GetButtons(e_Device Device)
{
    return m_Device[Device].GetButtonsState();
}

/*  Method
    *@brief: This function checks if new button was pressed/released.
    *@param: None
    *@retval: None
    */
void HControler::CheckButtonStates()
{
    /** Check the UpButton **/
    /** If button was pressed in the moment **/
     if(m_Device[D_DEVICE1].GetButtonsState().Up == true &&
        m_Device[D_DEVICE1].GetButtonsChanged().Up == false)
        {
         s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
         Buttons.Up = true;
         m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
         m_State[0] = S_GO_TO_CENTER;
        }
   /** If the button is still pressed **/
   else if(m_Device[D_DEVICE1].GetButtonsState().Up == true &&
           m_Device[D_DEVICE1].GetButtonsChanged().Up == true)
       {
       if( IsInCenter(D_DEVICE1, 0.01) && m_State[0] == S_GO_TO_CENTER)
           {
           m_State[0] = S_MOVE_WORKSPACE;
           }
       }
    /** If the button is released at the moment **/
   else if(m_Device[D_DEVICE1].GetButtonsState().Up == false &&
           m_Device[D_DEVICE1].GetButtonsChanged().Up == true)
           {
           s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
           Buttons.Up = false;
           m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
           m_State[0] = S_IDLE;
           vec3 Forces;
           Forces << 0 << 0 << 0;
           m_Device[D_DEVICE1].SetForces(Forces);
           }



    /** Check the LeftButton **/
    /** If button was pressed in the moment **/
   if(m_Device[D_DEVICE1].GetButtonsState().Left == true &&
          m_Device[D_DEVICE1].GetButtonsChanged().Left == false)
          {
          s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
          Buttons.Left = true;
          m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
          switch (m_MovementType)
            {
            case MT_POSITION:
                {
                SetWorkspace(D_DEVICE1,m_WorspaceSize[D_DEVICE1]-0.02);
                break;
                }
            case MT_ORIETNATION:
                {
                IncrementRotation(-0.03);
                break;
                }
             default:
                 break;
           }
        }
   /** If the button is still pressed **/
   else if(m_Device[D_DEVICE1].GetButtonsState().Left == true &&
          m_Device[D_DEVICE1].GetButtonsChanged().Left == true)
          {
          switch (m_MovementType)
            {
            case MT_POSITION:
                {
                SetWorkspace(D_DEVICE1,m_WorspaceSize[D_DEVICE1]-0.02);
                break;
                }
            case MT_ORIETNATION:
                {
                IncrementRotation(-0.03);
                break;
                }
             default:
                 break;
           }
        }

     /** If the button is released at the moment **/
   if(m_Device[D_DEVICE1].GetButtonsState().Left == false &&
                  m_Device[D_DEVICE1].GetButtonsChanged().Left == true)
                  {
                  s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
                  Buttons.Left = false;
                  m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
                  }



   /** Check the RightButton **/
   /** If button was pressed in the moment **/
  if(m_Device[D_DEVICE1].GetButtonsState().Right == true &&
         m_Device[D_DEVICE1].GetButtonsChanged().Right == false)
         {
         s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
         Buttons.Right = true;
         m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
         switch (m_MovementType)
           {
           case MT_POSITION:
               {
               SetWorkspace(D_DEVICE1,m_WorspaceSize[D_DEVICE1]+0.02);
               break;
               }
           case MT_ORIETNATION:
               {
               IncrementRotation(+0.03);
               break;
               }
            default:
                break;
          }
       }
  /** If the button is still pressed **/
  else if(m_Device[D_DEVICE1].GetButtonsState().Right == true &&
         m_Device[D_DEVICE1].GetButtonsChanged().Right == true)
         {
         switch (m_MovementType)
           {
           case MT_POSITION:
               {
               SetWorkspace(D_DEVICE1,m_WorspaceSize[D_DEVICE1]+0.02);
               break;
               }
           case MT_ORIETNATION:
               {
               IncrementRotation(+0.03);
               break;
               }
            default:
                break;
          }
       }

    /** If the button is released at the moment **/
  if(m_Device[D_DEVICE1].GetButtonsState().Right == false &&
                 m_Device[D_DEVICE1].GetButtonsChanged().Right == true)
                 {
                 s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
                 Buttons.Right = false;
                 m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
                 }


  /** Check the MiddleButton **/
  /** If button was pressed in the moment **/
 if(m_Device[D_DEVICE1].GetButtonsState().Middle == true &&
        m_Device[D_DEVICE1].GetButtonsChanged().Middle == false)
        {
        s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
        Buttons.Middle = true;
        m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
        switch (m_MovementType)
          {
          case MT_POSITION:
              {
              m_MovementType = MT_ORIETNATION;
              m_SetPosition = m_Device[D_DEVICE1].GetGlobalPosition();
              break;
              }
          case MT_ORIETNATION:
              {
              m_MovementType = MT_POSITION;
              break;
              }
           default:
               break;
         }
      }
 /** If the button is still pressed **/
 else if(m_Device[D_DEVICE1].GetButtonsState().Middle == true &&
        m_Device[D_DEVICE1].GetButtonsChanged().Middle == true)
        {
        switch (m_MovementType)
          {
          case MT_POSITION:
              {
              break;
              }
          case MT_ORIETNATION:
              {
              break;
              }
           default:
               break;
         }
      }

   /** If the button is released at the moment **/
 if(m_Device[D_DEVICE1].GetButtonsState().Middle == false &&
                m_Device[D_DEVICE1].GetButtonsChanged().Middle == true)
                {
                s_HButtons Buttons = m_Device[D_DEVICE1].GetButtonsChanged();
                Buttons.Middle = false;
                m_Device[D_DEVICE1].SetButtonsChanged(Buttons);
                }


   switch (m_State[0])
       {
        case S_IDLE:
            break;
        case S_GO_TO_CENTER:
            {
            GoToCenter(D_DEVICE1, 500);
            if(IsInCenter(D_DEVICE1,0.001))
                    m_State[0] = S_MOVE_WORKSPACE;
            break;
            }
        case S_MOVE_WORKSPACE:
             {
            MoveWorkspace(D_DEVICE1,300,0.01);
             break;
             }
       }
}

/*  Method
    *@brief: This method increment last joint angle (rotation about Z axis of grabber)
    *@param: Increment - increment of rotation.
    *@retval: None
    */
void HControler::IncrementRotation(double Increment)
{
    m_SetOrientation(2) += Increment;
}

/* @fungrup "Get/Set" standart functions
   @brief This functions return positions, orientation etc.
   @params various
   @retvals various
    */
e_HMovementType HControler::GetMovementType(e_Device Device)
{
    return m_MovementType;
}

vec3 HControler::GetPositionSet(e_Device Device)
{
    return m_SetPosition;
}

vec3 HControler::GetOrientationSet(e_Device Device)
{
    return m_SetOrientation;
}

vec3 HControler::GetOrientationAngles(e_Device Device)
{
    vec3 RetAngles;
    if (m_MovementType == MT_ORIETNATION)
        {
        vec3 UnitVector;
        UnitVector = m_SetPosition - m_Device[Device].GetGlobalPosition();
        UnitVector = normalise(UnitVector);
        RetAngles << asin(UnitVector(0)) << atan2(-UnitVector(1),UnitVector(2)) << m_SetOrientation(2);
        m_SetOrientation  << RetAngles(0) << RetAngles(1) << m_SetOrientation(2);
        }
    else
        RetAngles = m_SetOrientation;

    return RetAngles;
}
/* @fungroupend "Get/Set" standart functions
   */

/*  Method
    *@brief: This method calculate how fast pointer history should disappear.
    *@param: None
    *@retval: None
    */
void HControler::CalculateLogScale()
{
    int i;
    for(i = 0 ; i < m_MaxHistoryLength*0.8 ; i++)
        m_LogScale[i] = 1;
    for (int j = 0 ; j < m_MaxHistoryLength*0.2; j++)
        m_LogScale[j+i] = (-1.0/ (0.2*m_MaxHistoryLength))*j+1;
    /** In future: change to log-scale 2-exp(i*log(2)/m_MaxHistoryLength) **/
}
