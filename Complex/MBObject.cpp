/* *******************
 * File name : MBObject.cpp
 * Author : Marcin Piotrowski
 * Created : 29.04.2015    20:55
 * Brief : See MBObject.h
 * *******************
 */

#include "MBObject.h"

/*  Constructor
    *@class MBObject
    *@param
    */



vec6 MBObject::GraberVelocities() const
{
    return m_GraberVelocities;
}

void MBObject::setGraberVelocities(const vec6 &GraberVelocities)
{
    m_GraberVelocities = GraberVelocities;
}
MBObject::MBObject(): m_NumberOfLinks(0),
    m_NumberOfJoints(0),
    m_HighLightedPart(-1),
    m_PreSimulatedFlag(false),
    m_GravityFlag(true),
    m_GraberFlag(false)
{
    m_DTranslationVector << 0 << 0 << 0;
}

/*  Destructor
    *@class MBObject
    */
MBObject::~MBObject()
{
    if (m_Markers != NULL)
        {
        delete [] m_Markers;
        m_Markers = NULL;
        }

    if (Links != NULL)
        delete [] Links;
    if (Joints != NULL)
        delete [] Joints;
}

/*  Method
    *@brief: This method loads ADAMS file (.adm) and create Multibody System
    *@param const char* ADMFileName: path to ADAMS file
    *@retval: None
    */
