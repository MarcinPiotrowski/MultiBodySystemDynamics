/* *******************
 * File name : HDevice.cpp
 * Author : Marcin Piotrowski
 * Created : 23.04.2015    20:12
 * Brief : See HDevice.h
 * *******************
 */

#include "HDevice.h"

/*  Constructor
    *@class HDevice
    *@param
    */
HDevice::HDevice(): m_DeviceCalibrated(false),
                    m_DeviceHandle(HDL_INVALID_HANDLE),
                    m_ServoFunctionHandle(HDL_INVALID_HANDLE),
                    m_Initialized(false),
                    m_MaxForce(1)
{
    m_Buttons.Left = false;
    m_Buttons.Right = false;
    m_Buttons.Middle = false;
    m_Buttons.Up = false;
    m_ButtonsChanged.Left = false;
    m_ButtonsChanged.Right = false;
    m_ButtonsChanged.Middle = false;
    m_ButtonsChanged.Up = false;
    m_ZeroPosition << 0.0 << 0.0 << 0.0;
}

/*  Destructor
    *@class HDevice
    */
HDevice::~HDevice()
{
    Uninitialize();
}

/*  Method
    *@brief: This function initialize device
    *@param: None
    *@retval: None
    */
void HDevice::Initialize()
{
    if(m_Initialized == 0)
        {
        try
            {
            /** Initialize device with configuration file **/
            m_DeviceHandle = hdlInitNamedDevice("DEFAULT");
            }

        catch(...)
            {
            return;
            }

        if (m_DeviceHandle == HDL_INVALID_HANDLE)
            qDebug() << "Could not open device...";

        /** Starting Servo **/
        hdlStart();

        /** Using current device **/
        hdlMakeCurrent(m_DeviceHandle);

        /** Get Device Workspace **/
        hdlDeviceWorkspace(m_DeviceWorkspace);

        /** Get Device Model **/
        const char* Name = hdlDeviceModel();
        m_DeviceModel = QString::fromLatin1(Name);

        m_ServoFunctionHandle = hdlCreateServoOp(ServoFunction, this, false);

        if (m_ServoFunctionHandle == HDL_INVALID_HANDLE)
            qDebug() << "Invalid servo op handle";

        double Workspace[] = {-1,-1,-1,1,1,1};

        hdluGenerateHapticToAppWorkspaceTransform(m_DeviceWorkspace,Workspace,
                                                  m_UniformTransformationMatrix, m_TransformationMatrix);

        m_ToolForces[0] = 0;
        m_ToolForces[1] = 0;
        m_ToolForces[2] = 0;
        m_Initialized = true;
    }
}

/*  Method
    *@brief: This function unitialize device.
    *@param: None
    *@retval: None
    */
void HDevice::Uninitialize()
{
    if(m_ServoFunctionHandle != HDL_INVALID_HANDLE)
        {
        hdlDestroyServoOp(m_ServoFunctionHandle);
        m_ServoFunctionHandle = HDL_INVALID_HANDLE;
        }

    if(m_DeviceHandle != HDL_INVALID_HANDLE)
        {
        hdlUninitDevice(m_DeviceHandle);
        m_DeviceHandle = HDL_INVALID_HANDLE;
        }
    m_Initialized = false;
}

/*  Function
    *@brief: This function operate every 1 ms to generate forces and get positions.
    *@param Data: HDevice object
    *@retval HDLServoOpExitCode: HDL library code
    */
HDLServoOpExitCode ServoFunction(void *Data)
{
    HDevice *HapticObject = static_cast <HDevice*> (Data);

    hdlToolPosition(HapticObject->m_ToolPosition);

    hdlSetToolForce(HapticObject->m_ToolForces);

    int *Buttons;
    hdlToolButtons(Buttons);

    HapticObject->m_Buttons.Middle = *Buttons & HDL_BUTTON_1 ? true : false;
    HapticObject->m_Buttons.Left = *Buttons & HDL_BUTTON_2 ? true : false;
    HapticObject->m_Buttons.Up = *Buttons & HDL_BUTTON_3 ? true : false;
    HapticObject->m_Buttons.Right = *Buttons & HDL_BUTTON_4 ? true : false;

    return HDL_SERVOOP_CONTINUE;
}

void HDevice::SetForces(vec3 Forces)
{
    m_ToolForces[0] = Forces(0) > m_MaxForce ? m_MaxForce : Forces(0);
    m_ToolForces[1] = Forces(1) > m_MaxForce ? m_MaxForce : Forces(1);
    m_ToolForces[2] = Forces(2) > m_MaxForce ? m_MaxForce : Forces(2);
}

void HDevice::SetZeroPosition(vec3 ZeroPosition)
{
    m_ZeroPosition = ZeroPosition;
}

vec3 HDevice::GetZeroPosition()
{
    return m_ZeroPosition;
}

vec3 HDevice::GetPosition()
{

    vec3 RetVec;
    RetVec << m_ToolPosition[0] << m_ToolPosition[1] << m_ToolPosition[2];
    return RetVec;
}

vec3 HDevice::GetGlobalPosition()
{
    vec3 RetVec;
    RetVec << m_ToolPosition[0] << m_ToolPosition[1] << m_ToolPosition[2];
    return m_Workspace*RetVec+m_ZeroPosition;
}

double HDevice::GetMaxForce()
{
    return m_MaxForce;
}

void HDevice::SetMaxForce(double Force)
{
    m_MaxForce = Force;
}

bool HDevice::IsInitialized()
{
    return m_Initialized;
}

QString HDevice::GetDeviceModel()
{
    return m_DeviceModel;
}

s_HButtons HDevice::GetButtonsState()
{
    return m_Buttons;
}

void HDevice::SetButtonsChanged(s_HButtons Buttons)
{
    m_ButtonsChanged = Buttons;
}

s_HButtons HDevice::GetButtonsChanged()
{
    return m_ButtonsChanged;
}

void HDevice::SetWorkspace(double Workspace)
{
    m_Workspace = Workspace / 0.1;
}
