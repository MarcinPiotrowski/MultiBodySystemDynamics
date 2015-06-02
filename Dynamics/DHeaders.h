/* *******************
 * File name : DHeaders.h
 * Author : Marcin Piotrowski
 * Created : 12.04.2015    10:04
 * Brief : This file containst definition of constants (now only gravity acceleration constant)
 *         and definition of Multibody System parameters (mass of link, 3D model path etc.) and
 *         variables (position, velocity etc.).
 * *******************
 */


#ifndef __DHEADERS__H__
#define __DHEADERS__H__

#include <Eigen>
#include <LU>
#include <iostream>
#include <QString>
#include <QDebug>
#include <armadillo>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace Eigen;
using namespace std;
using namespace arma;
using namespace boost::property_tree;

// Gravity acceleration constant
 #define g_acc -9.80665

/*  Enum
    *@brief: Graphic type of the model.
    */
enum e_GraphicModel
{
    GM_DEFUALT,     // Object represented by default primitive cylinder
    GM_LOADED       // Object represented by user-defined graphic object
};

/*  Enum
    *@brief: Type of analisys.
    */
enum e_Analysis
{
    A_DYNAMIC,          // Real-time dynamic analisys
    A_ANIMATION         // Post-simulated animation
};

/*  Struct
    *@brief: Link parameters
    */
struct s_LinkParameters
{
    double Mass;                    // Mass of the link
    double Ixx;                     // Moment of inertia about X axis
    double Iyy;                     // Moment of inertia about Y axis
    double Izz;                     // Moment of inertia about Z axis
    e_GraphicModel GraphicModel;    // Graphic type of the model
    QString ModelPath;              // Path of the .wavefront file
    QString Name;                   // Name of the link
};

/*  Struct
    *@brief: Base parameters
    */
struct s_BaseParameters
{
    double Xposition;                   // X position of base frame
    double Yposition;                   // Y position of base frame
    double Zposition;                   // Z position of base frame
    e_GraphicModel GraphicModel;        // Graphic type of the model
    QString ModelPath;                  // Path of the .wavefront file
};

/*  Struct
    *@brief: Multibody system parameters
    */
struct s_MBSParameters
{
    QString Name;                          // Name of multibody system
    int NumberOfJoints;                    // Number of joints in mulibody system
    s_LinkParameters *LinkParameters;      // Array of link parameters
    s_BaseParameters BaseParameters;       // Base parameters
    double SimulationSpeed;                // Simulation speed
    double RealTimeSimulationStep;         // Real-time simulation step (in seconds)
    e_Analysis AnalisysType;               // Type of analisys
};

/*  Struct
    *@brief: Multibody system variables
    */
struct s_MBSVariables
{
    double* JointsPositions;        // Joints positions (q vector)
    double* JointsVelocities;       // Joints velocities (qd vector)
    double* JointsAccelerations;    // Joints accelerations (qdd vector)
    double* KineticEnergies;        // Joints kinetic energies (in J)
    double* PotentialEnergy;        // Joints potential energies (in J)
    double TotalKineticEnergy;      // Total kinetic energy of multibody system
    double TotalPotentialEnergy;    // Total potential energy of multibody system
};

/*  Struct
    *@brief: Multibody system parameters and variables
    */
struct s_MBS
{
    s_MBSParameters Parameters;     // Multibody system parameters
    s_MBSVariables Variables;       // Multibody system variables
};

#endif __DHEADERS__H__