void MBObject::LoadADAMSFile(const char* ADMFileName)
{
    /** Opening file **/
	ifstream FileS(ADMFileName);

    size_t CurrentPosition;                         // Current position in file

    int NumberOfParts=0,            // Total number of parts (not including base)
        NumberOfJoints=0;           // Total number of joints
    int TotalNumberOfMarkers = 0;   // Total number of markers
    int TempMarkerNumber = 0;       // Current marker number during parsing
    int* CylinderCMMarkers;
    ivec NumberOfMarkers;       // Number of markers for every part, see brief below

    /** Strings included in ADAMS file **/
	string sPart = "-- Part --", 
        sGround = "-- Ground --",
		sMarker = "MARKER/", 
		sMass = ", MASS = ",
		sInertia = ", IP = ",
		sGraphics = "GRAPHICS/",
		sCylinder = ", CYLINDER",
		sEqual = " = ",
		sQP = ", QP = ",
		sREuler = ", REULER = ",
		sCM = ", CM = ",
		sI = ", I = ",
		sJ = ", J = ",
        sIC = ", IC = ",
        sModelName = "ADAMS/View model name: ",
        sPartName = "adams_view_name='";

    // Because of base
    NumberOfMarkers.resize(NumberOfMarkers.n_rows+1);
    NumberOfMarkers(0)=0;

    /** Brief: 1. TotalNumberOfMarkers is not number of markers in total, but number of the highest number
     *            in ADAMS file, so for example:
     *            In ADAMS file there are only 3 markers: MARKER1, MARKER2 and MARKER 5. ToTalNumberOfMarkers will
     *            be 5, not 3.
     *            The consequency is that program needs to allocate more memory (some of markers are not used), but
     *            it simplify the code. To chceck hishest number of marker variable TempMarkerNumber is used.
     *         2. String sPart, sGround, sMarker... are used to find specyfic keyword in ADAMS file.
     *         3. NumberOfMarkers is the Vector of size NumberOfParts, that includes how many markers have specyfic part.
     *            For example: there are 3 parts in ADAMS file, first contain 3 markers, second containts 2 markers and
     *            third containts 7 markers.
     *            NumberOfMarkers Vector will be: [3,2,7]
     *         4. Graber must be the last part in file!
     */


    /** 1st loop - Getting information about number of markers and cylinders **/
	for(string line; getline(FileS,line);)
	{
        /** Get model name **/
        CurrentPosition=line.find(sModelName);
        if(CurrentPosition!=string::npos)
            m_MBSinfo.Parameters.Name = QString::fromStdString(line.substr(sModelName.length()));

        /** When founded new part (not base) **/
		CurrentPosition=line.find(sPart);
		if(CurrentPosition!=string::npos)
			{
            string SubString;
            size_t sz;

            getline(FileS,line);
            getline(FileS,line);
            CurrentPosition=line.find(sPartName);
            SubString = line.substr(CurrentPosition+sPartName.length());
            SubString = SubString.substr(0,SubString.length()-1);
            sz = SubString.find("GRABER");
            if(sz!=string::npos)  // Found graber
                m_GraberFlag = true;
            NumberOfParts++;        // Increment number of parts
            NumberOfMarkers.resize(NumberOfMarkers.n_rows+1);
            NumberOfMarkers(NumberOfParts)=0;
			}

        /** When founded new marker **/
		CurrentPosition=line.find(sMarker);
        if( (CurrentPosition!=string::npos) )
			{
            TempMarkerNumber = stoi(line.substr(sMarker.length()));
			if (TempMarkerNumber > TotalNumberOfMarkers )
				TotalNumberOfMarkers = TempMarkerNumber;
            NumberOfMarkers(NumberOfParts)++;
			}

        /** When found new joint **/
		CurrentPosition=line.find(sJ);
		if(CurrentPosition!=string::npos)
			NumberOfJoints++;
	}

    /** Creating Parts, Joints and Markers **/
	m_NumberOfLinks = NumberOfParts;
	m_NumberOfJoints = NumberOfJoints;

	Links = new CObject[NumberOfParts];
	Joints = new DJoint[NumberOfParts];
    Base = new CObject;
    CylinderCMMarkers = new int[NumberOfParts+1]; // +1 because of base cylinder

    Base->SetNumberOfMarkers(NumberOfMarkers(0));
    Base->MarkersResize();
	for(int i=0; i < NumberOfParts ; i++)
        {
        Links[i].SetNumberOfMarkers(NumberOfMarkers(i+1));
		Links[i].MarkersResize();
        Joints[i].SetNumberOfMarkers(NumberOfMarkers(i+1));
		Joints[i].MarkersResize();
		Links[i].m_InertiaMatrix.fill(0);
        }

	m_Markers = new DMarker[TotalNumberOfMarkers];
	m_NumberOfMarkers = TotalNumberOfMarkers;

    m_HMatrix.resize(NumberOfParts,NumberOfParts);
    m_CMatrix.resize(NumberOfParts,NumberOfParts);
    m_GVector.resize(NumberOfParts);


    /** Clear Input File Stream and go back to the beginning **/
	FileS.clear();
	FileS.seekg(0,FileS.beg);

    int CurrentJoint = 0;     // Current joint

    /** 2nd loop - setting joints markers **/
	for(string line; getline(FileS,line);)
        {
        /** When founded I Marker **/
		CurrentPosition=line.find(sI);
		if(CurrentPosition!=string::npos)
            {
            CurrentJoint++;
			int MNumber = stoi(line.substr(sI.length()));
			m_Markers[MNumber-1].m_Type = D_JOINT_I;
            }

        /** When founded J Marker **/
		CurrentPosition=line.find(sJ);
		if(CurrentPosition!=string::npos)
            {
			int MNumber = stoi(line.substr(sJ.length()));
			m_Markers[MNumber-1].m_Type = D_JOINT_J;
            }

        /** When founded Initial Conditions **/
		CurrentPosition=line.find(sIC);
		if(CurrentPosition!=string::npos)
			{
			string SubString = line.substr(CurrentPosition+sIC.length());
			string::size_type sz;

            Joints[CurrentJoint-1].SetJointVelocity(-stod(SubString, &sz));
            SubString = SubString.substr(sz+2);
            Joints[CurrentJoint-1].SetJointAngle(-stod(SubString, &sz));
			}
        }

    /** Clear Input File Stream and go back to the beginning **/
	FileS.clear();
	FileS.seekg(0,FileS.beg);

    if(m_GraberFlag)
        {
        Joints[NumberOfParts-1].SetJointVelocity(0.0);
        Joints[NumberOfParts-1].SetJointAngle(0.0);
        }

    int CurrentPart = 0; // Current link

    /** 3rd loop - initializing Inertia Matrix, Markers and Graphics, Initial Conditions **/
	for(string line; getline(FileS,line);)
        {
        /** When founded ground **/
        CurrentPosition=line.find(sGround);
        if(CurrentPosition!=string::npos)
            {
            // Do nothing
            }

        /** When founded new link **/
		CurrentPosition=line.find(sPart);
		if(CurrentPosition!=string::npos)
            CurrentPart++;

        /** When found mass of link **/
		CurrentPosition=line.find(sMass);
        if( (CurrentPosition!=string::npos) && (CurrentPart > 0) )
            Links[CurrentPart-1].m_Mass = stod(line.substr(CurrentPosition+sMass.length()));

        /** When found CM of link **/
		CurrentPosition=line.find(sCM);
        if( (CurrentPosition!=string::npos) && (CurrentPart > 0) )
			{
			int MNumber = stoi(line.substr(sCM.length()));
            m_Markers[MNumber-1].m_Type = D_CM;                         // Set type of marker
            m_Markers[MNumber-1].m_LinkNumber = CurrentPart-1;          // Set number of link connected to the marker
            Links[CurrentPart-1].m_MarkerCM = &m_Markers[MNumber-1];    // Set CM marker connected to link
			}
			
        /** When found Interia of link **/
		CurrentPosition=line.find(sInertia);
        if( (CurrentPosition!=string::npos) && (CurrentPart > 0) )
			{
			string SubString = line.substr(CurrentPosition+sInertia.length());
			string::size_type sz;
            Links[CurrentPart-1].m_InertiaMatrix(0,0) = stod(SubString, &sz);
			SubString = SubString.substr(sz+2);
            Links[CurrentPart-1].m_InertiaMatrix(1,1) = stod(SubString, &sz);
			SubString = SubString.substr(sz+2);
            Links[CurrentPart-1].m_InertiaMatrix(2,2) = stod(SubString, &sz);
			}

        /** When found graphics properties of link/ground **/
		CurrentPosition=line.find(sGraphics);
        if( (CurrentPosition!=string::npos) )
            {
			string SubString;

            if(CurrentPart > 0) // Link graphics
                {
                getline(FileS,line);
                CurrentPosition=line.find(sCylinder);
                if( (CurrentPosition!=string::npos) )
                    {
                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    CylinderCMMarkers[CurrentPart] = stoi(SubString);
                    Links[CurrentPart-1].m_CMCylinderPosition =&m_Markers[CylinderCMMarkers[CurrentPart]-1];

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Links[CurrentPart-1].m_LinkParameters.u_Cylinder.Lenght = stod(SubString);

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Links[CurrentPart-1].m_LinkParameters.u_Cylinder.Radius = stod(SubString);
                    }
                }
            else    // Ground graphics
                {
                getline(FileS,line);
                CurrentPosition=line.find(sCylinder);
                if( (CurrentPosition!=string::npos) )
                    {
                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    CylinderCMMarkers[0] = stoi(SubString);
                    Base->m_CMCylinderPosition = &m_Markers[CylinderCMMarkers[0]-1];

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Base->m_LinkParameters.u_Cylinder.Lenght = stod(SubString);

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Base->m_LinkParameters.u_Cylinder.Radius = stod(SubString);
                    }
                }
            }

        /** When found new marker **/
		CurrentPosition=line.find(sMarker);
        if( (CurrentPosition!=string::npos))
			{
            if(CurrentPart > 0)
                {
                int MNumber = stoi(line.substr(sMarker.length()));
                m_Markers[MNumber-1].m_LinkNumber = CurrentPart-1;
                string SubString;
                string::size_type sz;

                getline(FileS, line);
                getline(FileS, line);
                CurrentPosition=line.find(sQP);
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sQP.length());
                    m_Markers[MNumber-1].m_MarkerPosition(3) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(4) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(5) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentPosition=line.find(sREuler);
                    }

                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(3) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(4) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(5) = 0.0f;
                    CurrentPosition=line.find(sREuler);
                    }
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sREuler.length());
                    m_Markers[MNumber-1].m_MarkerPosition(0) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(1) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(2) = stod(SubString,&sz);
                    }
                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(0) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(1) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(2) = 0.0f;
                    }
                }

            else
                {
                int MNumber = stoi(line.substr(sMarker.length()));
                m_Markers[MNumber-1].m_LinkNumber = -1;
                string SubString;
                string::size_type sz;

                getline(FileS, line);
                getline(FileS, line);
                CurrentPosition=line.find(sQP);
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sQP.length());
                    m_Markers[MNumber-1].m_MarkerPosition(3) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(4) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(5) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentPosition=line.find(sREuler);
                    }

                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(3) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(4) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(5) = 0.0f;
                    CurrentPosition=line.find(sREuler);
                    }
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sREuler.length());
                    m_Markers[MNumber-1].m_MarkerPosition(0) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(1) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(2) = stod(SubString,&sz);
                    }
                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(0) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(1) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(2) = 0.0f;
                    }
                }
            }

        /** When found I marker **/
		CurrentPosition=line.find(sI);
        if( (CurrentPosition!=string::npos))
			{
			int MNumber = stoi(line.substr(sI.length()));
			int PartNumber;

			PartNumber = m_Markers[MNumber-1].m_LinkNumber;
			if(PartNumber != -1)
				Links[PartNumber].m_MarkerJointI = &m_Markers[MNumber-1];
            else
                Base->m_MarkerJointI = &m_Markers[MNumber -1];
			}

        /** When found J marker **/
		CurrentPosition=line.find(sJ);
        if( (CurrentPosition!=string::npos) && (CurrentPart>0))
			{
			int MNumber = stoi(line.substr(sJ.length()));
			int PartNumber;

			PartNumber = m_Markers[MNumber-1].m_LinkNumber;
			if(PartNumber != -1)
				Links[PartNumber].m_MarkerJointJ = &m_Markers[MNumber-1];
			}
        }

   // if (m_GraberFlag)


    /** Setting markers numbers **/
	for(int i = 0 ; i < TotalNumberOfMarkers ; i++)
		m_Markers[i].m_MarkerNumber = i;



    m_MassMatrixJ.resize(NumberOfParts,NumberOfParts);
    m_MassMatrixO.resize(NumberOfParts,NumberOfParts);
    m_Jacobian.resize(NumberOfParts,NumberOfParts);
    m_CCVectorJ.resize(NumberOfParts);
    m_B2.resize(NumberOfParts);
    m_CCVectorO.resize(NumberOfParts);
    m_GVectorJ.resize(NumberOfParts);
    m_GVectorO.resize(NumberOfParts);
    m_ForcesJ.resize(NumberOfParts);
    m_ForcesO.resize(NumberOfParts);
    m_FG.resize(6*(NumberOfParts));
    m_FQ.resize(6*(NumberOfParts));

    m_MBSinfo.Parameters.NumberOfJoints = NumberOfParts;
    m_MBSinfo.Variables.JointsPositions = new double[NumberOfParts];
    m_MBSinfo.Variables.JointsVelocities = new double[NumberOfParts];
    m_MBSinfo.Variables.JointsAccelerations = new double[NumberOfParts];
    m_MBSinfo.Variables.KineticEnergies = new double[NumberOfParts];
    m_MBSinfo.Variables.PotentialEnergy = new double[NumberOfParts];

    m_MBSinfo.Parameters.BaseParameters.GraphicModel = GM_DEFUALT;
    m_MBSinfo.Parameters.BaseParameters.Xposition = 0;
    m_MBSinfo.Parameters.BaseParameters.Yposition = 0;
    m_MBSinfo.Parameters.BaseParameters.Zposition = 0;


    m_MBSinfo.Parameters.LinkParameters = new s_LinkParameters[NumberOfParts];

    for(int i = 0 ; i < NumberOfParts ; i++)
    {
         m_MBSinfo.Parameters.LinkParameters[i].GraphicModel=GM_DEFUALT;
         m_MBSinfo.Parameters.LinkParameters[i].Mass = Links[i].m_Mass;
         m_MBSinfo.Parameters.LinkParameters[i].Ixx = Links[i].m_InertiaMatrix(0,0);
         m_MBSinfo.Parameters.LinkParameters[i].Iyy = Links[i].m_InertiaMatrix(1,1);
         m_MBSinfo.Parameters.LinkParameters[i].Izz = Links[i].m_InertiaMatrix(2,2);
    }

    m_MBSinfo.Parameters.SimulationSpeed = 1.0;
    m_MBSinfo.Parameters.RealTimeSimulationStep = 0.01;
    m_MBSinfo.Parameters.AnalisysType = A_DYNAMIC;

}

