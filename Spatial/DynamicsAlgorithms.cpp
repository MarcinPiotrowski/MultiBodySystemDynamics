/* *******************
 * File name : DynamicsAlgorithms.cpp
 * Author : Marcin Piotrowski
 * Created : 2015-03-05 19:09
 * Brief : See DynamicAlgorithms.h
 * *******************
 */

#include "DynamicsAlgorithms.h"

QElapsedTimer tim2;
QElapsedTimer tim3;

/*  Method
    *@brief: This method initialize DAlgorithms object for specific Multibody object
    *@param MBSystem: Multibody object, that will use DAlgorithm object
    *@param Gravity: Flag representing if gravity is on/off
    *@retval
    */
void DAlgorithms::Initialize(MBObject *MBSystem, int Gravity)
{ 
    /** Defining objects - matrices, vectors and arrays **/
    m_N = MBSystem->GetNumberOfLinks();        // Number of links

    m_Iterator = 0;
    /** Creating new matrices **/
    m_Xup = new mat66[m_N];
    m_IA = new mat66[m_N];

    m_Xn.eye();

    m_q.resize(m_N);
    m_qd.resize(m_N);
    m_qdd.resize(m_N);
    m_Tau.resize(m_N);

    /** Creating new vectors and arrays **/
    m_D = new double[m_N];
    m_u = new double[m_N];
    m_c = new vec6[m_N];
    m_v = new vec6[m_N];
    m_pA = new vec6[m_N];
    m_fExtCM = new vec6[m_N];
    m_a = new vec6[m_N];
    m_F = new vec6[m_N];
    m_U = new vec6[m_N];
    m_S << 0 << 0 << 1 << 0 << 0 << 0;      // S for rovolve joint

    /** Resizing matrices and vectors **/
    for(int i = 0 ; i < m_N ; i++)
        {
        m_fExtCM[i].fill(0);
        }

    /** Counting gravity forces **/
    if(Gravity)
        for(int i = 0 ; i < m_N ; i++)
            m_fExtCM[i](4) = MBSystem->GetMass(i)*g_acc;

    kq1.resize(m_N);
    kq2.resize(m_N);
    kq3.resize(m_N);
    kq4.resize(m_N);

    kqd1.resize(m_N);
    kqd2.resize(m_N);
    kqd3.resize(m_N);
    kqd4.resize(m_N);

    q0.resize(m_N);
    qd0.resize(m_N);
    qt.resize(m_N);
    qdt.resize(m_N);

    m_CountingGlobalPositions = true;

    m_MassMatrixJ.resize(m_N,m_N);
    m_MassMatrixO.resize(m_N,m_N);
    m_Jacobian.resize(m_N,m_N);
    m_CCVectorJ.resize(m_N);
    m_B2.resize(m_N);
    m_CCVectorO.resize(m_N);
    m_GVectorJ.resize(m_N);
    m_GVectorO.resize(m_N);
    m_ForcesJ.resize(m_N);
    m_ForcesO.resize(m_N);

    m_B.resize(6*(m_N), 6*(m_N));
    m_H.resize(6*(m_N),m_N);
    m_Bp.resize(6*(m_N), 6*(m_N));
    m_Hp.resize(6*(m_N),m_N);
    m_FI.resize(6*(m_N), 6*(m_N));
    m_T1.resize(6*(m_N),m_N);
    m_T2.resize(m_N,6*(m_N));
    m_T3.resize(6*(m_N),m_N);

    m_B.fill(0.0);
    m_H.fill(0.0);
    m_Bp.fill(0.0);
    m_Hp.fill(0.0);
    m_FI.eye();

    m_Bj.eye();
    m_Bpj.fill(0.0);
    m_Hj.fill(0.0);
    m_Hpj.fill(0.0);

    m_M.resize(6*(m_N), 6*(m_N));
    m_FG.resize(6*(m_N));
    m_FQ.resize(6*(m_N));
}

