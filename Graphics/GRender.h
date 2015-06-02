/* *******************
 * File name : GRender.h
 * Author : Marcin Piotrowski
 * Created : 15.04.2015    20:43
 * Brief : This file containts GRender class, which is used to render objects.
 * Attributes examples: Shader program object, camera object, mouse object,
 *                      rendering objects, ModelView matrix.
 * Methods examples: Rendering, setting background, allocate rendering objects.
 * *******************
 */

#ifndef __GRENDER__H__
#define __GRENDER__H__

#include <iostream>
#include <string>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Compatibility>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>

#include "GCamera.h"
#include "GLoadedObject.h"
#include "GMouse.h"
#include "GObject.h"
#include "GPrimitiveObject.h"
#include "GRender.h"
#include "GShaderProgram.h"
#include "MBObject.h"
#include "DynamicsAlgorithms.h"

#include <GL/glu.h>

using namespace std;

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)


class GRender : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Compatibility
{
    Q_OBJECT

private:

    GShaderProgram m_ShaderProgram;
    GCamera camera;
    GMouse mouse;
    GLGeometryTransform tranformPipeline;
    GLMatrixStack modelViewMatrix;
    GLMatrixStack projectionMatrix;
    GLfloat m_ClearColor[4];
    QList<GObject *> m_RenderingObjects;
    int m_Initialized;

    void UpdateClearColor();

signals:

    void OpenGLInitialized();

public:

    GRender(QWidget *parent = 0);
    ~GRender();

    void SetBackgroundColor(const GLfloat* color);
    void SetBackgroundColorR(int R);
    void SetBackgroundColorG(int G);
    void SetBackgroundColorB(int B);
    bool IsOpenGLInitialized();

    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

    void AddRenderingObject(GObject *Object, int NumberOfObjects);
    void UpdateRenderingObject(GObject *Object);

    void cleanup();
};

#endif //__GRENDER__H__

/*todo
 * 1. Complete AddRenderingObject function, to add multiple objects (only when needed).
 */
