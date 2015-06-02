/* *******************
 * File name : DLink.cpp
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    20:49
 * Brief : See DLink.h
 * *******************
 */

#include "DLink.h"

/*  Constructor
    *@class: DLink
    *@param: None
    */
DLink::DLink(): m_Mass(0.0),
                m_MarkerCM(NULL),
                m_MarkerJointI(NULL),
                m_MarkerJointJ(NULL),
                m_CMCylinderPosition(NULL)
{
}

/*  Destructor
    *@class: DLink
    */
DLink::~DLink()
{
}

vec3 DLink::GetJToCMTranslationVector()
{
    return m_JtoCMTranslationVector;
}

double DLink::GetMass()
{
    return m_Mass;
}
