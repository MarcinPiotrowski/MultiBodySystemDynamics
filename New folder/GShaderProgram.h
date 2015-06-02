
#ifndef __GSHADERPROGRAM__H__
#define __GSHADERPROGRAM__H__

#include "GHeaders.h"


class GShaderProgram
{
private:

	GLint m_LocMVP;				// Location for Model-view Projection Matrix uniform
	GLint m_LocMV;				// Location for Model-view Matrix uniform
	GLint m_LocNM;				// Location for Normal Matrix uniform
	GLint m_LocDiffuse;			// Location for Diffuse Color Vector uniform
	GLint m_LocAmbient;			// Location for Ambient Color Vector uniform
	GLint m_LocSpecular;		// Location for Specular Color Vector uniform
	GLint m_LocLight;			// Location for Light Position Vector uniform
	GLint m_ShaderProgram;		// Refference to Shader Program

public:

	GLint GetMVPLocation();
	GLint GetMVLocation();
	GLint GetNMLocation();
	GLint GetDiffuseLocation();
	GLint GetAmbientLocation();
	GLint GetSpecularLocation();
	GLint GetLightLocation();
	void LoadShader(char *VertexShaderName, char *FragmentShaderName);
	void UseProgram();
};

#endif // __GSHADERPROGRAM__H__