/*  Method
    *@brief: This method generate macro for Adams to create measures needed for post-simulation
    *@param: const char* ADMFileName - path to ADM file
    *@retval: Command for Adams
    */
QString MBObject::GenerateMeasureCommand(const char* ADMFileName)
{
    // Opening file
    ifstream FileS(ADMFileName);

    // Current position in file
    size_t CurrentPosition;

    int NumberOfParts = 0;
    int CurrentPart = 0;

    // Command
    QString Command;

    // Strings included in ADAMS files
    string sPart = "-- Part --",
        sGround = "-- Ground --",
        sPartName = "adams_view_name='",
       sModelName = "ADAMS/View model name: ";


    s_MBSParameters Parameters;

    /** 1st loop - Getting information about number of markers and cylinders **/
    for(string line; getline(FileS,line);)
    {
        /** Get model name **/
        CurrentPosition=line.find(sModelName);
        if(CurrentPosition!=string::npos)
            {
            Parameters.Name = QString::fromStdString(line.substr(sModelName.length()));
            }

        /** When founded new part **/
        CurrentPosition=line.find(sPart);
        if(CurrentPosition!=string::npos)
            {
            NumberOfParts++;
            }
    }

    Parameters.LinkParameters = new s_LinkParameters[NumberOfParts];

    /** Clear Input File Stream and go back to the beginning **/
    FileS.clear();
    FileS.seekg(0,FileS.beg);

    /** 2nd loop - Getting information about number of markers and cylinders **/
    for(string line; getline(FileS,line);)
    {
        /** When founded new part **/
        CurrentPosition=line.find(sPart);
        if(CurrentPosition!=string::npos)
            {
            size_t sz;
            CurrentPart++;
            getline(FileS,line);
            getline(FileS,line);
            sz=line.find(sPartName);
            Parameters.LinkParameters[CurrentPart-1].Name = (QString::fromStdString(line.substr(sz+sPartName.length())));
            Parameters.LinkParameters[CurrentPart-1].Name =
                    Parameters.LinkParameters[CurrentPart-1].Name.left(Parameters.LinkParameters[CurrentPart-1].Name.length() -1);

            }
    }

    Command = "!USER_ENTERED_COMMAND CreateMeasures\n";
    for(int i = 0 ; i < NumberOfParts ; i++)
        {
        Command += "measure create point measure_name = ." + Parameters.Name +".x" + QString::number(i)
                   + " point = ." + Parameters.Name + "." + Parameters.LinkParameters[i].Name + ".REF " +
                "characteristic = translational_displacement component = x_component create_measure_display = no\n";
        Command += "measure create point measure_name = ." + Parameters.Name +".y" + QString::number(i)
                   + " point = ." + Parameters.Name + "." + Parameters.LinkParameters[i].Name + ".REF " +
                "characteristic = translational_displacement component = y_component create_measure_display = no\n";
        Command += "measure create point measure_name = ." + Parameters.Name +".z" + QString::number(i)
                   + " point = ." + Parameters.Name + "." + Parameters.LinkParameters[i].Name + ".REF " +
                "characteristic = translational_displacement component = z_component create_measure_display = no\n";

        Command += "measure create orient measure_name = ." + Parameters.Name +".f" + QString::number(i)
                + " component = angle_1_component characteristic = euler_angles to_frame = ." + Parameters.Name
                + "." + Parameters.LinkParameters[i].Name + ".REF create_measure_display = no\n";

        Command += "measure create orient measure_name = ." + Parameters.Name +".p" + QString::number(i)
                + " component = angle_2_component characteristic = euler_angles to_frame = ." + Parameters.Name
                + "." + Parameters.LinkParameters[i].Name + ".REF create_measure_display = no\n";

        Command += "measure create orient measure_name = ." + Parameters.Name +".t" + QString::number(i)
                + " component = angle_3_component characteristic = euler_angles to_frame = ." + Parameters.Name
                + "." + Parameters.LinkParameters[i].Name + ".REF create_measure_display = no\n";
        }

    QString FilePath = ADMFileName;
    FilePath = FilePath.left(FilePath.lastIndexOf("/"));
    QString filename= FilePath + "/" + Parameters.Name + "Meas.cmd";
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << Command;

    // optional, as QFile destructor will already do it:
    file.close();

    QString Macro;
    Macro = "macro read macro_name = " + Parameters.Name + "Meas file_name = \""  + filename + "\"";
    return Macro;

}

