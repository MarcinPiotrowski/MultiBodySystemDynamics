/* *******************
 * File name : GShaderProgram.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    20:32
 * Brief : This file containts GShaderProgram class, which is used to render
 *         scene in OpenGL.
 * Attributes examples: Locations to uniform variables, QT object of Shader program.
 * Methods examples: Loading shader from .vert and .frag files, using shader to render.
 * *******************
 */

#ifndef __GSHADERPROGRAM__H__
#define __GSHADERPROGRAM__H__

#include "GHeaders.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Compatibility>

class GShaderProgram : protected QOpenGLFunctions_3_3_Compatibility
{
private:

    QOpenGLShaderProgram *m_Prog;   // QT object of Shader program
    GLint m_LocMVP;                 // Location for Model-view Projection Matrix uniform
    GLint m_LocMV;                  // Location for Model-view Matrix uniform
    GLint m_LocNM;                  // Location for Normal Matrix uniform
    GLint m_LocDiffuse;             // Location for Diffuse Color Vector uniform
    GLint m_LocAmbient;             // Location for Ambient Color Vector uniform
    GLint m_LocSpecular;            // Location for Specular Color Vector uniform
    GLint m_LocLight;               // Location for Light Position Vector uniform
    GLint m_LocShading;             // Location for Shading flag uniform
    GLint m_LocTextures;            // Location for Textures flag uniform
    GLint m_LocSampler2D;           // Location for Sampler2D unifrom

public:

	GLint GetMVPLocation();
	GLint GetMVLocation();
	GLint GetNMLocation();
	GLint GetDiffuseLocation();
	GLint GetAmbientLocation();
	GLint GetSpecularLocation();
	GLint GetLightLocation();
    GLint GetShadingLocation();
    GLint GetTexturesLocation();
    GLint GetSampler2DLocation();
    void LoadShader();
	void UseProgram();
};

#endif // __GSHADERPROGRAM__H__
