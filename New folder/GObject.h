
#ifndef __GOBJECT__H__
#define __GOBJECT__H__

#include "GHeaders.h"
#include "GShaderProgram.h"
#include "SFunctions.h"

class GObject
{
protected:

	static int s_ObjectCount;					// How many objects was created
	Matrix3d m_RotationMatrix;					// Rotation matrix of the object
	Vector3d m_EulerAngles;						// Euler angles of the object
	Vector3d m_TranslationVector;				// Translation vector of the object
	GLfloat m_DiffuseColor[4];					// Diffuse Color
	GLfloat m_AmbientColor[4];					// Ambient Color
	GLfloat m_AmbientColorNotHighlighted[4];	// Ambient Color before highlighting
	GLfloat m_SpecularColor[4];					// Specular Color
	Vector3d m_Scale;							// Object scale
	int m_HighLighted;							// Flag represents if the object is highlighted

public:

	GObject();
	virtual void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline) = 0;
	void GetDiffuseColor(GLfloat *color);
	void SetDiffuseColor(const GLfloat *color);
	void GetAmbientColor(GLfloat *color);
	void SetAmbientColor(const GLfloat *color);
	void GetSpecularColor(GLfloat *color);
	void SetSpecularColor(const GLfloat *color);
	void SetRandomColors();
	void SetGTranslationVector(Vector3d Vec);
	void SetGPositionX(float x);
	void SetGPositionY(float y);
	void SetGPositionZ(float z);
	void SetGPosition(float x, float y, float z);
	float GetGPositionX();
	float GetGPositionY();
	float GetGPositionZ();
	void SetGRotationMatrix(Matrix3d Mat);
	void SetGEulerAngles(Vector3d Vec);
	Matrix3d GetGRotationMatrix();
	void SetScale(float x, float y, float z);
	int GetObjectCount();
	void DrawingSetup(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline);
	void HighLight();
	void UnHighLight();
};

#endif // __GOBJECT__H__