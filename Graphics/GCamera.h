/* *******************
 * File name : GCamera.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    21:59
 * Brief : This file containts GCamera class. GCamera object operates camera.
 * Attributes examples: Frustrum, View matrix, position and reference position.
 * Methods examples: Move, rotate, set frustrum
 * *******************
 */

#ifndef __GCAMERA__H__
#define __GCAMERA__H__

#include "GHeaders.h"

class GCamera
{
private:

    GLFrustum m_Frustum;            // Perspective frustum
    matG44 m_ViewMatrix;            // View matrix
    vecG3 m_xAxis,                  // X axis
         m_yAxis,                   // Y axis
         m_zAxis,                   // Z axis
         m_Reference,               // Reference position
         m_Position;                // Current position

public:

    GCamera();
    void SetPerspective(float fFov, float fAspect, float fNear, float fFar);
    const M3DMatrix44f& GetProjectionMatrix();
    const matG44 &GetViewMatrix();

    void CalculateView();
    void Translate(float dx, float dy);
    void Rotate(float dx, float dy);
    void Zoom(float d);

};

#endif // __GCAMERA__H__
