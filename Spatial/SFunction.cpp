/* *******************
 * File name : SFunction.cpp
 * Author : Marcin Piotrowski
 * Created : 2015-03-08 19:25
 * Brief : See SFunction.h
 * *******************
 */

#include "SFunctions.h"
#include <armadillo>

using namespace arma;

 //#define qprint
/** Undefine if printing should be turn on **/

mat33 EulerRotMat(double yaw, double pitch, double roll)
{
    return mat33(RotZ(yaw)*RotX(pitch)*RotZ(roll));
}

mat33 EulerRotMat(vec3 Vector)
{
    return mat33(RotZ(Vector(0))*RotX(Vector(1))*RotZ(Vector(2)));
}

mat66 EulerRotMatSpatial(double yaw, double pitch, double roll)
{
    mat66 RetMatrix;
	RetMatrix.fill(0);
    RetMatrix(0,0,size(3,3) ) = EulerRotMat(yaw, pitch, roll);
    RetMatrix(3,3,size(3,3) ) = RetMatrix(0,0,size(3,3) );
	return RetMatrix;
}

vec3 EulerAnglesFromRotMat(mat33 Mat)
{
    vec3 RetVec;
	RetVec(1) =  acos(Mat(2,2));
	if(RetVec(1) >-0.0000001 && RetVec(1) < 0.0000001)
		{
		RetVec(0) = 0;
		RetVec(2) = atan2(Mat(1,0) , Mat(0,0));
		}
	else
		{	
		RetVec(0) = atan2(Mat(0,2)/sin(RetVec(1)),-Mat(1,2)/sin(RetVec(1)));
		RetVec(2) = atan2(Mat(2,0)/sin(RetVec(1)),Mat(2,1)/sin(RetVec(1)));
		}
	return RetVec;
}

vec3 X213AnglesFromRotMat(mat33 Mat)
{
    vec3 RetVec;
    RetVec(1) =  -asin(Mat(1,2));
    RetVec(0) = atan2(Mat(0,2),Mat(2,2));
    RetVec(2) = atan2(Mat(1,0),Mat(1,1));
    return RetVec;

}

mat33 RotX(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat33 RMat;
    RMat << 1 << 0 << 0 << endr <<
            0 << c << -s << endr <<
            0 << s << c << endr;

	return RMat;
}

mat33 RotY(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat33 RMat;
    RMat << c  << 0  << s  << endr
         << 0  << 1  << 0  << endr
         <<-s  << 0  << c << endr;

	return RMat;
}

mat33 RotZ(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat33 RMat;
    RMat << c  << -s  << 0  << endr
         << s  << c  << 0  << endr
         << 0  << 0  << 1 << endr;

	return RMat;
}

mat66 RotXST(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat66 RMat;
    RMat <<  1  <<  0  <<  0  <<  0  <<  0  <<  0  << endr <<
             0  <<  c  <<  s  <<  0  <<  0  <<  0  << endr <<
             0  << -s  <<  c  <<  0  <<  0  <<  0  << endr <<
             0  <<  0  <<  0  <<  1  <<  0  <<  0  << endr <<
             0  <<  0  <<  0  <<  0  <<  c  <<  s  << endr <<
             0  <<  0  <<  0  <<  0  << -s  <<  c  << endr;

	return RMat;
}

mat66 RotYST(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat66 RMat;
    RMat <<  c  <<  0  << -s  <<  0  <<  0  <<  0  << endr <<
             0  <<  1  <<  0  <<  0  <<  0  <<  0  << endr <<
             s  <<  0  <<  c  <<  0  <<  0  <<  0  << endr <<
             0  <<  0  <<  0  <<  c  <<  0  << -s  << endr <<
             0  <<  0  <<  0  <<  0  <<  1  <<  0  << endr <<
             0  <<  0  <<  0  <<  s  <<  0  <<  c  << endr;

	return RMat;
}

