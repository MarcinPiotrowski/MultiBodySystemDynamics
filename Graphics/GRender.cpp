/* *******************
 * File name : GRender.cpp
 * Author : Marcin Piotrowski
 * Created : 15.04.2015    20:43
 * Brief : See GRender.h
 * *******************
 */

#include "GRender.h"

/*  Constructor
    *@class GRender
    *@param QWidget *parent
    */
GRender::GRender(QWidget *parent):
    QOpenGLWidget(parent),
    m_Initialized(0)
{
    /** Set Clear Color to white, however Clear Color is setted by
        program options **/
    m_ClearColor[0] = 1.0;
    m_ClearColor[1] = 1.0;
    m_ClearColor[2] = 1.0;
    m_ClearColor[3] = 1.0;
}

/*  Destructor
    *@class: GRender
    */
GRender::~GRender()
{
       makeCurrent();
       doneCurrent();
}

/* @fungrup "Set/Get" standard functions
   @brief various
   @params various
   @retvals various
    */

void GRender::SetBackgroundColor(const GLfloat* color)
{
    glClearColor(color[0], color[1], color[2], color[3]);
}

void GRender::SetBackgroundColorR(int R)
{
    m_ClearColor[0] = GLfloat(R/256.0);
    UpdateClearColor();
}

void GRender::SetBackgroundColorG(int G)
{
    m_ClearColor[1] = GLfloat(G/256.0);
     UpdateClearColor();
}

void GRender::SetBackgroundColorB(int B)
{
    m_ClearColor[2] = GLfloat(B/256.0);
     UpdateClearColor();
}

bool GRender::IsOpenGLInitialized()
{
    return m_Initialized;
}
/* @fungroupend "Set/Get" standard functions
   */

/*  Method
    *@brief: This method initialize every function of OpenGL to render objects.
    *@param: none
    *@retval: none
    */
void GRender::initializeGL()
{
    /** Line bellow should be review **/
    // connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GRender::cleanup);

    /** Initialize OpenGL Functions **/
    initializeOpenGLFunctions();

    /** Set Clear Color **/
    UpdateClearColor();

    /** Enable Depth Test **/
    glEnable(GL_DEPTH_TEST);

    /** Enable Smooth Line **/
    glEnable( GL_LINE_SMOOTH );

    /** Enable Color Blending **/
    glEnable( GL_BLEND );

    /** Setting parameters of color blending **/
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    /** Setting parameters of smoothness **/
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );

    /** Load Shader Program **/
    initializeOpenGLFunctions();
    m_ShaderProgram.LoadShader();

    /** Setting Camera **/
    camera.SetPerspective(35.0f, ( (float) 500 )/( (float) 500), 0.1f, 100.0f);

    /** Setting Projection Matrix **/
    projectionMatrix.LoadMatrix(camera.GetProjectionMatrix());

    /** Setting Transformation Pipeline **/
    tranformPipeline.SetMatrixStacks(modelViewMatrix,projectionMatrix);

    /** To be reviewed **/
    m_Initialized = 1;
    emit OpenGLInitialized();

}

/*  Method
    *@brief: This method renders scene.
    *@param: None
    *@retval: None
    */
void GRender::paintGL()
{
    /** Clear Color Buffer and Depth Buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /** Use shader program */
    m_ShaderProgram.UseProgram();

    /** Enable depth test */
    glEnable(GL_DEPTH_TEST);

    modelViewMatrix.PushMatrix();               // Push 1
    matG44 matrixn = camera.GetViewMatrix();
    modelViewMatrix.PushMatrix(&matrixn);       // Push 2

    GLfloat vEyeLight[] = {-100.0f, 100.0f, 100.0f};
    glUniform3fv(m_ShaderProgram.GetLightLocation(), 1, vEyeLight);

    for (int i = 0 ; i < m_RenderingObjects.length(); i++)
        m_RenderingObjects.at(i)->Draw(m_ShaderProgram, modelViewMatrix, tranformPipeline);

    modelViewMatrix.PopMatrix();                // Pop 2
    modelViewMatrix.PopMatrix();                // Pop 1

    glBindVertexArray(0);
    update();

}

/*  Method
    *@brief: This method is called, when window was resized.
    *@param int width: New width of the window
    * @param int height: New height of the window
    *@retval: None
    */
void GRender::resizeGL(int width, int height)
{
    camera.SetPerspective(35.0f, ( (float) width )/( (float) height), 0.1f, 100.0f);
    projectionMatrix.LoadMatrix(camera.GetProjectionMatrix());
    tranformPipeline.SetMatrixStacks(modelViewMatrix,projectionMatrix);
}

