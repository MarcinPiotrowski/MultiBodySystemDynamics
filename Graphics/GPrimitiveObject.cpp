/* *******************
 * File name : GPrimitiveObject.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    19:55
 * Brief : See GPrimitiveObject.h
 * *******************
 */

#include "GPrimitiveObject.h"

/*	*@brief Constructor
	*@param none
	*@retval none
	*/
GPrimitiveObject::GPrimitiveObject():
    m_IsTriangleBatch(0),
    m_PrimitiveType(G_NONE)
{
    m_ShadingFlag = 0;
}

GPrimitiveObject::~GPrimitiveObject()
{
}

/*  Method
    *@brief: This function sets a type and parameters of the object.
    *@param e_PrimitiveType Type: Type of the object.
    *@param u_TypeParameters Parameters: Parameters of selected type.
    *@retval: none
    */
void GPrimitiveObject::SetObjectTypeAndParameters(const e_PrimitiveType Type,const u_TypeParameters Parameters)
{
    m_PrimitiveType = Type;
    m_TypeParameters = Parameters;
}

/*  Method
    *@brief: This function sets parameters of floor object.
    *@param double areaWidth: Width of floor
    *@param double areaDepth: Depth of floor
    *@param double linesWidth: Width distance between lines
    *@param double linesDepth: Depth distance between lines
    *@retval: none
    */
void GPrimitiveObject::SetFloor(double areaWidth, double areaDepth, double linesWidth, double linesDepth)
{
    m_PrimitiveType = G_LINE;
    m_TypeParameters.Lines.AreaWidht = areaWidth;
    m_TypeParameters.Lines.AreaDepth = areaDepth;
    m_TypeParameters.Lines.LinesWidth = linesWidth;
    m_TypeParameters.Lines.LinesDepth = linesDepth;
}

/*
	* @brief This function creates floor containing crossing lines
	* @param areaWidth : Width of floor
	* @param areaDepth : Depth of floor
	* @param linesWidth : Number of lines in width
	* @param linesDepth : Number of lines in depth
	* @retval None
	*/
void GPrimitiveObject::CreateFloor(double areaWidth, double areaDepth, double linesWidth, double linesDepth)
{
    initializeOpenGLFunctions();
    glGenVertexArrays(1,&m_VAO);
    glGenBuffers(3,m_VBO);

    if (m_VAO != 0)
        {
        glBindVertexArray(m_VAO);
        glDeleteBuffers(3,m_VBO);
        glBindVertexArray(0);
        glGenBuffers(3,m_VBO);
        glGenVertexArrays(1,&m_VAO);
        }

    /** Allocate memory **/
    int LinesNumberWidth = int (areaWidth / linesWidth) + 1 ;
    int LinesNumberDepth = int (areaDepth / linesDepth) + 1 ;
    int Size = LinesNumberWidth*6 + LinesNumberDepth*6;

    GLfloat* data_V = new GLfloat[Size];
    GLfloat* data_C = new GLfloat[Size];
    for(int i = 0; i < Size ; i++)
        data_C[i] = 1.0f;

    m_NumberOfLines = LinesNumberDepth + LinesNumberWidth;

    int i = 0;

    /** Set vertices **/
    for( GLfloat x = -areaDepth /2 ; x <= areaDepth /2 ;x+=linesDepth)
    {
        data_V[i++] = - areaWidth / 2;
        data_V[i++] = 0.0f;
        data_V[i++] = x;

        data_V[i++] = areaWidth / 2;
        data_V[i++] = 0.0f;
        data_V[i++] = x;
    }

    for( GLfloat x = -areaWidth /2 ; x <= areaWidth /2 ;x+=linesWidth)
    {
        data_V[i++] = x;
        data_V[i++] = 0.0f;
        data_V[i++] = -areaDepth /2 ;

        data_V[i++] = x;
        data_V[i++] = 0.0f;
        data_V[i++] = areaDepth / 2;
    }

    glBindVertexArray(m_VAO);

    /** Writing data to GPU **/
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Size ,data_V, GL_STATIC_DRAW);

    /** Currently color vertices are not used, so this code does nothing **/
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Size ,data_C, GL_STATIC_DRAW);     // data_C - wrong, but for now doesn't matter

    /** Currently color vertices are not used, so this code does nothing **/
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[2]);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*Size ,data_C, GL_STATIC_DRAW);

    /** Unbind previously binded buffers **/
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

/* NOT FINISHED
    * @brief: This function creates cube
	* @param a : Side of cube
	* @retval None
	*/
void GPrimitiveObject::CreateSphere(float a)
{
	// Batch of object is simple Batch type
    m_IsTriangleBatch = 0;
	// Create cube
    // gltMakeCube(m_ObjectBatch, a);
}

/* NOT FINISHED
	* @brief This function creates cylinder
	* @param R : Radius of cylinder
	* @param L : Length of cylinder
	* @retval None
	*/
void GPrimitiveObject::CreateCylinder(double R, double L)
{
	// Batch of object is TriangleBatch type
    m_IsTriangleBatch = 1;
    GLUquadricObj* obj = gluNewQuadric();
    gluCylinder(obj,R,R,L,30,30);
	// Create Cylinder
    // gltMakeCylinder(m_ObjectTriangleBatch,R,R,L,30,30);
}

/*
    * @brief This function draw primitive object.
    * @params: See virtual definition.
    * @retval: None
	*/
void GPrimitiveObject::Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline)
{
    SetAmbientColor(0,0,0);
    SetDiffuseColor(0,0,0);
    SetSpecularColor(0,0,0);
    DrawingSetup(ShaderProgram, modelViewMatrix, tranformPipeline);
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_LINES,0,2*m_NumberOfLines);
    glBindVertexArray(0);
}


/*  Function
    *@brief: See declaration in base class.
    */
void GPrimitiveObject::InitializeToRender()
{
    switch (m_PrimitiveType)
        {
        case G_LINE:
            {
            CreateFloor(m_TypeParameters.Lines.AreaDepth,m_TypeParameters.Lines.AreaWidht,
                        m_TypeParameters.Lines.LinesDepth,m_TypeParameters.Lines.LinesWidth);
            break;
            }
        case G_CYLINDER:
            {
            CreateCylinder(m_TypeParameters.Cylinder.Radius, m_TypeParameters.Cylinder.Length);
            break;
            }
        default:
            break;
        }
}
