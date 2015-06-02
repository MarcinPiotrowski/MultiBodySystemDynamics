/* *******************
 * File name :
 * Author : Marcin Piotrowski
 * Created :
 * Brief : This file containts DMarker class. DMarker object contains data of marker - euler angles (yaw, pitch and roll) and
 *         position of marker.
 * Attributes examples: Marker position, marker number
 * Methods examples: Get marker position.
 * *******************
 */

#ifndef __DMARKER__H__
#define __DMARKER__H__

#include "DHeaders.h"


/*  Enum
    *@brief: Type of marker
    */
enum MarkerType
{
	D_CM,			// Center mass marker
	D_JOINT_I,		// Parent joint marker
	D_JOINT_J,		// Child joint marker
	D_USER_DEFINED	// Other marker
};

class DMarker
{
	friend class MBObject;

private:

    vec6 m_MarkerPosition;	// Spacial Vector - position of the marker
	MarkerType m_Type;			// Marker Type, see MarkerType enum
	int m_MarkerNumber;			// Number of the marker
	int m_LinkNumber;			// Number of link containing the marker

public:

	DMarker();
    vec6 GetMarkerPosition();
	void PrintMarker();

};

#endif // __DMARKER__H__

/*@todo
 * 1. Does friend class MBObject is really needed?
 */
