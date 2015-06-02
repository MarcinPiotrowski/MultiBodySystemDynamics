/* *******************
 * File name : MBObject.h
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    20:54
 * Brief : This is Multibody System Object containing Links connected with Joints.
 * Attributes examples: Links, Joints, Mass Matrix, Position
 * Methods examples: Load object from file, draw, set joints positions, velocities and accelerations.
 * *******************
 */

#ifndef __MBOBJECT__H__
#define __MBOBJECT__H__

#include "GObject.h"
#include "DObject.h"
#include "DJoint.h"
#include "CObject.h"
#include <iostream>
#include <fstream>
#include <vector>

struct s_MBObject
{
    bool GraberFlag;
    bool Gravity;
    
};

class MBObject: public GObject, public DObject
{
    friend class DAlgorithms;
    friend class MBObject;
    friend class KMain;

private:

    CObject *Base;          // Base of Multibody System
    DJoint *Joints;			// Joints of Multibody Object
    CObject *Links;			// Links of Multibody Object
    CObject *Graber;        // Graber of Multibody System

    s_MBS m_MBSinfo;                        // Name of Multibody System, number of links etc.
    s_MBSVariables m_MBSInitialValues;      // Initial values of positions, velocietes etc.
    int m_NumberOfLinks;                    // Number of links
    int m_NumberOfJoints;                   // Number of joints
    int m_HighLightedPart;                  // Number of part, that is currently highlighted
    bool m_PreSimulatedFlag;                // Was Object simulated earlier in Adams?
    bool m_GravityFlag;                     // Is gravity enabled?
    vector<mat> m_SimulationResults;        // Results of simulations in Adams
    int m_CurrentStep;                      // Current step of simulation in Adams
    mat m_HMatrix;                          // Mass matrix
    mat m_CMatrix;                          // Coriolis and centrifugas Matrix
    vec m_GVector;                          // Gravity Vector
    bool m_GraberFlag;                      // Is graber enabled?

    /** Dynamic parameters **/
    mat    m_MassMatrixJ,
           m_MassMatrixO,
           m_Jacobian,
           m_Jacobianp,
           m_InvJacobian;

    vec    m_CCVectorJ,
           m_B2,
           m_CCVectorO,
           m_GVectorJ,
           m_GVectorO,
           m_ForcesJ,
           m_ForcesO,
           m_FG,
           m_FQ;

    vec3 m_GraberPosition;      // Position of graber
    vec3 m_GraberOrientation;   // Orientation of graber
    vec6 m_GraberVelocities;    // Velocity of graber

public:

	MBObject();
	~MBObject();
	void PrintAllMarkers();
    void LoadADAMSFile(const char* ADMFileName);
    void LoadADAMSFileKinematic(const char* ADMFileName);
    void LoadResultsSet(const char* ResultsFileName);
    QString GenerateMeasureCommand(const char* ADMFileName);
	void Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline);
    void SetMarkersRefferenceToJointFrame();
	void ReCalculateInertiaMatrices();
	void GeneratePrimitives();
	void CalculateTransformationMatrices();
	void UnHighLight();
	void HighLight(int PartNumber);
	void MoveHighLighted(double angle);
    void SetCurrentStep(int Step);

    void UpdateParameters();
    void InitializeToRender();
    void EnableGravity(bool Gravity);
    bool IsGravityEnabled();
    bool IsGraber();

    void SaveMultibodyObjectToFile(QString FileName);
    void SaveInitialValues();
    void Refresh();

    vec GetJointsAcceleration();
    s_MBSParameters GetParameters();
    s_MBSVariables GetVariables();
    void SetParameters(s_MBSParameters MBSParameters);
    void SetVariables(s_MBSVariables MBSVariables);
    mat GetMassMatrixJ() const;
    void SetMassMatrixJ(const mat &MassMatrixJ);
    mat GetMassMatrixO() const;
    void SetMassMatrixO(const mat &MassMatrixO);
    mat GetJacobian() const;
    void SetJacobian(const mat &Jacobian);
    mat GetJacobianp() const;
    void SetJacobianp(const mat &Jacobianp);
    mat GetInvJacobian() const;
    void SetInvJacobian(const mat &InvJacobian);
    vec GetCCVectorJ() const;
    void SetCCVectorJ(const vec &CCVectorJ);
    vec GetB2() const;
    void SetB2(const vec &B2);
    vec GetCCVectorO() const;
    void SetCCVectorO(const vec &CCVectorO);
    vec GetGVectorJ() const;
    void SetGVectorJ(const vec &GVectorJ);
    vec GetGVectorO() const;
    void SetGVectorO(const vec &GVectorO);
    vec GetForcesJ() const;
    void SetForcesJ(const vec &ForcesJ);
    vec GetForcesO() const;
    void SetForcesO(const vec &ForcesO);
    vec GetFG() const;
    void SetFG(const vec &FG);
    vec GetFQ() const;
    void SetFQ(const vec &FQ);
    void SetGraberPosition(const vec3 &Position);
    vec3 GetGraberPosition();
    void SetGraberOrientation(const vec3 &Orientation);
    vec3 GetGraberOrientation();
    void MBObject::SetJointsPositions(const vec &Positions);
    void MBObject::SetJointsVelocities(const vec &Velocities);
    vec6 GraberVelocities() const;
    void setGraberVelocities(const vec6 &GraberVelocities);
    int GetNumberOfLinks();
    vec GetJointsPositions();
    vec GetJointsVelocities();
    void GetJointsPositionsAndVelocities(int& n, vec& Positions, vec& Velocities);
    void SetJointsPositionsAndVelocities(const vec& Positions,const vec& Velocities);
    void SetJointsAcceleration(const vec &Accelerations);
    void SetTorques(vec Torques);
    vec GetTorques();
    double GetMass(int Index);
};

#endif // __MBOBJECT__H__