void DAlgorithms::FD_AB(MBObject *MBSystem)
{
    tim3.start();
    MBSystem->GetJointsPositionsAndVelocities(m_numberM, m_q, m_qd);
    s_MBSVariables Variables = MBSystem->GetVariables();

    previous_mat.eye();
    MBSystem->Base->SetDTranslationVector(MBSystem->GetDTranslationVector());
    MBSystem->Base->SetDRotationMatrix(previous_mat);

    for(int i = 0 ; i < m_N ; i++)
        m_fExtCM[i].fill(0);

    /** Setting graber forces **/
    if(MBSystem->IsGraber())
        m_fExtCM[m_N-1] = MBSystem->Links[m_N-1].GetSpatialForcesVector();


    /** Counting gravity forces **/
    if(MBSystem->IsGravityEnabled())
        for(int i = 0 ; i < m_N ; i++)
            m_fExtCM[i](4) += MBSystem->GetMass(i)*g_acc;

    m_Xn.eye();


    /** First loop **/
    for(int i = 0 ; i < m_N ; i++)
            {

                m_XJ = RotZST(m_q(i));
                m_vJ << 0 << 0 << m_qd(i) << 0 << 0 << 0;        //PERF

            if( i == 0 )
                {
                m_Xup[i]=mat66(m_XJ * (MBSystem->Base->m_SpatialTransformationMatrix));
                m_v[i] = m_vJ;
                m_c[i].fill(0);
                }
            else
                {
                m_Xup[i] = mat66(m_XJ * (MBSystem->Links[i-1].m_SpatialTransformationMatrix));
                m_v[i] = m_Xup[i]*m_v[i-1]+m_vJ;
                // m_c[i] = CrossProductOperator_6R(m_v[i]) * m_vJ;
                 m_c[i] << m_vJ(2)*(m_v[i](1)) << -m_vJ(2)*(m_v[i](0)) <<  0 << m_vJ(2)*(m_v[i](4)) << -m_vJ(2)*(m_v[i](3)) << 0;  //PERF

                }
            m_Xn = mat66(m_Xup[i]*m_Xn);
            if(m_CountingGlobalPositions)
                {
                if (i == 0)
                    {
                    MBSystem->Links[0].SetDTranslationVector(MBSystem->GetDTranslationVector()+MBSystem->Base->GetDTranslationVector()+previous_mat*MBSystem->Base->m_JtoITranslationVector);
                    previous_mat = mat33(MBSystem->Base->m_ItoJRotationMatrix*RotZ(MBSystem->Joints[0].GetJointAngle()));
                    MBSystem->Links[0].SetDRotationMatrix(previous_mat);
//                    Variables.PotentialEnergy[i] = - MBSystem->Links[i].m_Mass * g_acc * ( MBSystem->Links[0].GetDTranslationVector() +
//                                                                                         previous_mat *
//                                                                                         (MBSystem->Links[i].GetJToCMTranslationVector()))(1);
                    }
                else
                    {
                    MBSystem->Links[i].SetDTranslationVector(MBSystem->GetDTranslationVector()+MBSystem->Links[i-1].GetDTranslationVector()+ previous_mat*MBSystem->Links[i-1].m_JtoITranslationVector);
                    previous_mat = mat33(previous_mat * MBSystem->Links[i-1].m_ItoJRotationMatrix *RotZ(MBSystem->Joints[i].GetJointAngle()));
                    MBSystem->Links[i].SetDRotationMatrix(previous_mat);
//                    Variables.PotentialEnergy[i] = - MBSystem->Links[i].m_Mass * g_acc * ( MBSystem->Links[i].GetDTranslationVector() +
//                                                                                         previous_mat *
//                                                                                         (MBSystem->Links[i].GetJToCMTranslationVector()))(1);
                    }
                }
            m_IA[i] = MBSystem->Links[i].m_SpacialInertiaMatrix;
            m_fExtCM[i] = m_Xn*m_fExtCM[i];
            m_fExt(0,0,size(3,1) ) = m_fExtCM[i](0,0,size(3,1) ) - CrossProductOperator_3R(m_fExtCM[i](3,0,size(3,1) ) ) * MBSystem->Links[i].m_JtoCMTranslationVector;
            m_fExt(3,0,size(3,1) ) = m_fExtCM[i](3,0,size(3,1) );
            m_pA[i] = -(CrossProductOperator_6R(m_v[i]).t()) * MBSystem->Links[i].m_SpacialInertiaMatrix * m_v[i]-m_fExt;

            }

         /** Second loop **/
        for(int i = m_N -1 ; i >= 0 ; i--)
            {
               m_U[i] = m_IA[i].col(2);        // PERF
               m_D[i] = m_U[i](2);     // PERF
               m_u[i] = MBSystem->Joints[i].GetJointTorque() - m_pA[i](2);
                if ( i!=0)
                    {
                    m_Ia = m_IA[i] - m_U[i]*(m_U[i].t())/m_D[i];
                    m_pa = m_pA[i]+m_Ia*m_c[i]+m_U[i]*m_u[i]/m_D[i];
                    m_IA[i-1] = m_IA[i-1] + m_Xup[i].t()*m_Ia*m_Xup[i];
                    m_pA[i-1] = m_pA[i-1] + m_Xup[i].t()*m_pa;
                    }

            }

        /** Third loop **/
        for(int i = 0 ; i < m_N ; i++)
            {
            if(i==0)
                m_a[i] = m_c[i];
            else
                m_a[i] = m_Xup[i] * m_a[i-1] + m_c[i];

            m_qdd[i] =  (m_u[i] - as_scalar(m_U[i].t()*m_a[i]) )/m_D[i];
            m_a[i] += m_S*m_qdd[i];
            }


        /** Saving data **/
         MBSystem->SetJointsAcceleration(m_qdd);


        for(int i = 0 ; i < m_N ; i++)
            {
            Variables.JointsPositions[i] = m_q[i];
            Variables.JointsVelocities[i] = m_qd[i];
            Variables.JointsAccelerations[i] = m_qdd[i];
            Variables.KineticEnergies[i] = 0.5*as_scalar(m_v[i].t() *(MBSystem->Links[i].m_SpacialInertiaMatrix)*m_v[i]);
            }
          Variables.TotalKineticEnergy = 0;
          Variables.TotalPotentialEnergy = 0;
          for(int i = 0 ; i < m_N ; i++)
              {
              Variables.TotalPotentialEnergy += Variables.PotentialEnergy[i];
              Variables.TotalKineticEnergy += Variables.KineticEnergies[i];
              }

        MBSystem->SetVariables(Variables);
}

