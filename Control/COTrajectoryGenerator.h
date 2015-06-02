/* *******************
 * File name : cotrajectorygenerator.cpp
 * Author : Marcin Piotrowski
 * Created : 12.04.2015    13:09
 * Brief : This file include COTrajectoryGenerator class.
 * *******************
 */

#ifndef COTRAJECTORYGENERATOR
#define COTRAJECTORYGENERATOR

#include "DHeaders.h"
#include "comovementprogram.h"


/*  Enum
    *@brief
    */
enum e_COTGType
{
    COTG_HapticPosition,
    COTG_HapticOrientation
};

class COTrajcetoryGenerator
{
private:
    QList<COMovementProgram> MovementPrograms;
    int m_N;    // Number of joints.
    double m_Frequency;
    vec3 m_PositionSet;
    vec3 m_OrientationSet;
    e_COTGType m_Type;


public:
    COTrajcetoryGenerator(double Frequency = 500);
    void SetFrequency(double Frequency);
    void SetNumberOfJoints(int N);
    vec3 GetPositionSet();
    void SetPositionSet(vec3 Position);
    vec3 GetOrientationSet();
    void SetOrientationSet(vec3 Position);
    void SetGeneratorType(e_COTGType Type);
    e_COTGType GetGeneratorType();
};


#endif // COTRAJECTORYGENERATOR

