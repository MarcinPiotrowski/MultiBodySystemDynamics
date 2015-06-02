/* *******************
 * File name : GObject.cpp
 * Author : Marcin Piotrowski
 * Created : 15.04.2015    21:29
 * Brief : See GObject.h
 * *******************
 */

#include "GObject.h"


/*	*@brief Constructor
	*@param none
	*@retval none
	*/
GObject::GObject()
{
    //initializeOpenGLFunctions();
    /** Initializing Graphic Spatial Position with 0 values **/
    m_GTranslationVector.zeros();
    m_GEulerAngles.zeros();
    m_Scale << 1.0 << 1.0 << 1.0;
    m_GRotationMatrix.eye();
	m_HighLighted = 0;
    m_ShadingFlag = true;
    m_TexturesFlag = false;

	// Initializing Colors with 0 values
	for ( int i=0 ; i<4 ; i++)
		m_DiffuseColor[i]=m_AmbientColor[i]=m_SpecularColor[0]=0;
}

/* @fungrup "Get/Set" standart functions
   @brief This functions return positions of object, total number of objects, vectors of colors
		  This functions sets vectors of colors
   @params various
   @retvals various
	*/

void GObject::SetGRotationMatrix(const mat33 &Mat)
{
	m_GRotationMatrix = Mat;
    m_GEulerAngles=EulerAnglesFromRotMat(m_GRotationMatrix);
}

void GObject::SetGEulerAngles(const vec3 &Vec)
{
	m_GEulerAngles = Vec;
}

void GObject::SetGPosition(const vec3 &Vec)
{
	m_GTranslationVector = Vec;
}

mat33 GObject::GetGRotationMatrix()
{
	return m_GRotationMatrix;
}

float GObject::GetGPositionX()
{
	return m_GTranslationVector(0);
}


float GObject::GetGPositionY()
{
	return m_GTranslationVector(1);
}


float GObject::GetGPositionZ()
{
	return m_GTranslationVector(2);
}

void GObject::SetGPositionX(float x)
{
	m_GTranslationVector(0) = x;
}

void GObject::SetGPositionY(float y)
{
	m_GTranslationVector(1) = y;
}

void GObject::SetGPositionZ(float z)
{
	m_GTranslationVector(2) = z;
}

void GObject::SetGPosition(float x, float y, float z)
{
	m_GTranslationVector(0) = x;
	m_GTranslationVector(1) = y;
	m_GTranslationVector(2) = z;
}

vec3 GObject::GetGPosition()
{
    return m_GTranslationVector;
}

vec3 GObject::GetScale()
{
    return m_Scale;
}

void GObject::SetScale(float x, float y, float z)
{
	m_Scale(0) = x;
	m_Scale(1) = y;
	m_Scale(2) = z;
}

void GObject::SetScale(const vec3 &Scale)
{
    m_Scale = Scale;
}

vec4 GObject::GetDiffuseColor()
{
    vec4 RetVec;
    RetVec << m_DiffuseColor[0] << m_DiffuseColor[1] <<
                   m_DiffuseColor[2] << m_DiffuseColor[3];
    return RetVec;
}

void GObject::GetDiffuseColor(GLfloat *color)
{
	memcpy(color,m_DiffuseColor,sizeof(float)*4);
}

void GObject::SetDiffuseColor(const GLfloat *color)
{
	memcpy(m_DiffuseColor,color,sizeof(float)*4);
}

void GObject::SetDiffuseColor(float R, float G, float B, float A)
{
    m_DiffuseColor[0] = R;
    m_DiffuseColor[1] = G;
    m_DiffuseColor[2] = B;
    m_DiffuseColor[3] = A;
}

void GObject::SetDiffuseColor(const vec4 &Color)
{
    m_DiffuseColor[0] = Color(0);
    m_DiffuseColor[1] = Color(1);
    m_DiffuseColor[2] = Color(2);
    m_DiffuseColor[3] = Color(3);
}

vec4 GObject::GetAmbientColor()
{
    vec4 RetVec;
    RetVec << m_AmbientColor[0] << m_AmbientColor[1] <<
                   m_AmbientColor[2] <<  m_AmbientColor[3];
    return RetVec;
}

void GObject::GetAmbientColor(GLfloat *color)
{
	memcpy(color,m_AmbientColor,sizeof(float)*4);
}

void GObject::SetAmbientColor(const GLfloat *color)
{
	memcpy(m_AmbientColor,color,sizeof(float)*4);
	memcpy(m_AmbientColorNotHighlighted,color,sizeof(float)*4);
}

void GObject::SetAmbientColor(float R, float G, float B, float A)
{
    m_AmbientColor[0] = R;
    m_AmbientColor[1] = G;
    m_AmbientColor[2] = B;
    m_AmbientColor[3] = A;
}

void GObject::SetAmbientColor(const vec4 &Color)
{
    m_AmbientColor[0] = Color(0);
    m_AmbientColor[1] = Color(1);
    m_AmbientColor[2] = Color(2);
    m_AmbientColor[3] = Color(3);
}

