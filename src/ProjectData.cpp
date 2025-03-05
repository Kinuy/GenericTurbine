#include "ProjectData.h"


ProjectData::ProjectData(std::string projectFile) :_projectFile(projectFile) {
	try {
		readProjectData();

		processProjectData();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
ProjectData::~ProjectData() {
}

void ProjectData::readProjectData() {
	
	std::ifstream inputProjectDataFile(_projectFile);
	if (!inputProjectDataFile.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	std::string line;

	while (std::getline(inputProjectDataFile, line))
	{
		stripCommentsFromLine(line);

		if (!line.empty())
		{
			projectData.push_back(line);
		}
	}

	inputProjectDataFile.close();
}

void ProjectData::processProjectData()
{
	for (auto const& line : projectData)
	{
		std::string temp = "";
		std::string& tempLine = temp;
		if (findKeyAndReturnValue("RUN_MODE_VEC", line, tempLine))
		{
			_runModes = line2Vector<int>(tempLine);
		}
		if (findKeyAndReturnValue("TSR_VEC", line, tempLine))
		{
			_TSR = line2Vector<double>(tempLine);
			_TSR = makeVector(_TSR);
		}
		if (findKeyAndReturnValue("VG_BLADE_SECTIONS_VEC", line, tempLine))
		{
			_addonVGBladeSections = line2Vector<double>(tempLine);
		}
		if (findKeyAndReturnValue("ANALYSE_BLADE_SECTIONS_VEC", line, tempLine))
		{
			_analyseBladeSections = line2Vector<double>(tempLine);
		}
		if (findKeyAndReturnValue("BLADE_GEO_DATA", line, tempLine))
		{
			_pathToBladeGeoDataFile = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("AIRFOIL_GEO_DATA", line, tempLine))
		{
			_pathToAirfoilGeoDataFile = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("AIRFOIL_PERFO_DATA", line, tempLine))
		{
			_pathToAirfoilPerfoDataFile = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("PROJECT_NAME", line, tempLine))
		{
			_projectName = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("PROJECT_NUMBER", line, tempLine))
		{
			_projectNumber = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("PROJECT_REVISION", line, tempLine))
		{
			_projectRevision = line2SingleValue<std::string>(tempLine);
		}
		if (findKeyAndReturnValue("HUB_RADIUS", line, tempLine))
		{
			_hubRadius = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("BLADE_LENGTH", line, tempLine))
		{
			_bladeLength = line2SingleValue<int>(tempLine);
		}
		if (findKeyAndReturnValue("NUMBER_OF_BLADES", line, tempLine))
		{
			_numberOfBlades = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("RATED_ROTOR_SPEED", line, tempLine))
		{
			_ratedRotorSpeed = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("MIN_ROTOR_SPEED", line, tempLine))
		{
			_minRotorSpeed = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("RATED_ELECTRICAL_POWER", line, tempLine))
		{
			_ratedElectricalPower = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("DRIVETRAIN_LOSSES", line, tempLine))
		{
			_driveTrainLosses = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("AIR_DENSITY", line, tempLine))
		{
			_airDensity = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("DYNAMIC_VISCOSITY", line, tempLine))
		{
			_dynamicViscosity = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("MAX_FLAP_MOMENT_ALLOWED", line, tempLine))
		{
			_maxFlapMomentAllowed = line2SingleValue<double>(tempLine);
		}
		if (findKeyAndReturnValue("USE_TIPLOSS_FACTOR", line, tempLine))
		{
			_usePrandtlTipLoss = line2SingleValue<double>(tempLine);
		}
	}
}

bool ProjectData::findKeyAndReturnValue(std::string key, const std::string& inputLine, std::string& tempLine)
{
	bool validLine = false;

	if (inputLine.find(key.append(" ")) == 0)
	{
		tempLine.assign(inputLine);
		tempLine = tempLine.erase(0, key.size());

		if (tempLine != "")
		{
			validLine = true;
		}
	}
	return validLine;
}

void ProjectData::stripCommentsFromLine(std::string& line)
{
	size_t startPosition = line.find_first_not_of(" \t");
	size_t find = line.find("#");
	if (find < 10000)
	{
		line.erase(find, std::string::npos);
		return;
	}

	if (std::string::npos != startPosition)
	{
		line = line.substr(startPosition);
	}

}

