/* *******************
 * File name : HControler.h
 * Author : Marcin Piotrowski
 * Created : 24.04.2015    16:25
 * Brief : This file containts Haptic Controller class. Haptic Controller controls all Novint Falcon devices currently connected
 *         to the application.
 * *******************
 */

#ifndef HCONTROLER_H
#define HCONTROLER_H

#include "HDevice.h"
#include "GLoadedObject.h"

enum e_HState
{
    S_IDLE,
    S_GO_TO_CENTER,
    S_MOVE_WORKSPACE
};

enum e_HMovementType
{
    MT_POSITION,
    MT_ORIETNATION
};


class HControler: public GObject
{
private:

    HDevice *m_Device;                              // Devices connected to the application
    int m_PointerSize[2];                           // Size of pointers
    double m_WorspaceSize[2];                       // Size of cubic workspace
    GLoadedObject *m_Pointer;                       // Pointer objects
    GLoadedObject *m_PointerWorkspace;              // Workspace objects
    GLoadedObject *m_HistoryPointer;                // History pointers objects
    e_HState m_State[2];                            // Current state of controler
    vec3 *m_DataHistory;                            // Positions of history pointers
    int m_CurrentHistoryIndex;                      // Current index of history pointers
    int m_DataHistoryLength;                        // Used only in first second of live of the object
    int m_MaxHistoryLength;                         // How many history pointers will be drawn
    vec3 m_SetPosition;                             // Saved position of grabber
    vec3 m_SetOrientation;                          // Saved orientation of grabber
    e_HMovementType m_MovementType;                 // Movement type of the device
    double *m_LogScale;                             // Used to scale pointer history in time

    void CheckButtonStates();
    void IncrementRotation(double Increment);

public:

    HControler();
    ~HControler();
    void SetForces(vec3 Forces, e_Device Device);
    vec3 GetPositions(e_Device Device);
    vec3 GetGlobalPositions(e_Device Device);
    void ConnectToDevice(e_Device Device);
    void DisconnetFromDevice(e_Device Device);
    void Block();
    void Unblock();
    double GetMaxForce(e_Device Device);
    void SetMaxForce(double Force, e_Device Device);
    void SetPointerSize(int Size, e_Device Device);
    int GetPointerSize(e_Device Device);
    bool GetStatus(e_Device Device);
    void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
    void InitializeToRender();
    bool IsInCenter(e_Device Device, double Eps);
    void GoToCenter(e_Device Device, double K);
    void MoveWorkspace(e_Device Device, double K, double Eps);
    void SetWorkspace(e_Device Device, double Workspace);
    s_HButtons GetButtons(e_Device Device);
    void DeviceFunction(int ID);
    e_HMovementType GetMovementType(e_Device Device);
    vec3 GetPositionSet(e_Device Device);
    vec3 GetOrientationSet(e_Device Device);
    vec3 GetOrientationAngles(e_Device Device);
    void CalculateLogScale();
    vec6 GetPositionsAndOrientations(e_Device Device);
};

#endif // HCONTROLER_H