/*  Method
    *@brief: This method loads post-simulated model.
    *@param const char* ADMFileName: Path to ADM file
    *@retval: None
    */
void MBObject::LoadADAMSFileKinematic(const char* ADMFileName)
{
    // Opening file
    ifstream FileS(ADMFileName);

    // Current position in file
    size_t CurrentPosition;

    int NumberOfParts=0, NumberOfJoints=0;
    ivec NumberOfMarkers;
    int TotalNumberOfMarkers = 0;
    int TempMarkerNumber = 0;
    int* CylinderCMMarkers;
    int NumberOfAdd = 0;

    // Strings included in ADAMS file
    string sPart = "-- Part --",
        sGround = "-- Ground --",
        sMarker = "MARKER/",
        sGraphics = "GRAPHICS/",
        sCylinder = ", CYLINDER",
        sEqual = " = ",
        sQP = ", QP = ",
        sREuler = ", REULER = ",
        sModelName = "ADAMS/View model name: ";

    // Because of base
    NumberOfMarkers.resize(NumberOfMarkers.n_rows+1);
    NumberOfMarkers(0)=0;


    /** 1st loop - Getting information about number of markers and cylinders **/
    for(string line; getline(FileS,line);)
    {
        /** Get model name **/
        CurrentPosition=line.find(sModelName);
        if(CurrentPosition!=string::npos)
            m_MBSinfo.Parameters.Name = QString::fromStdString(line.substr(sModelName.length()));

        /** When founded new part **/
        CurrentPosition=line.find(sPart);
        if(CurrentPosition!=string::npos)
            {
            NumberOfParts++;
            NumberOfMarkers.resize(NumberOfMarkers.n_rows+1);
            NumberOfMarkers(NumberOfParts)=0;
            }

        /** When founded new marker **/
        CurrentPosition=line.find(sMarker);
        if( (CurrentPosition!=string::npos) )
            {
            TempMarkerNumber = stoi(line.substr(sMarker.length()));
            if (TempMarkerNumber > TotalNumberOfMarkers )
                TotalNumberOfMarkers = TempMarkerNumber;
            NumberOfMarkers(NumberOfParts)++;
            }
    }

    /** Creating Parts, Joints and Markers **/
    m_NumberOfLinks = NumberOfParts;
    m_NumberOfJoints = NumberOfJoints;

    Links = new CObject[NumberOfParts];
    Joints = new DJoint[NumberOfParts];
    Base = new CObject;
    CylinderCMMarkers = new int[NumberOfParts+1]; // +1 because of base cylinder

    Base->SetNumberOfMarkers(NumberOfMarkers(0));
    Base->MarkersResize();
    for(int i=0; i < NumberOfParts ; i++)
    {
        Links[i].SetNumberOfMarkers(NumberOfMarkers(i+1));
        Links[i].MarkersResize();
        Joints[i].SetNumberOfMarkers(NumberOfMarkers(i+1));
        Joints[i].MarkersResize();
        Links[i].m_InertiaMatrix.fill(0);
    }

    m_Markers = new DMarker[TotalNumberOfMarkers];
    m_NumberOfMarkers = TotalNumberOfMarkers;

    /** Clear Input File Stream and go back to the beginning **/
    FileS.clear();
    FileS.seekg(0,FileS.beg);

    NumberOfJoints = 0;     // Current joint

    /** Clear Input File Stream and go back to the beginning **/
    FileS.clear();
    FileS.seekg(0,FileS.beg);

    NumberOfParts = 0; // Current link

    /** 3rd loop - initializing Inertia Matrix, Markers and Graphics, Initial Conditions **/
    for(string line; getline(FileS,line);)
        {
        /** When founded ground **/
        CurrentPosition=line.find(sGround);
        if(CurrentPosition!=string::npos)
            {
            // Do nothing for now
            }

        /** When founded new link **/
        CurrentPosition=line.find(sPart);
        if(CurrentPosition!=string::npos)
            {
            NumberOfParts++;
            NumberOfMarkers(NumberOfParts)=0;
            }


        /** When found graphics properties of link/ground **/
        CurrentPosition=line.find(sGraphics);
        if( (CurrentPosition!=string::npos) )
            {
            string SubString;

            if(NumberOfParts > 0) // Link graphics
                {
                getline(FileS,line);
                CurrentPosition=line.find(sCylinder);
                if( (CurrentPosition!=string::npos) )
                    {
                    }
                }
            else    // Ground graphics
                {
                getline(FileS,line);
                CurrentPosition=line.find(sCylinder);
                if( (CurrentPosition!=string::npos) )
                    {
                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    CylinderCMMarkers[0] = stoi(SubString);
                    Base->m_CMCylinderPosition = &m_Markers[CylinderCMMarkers[0]-1];

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Base->m_LinkParameters.u_Cylinder.Lenght = stod(SubString);

                    getline(FileS,line);
                    CurrentPosition=line.find(sEqual);
                    SubString = line.substr(CurrentPosition+sEqual.length());
                    Base->m_LinkParameters.u_Cylinder.Radius = stod(SubString);
                    }
                }
            }

        /** When found new marker **/
        CurrentPosition=line.find(sMarker);
        if( (CurrentPosition!=string::npos))
            {
            if(NumberOfParts > 0)
                {
                int MNumber = stoi(line.substr(sMarker.length()));
                m_Markers[MNumber-1].m_LinkNumber = NumberOfParts-1;
                string SubString;
                string::size_type sz;

                getline(FileS, line);
                getline(FileS, line);
                CurrentPosition=line.find(sQP);
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sQP.length());
                    m_Markers[MNumber-1].m_MarkerPosition(3) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(4) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(5) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentPosition=line.find(sREuler);
                    }

                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(3) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(4) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(5) = 0.0f;
                    CurrentPosition=line.find(sREuler);
                    }
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sREuler.length());
                    m_Markers[MNumber-1].m_MarkerPosition(0) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(1) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(2) = stod(SubString,&sz);
                    }
                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(0) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(1) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(2) = 0.0f;
                    }
                }

            else
                {
                int MNumber = stoi(line.substr(sMarker.length()));
                m_Markers[MNumber-1].m_LinkNumber = -1;
                string SubString;
                string::size_type sz;

                getline(FileS, line);
                getline(FileS, line);
                CurrentPosition=line.find(sQP);
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sQP.length());
                    m_Markers[MNumber-1].m_MarkerPosition(3) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(4) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(5) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentPosition=line.find(sREuler);
                    }

                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(3) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(4) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(5) = 0.0f;
                    CurrentPosition=line.find(sREuler);
                    }
                if( CurrentPosition!=string::npos)
                    {
                    SubString = line.substr(CurrentPosition+sREuler.length());
                    m_Markers[MNumber-1].m_MarkerPosition(0) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(1) = stod(SubString,&sz);
                    SubString = SubString.substr(sz+2);
                    m_Markers[MNumber-1].m_MarkerPosition(2) = stod(SubString,&sz);
                    }
                else
                    {
                    m_Markers[MNumber-1].m_MarkerPosition(0) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(1) = 0.0f;
                    m_Markers[MNumber-1].m_MarkerPosition(2) = 0.0f;
                    }
                }
            }

        }


    /** Setting markers numbers **/
    for(int i = 0 ; i < TotalNumberOfMarkers ; i++)
        m_Markers[i].m_MarkerNumber = i;


    for(int i = 0 ; i < NumberOfParts ; i++)
        Links[i].m_CylinderRotationMatrix << 1 << 0 << 0 << endr <<
                                             0 << 1 << 0 << endr <<
                                             0 << 0 << 1 << endr;
    m_PreSimulatedFlag = true;

    m_MBSinfo.Parameters.NumberOfJoints = NumberOfParts;
    m_MBSinfo.Variables.JointsPositions = new double[NumberOfParts];
    m_MBSinfo.Variables.JointsVelocities = new double[NumberOfParts];
    m_MBSinfo.Variables.JointsAccelerations = new double[NumberOfParts];

    m_MBSinfo.Parameters.BaseParameters.GraphicModel = GM_DEFUALT;
    m_MBSinfo.Parameters.BaseParameters.Xposition = 0;
    m_MBSinfo.Parameters.BaseParameters.Yposition = 0;
    m_MBSinfo.Parameters.BaseParameters.Zposition = 0;

    m_MBSinfo.Parameters.LinkParameters = new s_LinkParameters[NumberOfParts];

    for(int i = 0 ; i < NumberOfParts ; i++)
    {
         m_MBSinfo.Parameters.LinkParameters[i].GraphicModel=GM_DEFUALT;
         m_MBSinfo.Parameters.LinkParameters[i].Mass = Links[i].m_Mass;
         m_MBSinfo.Parameters.LinkParameters[i].Ixx = Links[i].m_InertiaMatrix(0,0);
         m_MBSinfo.Parameters.LinkParameters[i].Iyy = Links[i].m_InertiaMatrix(1,1);
         m_MBSinfo.Parameters.LinkParameters[i].Izz = Links[i].m_InertiaMatrix(2,2);
    }

    m_MBSinfo.Parameters.SimulationSpeed = 1.0;
    m_MBSinfo.Parameters.RealTimeSimulationStep = 0.01;
    m_MBSinfo.Parameters.AnalisysType = A_ANIMATION;
}