mat66 RotZST(double angle)
{
	double c = cos(angle);
	double s = sin(angle);

    mat66 RMat;
    RMat <<  c  <<  s  <<  0  <<  0  <<  0  <<  0  << endr <<
            -s  <<  c  <<  0  <<  0  <<  0  <<  0  << endr <<
             0  <<  0  <<  1  <<  0  <<  0  <<  0  << endr <<
             0  <<  0  <<  0  <<  c  <<  s  <<  0  << endr <<
             0  <<  0  <<  0  << -s  <<  c  <<  0  << endr <<
             0  <<  0  <<  0  <<  0  <<  0  <<  1  << endr;

	return RMat;
}

mat33 CrossProductOperator_3R(vec3 Vec)
{
    mat33 RetMatrix;
	RetMatrix.fill(0);

	RetMatrix(0,1) = -Vec(2);
	RetMatrix(1,0) = Vec(2);
	RetMatrix(0,2) = Vec(1);
	RetMatrix(2,0) = -Vec(1);
	RetMatrix(1,2) = -Vec(0);
	RetMatrix(2,1) = Vec(0);

	return RetMatrix;
}

mat66 CrossProductOperator_6R(vec6 Vec)
{
    mat66 RetMatrix;
    RetMatrix <<  0      << -Vec(2)  << Vec(1)   << 0        << 0        << 0       << endr <<
                 Vec(2)  << 0        << -Vec(0)  << 0        << 0        << 0       << endr <<
                -Vec(1)  << Vec(0)   << 0        << 0        << 0        << 0       << endr <<
                  0      << -Vec(5)  << Vec(4)   << 0        << -Vec(2)  << Vec(1)  << endr <<
                Vec(5)   << 0        << -Vec(3)  << Vec(2)   << 0        << -Vec(0) << endr <<
                -Vec(4)  << Vec(3)   << 0        << -Vec(1)  << Vec(0)   << 0       << endr;
	return RetMatrix;
}


mat66 CalcInertia(mat33 SrcInertia, double mass, mat33 TransformationMatrix, vec3 TranslateVector)
{
    mat66 RetInertia;
    mat33 RetInertia_3R;
    mat33 CrossProductMatrix;

    RetInertia_3R = mat33(TransformationMatrix * SrcInertia * TransformationMatrix.t());
	CrossProductMatrix = CrossProductOperator_3R(TranslateVector);

    RetInertia(0,0,size(3,3) ) = RetInertia_3R + mass*CrossProductMatrix*(CrossProductMatrix.t());
    RetInertia(0,3,size(3,3) ) = mass*CrossProductMatrix;
    RetInertia(3,0,size(3,3) ) = mass*(CrossProductMatrix.t());
    RetInertia(3,3,size(3,3) ) = mass*eye<mat>(3,3);

	return RetInertia;
}

mat66 TranslationMatrix(vec3 Vec)
{

    mat66 RetMatrix;
    RetMatrix.eye();
	RetMatrix(3,1) = Vec(2);
	RetMatrix(4,0) = -Vec(2);
	RetMatrix(3,2) = -Vec(1);
	RetMatrix(5,0) = Vec(1);
	RetMatrix(4,2) = Vec(0);
	RetMatrix(5,1) = -Vec(0);

	return RetMatrix;
}

mat66 TransformationMatrixFromMarkersPosition(vec6 Vec)
{
    return mat66(EulerRotMatSpatial(Vec(0),Vec(1),Vec(2))*TranslationMatrix(Vec));
}

void PrintMatrix(mat Matrix, QString name)
{
#ifdef qprint

    qDebug() << "Matrix " << name << ":";
    for(int i = 0 ; i < Matrix.n_rows ; i++)
            qDebug() << Matrix(i,0) << "   " << Matrix(i,1) << "   " << Matrix(i,2) << "   " <<
                        Matrix(i,3) << "   " << Matrix(i,4) << "   " << Matrix(i,5);
#endif
}

void PrintVector(vec Vector, QString Name)
{
#ifdef qprint
     qDebug() << "Vector " << Name << ":";
     qDebug() << Vector(0) << "   " << Vector(1) << "   " << Vector(2) << "   " <<
                 Vector(3) << "   " << Vector(4) << "   " << Vector(5);
#endif
}

