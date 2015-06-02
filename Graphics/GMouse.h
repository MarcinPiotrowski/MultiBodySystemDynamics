/* *******************
 * File name : GMouse.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    21:55
 * Brief : This file containts GMouse class. GMouse object containts information about
 *         mouse events.
 * Attributes examples: Mouse position, current mouse operation.
 * Methods examples: Set/Get methods
 * *******************
 */

#ifndef __GMOUSE__H__
#define __GMOUSE__H__

/*  Enum
    *@brief Mouse operation (what mouse is currently performing).
    */
enum e_MoveOperation
{
	MO_NONE,
	MO_TRANSLATE,
	MO_ROTATE,
	MO_ZOOM
};

class GMouse
{
private:

	float m_MouseClickPosition[2];		// Position of the mouse, when a button was clicked
	float m_MouseCurrentPosition[2];	// Current position of the mouse
	int m_MouseButtonDownFlag;			// Flag represents if a button is pressed
	e_MoveOperation m_Operation;		// Operation to handle by Camera

public:

	GMouse();
	void SetMouseClickPosition(float x, float y);
	void SetMouseCurrentPosition(float x, float y);
	float GetMouseClickPositionX();
	float GetMouseClickPositionY();
	float GetMouseCurrentPositionX();
	float GetMouseCurrentPositionY();
	void MouseButtonDown();
	void MouseButtonUp();
	int GetMouseButtonState();
	void SetOperation(e_MoveOperation op);
	e_MoveOperation GetOperation();

};

#endif // __GMOUSE__H__