/*  Method
    *@brief: This method loads results of simulation in Adams
    *@param const char *ResultsFileName: Path to results
    *@retval: None
    */
void MBObject::LoadResultsSet(const char *ResultsFileName)
{
    // Opening file
    ifstream FileS(ResultsFileName);

    // Current position in file
    size_t CurrentPosition;

    int Steps = 0;

    // Strings included in ADAMS file
    string sResultID = " Result ID",
            sX = "x",
            sY = "y",
            sZ = "z",
            sF = "f",
            sP = "p",
            sT = "t";

    mat *PartResults = new mat[m_NumberOfLinks];

    /** 1st loop - Getting information about time **/
    for(string line; getline(FileS,line);)
    {

        /** When founded Result ID **/
        CurrentPosition=line.find(sResultID);
        if(CurrentPosition!=string::npos)
            {
            getline(FileS,line);
            getline(FileS,line);
            getline(FileS,line);
            getline(FileS,line);
            while(line.length()!=0)
                {
                Steps++;
                getline(FileS,line);
                }
            break;
            }
    }

    for ( int i = 0 ; i < m_NumberOfLinks ; i++)
        PartResults[i].resize(Steps,6);

    FileS.clear();
    FileS.seekg(0,FileS.beg);

    /** 2nd loop - Getting information about time **/
    for(string line; getline(FileS,line);)
    {

        /** When founded Result ID **/
        CurrentPosition=line.find(sResultID);
        if(CurrentPosition!=string::npos)
            {
            getline(FileS,line);
            string::size_type sz;
            int CurrentStep = 0;
            int partNumber;
            double temp;
            string SubString;
            sz=line.find("\"",1);
            SubString = line.substr(0,sz);

            CurrentPosition=SubString.find(sX);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sX.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,0) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            CurrentPosition=SubString.find(sY);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sY.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,1) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            CurrentPosition=SubString.find(sZ);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sZ.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,2) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            CurrentPosition=SubString.find(sF);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sF.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,3) = stod(SubString,&sz);
                    temp = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            CurrentPosition=SubString.find(sP);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sP.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,4) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            CurrentPosition=SubString.find(sT);
            if(CurrentPosition!=string::npos)
                {
                SubString = line.substr(CurrentPosition+sT.length());
                partNumber = stoi(SubString,&sz);
                getline(FileS,line);
                getline(FileS,line);
                getline(FileS,line);
                while(line.length()!=0)
                    {
                    stod(line,&sz);
                    SubString = line.substr(sz+1);
                    PartResults[partNumber](CurrentStep,5) = stod(SubString,&sz);
                    getline(FileS,line);
                    CurrentStep++;
                    }
                }

            }
    }
}