vec4 GObject::GetSpecularColor()
{
    vec4 RetVec;
    RetVec << m_SpecularColor[0] << m_SpecularColor[1] <<
                   m_SpecularColor[2] << m_SpecularColor[3];
    return RetVec;
}

void GObject::GetSpecularColor(GLfloat *color)
{
    memcpy(color,m_SpecularColor,sizeof(float)*4);
}

void GObject::SetSpecularColor(const GLfloat *color)
{
    memcpy(m_SpecularColor,color,sizeof(float)*4);
}

void GObject::SetSpecularColor(float R, float G, float B, float A)
{
    m_SpecularColor[0] = R;
    m_SpecularColor[1] = G;
    m_SpecularColor[2] = B;
    m_SpecularColor[3] = A;
}

void GObject::SetSpecularColor(const vec4 &Color)
{
    m_SpecularColor[0] = Color(0);
    m_SpecularColor[1] = Color(1);
    m_SpecularColor[2] = Color(2);
    m_SpecularColor[3] = Color(3);
}

void GObject::HighLight()
{
	if (m_HighLighted == 0 )
		{
		for( int i = 0 ; i < 4 ; i++)
			m_AmbientColor[i]*=5;
		}
	m_HighLighted = 1;
}

void GObject::UnHighLight()
{
	if (m_HighLighted == 1 )
		for(int i = 0 ; i < 4 ; i++)
			m_AmbientColor[i] = m_AmbientColorNotHighlighted[i];
	m_HighLighted = 0;
}

void GObject::EnableShading(bool flag)
{
    m_ShadingFlag = flag;
}

void GObject::EnableTextures(bool flag)
{
    m_TexturesFlag = flag;
}

/* @fungroupend "Get/Set" standart functions
   */

/*  Virtual function
    *@brief: This function renders objects. See definition in childs.
    *@params: See DrawingSetup function.
    *@retval: None
    */
/**
virtual void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline) = 0;
**/

/*
	* @brief This function sets Uniform Variables.
	* @param ShaderProgram : Shader Program used for rendering
	* @param ModelViewMatrix : Model View Matrix containing Camera data
	* @param TransformPipeline : Transformation Pipeline containing MVP Matrix, MV Matrix and N Matrix data
	* @retval None
	*/
void GObject::DrawingSetup(GShaderProgram& ShaderProgram, GLMatrixStack& ModelViewMatrix, GLGeometryTransform& TransformPipeline)
{
    // First Matrix Push
	ModelViewMatrix.PushMatrix();	

	// Translating and rotating (euler angles) the object
	ModelViewMatrix.Translate(m_GTranslationVector(0), m_GTranslationVector(1), m_GTranslationVector(2) );
	ModelViewMatrix.Rotate(m_GEulerAngles(0)*180.0/M_PI,0.0, 0.0, 1.0);
	ModelViewMatrix.Rotate(m_GEulerAngles(1)*180.0/M_PI,1.0, 0.0, 0.0);
	ModelViewMatrix.Rotate(m_GEulerAngles(2)*180.0/M_PI,0.0, 0.0, 1.0);

	// Setting Uniform for Normal Matrix before scalling
    glUniformMatrix3fv(ShaderProgram.GetNMLocation(), 1, GL_FALSE, TransformPipeline.GetNormalMatrix() );
    ModelViewMatrix.Scale(m_Scale(0), m_Scale(1), m_Scale(2));

    // Setting Uniforms for MVP Matrix, MV Matrix
    glUniformMatrix4fv(ShaderProgram.GetMVPLocation(), 1, GL_FALSE, TransformPipeline.GetModelViewProjectionMatrix());
    glUniformMatrix4fv(ShaderProgram.GetMVLocation(), 1, GL_FALSE, TransformPipeline.GetModelViewMatrix() );

    // Setting Uniforms for Diffuse Color, Ambient Color, Specular Color and Shading Flag
    glUniform4fv(ShaderProgram.GetDiffuseLocation(), 1, m_DiffuseColor);
    glUniform4fv(ShaderProgram.GetAmbientLocation(), 1, m_AmbientColor);
    glUniform4fv(ShaderProgram.GetSpecularLocation(), 1, m_SpecularColor);
    glUniform1i(ShaderProgram.GetShadingLocation(),m_ShadingFlag);
    glUniform1i(ShaderProgram.GetTexturesLocation(),m_TexturesFlag);

    // Sampler 2D uniform
     glUniform1i(ShaderProgram.GetSampler2DLocation(),0);

	// First Matrix Pop
	ModelViewMatrix.PopMatrix();		
}

/*  Function
    *@brief: This function do some task before the object will be ready to render.
    *@param: None
    *@retval: None
    */
void GObject::InitializeToRender()
{
    // Do nothing
}

/*
    * @brief This function sets random Diffuse color for the object.
    * @param none
    * @retval None
    */
void GObject::SetRandomColors()
{
    GLfloat RColor, GColor, BColor;
    RColor = (rand()%1000)/1000.0;
    GColor = (rand()%1000)/1000.0;
    BColor = (rand()%1000)/1000.0;

    SetDiffuseColor(RColor, GColor, BColor, 1.0f);
    SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
    SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
}
