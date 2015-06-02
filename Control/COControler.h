/* *******************
 * File name : COControler.h
 * Author : Marcin Piotrowski
 * Created : 05.05.2015    21:42
 * Brief : This file containts Controller class, that use various controlling methods to set output (torques).
 * *******************
 */

#ifndef COCONTROLER_H
#define COCONTROLER_H

#include "DHeaders.h"
#include "MBObject.h"

/*  Enum
    *@brief: Type of controller
    */
enum e_COType
{
    COT_PPLUS,
    COT_PD,
    COT_OPERATIONAL_SPACE_SPEC_PATH,
    COT_OPERATIONAl_SPACE_NO_PATH
};

/*  Struct
    *@brief: Controllers parameters
    */
struct s_ControlersParameters
{
    e_COType Type;
    int Size;
    vec m_KpDiag;
    vec m_KvDiag;
    vec m_KfDiag;
    vec m_KvfDiag;
    double m_MaxV;
};

class COControler
{
private:
    e_COType m_Type;        // Controller type
    mat m_Kp;               // Controller Kp matrix
    mat m_Kv;               // Controller Kv matrix
    mat m_Kf;               // Controller Kf matrix
    mat m_Kvf;              // Controller Kvf matrix
    int m_Size;             // Controller matrices size
    double m_MaxV;          // Max velocity in COT_OPERATIONAl_SPACE_NO_PATH controlling type
public:
    COControler();
    ~COControler();
    void SetControler(e_COType Type, mat Kp, mat Kv, int Size);
    void SetControler(e_COType Type, int Size);
    void SetControlerType(e_COType Type);
    void SetK(vec Kp, vec Kv, vec Kf, vec Kvf);
    void SetK(vec Kp, vec Kv);
    void SetKp(vec Kp);
    void SetKv(vec Kv);
    void SetKf(vec Kf);
    void SetKvf(vec Kvf);
    void SetMaxV(double V);
    void SetInitialValues(vec q, vec qd);
    vec GetTorques(vec q, vec qd, vec qr, vec gdr, MBObject *MBSystem);
    s_ControlersParameters GetParameters();
};

#endif // COCONTROLER_H
