/* *******************
 * File name : GCamera.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    22:24
 * Brief : See GCamera.h
 * *******************
 */

#include "GCamera.h"

/*  Constructor
    *@class GCamera
    *@param
    */
GCamera::GCamera()
{
    m_Reference = vecG3(0,0,0);
    m_Position = vecG3(0,0,5);

    m_xAxis = vecG3(1.0, 0.0, 0.0);
    m_yAxis = vecG3(0.0, 1.0, 0.0);
    m_zAxis = vecG3(0.0, 0.0, 1.0);
}

/* @fungrup "Get/Set" standart functions
    */
void GCamera::SetPerspective(float fFov, float fAspect, float fNear, float fFar)
{
    m_Frustum.SetPerspective(fFov,fAspect,fNear,fFar);
}

const M3DMatrix44f &GCamera::GetProjectionMatrix()
{
    return m_Frustum.GetProjectionMatrix();
}

const matG44 &GCamera::GetViewMatrix()
{
    CalculateView();
    return m_ViewMatrix;
}
/* @fungroupend "Get/Set" standart functions
   */

/*  Method
    *@brief: This method recalculate View Matrix
    *@param: None
    *@retval: None
    */
void GCamera::CalculateView()
{
    m_ViewMatrix = ViewMatrix(m_xAxis, m_yAxis, m_zAxis, m_Position);
}

/*  Method
    *@brief: This method zooms camera
    *@param float d: Zoom ratio
    *@retval: None
    */
void GCamera::Zoom(float d)
{
    m_Position -= m_Reference;
    if(d < 0 && length(m_Position) < 500.0f)
        {
        m_Position += m_Position * 0.1f;
        }
    if(d > 0 && length(m_Position) > 0.05f)
        {
        m_Position -= m_Position * 0.1f;
        }

    m_Position += m_Reference;
    CalculateView();
}

/*  Method
    *@brief: This method translates camera
    *@param float dx: X displacement
    *@param float dy: Y displacement
    *@retval: None
    */
void GCamera::Translate(float dx, float dy)
{
    vecG3 Up = m_yAxis;
    vecG3 Right = m_xAxis;
    vecG3 MoveVec = (Up*dy) - (Right*dx);
    m_Reference += MoveVec;
    m_Position += MoveVec;
}

/*  Method
    *@brief: This method rotates camera
    *@param float dx: X angle
    *@param float dy: Y agnle
    *@retval: None
    */
void GCamera::Rotate(float dx, float dy)
{
    float sensitivity = 0.25f;
    float hangle = (float)dx * sensitivity;
    float vangle = (float)dy * sensitivity;
    m_Position -= m_Reference;
    m_yAxis = rotate(m_yAxis, vangle, m_xAxis);
    m_zAxis = rotate(m_zAxis, vangle, m_xAxis);

    if(m_yAxis.y < 0.0f)
        {
        m_zAxis = vecG3(0.0f, m_zAxis.y > 0.0f ? 1.0f : -1.0f, 0.0f);
        m_yAxis = cross(m_zAxis, m_xAxis);
        }

    m_xAxis = rotate(m_xAxis, hangle, vecG3(0.0f, 1.0f, 0.0f));
    m_yAxis = rotate(m_yAxis, hangle, vecG3(0.0f, 1.0f, 0.0f));
    m_zAxis = rotate(m_zAxis, hangle, vecG3(0.0f, 1.0f, 0.0f));
    m_Position = m_Reference + m_zAxis * length(m_Position);
    CalculateView();
}
