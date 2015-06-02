/* *******************
 * File name : DMarker.cpp
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    18:14
 * Brief : See DMarker.h
 * *******************
 */

#include "DMarker.h"

/*  Constructor
    *@class DMarker
    *@param
    */
DMarker::DMarker():
	m_Type(D_USER_DEFINED),
	m_LinkNumber(-1)
{
	m_MarkerPosition.fill(0);
}

/*  Method
    *@brief: This method returns Marker Position.
    *@param: None
    *@retval VectorXd: Marker position
    */
vec6 DMarker::GetMarkerPosition()
{
	return m_MarkerPosition;
}

/*  Method
    *@brief: This method prints position of marker.
    *@param: None
    *@retval: None
    */
void DMarker::PrintMarker()
{
    cout << "Part number:" << m_LinkNumber << ", type:" << m_Type << endl;
    m_MarkerPosition.print();
}
