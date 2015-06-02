/* *******************
 * File name : GHeader.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    20:30
 * Brief : This file include headers, that every Graphic object should include.
 * *******************
 */

#ifndef __G__HEADERS__H__
#define __G__HEADERS__H__

#define __glew_h__
#define __GLEW_H__

//#define WIN32
#define FREEGLUT_STATIC

#include <GLTools.h>
#include <GLShaderManager.h>
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <GLMath.h>
#include <Eigen>
#include <armadillo>
#include <FreeImage.h>

#include <QOpenGLFunctions_3_3_Compatibility>
#include "GFunctions.h"
#include <QDebug>
#include <QFileInfo>
#include <GL/glu.h>

using namespace Eigen;
using namespace arma;

#define G_VERT_INDEX 0
#define G_TEXT_INDEX 1
#define G_NORM_INDEX 2

#endif // __G__HEADERS__H__
