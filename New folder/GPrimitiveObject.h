
#ifndef __GPRIMITIVEOBJECT__H__
#define __GPRIMITIVEOBJECT__H__

#include "GObject.h"

class GPrimitiveObject : public GObject
{
private:
	GLBatch m_ObjectBatch;
	GLTriangleBatch m_ObjectTriangleBatch;
	int m_IsTriangleBatch;
public:
	GPrimitiveObject();
	void CreateFloor(int areaWidth, int areaDepth, int linesWidth, int linesDepth);
	void CreateSphere(float r);
	void CreateCylinder(double R, double L);
	void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
};

#endif // __GPRIMITIVEOBJECT__H__