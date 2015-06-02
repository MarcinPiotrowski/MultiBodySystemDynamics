/* *******************
 * File name : GLoadedObject.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    20:14
 * Brief : This file containts GLoadedObject class. GLoadedObject is an object, that
 *         can contain wavefront 3D object and can render it.
 *         Attributes examples: Model path, number of triangles, vertices.
 *         Methods examples: Load 3D model, draw object.
 * *******************
 */

#ifndef __GLOADEDOBJECT__H__
#define __GLOADEDOBJECT__H__

#include "GHeaders.h"
#include "GObject.h"

class GLoadedObject : public GObject
{
private:

    GLfloat *m_TextureCoordinates;  // Coordinates of texture
    GLfloat *m_Vertices;            // Array containing vertices positions
    GLfloat *m_Normals;             // Array containing vertices normals
    int m_TrianglesCount;           // Number of the triangles of the object
    GLuint VBO[3];                  // Vertex Buffer Object Array
    GLuint VAO;                     // Vertex Array Object
    QString m_ModelPath;            // Path of 3D model file
    bool m_UpToDate;                // Flag represents if loaded object is Up-To-Date with Model path
    bool m_UseTextures;             // Flag represents if object should use
    GLuint m_Texture;               // Texture handler
    void LoadTexture();

public:

	GLoadedObject();
	~GLoadedObject();
    void SetModelPath(QString Path);
	void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
	void FillVertexBuffer();
    bool LoadGraphicObject();
    void InitializeToRender();
};

#endif // __GLOADEDOBJECT__H__

/*@todo
 * 1. Check if everything is OK with SetModelPath function (compare function
 *    may be wrong).
 */