void DAlgorithms::FD_RK4(MBObject *MBSystem, double dt, double t)
{
    int M;           // Unused variable, need for GetJointsPositionsAndVelocities function

    tim2.start();

        /** RK4 Algorithm **/

        /** Save q and qd before counting **/
        MBSystem->GetJointsPositionsAndVelocities(M, q0, qd0);

        /** Step 1 **/
        this->FD_AB(MBSystem);

        kqd1 = dt * MBSystem->GetJointsAcceleration();
        kq1 = dt * qd0;

        /** Step 2 **/

        qt = q0+0.5*kq1;
        qdt = qd0+0.5*kqd1;
        MBSystem->SetJointsPositionsAndVelocities(qt,qdt);
        this->FD_AB(MBSystem);

        kqd2 = dt * MBSystem->GetJointsAcceleration();
        kq2 = dt * qdt;

        /** Step 3 **/
        qt = q0+0.5*kq2;
        qdt = qd0+0.5*kqd2;
        MBSystem->SetJointsPositionsAndVelocities(qt,qdt);
        this->FD_AB(MBSystem);
        kqd3 = dt * MBSystem->GetJointsAcceleration();
        kq3 = dt * qdt;

        /** Step 4 **/
        qt = q0+kq3;
        qdt = qd0+kqd3;
        MBSystem->SetJointsPositionsAndVelocities(qt,qdt);
        this->FD_AB(MBSystem);
        kqd4 = dt * MBSystem->GetJointsAcceleration();
        kq4 = dt *qdt;

        q0 += (kq1 + 2*kq2 + 2*kq3 + kq4)/6;
        qd0 += (kqd1 + 2*kqd2 + 2*kqd3 + kqd4)/6;

        MBSystem->SetJointsPositionsAndVelocities(q0,qd0);

}



