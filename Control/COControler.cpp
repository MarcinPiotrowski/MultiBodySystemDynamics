/* *******************
 * File name : COControler.cpp
 * Author : Marcin Piotrowski
 * Created : 05.05.2015    21:45
 * Brief : See COControler.h.
 * *******************
 */

#include "COControler.h"

int Step;

/*  Constructor
    *@class COControler
    *@param
    */
COControler::COControler()
{
    m_MaxV = 10000;
    iter2 = 0;
}

/*  Destructor
    *@class COControler
    */
COControler::~COControler()
{
}

/*  Method
    *@brief: This function sets controller parameters
    *@param Type: type of the controller
    *@param Kp: Kp matrix
    *@param Kv: Kv matrix
    *@param Size: size of matrices
    *@retval: None
    */
void COControler::SetControler(e_COType Type, mat Kp, mat Kv, int Size)
{
    m_Size = Size;
    m_Kp.resize(m_Size,m_Size);
    m_Kv.resize(m_Size,m_Size);
    m_Type = Type;
    m_Kp = Kp;
    m_Kv = Kv;
}

/*  Method
    *@brief: This function sets controller parameters
    *@param Type: type of the controller
    *@param Size: size of matrices
    *@retval: None
    */
void COControler::SetControler(e_COType Type,int Size)
{
    m_Size = Size;
    m_Type = Type;
    m_Kp.resize(m_Size,m_Size);
    m_Kv.resize(m_Size,m_Size);
    m_Kf.resize(m_Size,m_Size);
    m_Kvf.resize(m_Size,m_Size);
}

/*  Method
    *@brief: This function sets controller type
    *@param Type: type of the controller
    *@retval: None
    */
void COControler::SetControlerType(e_COType Type)
{
    m_Type = Type;
}

/*  Method
    *@brief: This function calculate torques and returns them.
    *@param q: Current position of manipulator
    *@param qd: Current velocity of manipulator
    *@param qr: Reference position of manipulator
    *@param qdr: Reference velocity of manipulator
    *@param MBSystem: Manipulator
    *@retval vec - Torques
    */
vec COControler::GetTorques(vec q, vec qd, vec qr, vec qdr, MBObject *MBSystem)
{
    vec6 Torques;
    vec6 FmPre;
    switch (m_Type)
        {
        case COT_PD:
            {
            Torques = m_Kp*(qr-q)-m_Kv*(qdr-qd);
            break;
            }
        case COT_PPLUS:
            {
            Torques =  m_Kp*(qr-q)-m_Kv*qd;
            break;
            }
        case COT_OPERATIONAl_SPACE_NO_PATH:
            {
            double ni;
            vec xdp;
            xdp.resize(m_Size);
            for(int i = 0 ; i < m_Size ; i++)
                xdp(i) = (m_Kp(i,i) / m_Kv(i,i)) * (qr(i)-q(i));

            PrintVector(xdp,"xdp");
            ni = m_MaxV / (sqrt( as_scalar(xdp.t() * xdp)));
            if (ni > 1)
                ni = 1;
            FmPre = - m_Kv * (qd - ni * xdp);
            FmPre(4) = 0 ;
            FmPre(5) = 0;

            Torques = MBSystem->GetJacobian().t()*(MBSystem->GetMassMatrixO()*FmPre+MBSystem->GetCCVectorO()+MBSystem->GetGVectorO());
            PrintVector(Torques,"Torques");


           //Torques(3) = 0;
            Torques(4) = 0;
            Torques(5) = 0;
            break;
            }
        default:
            break;
        }

    if(Step == 200)
        {
        qDebug() << "q:" << q(0) << q(1) << q(2) << q(3) << q(4) << q(5) ;
        qDebug() << "qr:" << qr(0) << qr(1) << qr(2) << qr(3) << qr(4) << qr(5) ;
        qDebug() << "FmPre" << FmPre(0) << FmPre(1) << FmPre(2) << FmPre(3) << FmPre(4) << FmPre(5) ;
        qDebug() << "Torques" << Torques(0) << Torques(1) << Torques(2) << Torques(3) << Torques(4) << Torques(5) ;
        iter2 = 0;
        }
    else
        Step++;

    return Torques;
}

/*  Method
    *@brief: This method return controller parameters
    *@param: None
    *@retval s_ControlersParameters: Parameters of the controller
    */
s_ControlersParameters COControler::GetParameters()
{
    s_ControlersParameters Parameters;
    Parameters.Size = m_Size;
    Parameters.Type = m_Type;
    Parameters.m_KpDiag = m_Kp.diag();
    Parameters.m_KvDiag =  m_Kv.diag();
    Parameters.m_KfDiag = m_Kf.diag();
    Parameters.m_KvfDiag = m_Kvf.diag();
    Parameters.m_MaxV = m_MaxV;
    return Parameters;
}

void COControler::SetK(vec Kp, vec Kv, vec Kf, vec Kvf)
{
    m_Kp.diag() = Kp;
    m_Kv.diag() = Kv;
    m_Kf.diag() = Kf;
    m_Kvf.diag() = Kvf;
}

void COControler::SetK(vec Kp, vec Kv)
{
    m_Kp.diag() = Kp;
    m_Kv.diag() = Kv;
}

void COControler::SetKp(vec Kp)
{
    m_Kp.diag() = Kp;
}

void COControler::SetKv(vec Kv)
{
    m_Kv.diag() = Kv;
}

void COControler::SetKf(vec Kf)
{
    m_Kf.diag() = Kf;
}

void COControler::SetKvf(vec Kvf)
{
    m_Kvf.diag() = Kvf;
}

void COControler::SetMaxV(double V)
{
    m_MaxV = V;
}