/*  Method
    *@brief: This method prints positions of all markers.
    *@param: None
    *@retval: None
    */
void MBObject::PrintAllMarkers()
{	
	cout << "--------LINKS-------\n";
	for(int i = 0 ; i <m_NumberOfMarkers; i++)
		{
		cout << "\nMarker nr [" << i << "]:" << endl;
		m_Markers[i].PrintMarker();
		}
}

/*  Method
    *@brief: This function unhighlights all links.
    *@param: None
    *@retval: None
    */
void MBObject::UnHighLight()
{
    for ( int i = 0 ; i < m_NumberOfLinks ; i++)
        Links[i].UnHighLight();
    m_HighLightedPart = -1;
}

/*  Method
    *@brief: This function highlights specyfic link.
    *@param: None
    *@retval: None
    */
void MBObject::HighLight(int PartNumber)
{
    if(PartNumber > -1 && PartNumber < m_NumberOfLinks )
        {
        m_HighLightedPart = PartNumber;
        Links[PartNumber].HighLight();
        }
}

s_MBSParameters MBObject::GetParameters()
{
    return m_MBSinfo.Parameters;
}

s_MBSVariables MBObject::GetVariables()
{
    return m_MBSinfo.Variables;
}

void MBObject::SetParameters(s_MBSParameters MBSParameters)
{
    m_MBSinfo.Parameters = MBSParameters;
}

void MBObject::SetVariables(s_MBSVariables MBSVariables)
{
    m_MBSinfo.Variables = MBSVariables;
}

void MBObject::MoveHighLighted(double angle)
{
    vec6 Vec;
	if (m_HighLightedPart != -1)
		{
		Vec = Joints[m_HighLightedPart].GetSpatialPositionVector();
		Vec(0) +=angle;
		Joints[m_HighLightedPart].SetSpatialPositionVector(Vec);
		}
}

void MBObject::Draw(GShaderProgram& ShaderProgram, GLMatrixStack& modelViewMatrix, GLGeometryTransform& tranformPipeline)
{
    if(m_PreSimulatedFlag)
        {
        vec3 PositionVector;
        mat33 OrientationMatrix;
        vector<mat>::iterator iter;
        iter = m_SimulationResults.begin();
        for(int i = 0 ; i <m_NumberOfLinks; i++)
            {
            PositionVector << (*iter)(m_CurrentStep,0) << (*iter)(m_CurrentStep,1) << (*iter)(m_CurrentStep,2);
            OrientationMatrix = EulerRotMat((*iter)(m_CurrentStep,3),(*iter)(m_CurrentStep,4),(*iter)(m_CurrentStep,5));
            Links[i].SetGPosition(this->m_DTranslationVector);
            Links[i].SetDTranslationVector( PositionVector);
            Links[i].SetDRotationMatrix( OrientationMatrix);
            Links[i].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);
            ++iter;
            }
        }
    else
    {
        Base->Draw(ShaderProgram,modelViewMatrix,tranformPipeline);
        for(int i = 0 ; i <m_NumberOfLinks; i++)
            Links[i].Draw(ShaderProgram, modelViewMatrix, tranformPipeline);
    }
}

/*  Method
    *@brief: After loading markers from ADAMS file all markers are in global cartesian frame. This method sets all markers of
    *        all links to J frame (called P_J).
    *@param: None
    *@retval: None
    */
void MBObject::SetMarkersRefferenceToJointFrame()
{
    mat Refferences;
	Refferences.resize(6, m_NumberOfLinks);

    Base->m_ItoJRotationMatrix = EulerRotMat(Base->m_MarkerJointI->m_MarkerPosition(0,0,size(3,1) ) );
    Base->m_JtoITranslationVector = Base->m_MarkerJointI->m_MarkerPosition(3,0,size(3,1));
    Base->m_CylinderRotationMatrix = EulerRotMat(Base->m_CMCylinderPosition->m_MarkerPosition(0,0,size(3,1) ) );
    Base->m_SpatialTransformationMatrix.fill(0);
    Base->m_SpatialTransformationMatrix(0,0,size(3,3)) = Base->m_ItoJRotationMatrix.t();
    Base->m_SpatialTransformationMatrix(3,3,size(3,3)) = Base->m_ItoJRotationMatrix.t();
    Base->m_SpatialTransformationMatrix(3,0,size(3,3)) = CrossProductOperator_3R(Base->m_JtoITranslationVector).t();



	for(int i = 0 ; i < m_NumberOfLinks ; i++)
	{
        /** Calculate Translation vector from beginning of the joint (J marker) to next joint (I marker) and
         *  Rotation matrix that transforms vectors in I frame to J frame */
        if ( i != m_NumberOfLinks-1)        // The last link doesnt't have I Marker
			{
            Links[i].m_ItoJRotationMatrix = mat33(EulerRotMat(Links[i].m_MarkerJointJ->m_MarkerPosition(0,0,size(3,1) ) ).t()
                                        *EulerRotMat(Links[i].m_MarkerJointI->m_MarkerPosition(0,0,size(3,1) ) ));
            Links[i].m_JtoITranslationVector = EulerRotMat(Links[i].m_MarkerJointJ->m_MarkerPosition(0,0,size(3,1) ) ).t()*
                                                (Links[i].m_MarkerJointI->m_MarkerPosition(3,0,size(3,1) )-Links[i].m_MarkerJointJ->m_MarkerPosition(3,0,size(3,1) ) );
			}

        Links[i].m_JtoCMTranslationVector = EulerRotMat(Links[i].m_MarkerJointJ->m_MarkerPosition(0,0,size(3,1) ) ).t()*
            (Links[i].m_MarkerCM->m_MarkerPosition(3,0,size(3,1))-Links[i].m_MarkerJointJ->m_MarkerPosition(3,0,size(3,1) ) );

        Links[i].m_CylinderRotationMatrix = mat33(EulerRotMat(Links[i].m_MarkerJointJ->m_MarkerPosition(0,0,size(3,1) ) ).t()
            *EulerRotMat(Links[i].m_CMCylinderPosition->m_MarkerPosition(0,0,size(3,1) ) ));

        Links[i].m_CMRotationMatrix = mat33(EulerRotMat(Links[i].m_MarkerJointJ->m_MarkerPosition(0,0,size(3,1) ) ).t()
                *EulerRotMat(Links[i].m_MarkerCM->m_MarkerPosition(0,0,size(3,1) ) ));

		Links[i].m_SpatialTransformationMatrix.fill(0);
        Links[i].m_SpatialTransformationMatrix(0,0,size(3,3) ) = Links[i].m_ItoJRotationMatrix.t();
        Links[i].m_SpatialTransformationMatrix(3,3,size(3,3) ) = Links[i].m_ItoJRotationMatrix.t();
        Links[i].m_SpatialTransformationMatrix(3,0,size(3,3) ) = CrossProductOperator_3R(Links[i].m_JtoITranslationVector).t();
	}
}

