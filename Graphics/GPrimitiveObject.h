/* *******************
 * File name : GPrimitiveObject.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    19:39
 * Brief : This file containts GPrimitiveObject class. This class is used to create and render
 *         primitive graphic objects (cylinder, lines etc.).
 *         Attributes examples: Object type, object parameters, OpenGL handlers.
 *         Methods examples: Creating primitives, drawing.
 * *******************
 */

#ifndef __GPRIMITIVEOBJECT__H__
#define __GPRIMITIVEOBJECT__H__

#include "GObject.h"

/*  Enum
    *@brief Type of primitive object
    */
enum e_PrimitiveType
{
    G_NONE,
    G_LINE,
    G_CUBE,
    G_CYLINDER,
};

/*  Struct
    *@brief: Parameters of Line primitive object
    */
struct s_Lines
{
    double AreaWidht;
    double AreaDepth;
    double LinesWidth;
    double LinesDepth;
};

/*  Struct
    *@brief: Parameters of Cylinder primitive object
    */
struct s_Cylinder
{
    double Radius;
    double Length;
};

/*  Union
    *@brief: Paramiters of primitive object
    */
union u_TypeParameters
{
    s_Lines Lines;
    s_Cylinder Cylinder;
};

class GPrimitiveObject : public GObject
{
private:

    e_PrimitiveType m_PrimitiveType;        // Type of primitive object
    u_TypeParameters m_TypeParameters;      // Parameters of primitive object
    int m_IsTriangleBatch;                  /* Flag representing if object must be render by GLTools library.
                                               Currently not used. */
    GLuint m_VAO;                           // Vertex Array Object (OpenGL)
    GLuint m_VBO[3];                        // Vertex Buffer Object (OpenGL)
    int m_NumberOfLines;                    // Number of lines used when rendering lines

public:

    GPrimitiveObject();
    ~GPrimitiveObject();
    void SetObjectTypeAndParameters(const e_PrimitiveType Type,const u_TypeParameters Parameters);
    void SetFloor(double areaWidth, double areaDepth, double linesWidth, double linesDepth);
    void CreateFloor(double areaWidth, double areaDepth, double linesWidth, double linesDepth);
	void CreateSphere(float r);
	void CreateCylinder(double R, double L);
	void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
    void InitializeToRender();
};

#endif // __GPRIMITIVEOBJECT__H__

/*@todo
 * 1. Add other primitives (only when needed).
 */
