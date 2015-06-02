/* *******************
 * File name : GLoadedObject.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    20:19
 * Brief : See GLoadedObject.h
 * *******************
 */

#include "GLoadedObject.h"
#include <cstdlib>
#include <ctime>

/*  Constructor
    *@class: GLoadedObject
    *@param: None
    */
GLoadedObject::GLoadedObject() : m_TrianglesCount(0)
{
    m_ModelPath = "";
    VAO = 0 ;
	VBO[0]=0;
	VBO[1]=0;
	m_Normals = NULL;
	m_Vertices = NULL;
    m_TextureCoordinates = NULL;
    initializeOpenGLFunctions();
    m_Texture = 0;
    m_TexturesFlag = 1;
}

/*  Destructor
    *@class: GLoadedObject
    *@brief: Deletes vertices and normals.
    */
GLoadedObject::~GLoadedObject()
{
	if ( m_Vertices != NULL)
		delete [] m_Vertices;
	if ( m_Normals != NULL)
		delete [] m_Normals;
}

/*  Method
    *@brief: This function check if Model path is Up-To-Date. If not - it sets new path.
    *@param QString Path: Path of the model file.
    *@retval: None
    */
void GLoadedObject::SetModelPath(QString Path)
{
    int x = QString::compare(Path, m_ModelPath, Qt::CaseSensitive);
    if (x != 0)
        {
        m_ModelPath.clear();
        m_ModelPath.append(Path);
        m_UpToDate = false;
        }
}

/*  Method
    *@brief: This method generetes the Vertex Buffer Objects, the Vertex Array Object and writes
    *        the data to the GPU
    *@param: None
    *@retval: None
    */
