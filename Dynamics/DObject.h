/* *******************
 * File name : DObject.h
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    07:46
 * Brief : This file containts DObject class. DObject class is the base class of every
 *         dynamic object (ie. an object, that moves in a space, has mass, inertia etc.).
 * Attributes examples: Position, velocity, acceleration, forces acting on object, markers
 *                      of the object.
 * Methods examples: Get/Set method.
 * *******************
 */

#ifndef __DOBJECT__H__
#define __DOBJECT__H__

#include "DHeaders.h"
#include "DMarker.h"

class DObject
{
private:

    vec6 m_ForcesVector;		// Spatial Forces Vector
    vec6 m_VelocityVector;		// Spatial Velocity Vector
    vec6 m_AccelerationVector;	// Spatial Acceleration Vector

protected:

    DMarker* m_Markers;				 // Markers of object
    int m_NumberOfMarkers;			 // Number of markers that object contains
    mat33 m_DRotationMatrix;      // Rotation Matrix
    vec3 m_DTranslationVector;   // Translation Vector

public:

	DObject();
    ~DObject();
    void SetDTranslationVector(const vec3 &Vec);
    vec3 GetDTranslationVector();
    mat33 GetDRotationMatrix();
    void SetDRotationMatrix(const mat33 &Mat);

	void PrintAllMarkers();
	void MarkersResize();
	void SetNumberOfMarkers(const int& n);
    vec6 GetSpatialPositionVector();
    void SetSpatialPositionVector(const vec6& vec);
    vec6 GetSpatialVelocityVector();
    void SetSpatialVelocityVector(const vec6& Vec);
    vec6 GetSpatialForcesVector();
    void SetSpatialForcesVector(const vec6& Vec);
    vec6 GetSpatialAccelerationVector();
    void SetSpatialAccelerationVector(const vec6 &Vec);
};

#endif // __DOBJECT__H__