/*  Method
    *@brief: This method is called, when one of the mouse button is clicked.
    *@param QMouseEvent *event: QT event
    *@retval: None
    */
void GRender::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (event->button() == Qt::MidButton)
        {
        switch(event->modifiers())
               {
               case Qt::ShiftModifier:
                   {
                   mouse.MouseButtonDown();
                   mouse.SetMouseCurrentPosition(x,y);
                   mouse.SetMouseClickPosition(x,y);
                   mouse.SetOperation(MO_TRANSLATE);
                   break;
                   }

                case 0:
                    {
                    mouse.MouseButtonDown();
                    mouse.SetMouseCurrentPosition(x,y);
                    mouse.SetMouseClickPosition(x,y);
                    mouse.SetOperation(MO_ROTATE);
                    break;
                    }

               default:
                   break;
               }
       }
    update();
}

/*  Method
    *@brief: This method is called, when one of the mouse button is released.
    *@param QMouseEvent *event: QT event
    *@retval: None
    */
void GRender::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MidButton)
        {
        switch(mouse.GetOperation())
               {
               case MO_TRANSLATE:
                   {
                   mouse.MouseButtonUp();
                   mouse.SetOperation(MO_NONE);
                   mouse.SetMouseClickPosition(0,0);
                   break;
                   }

               case MO_ROTATE:
                   {
                   mouse.MouseButtonUp();
                   mouse.SetOperation(MO_NONE);
                   mouse.SetMouseClickPosition(0,0);
                   break;
                   }

               default:
                   break;
               }
       }
}

/*  Method
    *@brief: This method is called, when mouse is moved.
    *@param QMouseEvent *event: QT event
    *@retval: None
    */
void GRender::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (mouse.GetMouseButtonState())
        mouse.SetMouseCurrentPosition(x,y);

    if ( mouse.GetMouseButtonState() )
        {
            switch(mouse.GetOperation())
            {
            case MO_TRANSLATE:
                {
                camera.Translate( (x-mouse.GetMouseClickPositionX()) / 300.0 ,
                                  (y-mouse.GetMouseClickPositionY()) / 300.0);
                mouse.SetMouseCurrentPosition(x,y);
                mouse.SetMouseClickPosition(x, y);
                break;
                }
            case MO_ROTATE:
                {
                camera.Rotate(x-mouse.GetMouseClickPositionX(), -(y-mouse.GetMouseClickPositionY() ) );
                mouse.SetMouseCurrentPosition(x,y);
                mouse.SetMouseClickPosition(x, y);
                break;
                }

            default:
                break;
            }
        }

    mouse.SetMouseClickPosition(x,y);
    update();
}

/*  Method
    *@brief: This method is called, when mouse wheel is activated.
    *@param QWheelEvent *event: QT event
    *@retval: None
    */
 void GRender::wheelEvent(QWheelEvent *event)
 {
    if ( event->delta() > 0 )
          camera.Zoom(0.1f);
    if ( event->delta() < 0 )
           camera.Zoom(-0.1f);

    update();
 }

/*  Method
    *@brief: This method adds every GObject to QList m_RenderingObjects.
    *        After that, it initializes object to be ready to render (so for
    *        example for GLoadedObjects - file containing 3D model is readed and
    *        vertices are beeing saved in GPU.
    *@param: GObject *Object - every GObject, that will be rendered.
    *@param: int NumberOfObjects - number of Objects to add.
    *@retval: None
    */
void GRender::AddRenderingObject(GObject *Object, int NumberOfObjects)
{
    makeCurrent();
    m_RenderingObjects+=Object;
    initializeOpenGLFunctions();
    Object->InitializeToRender();
}

/*  Method
    *@brief: This method initializes object to be ready to render (so for
    *        example for GLoadedObjects - file containing 3D model is readed and
    *        vertices are beeing saved in GPU.
    *@param: GObject *Object - every GObject, that will be rendered.
    *@retval: None
    */
void GRender::UpdateRenderingObject(GObject *Object)
{
    makeCurrent();
    initializeOpenGLFunctions();
    Object->InitializeToRender();
}

/*  Function
    *@brief: Currently not used (see initializeGL)
    *@param
    *@retval
    */
void GRender::cleanup()
{
    makeCurrent();
    doneCurrent();
}

/*  Function
    *@brief: This function updates Clear Color
    *@param: none
    *@retval: none
    */
void GRender::UpdateClearColor()
{
    makeCurrent();
    glClearColor(m_ClearColor[0],
                 m_ClearColor[1],
                 m_ClearColor[2],
                 m_ClearColor[3]);
}