void DAlgorithms::FD_RK(MBObject *MBSystem, double dt, double t)
{
    int M;           // Unused variable, need for GetJointsPositionsAndVelocities function

    tim2.start();

        /** RK4 Algorithm **/

        /** Save q and qd before counting **/
        MBSystem->GetJointsPositionsAndVelocities(M, q0, qd0);

        /** Step 1 **/
        this->FD_AB(MBSystem);

        kqd1 = dt * MBSystem->GetJointsAcceleration();
        kq1 = dt * qd0;

        /** Step 2 **/

        qt = q0+kq1;
        qdt = qd0+kqd1;
        MBSystem->SetJointsPositionsAndVelocities(qt,qdt);
        this->FD_AB(MBSystem);

        kqd2 = dt * MBSystem->GetJointsAcceleration();
        kq2 = dt * qdt;

        q0 += (kq1 + kq2)/2;
        qd0 += (kqd1 + kqd2)/2;

       MBSystem->SetJointsPositionsAndVelocities(q0,qd0);

}


/*  Function
    *@brief This method return H, C matrices and G vector included in Model-state Equation:
    *       H(q) * qdd    +    C(q,qd) * qd    +    G(q)    =  T
    *@param MBSystem
    *@retval none
    */
void DAlgorithms::GetHCG(MBObject *MBSystem)
{
}


vec DAlgorithms::ID(MBObject *MBSystem)
{

    m_q = MBSystem->GetJointsPositions();
    m_qd = MBSystem->GetJointsVelocities();
    m_qdd = MBSystem->GetJointsAcceleration();

    vec6 acc;

    for(int i = 0 ; i < m_N ; i++)
        m_fExtCM[i].fill(0);

    /** Counting gravity forces **/
    if(0)
        for(int i = 0 ; i < m_N ; i++)
            m_fExtCM[i](4) = MBSystem->Links[i].m_Mass*g_acc;
    else
        for(int i = 0 ; i < m_N ; i++)
            m_fExtCM[i](4) = 0.0;

    m_Xn.eye();


    /** First loop **/
    for(int i = 0 ; i < m_N ; i++)
        {

            m_XJ = RotZST(m_q(i));
             m_vJ << 0 << 0 << m_qd(i) << 0 << 0 << 0;

        if( i == 0 )
            {
            m_Xup[i]=mat66(m_XJ * (MBSystem->Base->m_SpatialTransformationMatrix));
            m_v[i] = m_vJ;
            m_c[i].fill(0);
            }
        else
            {
            m_Xup[i] = mat66(m_XJ * (MBSystem->Links[i-1].m_SpatialTransformationMatrix));
            m_v[i] = m_Xup[i]*m_v[i-1]+m_vJ;
             m_c[i] << m_vJ(2)*(m_v[i](1)) << -m_vJ(2)*(m_v[i](0)) <<  0 << m_vJ(2)*(m_v[i](4)) << -m_vJ(2)*(m_v[i](3)) << 0;  //PERF

            }
        m_Xn = mat66(m_Xup[i]*m_Xn);
        if( i == 0)
            m_a[i] = m_S*(m_qdd(i))+CrossProductOperator_6R(m_v[i])*m_vJ;
        else
            m_a[i] = m_Xup[i]*m_a[i-1]+m_S*m_qdd(i)+CrossProductOperator_6R(m_v[i])*m_vJ;




        m_fExtCM[i] = m_Xn*m_fExtCM[i];
        m_fExt(0,0,size(3,1) ) = m_fExtCM[i](0,0,size(3,1) ) - CrossProductOperator_3R(m_fExtCM[i](3,0,size(3,1) ) ) * MBSystem->Links[i].m_JtoCMTranslationVector;
        m_fExt(3,0,size(3,1) ) = m_fExtCM[i](3,0,size(3,1) );
        m_F[i] = MBSystem->Links[i].m_SpacialInertiaMatrix*m_a[i]-(CrossProductOperator_6R(m_v[i]).t()) * MBSystem->Links[i].m_SpacialInertiaMatrix * m_v[i]-m_fExt;
        }

        vec6 temp5;
     /** Second loop **/
    for(int i = m_N-1 ; i >= 0 ; i--)
        {
        m_Tau(i) = m_F[i](2);
        //qDebug() << m_Tau(i);
        if(i!=0)
            m_F[i-1] = m_F[i-1] + m_Xup[i].t()*m_F[i];

        }

    PrintVector(m_Tau,"TAU");
    return m_Tau;
}

