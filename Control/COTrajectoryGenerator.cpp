/* *******************
 * File name : COTrajectoryGenerator.cpp
 * Author : Marcin Piotrowski
 * Created : 12.04.2015    13:29
 * Brief : This file includes definition of COTrajectoryGenerator class methods.
 * *******************
 */

#include "COTrajectoryGenerator.h"

/*  Constructor
    *@class COTrajectoryGenerator
    *@param e_TrajectoryType Type
    *@param double Frequency
    */


COTrajcetoryGenerator::COTrajcetoryGenerator(double Frequency):
    m_Frequency(Frequency)
{
}

void COTrajcetoryGenerator::SetFrequency(double Frequency)
{
    m_Frequency = Frequency;
}

void COTrajcetoryGenerator::SetNumberOfJoints(int N)
{
    m_N = N;
}

vec3 COTrajcetoryGenerator::GetPositionSet()
{
    return m_PositionSet;
}

void COTrajcetoryGenerator::SetPositionSet(vec3 Position)
{
    m_PositionSet = Position;
}

vec3 COTrajcetoryGenerator::GetOrientationSet()
{
    return m_OrientationSet;
}

void COTrajcetoryGenerator::SetOrientationSet(vec3 Orientation)
{
    m_OrientationSet = Orientation;
}

e_COTGType COTrajcetoryGenerator::GetGeneratorType()
{
    return m_Type;
}

void COTrajcetoryGenerator::SetGeneratorType(e_COTGType Type)
{
    m_Type = Type;
}
