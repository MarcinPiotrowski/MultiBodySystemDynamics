/* *******************
 * File name : DJoint.h
 * Author : Marcin Piotrowski
 * Created : 12.04.2015    10:07
 * Brief : This file defines class DJoint and enumerated type JointType.
 * *******************
 */


#ifndef __DJOINT__H__
#define __DJOINT__H__

#include "DObject.h"

/*  * @enum Type of Joint
	*/
enum JointType
{
	D_REVOLUTE,
	D_PRISMATIC,
	D_SCREW,
    D_CYLINDRICAL,
    D_FIXED
};

class DJoint: public DObject
{
private:

	JointType m_Type;	// Type of joint
    double m_JointAngle;
    double m_JointVelocity;
    double m_JointAcceleration;
    double m_JointTorque;



public:
    DJoint();
    void SetJointAngle(double Angle);
    void SetJointVelocity(double Velocity);
    void SetJointAcceleration(double Acceleration);
    void SetJointTorque(double Torque);
    double GetJointAngle();
    double GetJointVelocity();
    double GetJointAcceleration();
    double GetJointTorque();
};

#endif // __DJOINT__H__
