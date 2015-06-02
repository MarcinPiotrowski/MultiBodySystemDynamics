

#ifndef __GRENDER__H__
#define __GRENDER__H__

#include <iostream>
#include <string>

using namespace std;

#include "GCamera.h"
#include "GLoadedObject.h"
#include "GMouse.h"
#include "GObject.h"
#include "GPrimitiveObject.h"
#include "GRender.h"
#include "GShaderProgram.h"

#include "MBObject.h"

#include "DynamicsAlgorithms.h"


class GRender
{
private:

	static GRender *instance;
	GShaderProgram ShaderProgram;
	GPrimitiveObject mPrimitiveObjects[2];
	GLoadedObject mLoadedObjects[2];
	GCamera camera;
	GMouse mouse;
	GLGeometryTransform tranformPipeline;
	GLMatrixStack modelViewMatrix;
	GLMatrixStack projectionMatrix;
	M3DMatrix44f translationMatrix;
	M3DMatrix44f rotationMatrix;
	MBObject manipulator;
	
	int buttonDown;
	int m_MenuValue;
	int m_MenuID;

public:

	void Init(int argc, char *argv);
	void StartMainLoop();
	void SetupRC();
	virtual void display();
	virtual void reshape(int width, int height);
	virtual void mouseFunction(int button, int state, int x, int y);
	virtual void mouseMotionFunction(int x, int y);
	virtual void keyboardFunc(unsigned char key, int x, int y);
	virtual void keyboardSpecFunc(int key, int x, int y);
	virtual void MenuFunc(int Value);
	static void displayWrapper();
	static void reshapeWrapper(int width, int height);
	static void keyboardFuncWrapper(unsigned char key, int x, int y);
	static void keyboardSpecFuncWrapper(int key, int x, int y);
	static void mouseWrapper(int button, int state, int x, int y);
	static void mouseMotionWrapper(int x, int y);
	static void MenuFuncWrapper(int Value);
};

#endif //__GRENDER__H__