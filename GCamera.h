

#ifndef __GCAMERA__H__
#define __GCAMERA__H__

#include "GHeaders.h"

class GCamera
{
private:

	GLFrame m_CameraFrame;
	GLFrustum m_Frustum;
	mat4x4 m_ViewMatrix;
	vec3 xAxis, yAxis, zAxis, reference, position;

public:

	GCamera();
	void Move(vec3 MoveVec);
	void SetPerspective(float fFov, float fAspect, float fNear, float fFar);
	const M3DMatrix44f& GetProjectionMatrix();
	void MoveForward(float d);
	const mat4x4 &GetViewMatrix();
	void CalculateView();
	void Rotate(float dx, float dy);
	void Translate(float dx, float dy);
};

#endif // __GCAMERA__H__