void MBObject::CalculateTransformationMatrices()
{
}

void MBObject::SetCurrentStep(int Step)
{
    m_CurrentStep = Step;
}

void MBObject::ReCalculateInertiaMatrices()
{
    for( int i = 0; i < m_NumberOfLinks ; i++)
        Links[i].m_SpacialInertiaMatrix = CalcInertia(Links[i].m_InertiaMatrix,
                                                      Links[i].m_Mass,
                                                      Links[i].m_CylinderRotationMatrix,
                                                      Links[i].m_JtoCMTranslationVector);


    /** TO CHANGE **/
     vec3  Vec8;
     for(int i = 0 ; i < m_NumberOfLinks - 1 ; i++)
         {
          Vec8 = EulerAnglesFromRotMat(Links[i].m_ItoJRotationMatrix);
          Links[i].m_SpatialTransformationMatrix = mat66(RotZST(Vec8(2))*RotXST(Vec8(1))*RotZST(Vec8(0))*TranslationMatrix(Links[i].m_JtoITranslationVector));
         }
}


void MBObject::GeneratePrimitives()
{
    double L,D;
    L = Base->m_LinkParameters.u_Cylinder.Lenght;
    D = 2*Base->m_LinkParameters.u_Cylinder.Radius;
    Base->SetModelPath("BasicCylinder.obj");
    Base->SetRandomColors();
    Base->SetScale(D,D,L);

	for( int i = 0 ; i < m_NumberOfLinks ; i++)
	{
        Links[i].SetModelPath("BasicCylinder.obj");
        Links[i].SetRandomColors();
        double L = Links[i].m_LinkParameters.u_Cylinder.Lenght;
        double D = 2*Links[i].m_LinkParameters.u_Cylinder.Radius;
        Links[i].SetScale(D,D,L);
	}
}

int MBObject::GetNumberOfLinks()
{
	return m_NumberOfLinks;
}

void MBObject::GetJointsPositionsAndVelocities(int &n, vec &Positions, vec &Velocities)
{
	n = m_NumberOfJoints;
    Positions.resize(n);
    Velocities.resize(n);
	for(int i = 0 ; i < m_NumberOfJoints ; i++)
		{
            Positions(i) = Joints[i].GetJointAngle();
            Velocities(i) = Joints[i].GetJointVelocity();
		}
}

void MBObject::SetJointsPositionsAndVelocities(const vec &Positions,const vec &Velocities)
{
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
        {
            Joints[i].SetJointAngle(Positions(i));
            Joints[i].SetJointVelocity(Velocities(i));
        }
}


void MBObject::SetJointsPositions(const vec &Positions)
{
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
            Joints[i].SetJointAngle(Positions(i));
}

void MBObject::SetJointsVelocities(const vec &Velocities)
{
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
            Joints[i].SetJointVelocity(Velocities(i));
}



void MBObject::SetJointsAcceleration(const vec &Accelerations)
{
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
        Joints[i].SetJointAcceleration(Accelerations(i));
}

vec MBObject::GetJointsPositions()
{
    vec Positions;
    Positions.resize(m_NumberOfJoints);
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
        Positions(i) = Joints[i].GetJointAngle();
    return Positions;
}

vec MBObject::GetJointsVelocities()
{
    vec Velocities;
    Velocities.resize(m_NumberOfJoints);
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
        Velocities(i) = Joints[i].GetJointVelocity();
    return Velocities;
}

vec MBObject::GetJointsAcceleration()
{
    vec Accelerations;
    Accelerations.resize(m_NumberOfJoints);
    for(int i = 0 ; i < m_NumberOfJoints ; i++)
        Accelerations(i) = Joints[i].GetJointAcceleration();
    return Accelerations;
}


void MBObject::UpdateParameters()
{
    if (m_MBSinfo.Parameters.BaseParameters.GraphicModel == GM_LOADED)
        {
        Base->SetModelPath(m_MBSinfo.Parameters.BaseParameters.ModelPath.toStdString().c_str());
        Base->SetRandomColors();
        Base->SetScale(0.001,0.001,0.001);
        }
    else
        {
        Base->SetModelPath("BasicCylinder.obj");
        Base->SetRandomColors();
        double L = Base->m_LinkParameters.u_Cylinder.Lenght;
        double D = 2*Base->m_LinkParameters.u_Cylinder.Radius;
        Base->SetScale(D,D,L);
        }

    m_DTranslationVector << m_MBSinfo.Parameters.BaseParameters.Xposition <<
                        m_MBSinfo.Parameters.BaseParameters.Yposition <<
                        m_MBSinfo.Parameters.BaseParameters.Zposition;

    for( int i = 0 ; i < m_NumberOfLinks ; i++)
        {
        Links[i].m_Mass = m_MBSinfo.Parameters.LinkParameters[i].Mass;
        Links[i].m_InertiaMatrix.fill(0);
        Links[i].m_InertiaMatrix(0,0) = m_MBSinfo.Parameters.LinkParameters[i].Ixx;
        Links[i].m_InertiaMatrix(1,1) = m_MBSinfo.Parameters.LinkParameters[i].Iyy;
        Links[i].m_InertiaMatrix(2,2) = m_MBSinfo.Parameters.LinkParameters[i].Izz;
        if (m_MBSinfo.Parameters.LinkParameters[i].GraphicModel == GM_LOADED)
            {
            Links[i].SetModelPath(m_MBSinfo.Parameters.LinkParameters[i].ModelPath.toStdString().c_str());
            Links[i].SetRandomColors();
            Links[i].SetScale(0.001,0.001,0.001);
            }
        else
            {
            Links[i].SetModelPath("BasicCylinder.obj");
            Links[i].SetRandomColors();
            double L = Links[i].m_LinkParameters.u_Cylinder.Lenght;
            double D = 2*Links[i].m_LinkParameters.u_Cylinder.Radius;
            Links[i].SetScale(D,D,L);
            }
        }
    ReCalculateInertiaMatrices();

}

