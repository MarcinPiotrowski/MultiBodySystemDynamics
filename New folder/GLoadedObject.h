
#ifndef __GLOADEDOBJECT__H__
#define __GLOADEDOBJECT__H__

#include "GHeaders.h"
#include "GObject.h"

class GLoadedObject : public GObject
{
private:

	GLfloat *m_Vertices;	// Array containing vertices positions
	GLfloat *m_Normals;		// Array containing vertices normals
	int TrianglesCount;		// Number of the triangles of the object
	GLuint VBO[2];			// Vertex Buffer Object Array
	GLuint VAO;				// Vertex Array Object

public:

	GLoadedObject();
	~GLoadedObject();
	void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
	void FillVertexBuffer();
	bool LoadGraphicObject(char *Filename);
};

#endif // __GLOADEDOBJECT__H__