/* *******************
 * File name : DynamicsAlgorithms.h
 * Author : Marcin Piotrowski
 * Created : 2015-03-05 19:07
 * Brief : This file containts Dynamic Algorithms class to perform various numerical computations.
 * *******************
 */

#ifndef __DYNAMICS__ALGORITHMS__H__
#define __DYNAMICS__ALGORITHMS__H__

#include "MBObject.h"
#include "QElapsedTimer"


void FD_AB(MBObject& MBSystem, int Gravity = 1);

void Int_PositionsAndVelocities(vec &Pos, vec &Vel, const vec &Acc, double dt, int n);

class DAlgorithms
{
private:
    int m_N;                     // Number of links
    int m_numberM;               // For future use
    int m_Iterator;              // Iterator
    mat66    m_XJ,               // Joint transformation matrix,
             m_Xn,               // Transformation matrix from base to link i
             m_Ia;               // Ia subexpression
    mat66   *m_Xup,              // Transformation matrix from link i-1 to i
            *m_IA;               // Articulated body interia matrix

    vec6     m_S,                // Joints motion subspace
             m_vJ,               // Joint velocity
             m_fExt,             // Force subexpression
             m_pa;               // Additional forces subexpression
    vec      m_q,                // Joints positions
             m_qd,               // Joints velocities
             m_qdd,              // Joints accelerations
             m_Tau;
    vec6     *m_c,               // Link Coriolis acceleration
             *m_v,               // Link velocity
             *m_pA,              // Link articulated body additional forces
             *m_fExtCM,          // Link forces in centre of mass coordinate system
             *m_a,               // Link acceleration
             *m_U,               // U subexpression
             *m_F;


    /* Joint-space and operational-space matrices and vectors **/
    mat    m_MassMatrixJ,
           m_MassMatrixO,
           m_Jacobian,
           m_Jacobianp,
           m_InvJacobian;
    vec    m_CCVectorJ,
           m_B2,
           m_CCVectorO,
           m_GVectorJ,
           m_GVectorO,
           m_ForcesJ,
           m_ForcesO,
           m_FG,
           m_FQ;

    mat   m_B,
          m_Bp,
          m_H,
          m_Hp,
          m_T1,     // Bp*FI*H+Hp
          m_T2,     // H'*FI'*M*FI
          m_T3,     // FI * H
          m_FI,
          m_M;


    mat66 m_Bj,
          m_Bpj,
          m_Mj;

    vec6 m_Hj,
         m_Hpj,
         m_FGj,
         m_FQj;


    double *m_D,                // D subexpression
           *m_u;                // u subexpression

    /** Variables for RK4 Algorithm **/
    vec kq1, kq2, kq3, kq4;
    vec kqd1, kqd2, kqd3, kqd4;
    vec q0, qd0;
    vec qt, qdt;
    bool m_CountingGlobalPositions;
    mat33 previous_mat;


public:
    void Initialize(MBObject *MBSystem, int Gravity = 1);
    void FD_AB(MBObject *MBSystem);
    void GetHCG(MBObject *MBSystem);
    vec ID(MBObject *MBSystem);
    void FD_RK4(MBObject *MBSystem, double dt, double endTime);
    void FD_RK(MBObject *MBSytem, double dt, double endTime);
    void EnableCountingGlobalPositions(bool Enable);
    vec6 IK(MBObject *MBSystem, vec6 rr);
    vec6 FK(MBObject *MBSystem);
    void CountParameters(MBObject *MBSystem);

};


#endif // __DYNAMICS__ALGORITHMS__H__
