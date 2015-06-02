/* *******************
 * File name : HDevice.h
 * Author : Marcin Piotrowski
 * Created : 23.04.2015    19:41
 * Brief : This file containts Haptic Device class. Haptic Device object is a basic object of Novint Falcon Device.
 * *******************
 */

#ifndef HDEVICE_H
#define HDEVICE_H

#include "hdl.h"
#include "hdlu.h"
#include "hdlConstants.h"
#include "hdlErrors.h"
#include "hdlExports.h"
#include "hdluExports.h"
#include "DHeaders.h"

/*  Enum
    *@brief: ID of the device
    */
enum e_Device
{
    D_DEVICE1,
    D_DEVICE2
};

/*  Struct
    *@brief: Buttons of Novint Falcon device
    */
struct s_HButtons
{
    bool Left;
    bool Right;
    bool Middle;
    bool Up;
};

class HDevice
{
   friend HDLServoOpExitCode ServoFunction(void *Data);

private:

    HDLDeviceHandle m_DeviceHandle;             // Device handle
    HDLOpHandle m_ServoFunctionHandle;          // Handle to function, that runs in 1000 Hz
    bool m_DeviceCalibrated;                    // Flag - is device calibrated?
    bool m_Initialized;                         // Flag - is device initialized?
    bool m_UniformTransformationMatrix;         // Should uniform transformation matrix be used?
    double m_DeviceWorkspace[6];                // Device workspace (in m)
    vec3 m_ZeroPosition;                        // Zero position of device
    vec3 m_Scale;                               // Scale of workspace
    double m_MaxForce;                          // Max force of the device
    double m_TransformationMatrix[16];          // Transformation matrix from device workspace to application workspace
    double m_ToolPosition[3];                   // Position of tool (in device workspace)
    double m_ToolForces[3];                     // Forces of the tool
    QString m_DeviceModel;                      // Device model name
    s_HButtons m_Buttons;                       // Current state of buttons
    s_HButtons m_ButtonsChanged;                // Last state of buttons
    double m_Workspace;                         // Workspace scale ratio


public:
    HDevice();
    ~HDevice();

    void Initialize();
    void Uninitialize();
    vec3 GetPosition();
    vec3 GetZeroPosition();
    vec3 GetGlobalPosition();
    void SetZeroPosition(vec3 ZeroPosition);
    void SetForces(vec3 Forces);
    void SetMaxForce(double Force);
    double GetMaxForce();
    bool IsInitialized();
    QString GetDeviceModel();
    s_HButtons GetButtonsState();
    void SetButtonsChanged(s_HButtons Buttons);
    s_HButtons GetButtonsChanged();
    void SetWorkspace(double Workspace);
};

#endif // HDEVICE_H
