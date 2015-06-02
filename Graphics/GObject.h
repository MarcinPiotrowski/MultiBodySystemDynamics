/* *******************
 * File name : GObject.h
 * Author : Marcin Piotrowski
 * Created : 15.04.2015    21:30
 * Brief : This file contain GObject class. This class is the virtual
 *         class created for Graphic Objects.
 *         GObject class is the base class of every object, that can be rendered using OpenGL.
 *         Attributes examples: Position in scene, rotation matrix of the object, colors.
 *         Methods examples: Set/Get Attributes, drawing the object (virtual), setup before drawing.
 * *******************
 */

#ifndef __GOBJECT__H__
#define __GOBJECT__H__

#include "GHeaders.h"
#include "GShaderProgram.h"
#include "SFunctions.h"

class GObject :  protected QOpenGLFunctions_3_3_Compatibility
{

protected:

    mat33 m_GRotationMatrix;					// Rotation matrix [3x3] of the object
    vec3 m_GEulerAngles;                        // Euler angles [3x1] of the object
    vec3 m_GTranslationVector;                  // Translation vector [3x1] of the object
    vec3 m_Scale;                               // Object scale
	GLfloat m_DiffuseColor[4];					// Diffuse Color
	GLfloat m_AmbientColor[4];					// Ambient Color
	GLfloat m_SpecularColor[4];					// Specular Color
    GLfloat m_AmbientColorNotHighlighted[4];	// Ambient Color before highlighting
    int m_HighLighted;							// Flag represents if the object is highlighted
    GLboolean m_ShadingFlag;                    // Flag represents if shading should be used
    GLboolean m_TexturesFlag;                   // Flag represents if Textures should be used

public:

    GObject();

    mat33 GetGRotationMatrix();
    void SetGRotationMatrix(const mat33 &Mat);

    void SetGEulerAngles(const vec3 &Vec);

    void SetGPositionX(float x);
    void SetGPositionY(float y);
    void SetGPositionZ(float z);
    void SetGPosition(float x, float y, float z);
    void SetGPosition(const vec3 &Vec);

    float GetGPositionX();
    float GetGPositionY();
    float GetGPositionZ();
    vec3 GetGPosition();

    vec3 GetScale();
    void SetScale(float x, float y, float z);
    void SetScale(const vec3 &Scale);

    vec4 GetDiffuseColor();
	void GetDiffuseColor(GLfloat *color);
	void SetDiffuseColor(const GLfloat *color);
    void SetDiffuseColor(float R, float G, float B, float A = 1.0);
    void SetDiffuseColor(const vec4 &Color);

    vec4 GetAmbientColor();
	void GetAmbientColor(GLfloat *color);
	void SetAmbientColor(const GLfloat *color);
    void SetAmbientColor(float R, float G, float B, float A = 1.0);
    void SetAmbientColor(const vec4 &Color);

    vec4 GetSpecularColor();
	void GetSpecularColor(GLfloat *color);
	void SetSpecularColor(const GLfloat *color);
    void SetSpecularColor(float R, float G, float B, float A = 1.0);
    void SetSpecularColor(const vec4 &Color);

    void HighLight();
    void UnHighLight();

    void EnableShading(bool flag);
    void EnableTextures(bool flag);

    virtual void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline) = 0;
	void DrawingSetup(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline);
    virtual void InitializeToRender();
    void SetRandomColors();
};

#endif // __GOBJECT__H__

/* @todo:
 * 1. When euler angles are set (function SetGEulerAngles) Rotation Matrix should be updated.
 */