void Int_PositionsAndVelocities(vec &Pos, vec &Vel, const vec &Acc, double dt, int n)
{
    for(int i = 0 ; i < n ; i ++)
        {
        Vel(i) += Acc(i)*dt;
        Pos(i) += Vel(i)*dt;
        }
}

void DAlgorithms::EnableCountingGlobalPositions(bool Enable)
{
    m_CountingGlobalPositions = Enable;
}

double L_B = 0.157;
double L_1 = 0.183;
double L_2 = 0.3995;
double L_3 = 0.184;
double L_4 = 0.2155;


vec6 DAlgorithms::IK(MBObject *MBSystem, vec6 rr)
{
    vec6 RetVec;
    vec3 rc;
    vec3 rck;
    rck << 0 << 0 << 0.2 ;
    rc = rr(0,0,size(3,1))-RotX(rr(3))*RotY(rr(4))*RotZ(rr(5))*rck;
    mat R36;

    double A = sqrt(rc(0)*rc(0)+rc(2)*rc(2));
    double Temp =   acos (((rc(1)-L_B-L_1)*(rc(1)-L_B-L_1) - L_2*L_2-(L_3+L_4)*(L_3+L_4)+rc(0)*rc(0)+rc(2)*rc(2) )  /
                           (2*L_2*(L_3+L_4)));
    double Temp2  = - atan2( A*(L_2+(L_3+L_4)*cos(Temp)) - (rc(1)-L_B-L_1)*(L_3+L_4)*sin(Temp),
                           (rc(1)-L_B-L_1)*(L_2+(L_3+L_4)*cos(Temp))+A*(L_3+L_4)*sin(Temp));

    double fi[6];
    fi[0] = atan2(-rc(2),rc(0));
    fi[1] = Temp2;
    fi[2] = -Temp;

   R36 = (RotX(-M_PI/2)*RotZ(fi[0])*RotX(M_PI/2)*RotZ(fi[1])*RotZ(fi[2])).t()*RotX(rr(3))*RotY(rr(4))*RotZ(rr(5));

   fi[4] = acos(R36(1,2));
   fi[3] = atan2( (R36(2,2))/sin(fi[4]),-R36(0,2)/sin(fi[4]));
   fi[5] = atan2( (R36(1,1))/sin(fi[4]),-R36(1,0)/sin(fi[4]));

    RetVec << fi[0] <<  fi[1]  <<  fi[2] << fi[3] << fi[4] << fi[5];
    return RetVec;

}

/*  Function
    *@brief: To implenet in the future
    *@param
    *@retval
    */
vec6 DAlgorithms::FK(MBObject *MBSystem)
{
    vec6 RetVec;
    return RetVec;
}

/*  Method
    *@brief: This method counts
    *@param
    *@retval
    */
