/* *******************
 * File name : comovementprogram.h
 * Author : Marcin Piotrowski
 * Created : 2015-06-02   20:16
 * Brief : See comovementprogram.cpp
 * *******************
 */

#include "comovementprogram.h"

vec COMovementProgram::GetSingleTrajectory(double t_c, double t_b, double t_e,
                                        vec q_b, vec q_e, e_TrajectoryType Type, e_TrajectoryProfile Profile, double Frequency)
{
    double s;
    vec retVec(m_N);
    int N = Frequency * (t_e - t_b);      /** Counting number of points **/
    int j = N* (t_c - t_b) / (t_e-t_b);
    int m = (0.1 * N);

    if (j <= m)
        s =  j*(j+1.0)  / ( (N-m+1)*2.0*m);
    else if( j < N-m+1)
        s = (2.0*j-m+1) / (2.0* (N-m+1));
    else
        s=1 - (N-j)*(N-j+1.0)/ ( (N-m+1)*2.0*m);

    retVec = q_b + s*(q_e-q_b);
    return retVec;
}
