/* *******************
 * File name : DJoint.cpp
 * Author : Marcin Piotrowski
 * Created : 03.05.2015
 * Brief : See DJoint.h
 * *******************
 */

#include "DJoint.h"


/*  Constructor
    *@class DJoint
    *@param
    */
DJoint::DJoint(): m_JointTorque(0)
{
}

void DJoint::SetJointAngle(double Angle)
{
    m_JointAngle = Angle;
}

void DJoint::SetJointVelocity(double Velocity)
{
    m_JointVelocity = Velocity;
}

void DJoint::SetJointAcceleration(double Acceleration)
{
    m_JointAcceleration = Acceleration;
}

void DJoint::SetJointTorque(double Torque)
{
    m_JointTorque = Torque;
}

double DJoint::GetJointAngle()
{
    return m_JointAngle;
}

double DJoint::GetJointVelocity()
{
    return m_JointVelocity;
}

double DJoint::GetJointAcceleration()
{
    return m_JointAcceleration;
}

double DJoint::GetJointTorque()
{
    return m_JointTorque;
}