void GLoadedObject::FillVertexBuffer()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(3, VBO);
	glBindVertexArray(VAO);

    LoadTexture();

    /** Writing data to GPU **/
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glEnableVertexAttribArray(G_VERT_INDEX);
	glVertexAttribPointer(G_VERT_INDEX, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,m_TrianglesCount*sizeof(GLfloat)*3*3 ,m_Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glEnableVertexAttribArray(G_TEXT_INDEX);
    glVertexAttribPointer(G_TEXT_INDEX, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,m_TrianglesCount*sizeof(GLfloat)*3*3 ,m_TextureCoordinates, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glEnableVertexAttribArray(G_NORM_INDEX);
	glVertexAttribPointer(G_NORM_INDEX, 3, GL_FLOAT, GL_FALSE,0,0);
    glBufferData(GL_ARRAY_BUFFER,m_TrianglesCount*sizeof(GLfloat)*3*3 ,m_Normals, GL_STATIC_DRAW);
	
    /** Unbind previously binded buffers **/
	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

/*  Method
    *@brief: This method loads the file (.obj) and saves the vertices and the normals to the arrays.
    *@param: None
    *@retval: bool - True if fill was load, false if there was error.
    */
bool GLoadedObject::LoadGraphicObject()
{
    char *ObjSource;
    long ObjLength;

    if(!ReadSource(m_ModelPath.toUtf8().constData(), &ObjSource, ObjLength)) return false;


    char *Line = ObjSource, *End = ObjSource + ObjLength;
    float x, y, z;
    int normalsCount = 0, verticesCount = 0, texturesCount = 0;
    int i1, i2, i3, i4, i5, i6, i7, i8, i9;

    /** Current index of Vertex, Normal, and Triangle **/
    int v = 0, n = 0, T = 0, t=0;
    int pos;

    /** Getting information about number of normals, vertices and triangles **/
    while(Line < End)
        {
        /** Ignore whitespace characters **/
        while(Line < End && (*Line == ' ' || *Line == '\t'))
            Line++;

        if(sscanf(Line, "vn %f %f %f", &x, &y, &z) == 3)
            normalsCount++;

        else if(sscanf(Line, "vt %f %f", &x, &y) == 2)
            texturesCount++;

        else if(sscanf(Line, "v %f %f %f", &x, &y, &z) == 3)
            verticesCount++;

        else if(sscanf(Line, "f %d//%d %d//%d %d//%d", &i1, &i2, &i3, &i4, &i5, &i6) == 6)
            m_TrianglesCount++;

        else if(sscanf(Line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9) == 9)
            m_TrianglesCount++;

        while(Line < End && *Line != 0)
            Line++;

        while(Line < End && *Line == 0)
            Line++;
        }

    /** Allocate memory **/
    GLfloat *normals = NULL;
    GLfloat *vertices = NULL;
    GLfloat *textures = NULL;

    if(normalsCount > 0) normals = new GLfloat[normalsCount*3];
    if(texturesCount > 0) textures = new GLfloat[texturesCount*3];
    if(verticesCount > 0) vertices = new GLfloat[verticesCount*3];

    if(m_Normals != NULL)
        delete [] m_Normals;
    if(m_TextureCoordinates != NULL)
        delete [] m_TextureCoordinates;
    if(m_Vertices != NULL)
        delete [] m_Vertices;

    m_Normals = new GLfloat[m_TrianglesCount * 3*3];
    m_Vertices = new GLfloat[m_TrianglesCount * 3*3];
    m_TextureCoordinates = new GLfloat[m_TrianglesCount * 3 *3];

    /** Set position to beginning **/
    Line = ObjSource;

    while(Line < End)
        {
        while(Line < End && (*Line == ' ' || *Line == '\t'))
            Line++;

        if(sscanf(Line, "vn %f %f %f", &x, &y, &z) == 3)
            {
            normals[n++] = x;
            normals[n++] = y;
            normals[n++] = z;
            }
        else if(sscanf(Line, "v %f %f %f", &x, &y, &z) == 3)
            {
            vertices[v++] = x;
            vertices[v++] = y;
            vertices[v++] = z;

            }
        else if(sscanf(Line, "vt %f %f", &x, &y) == 2)
            {
            textures[t++] = x;
            textures[t++] = y;
            textures[t++] = 0.0;
            }
        else if(sscanf(Line, "f %d//%d %d//%d %d//%d", &i1, &i2, &i3, &i4, &i5, &i6) == 6)
            {
            /** First point of triangle **/
            pos = 3*(i1-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i2-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];

            T+=3;

            /** Second point of triangle **/
            pos = 3*(i3-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i4-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];

            T+=3;

            /** Third point of triangle **/
            pos = 3*(i5-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i6-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];

            T+=3;
        }

        else if(sscanf(Line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9) == 9)
            {
            /** First point of triangle **/
            pos = 3*(i1-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i2-1);
            m_TextureCoordinates[T] = textures[pos];
            m_TextureCoordinates[T+1] = textures[pos+1];
            m_TextureCoordinates[T+2] = 0.0;

            pos = 3*(i3-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];


            T+=3;

            /** Second point of triangle **/
            pos = 3*(i4-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i5-1);
            m_TextureCoordinates[T] = textures[pos];
            m_TextureCoordinates[T+1] = textures[pos+1];
            m_TextureCoordinates[T+2] = 0.0;

            pos = 3*(i6-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];

            T+=3;

            /** Third point of triangle **/
            pos = 3*(i7-1);
            m_Vertices[T] = vertices[pos];
            m_Vertices[T+1] = vertices[pos+1];
            m_Vertices[T+2] = vertices[pos+2];

            pos = 3*(i8-1);
            m_TextureCoordinates[T] = textures[pos];
            m_TextureCoordinates[T+1] = textures[pos+1];
            m_TextureCoordinates[T+2] = 0.0;

            pos = 3*(i9-1);
            m_Normals[T] = normals[pos];
            m_Normals[T+1] = normals[pos+1];
            m_Normals[T+2] = normals[pos+2];

            T+=3;
        }
        while(Line < End && *Line != 0) Line++;
        while(Line < End && *Line == 0) Line++;
    }

    /** Writing data to GPU memory **/
    FillVertexBuffer();

    /** Releasing memory **/
    delete [] m_Vertices;
    delete [] m_Normals;
    delete [] normals;
    delete [] vertices;
    delete [] ObjSource;

    m_Vertices = NULL;
    m_Normals = NULL;

    m_UpToDate = true;

    return true;
}

/*  Method
    *@brief: This method loads texture from previously setted path.
    *@param: Noe
    *@retval: None
    */
void GLoadedObject::LoadTexture()
{
    QString Path = m_ModelPath;
    FIBITMAP *Bits = NULL;
    BYTE *Data = NULL;
    GLfloat *DataF = NULL;

    int Width, Height, Pitch, BPP;
    GLenum Format = 0;
    /** Get image format **/
    Path = Path.left(Path.length()-4);
    Path.append(".png");
    FREE_IMAGE_FORMAT ImageFormat = FreeImage_GetFileType(Path.toLatin1().constData());
    if(ImageFormat == FIF_UNKNOWN)
        {
         m_TexturesFlag = 0;
        qDebug() << "Error loading texutre " << Path ;
        return ;
        }
    m_TexturesFlag = 1;

    Bits = FreeImage_Load(ImageFormat, Path.toLatin1().constData());
    if( Bits == NULL)
        qDebug () << "Bits is NULL";

    Width = FreeImage_GetWidth(Bits);
    Height = FreeImage_GetHeight(Bits);
    Pitch = FreeImage_GetPitch(Bits);
    BPP = FreeImage_GetBPP(Bits);

    Data = FreeImage_GetBits(Bits);
    DataF = new GLfloat[Width*Height*4];

    if(BPP == 32) Format = GL_BGRA;
    if(BPP == 24) Format = GL_BGR;

    for(int i = 0 ; i <Width*Height*4 ; i=i+4)
    {
        DataF[i+2] = GLfloat(Data[i])/255.0;          // B
        DataF[i+1] = GLfloat(Data[i+1])/255.0;        // G
        DataF[i] = GLfloat(Data[i+2])/255.0;          // R
        DataF[i+3] = GLfloat(Data[i+3])/255.0;
    }

    GLfloat pBits[4];
    pBits[0] = DataF[0];
    pBits[1] = DataF[0];
    pBits[2] = DataF[0];
    pBits[3] = 1.0;

    qDebug() << "Dataf " << DataF[0];

    glDeleteTextures(1, &m_Texture);
    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, Width, Height, 0,
                                     GL_RGBA, GL_FLOAT, DataF);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    SetAmbientColor(0.4,0.4,0.4,1.0);
    SetDiffuseColor(0.4,0.4,0.4,1.0);

}


/*  Method
    * @brief: See definition in base class.
	*/
void GLoadedObject::Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline)
{
    DrawingSetup(ShaderProgram, modelViewMatrix, tranformPipeline);
    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_2D,m_Texture);
    glDrawArrays(GL_TRIANGLES, 0, m_TrianglesCount * 3);
    glBindVertexArray(0);
}

/*  Method
    * @brief: See definition in base class.
    */
void GLoadedObject::InitializeToRender()
{
    LoadGraphicObject();
}