void MBObject::InitializeToRender()
{
    for(int i = 0 ; i < m_NumberOfLinks ; i ++)
        Links[i].InitializeToRender();
    Base->InitializeToRender();
}

void MBObject::EnableGravity(bool Gravity)
{
    m_GravityFlag = Gravity;
}

bool MBObject::IsGravityEnabled()
{
    return m_GravityFlag;
}

bool MBObject::IsGraber()
{
    return m_GraberFlag;
}

void MBObject::SetTorques(vec Torques)
{
    for (int i = 0 ; i < m_NumberOfLinks ; i++)
        Joints[i].SetJointTorque(Torques(i));
}

vec MBObject::GetTorques()
{
    vec6 Torques;
    for (int i = 0 ; i < m_NumberOfLinks ; i++)
        Torques(i) = Joints[i].GetJointTorque();
    return Torques;
}


void MBObject::SaveMultibodyObjectToFile(QString FileName)
{
    ptree pt;
    std::string m_file = "AAA";
    std::string ff = "bbb.xml";
    // Put log filename in property tree
      pt.put("debug.filename", m_file);


    /** Save to file **/
    write_xml(ff,pt);


}



void MBObject::SaveInitialValues()
{
    m_MBSInitialValues.JointsPositions = new double[m_NumberOfLinks];
    m_MBSInitialValues.JointsVelocities = new double[m_NumberOfLinks];
    m_MBSInitialValues.JointsAccelerations = new double[m_NumberOfLinks];

    for(int i = 0 ; i < m_NumberOfLinks ; i++)
        {
        m_MBSInitialValues.JointsAccelerations[i] = Joints[i].GetJointAcceleration();
        m_MBSInitialValues.JointsVelocities[i] = Joints[i].GetJointVelocity();
        m_MBSInitialValues.JointsPositions[i] = Joints[i].GetJointAngle();
        }
}


void MBObject::Refresh()
{
    for(int i = 0 ; i < m_NumberOfLinks ; i++)
        {
        Joints[i].SetJointAngle(m_MBSInitialValues.JointsPositions[i]);
        Joints[i].SetJointVelocity(m_MBSInitialValues.JointsVelocities[i]);
        Joints[i].SetJointAcceleration(m_MBSInitialValues.JointsAccelerations[i]);
        Joints[i].SetJointTorque(0.0);
        }
}





mat MBObject::GetMassMatrixJ() const
{
    return m_MassMatrixJ;
}

void MBObject::SetMassMatrixJ(const mat &MassMatrixJ)
{
    m_MassMatrixJ = MassMatrixJ;
}

mat MBObject::GetMassMatrixO() const
{
    return m_MassMatrixO;
}

void MBObject::SetMassMatrixO(const mat &MassMatrixO)
{
    m_MassMatrixO = MassMatrixO;
}

mat MBObject::GetJacobian() const
{
    return m_Jacobian;
}

void MBObject::SetJacobian(const mat &Jacobian)
{
    m_Jacobian = Jacobian;
}

mat MBObject::GetJacobianp() const
{
    return m_Jacobianp;
}

void MBObject::SetJacobianp(const mat &Jacobianp)
{
    m_Jacobianp = Jacobianp;
}

mat MBObject::GetInvJacobian() const
{
    return m_InvJacobian;
}

void MBObject::SetInvJacobian(const mat &InvJacobian)
{
    m_InvJacobian = InvJacobian;
}

vec MBObject::GetCCVectorJ() const
{
    return m_CCVectorJ;
}

void MBObject::SetCCVectorJ(const vec &CCVectorJ)
{
    m_CCVectorJ = CCVectorJ;
}

vec MBObject::GetB2() const
{
    return m_B2;
}

void MBObject::SetB2(const vec &B2)
{
    m_B2 = B2;
}

vec MBObject::GetCCVectorO() const
{
    return m_CCVectorO;
}

void MBObject::SetCCVectorO(const vec &CCVectorO)
{
    m_CCVectorO = CCVectorO;
}

vec MBObject::GetGVectorJ() const
{
    return m_GVectorJ;
}

void MBObject::SetGVectorJ(const vec &GVectorJ)
{
    m_GVectorJ = GVectorJ;
}

vec MBObject::GetGVectorO() const
{
    return m_GVectorO;
}

void MBObject::SetGVectorO(const vec &GVectorO)
{
    m_GVectorO = GVectorO;
}

vec MBObject::GetForcesJ() const
{
    return m_ForcesJ;
}

void MBObject::SetForcesJ(const vec &ForcesJ)
{
    m_ForcesJ = ForcesJ;
}

vec MBObject::GetForcesO() const
{
    return m_ForcesO;
}

void MBObject::SetForcesO(const vec &ForcesO)
{
    m_ForcesO = ForcesO;
}

vec MBObject::GetFG() const
{
    return m_FG;
}

void MBObject::SetFG(const vec &FG)
{
    m_FG = FG;
}

vec MBObject::GetFQ() const
{
    return m_FQ;
}

void MBObject::SetFQ(const vec &FQ)
{
    m_FQ = FQ;
}

void MBObject::SetGraberPosition(const vec3 &Position)
{
    m_GraberPosition = Position;
}

vec3 MBObject::GetGraberPosition()
{
    return m_GraberPosition;
}

void MBObject::SetGraberOrientation(const vec3 &Orientation)
{
    m_GraberOrientation = Orientation;
}

vec3 MBObject::GetGraberOrientation()
{
    return m_GraberOrientation;
}

double MBObject::GetMass(int Index)
{
    return Links[Index].GetMass();
}
