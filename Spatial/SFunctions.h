/* *******************
 * File name : SFunction.h
 * Author : Marcin Piotrowski
 * Created : 2015-03-08 19:23
 * Brief : This file containts functions to operate on matrices and vectors.
 * *******************
 */


#ifndef __SFUNCTION__H__
#define __SFUNCTION__H__

#include <Eigen>
#include <iostream>
#include <armadillo>
#include <QString>
#include <QDebug>

using namespace Eigen;
using namespace arma;


bool ReadSource(char *FileName, char **Source, long &Length);
mat33 EulerRotMat(double yaw, double pitch, double roll);
mat33 EulerRotMat(vec3 Vector);
mat33 RotX(double angle);
mat33 RotY(double angle);
mat33 RotZ(double angle);
mat66 RotXST(double angle);
mat66 RotYST(double angle);
mat66 RotZST(double angle);
vec3 EulerAnglesFromRotMat(mat33 Mat);
vec3 X213AnglesFromRotMat(mat33 Mat);
mat33 CrossProductOperator_3R(vec3 Vec);
mat66 CrossProductOperator_6R(vec6 Vec);
mat66 CalcInertia(mat33 SrcInertia, double mass, mat33 TransformationMatrix, vec3 TranslateVector);
mat66 TransformationMatrixFromMarkersPosition(vec6 Vec);
mat66 TranslationMatrix(vec3 Vec);
mat66 EulerRotMatSpatial(double yaw, double pitch, double roll);
void PrintMatrix(mat Matrix, QString Name);
void PrintVector(vec Vector, QString Name);

#endif // __SFUNCTION__H__
