
#include "DObject.h"

/*  @class This virtual class contains data and functions of Dynamic Object: Spacial
	* Vectors (Position, Velocity, Acceleration and Forces) and Markers
	*/

/*	*@brief Constructor
	*@param none
	*@retval none
	*/
DObject::DObject(): 
	m_NumberOfMarkers(0)
{
	m_ForcesVector.fill(0);
    m_Markers = NULL;
}

DObject::~DObject()
{
    if( m_Markers)
        delete [] m_Markers;
}

/* @fungrup "Get/Set" standart functions
   @brief This functions return spatial vectors.
		  This functions sets spatial vectors and number of markers.
   @params various
   @retvals various
	*/

void DObject::SetSpatialPositionVector(const vec6& vec)
{
    m_DTranslationVector = vec;
}

void DObject::SetSpatialVelocityVector(const vec6& vec)
{
	m_VelocityVector = vec;
}

void DObject::SetSpatialForcesVector(const vec6& vec)
{
	m_ForcesVector = vec;
}

vec6 DObject::GetSpatialPositionVector()
{
    return m_DTranslationVector;
}

vec6 DObject::GetSpatialVelocityVector()
{
	return m_VelocityVector;
}

vec6 DObject::GetSpatialForcesVector()
{
	return m_ForcesVector;
}

void DObject::SetNumberOfMarkers(const int& n)
{
	m_NumberOfMarkers = n;
}

void DObject::SetDRotationMatrix(const mat33 &Mat)
{
	m_DRotationMatrix = Mat;
}

mat33 DObject::GetDRotationMatrix()
{
	return m_DRotationMatrix;
}
void DObject::SetDTranslationVector(const vec3 &Vec)
{
	m_DTranslationVector = Vec;
}

vec3 DObject::GetDTranslationVector()
{
	return m_DTranslationVector;
}

vec6 DObject::GetSpatialAccelerationVector()
{
    return m_AccelerationVector;
}

void DObject::SetSpatialAccelerationVector(const vec6 &Vec)
{
    m_AccelerationVector = Vec;
}

/* @brief This functions allocate memory for markers
   @param none
   @retval none
	*/
void DObject::MarkersResize()
{
	m_Markers = new DMarker[m_NumberOfMarkers];
}