void DAlgorithms::CountParameters(MBObject *MBSystem)
{
    vec3 *hij;
    vec3 *rij;
    vec3 j_S;
    vec6 *V;
    V = new vec6[6];
    int m_N = MBSystem->GetNumberOfLinks();
    vec JointsSpeed;
    vec JointsAccelerations;

    JointsSpeed.resize(m_N);
    JointsAccelerations.resize(m_N);

    JointsSpeed = MBSystem->GetJointsVelocities()(0,0,size(6,1));
    JointsAccelerations = MBSystem->GetJointsAcceleration()(0,0,size(6,1));

    j_S << 0 << 0 << 1;

    hij = new vec3[MBSystem->GetNumberOfLinks()];
    rij = new vec3[MBSystem->GetNumberOfLinks()];

    previous_mat.eye();

    /** Counting Hij and Rij **/
    for(int i = 0 ; i < m_N ; i++)
        {
        if (i == 0)
            {
            rij[i] = vec3(previous_mat * MBSystem->Base->m_JtoITranslationVector);
            previous_mat = mat33(MBSystem->Base->m_ItoJRotationMatrix*RotZ(MBSystem->Joints[0].GetJointAngle()));
            hij[i] =  previous_mat*j_S;
            }
        else
            {
            rij[i] = vec3(previous_mat*(MBSystem->Links[i-1].m_JtoITranslationVector));
            previous_mat = mat33(previous_mat * MBSystem->Links[i-1].m_ItoJRotationMatrix *RotZ(MBSystem->Joints[i].GetJointAngle()));
            hij[i] =  previous_mat*j_S;
            }
        }

    vec3 KPosition;
    KPosition.fill(0);
    for(int i = 0 ; i < m_N ; i++)
        KPosition += rij[i];

    MBSystem->SetGraberPosition(KPosition);
    vec3 KOrientation = X213AnglesFromRotMat(previous_mat);
    MBSystem->SetGraberOrientation(KOrientation);


    /** Counting H and B **/

    for(int i = 0 ; i < MBSystem->GetNumberOfLinks() ; i++)
        {
        m_Hj << 0 << 0 << 0 << hij[i](0) << hij[i](1) << hij[i](2);

        if (i==0)
            V[i]=m_Hj * JointsSpeed(i);
       else
            {
             m_Bj(0,3, size(3,3)) = - CrossProductOperator_3R(rij[i]);
             V[i] = m_Bj * V[i-1]  +  m_Hj * JointsSpeed(i);

             m_Hpj(3,0, size(3,1)) = CrossProductOperator_3R(V[i-1] (3,0, size(3,1)))*hij[i];

             m_Bpj(0,3,size(3,3)) = - CrossProductOperator_3R(CrossProductOperator_3R(V[i-1] (3,0, size(3,1)))*rij[i]);
             PrintMatrix(m_Bpj, "BPJ");
             m_B(6*i,6*(i-1),size(6,6)) = m_Bj;
             m_Bp(6*i,6*(i-1),size(6,6)) = m_Bpj;

             /** Counting FI **/
             for(int k = 0 ; k < i ; k++)
                 m_FI(6*i, 6*k, size(6,6)) = m_Bj * m_FI(6*(i-1),6*k, size(6,6));
            }

        m_H(6*i,i,size(6,1)) = m_Hj;
        m_Hp(6*i,i,size(6,1)) = m_Hpj;
        m_FGj.fill(0);
        m_FQj.fill(0);

        m_FG(6*i,0,size(6,1)) = m_FGj;
        m_FQ(6*i,0,size(6,1)) = m_FQj;
        }

    m_T3 = m_FI*m_H;
    m_Jacobian = m_T3(30,0,size(6,6));

    MatrixXd Mat;
    MatrixXd Mati;
    Mat.resize(6,6);
    Mati.resize(6,6);



    Mat << m_Jacobian(0,0) , m_Jacobian(0,1) , m_Jacobian(0,2) , m_Jacobian(0,3) , m_Jacobian(0,4) , m_Jacobian(0,5),
           m_Jacobian(1,0) , m_Jacobian(1,1) , m_Jacobian(1,2) , m_Jacobian(1,3) , m_Jacobian(1,4) , m_Jacobian(1,5),
           m_Jacobian(2,0) , m_Jacobian(2,1) , m_Jacobian(2,2) , m_Jacobian(2,3) , m_Jacobian(2,4) , m_Jacobian(2,5),
           m_Jacobian(3,0) , m_Jacobian(3,1) , m_Jacobian(3,2) , m_Jacobian(3,3) , m_Jacobian(3,4) , m_Jacobian(3,5),
           m_Jacobian(4,0) , m_Jacobian(4,1) , m_Jacobian(4,2) , m_Jacobian(4,3) , m_Jacobian(4,4) , m_Jacobian(4,5),
           m_Jacobian(5,0) , m_Jacobian(5,1) , m_Jacobian(5,2) , m_Jacobian(5,3) , m_Jacobian(5,4) , m_Jacobian(5,5);

    Mati = Mat.inverse();

    m_InvJacobian << Mati(0,0) << Mati(0,1) << Mati(0,2) << Mati(0,3) << Mati(0,4) << Mati(0,5) << endr <<
                     Mati(1,0) << Mati(1,1) << Mati(1,2) << Mati(1,3) << Mati(1,4) << Mati(1,5) << endr <<
                     Mati(2,0) << Mati(2,1) << Mati(2,2) << Mati(2,3) << Mati(2,4) << Mati(2,5) << endr <<
                     Mati(3,0) << Mati(3,1) << Mati(3,2) << Mati(3,3) << Mati(3,4) << Mati(3,5) << endr <<
                     Mati(4,0) << Mati(4,1) << Mati(4,2) << Mati(4,3) << Mati(4,4) << Mati(4,5) << endr <<
                     Mati(5,0) << Mati(5,1) << Mati(5,2) << Mati(5,3) << Mati(5,4) << Mati(5,5)  ;


    vec6 testjac;
    testjac = m_Jacobian * JointsSpeed;
    PrintVector(testjac, "predkosci");

    vec6 test8;
    test8 = m_InvJacobian * V[5];

    MBSystem->setGraberVelocities(V[5]);

    PrintVector(test8, "predkosci w zlaczach?");

    m_T1 = m_Bp*m_FI*m_H+m_Hp;
    m_T2 = (m_H.t()) * (m_FI.t()) * m_M * m_FI;
    mat Temp2;
    Temp2.resize(36,6);
    Temp2=m_FI * m_T1;
    m_Jacobianp = Temp2(30,0,size(6,6));

    vec6 JA;
    JA.fill(0.0);
    vec6 savedqdd;
    savedqdd = MBSystem->GetJointsAcceleration();
    MBSystem->SetJointsAcceleration(JA);
    m_CCVectorJ = ID(MBSystem);
    MBSystem->SetJointsAcceleration(savedqdd);

    vec6 delta;
    m_MassMatrixJ.fill(0);
    vec6 f1, f2;
    for(int i = 0 ; i < 6 ;i++)
    {
        delta.fill(0);
        MBSystem->SetJointsAcceleration(delta);
        f1 = ID(MBSystem);
        delta(i) = 1.0;
        MBSystem->SetJointsAcceleration(delta);
        f2 = ID(MBSystem);
        m_MassMatrixJ(0,i,size(6,1)) = f2 - f1;
    }

    MBSystem->SetJointsAcceleration(savedqdd);

    PrintMatrix(m_MassMatrixJ, "aaa");

    m_GVectorJ.fill(0);

    m_MassMatrixO =  (m_InvJacobian.t())*m_MassMatrixJ*m_InvJacobian; //*m_MassMatrixJ*m_InvJacobian;
    PrintMatrix(m_MassMatrixJ, "MassJ");
    PrintMatrix(m_InvJacobian, "invJ");
    PrintMatrix(m_Jacobian, "Jacobian");
    m_CCVectorO = m_InvJacobian.t()*m_CCVectorJ-m_MassMatrixO*m_Jacobianp*JointsSpeed;
    m_GVectorO = m_Jacobian.t()*m_GVectorJ;

    m_B2 = m_CCVectorJ - m_Jacobian.t()*m_MassMatrixO*m_Jacobianp * JointsSpeed;

    MBSystem->SetB2(m_B2);
    MBSystem->SetCCVectorJ(m_CCVectorJ);
    MBSystem->SetCCVectorO(m_CCVectorO);
    MBSystem->SetFG(m_FG);
    MBSystem->SetFQ(m_FQ);
    MBSystem->SetForcesJ(m_ForcesJ);
    MBSystem->SetForcesO(m_ForcesO);
    MBSystem->SetGVectorJ(m_GVectorJ);
    MBSystem->SetGVectorO(m_GVectorO);
    MBSystem->SetInvJacobian(m_InvJacobian);
    MBSystem->SetJacobian(m_Jacobian);
    MBSystem->SetJacobianp(m_Jacobianp);
    MBSystem->SetMassMatrixJ(m_MassMatrixJ);
    MBSystem->SetMassMatrixO(m_MassMatrixO);
}
