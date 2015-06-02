/* *******************
 * File name : GFunctions.h
 * Author : Marcin Piotrowski
 * Created : 28.04.2015    21:48
 * Brief : This file contains one function to read file.
 * *******************
 */

#ifndef __GFUNCTIONS__H__
#define __GFUNCTIONS__H__

#include <iostream>

bool ReadSource(const char *FileName, char **Source, long &Length);

#endif // __GFUNCTIONS__H__
