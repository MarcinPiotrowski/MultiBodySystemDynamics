/* *******************
 * File name : comovementprogram.h
 * Author : Marcin Piotrowski
 * Created : 2015-06-02   20:16
 * Brief : This file containt COMovementProgram class.
 * *******************
 */

#ifndef COMOVEMENTPROGRAM
#define COMOVEMENTPROGRAM

#include <QList>
#include <DHeaders.h>

/*  Enum
    *@brief: Type of trajectory
    */
enum e_TrajectoryType
{
    TT_DEFAULT,
    TT_LINEAR,
    TT_QUASILINEAR
};

/*  Enum
    *@brief: Velocity profile of trajectory
    */
enum e_TrajectoryProfile
{
    TP_DEFAULT,
    TP_CONSTANT,
    TP_TRAPEZOID,
    TP_QUADRATIC,
    TP_CUBIC,
    TP_QUARTIC
};

/*  Struct
    *@brief: Data of single trajectory
    */
struct s_SingleTrajectory
{
    double t_b;     // Starting point
    double t_e;     // Ending point
    e_TrajectoryProfile Profile;
    e_TrajectoryType Type;
};

class COMovementProgram
{
private:
    int m_N;
    QList<s_SingleTrajectory> Trajectories;

public:
    vec GetSingleTrajectory(double t_c, double t_b, double t_e,
                                 vec q_b, vec q_e, e_TrajectoryType Type = TT_DEFAULT, e_TrajectoryProfile Profile = TP_DEFAULT, double Frequency = 500);
    vec GetPosition(double t_c);
};

#endif // COMOVEMENTPROGRAM

