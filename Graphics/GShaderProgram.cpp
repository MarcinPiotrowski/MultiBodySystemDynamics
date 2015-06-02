/* *******************
 * File name : GShaderProgram.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    20:36
 * Brief : See GShaderProgram.h
 * *******************
 */

#include "GShaderProgram.h"

/*  @fungrup "Get" standart functions
    @brief This functions return uniforms locations
    @params None
	@retvals Locations of uniforms
	*/

GLint GShaderProgram::GetMVPLocation()
{
	return m_LocMVP;
}

GLint GShaderProgram::GetMVLocation()
{
	return m_LocMV;
}

GLint GShaderProgram::GetNMLocation()
{
	return m_LocNM;
}

GLint GShaderProgram::GetDiffuseLocation()
{
	return m_LocDiffuse;
}

GLint GShaderProgram::GetAmbientLocation()
{
	return m_LocAmbient;
}

GLint GShaderProgram::GetSpecularLocation()
{
	return m_LocSpecular;
}

GLint GShaderProgram::GetLightLocation()
{
	return m_LocLight;
}

GLint GShaderProgram::GetShadingLocation()
{
    return m_LocShading;
}

GLint GShaderProgram::GetTexturesLocation()
{
    return m_LocTextures;
}

GLint GShaderProgram::GetSampler2DLocation()
{
    return m_LocSampler2D;
}

/* @fungroupend "Get" standart functions
   */

/*  Method
    * @brief: This method loads shaders program - Vertex Shader and Fragment Shader.
    * @param: None
    * @retval: None
	*/
void GShaderProgram::LoadShader()
{
    initializeOpenGLFunctions();

    /** Loading shader **/
    m_Prog = new QOpenGLShaderProgram;
    m_Prog->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/GShaders/gvertexshader.vert");
    m_Prog->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GShaders/gfragmentshader.frag");
    m_Prog->bindAttributeLocation("vPosition",G_VERT_INDEX);
    m_Prog->bindAttributeLocation("vTextures",G_TEXT_INDEX);
    m_Prog->bindAttributeLocation("vNormal",G_NORM_INDEX);
    m_Prog->link();
    m_Prog->bind();

    /** Getting uniform locations **/
    m_LocMVP = glGetUniformLocation(m_Prog->programId(), "mMVP");
    m_LocMV = glGetUniformLocation(m_Prog->programId(), "mMV");
    m_LocNM = glGetUniformLocation(m_Prog->programId(), "mNormal");
    m_LocLight = glGetUniformLocation(m_Prog->programId(), "vLight");
    m_LocDiffuse = glGetUniformLocation(m_Prog->programId(), "vColorValue");
    m_LocAmbient = glGetUniformLocation(m_Prog->programId(), "ambientColor");
    m_LocDiffuse = glGetUniformLocation(m_Prog->programId(), "diffuseColor");
    m_LocSpecular = glGetUniformLocation(m_Prog->programId(), "specularColor");
    m_LocShading = glGetUniformLocation(m_Prog->programId(), "bShading");
    m_LocTextures = glGetUniformLocation(m_Prog->programId(), "bTextures");
    m_LocSampler2D = glGetUniformLocation(m_Prog->programId(), "colorMap");

}

/*  Method
    * @brief: This method tells OpenGL to use program, that was previously loaded with
    *		 function LoadShader()
    * @param: None
    * @retval: None
	*/
void GShaderProgram::UseProgram()
{
    m_Prog->bind();
}
