/* *******************
 * File name : CObject.cpp
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    20:51
 * Brief : See CObject.h
 * *******************
 */

#include "CObject.h"

/*  Constructor
    *@class: CObject
    *@param: None
    */
CObject::CObject()
{
}

/*  Method
    * @brief: See definition in base class (GObject).
	*/
void CObject::Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline)
{
	SetGRotationMatrix( m_DRotationMatrix*m_CylinderRotationMatrix );
    vec3 TranslationVectorSave = m_GTranslationVector;
    SetGPosition(m_DTranslationVector+m_GTranslationVector);
    GLoadedObject::Draw(ShaderProgram,modelViewMatrix,tranformPipeline);
    SetGPosition(TranslationVectorSave);
}
