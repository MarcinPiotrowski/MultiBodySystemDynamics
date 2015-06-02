/* *******************
 * File name : GMouse.cpp
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    21:58
 * Brief : See GMouse.h
 * *******************
 */

#include "GMouse.h"

/*  Constructor
    *@class: GMouse
    *@param: None
    */
GMouse::GMouse()
{
	m_MouseClickPosition[0] = 0;
	m_MouseClickPosition[1] = 0;
	m_MouseCurrentPosition[0] = 0;
	m_MouseCurrentPosition[1] = 0;
	m_MouseButtonDownFlag = 0;
}

/*  @fungrup "Get/Set" standart functions
    @brief
    @params various
    @retvals various
	*/

void GMouse::SetMouseClickPosition(float x, float y)
{
	m_MouseClickPosition[0] = x;
	m_MouseClickPosition[1] = y;
}

void GMouse::SetMouseCurrentPosition(float x, float y)
{
	m_MouseCurrentPosition[0] = x;
	m_MouseCurrentPosition[1] = y;
}

float GMouse::GetMouseClickPositionX()
{
	return m_MouseClickPosition[0];
}

float GMouse::GetMouseClickPositionY()
{
	return m_MouseClickPosition[1];
}

float GMouse::GetMouseCurrentPositionX()
{
	return m_MouseCurrentPosition[0];
}

float GMouse::GetMouseCurrentPositionY()
{
	return m_MouseCurrentPosition[1];
}

void GMouse::MouseButtonDown()
{
	m_MouseButtonDownFlag = 1;
}

void GMouse::MouseButtonUp()
{
	m_MouseButtonDownFlag = 0;
}

int GMouse::GetMouseButtonState()
{
	return m_MouseButtonDownFlag;
}

void GMouse::SetOperation(e_MoveOperation Operation)
{
	m_Operation = Operation;
}

e_MoveOperation GMouse::GetOperation()
{
	return m_Operation;
}
/*  @fungroupend "Get/Set" standart functions
    */
