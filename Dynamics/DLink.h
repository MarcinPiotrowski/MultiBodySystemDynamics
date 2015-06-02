/* *******************
 * File name : DLink.h
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    18:19
 * Brief : This file containts DLink class. DLink object containst data of the link in Multibody system.
 * Attributes examples:
 * Methods examples:
 * *******************
 */

#ifndef __DLINK__H__
#define __DLINK__H__

#include "DObject.h"


/*  Struct
    *@brief: Contains data of cylinder parameters.
    */
struct Cylinder
	{
	double Lenght;
	double Radius;
	};

/*  Struct
    *@brief: Contains data of geometry link parameters
    */
struct Link
	{
	double Widht;
	double Depth;
	};

/*  Union
    *@brief: Contains data of link parameters
    */
union LinkParameters
{
	Cylinder u_Cylinder;
	Link u_Link;
};

class DLink: public DObject
{
	friend class MBObject;
    friend void FD_AB(MBObject& MBSystem, int Gravity);
    friend class DAlgorithms;

protected:

    /** This attributes are in cartesian space (P_L) connectected with Joint J Marker **/
    DMarker* m_MarkerCM;				// Center of mass marker in P_L
    DMarker* m_MarkerJointI;			// I joint marker - end of the joint (connection with succesor) in P_L
    DMarker* m_MarkerJointJ;			// J joint marker - beginning of the joint (connection with accessor) in P_L
    vec3 m_JtoITranslationVector;       // Vector from J marker to I marker in P_L (so from I to J marker it will be with minus sign)
    vec3 m_JtoCMTranslationVector;      // Vector from J marker to CM marker in P_L (so from CM to J marker it will be with minus sign)


    mat33 m_ItoJRotationMatrix;		// 3x3 Matrix from marker I to J

    mat33 m_CylinderRotationMatrix;      // ???
    mat33 m_CMRotationMatrix;            // ???
    DMarker* m_CMCylinderPosition;          // ???
    mat66 m_SpatialTransformationMatrix; // ??

	double m_Mass;						// Mass of link
    mat33 m_InertiaMatrix;			// Inertia matrix (3x3)
    mat66 m_SpacialInertiaMatrix;	// Spacial inertia matrix (6x6)
	LinkParameters m_LinkParameters;	// Parameters of link

public:

	DLink();
	~DLink();
    void SetPositionsResults();
    void GetPositionsResults();
    vec3 GetJToCMTranslationVector();
    double GetMass();
};

#endif __DLINK__H__

/*@todo:
 * 1. Does friendship is needed?
 */
