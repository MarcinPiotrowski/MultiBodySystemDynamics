/* *******************
 * File name : CObject.h
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    20:50
 * Brief : This file containts CObject class. CObject object contains data and functions of Complex Objects: Graphic and Dynamic
 *         parameters .
 * Attributes examples: None
 * Methods examples: Drawing object.
 * *******************
 */

#ifndef __COBJECT__H__
#define __COBJECT__H__

#include "GLoadedObject.h"
#include "DLink.h"

class CObject: public GLoadedObject, public DLink
{
    friend class MBObject;
    friend class KMain;

public:

    CObject();
    void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);

};

#endif // __COBJECT__H__
