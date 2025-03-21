#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Utilities.h"

class ProjectData
{
public:
	ProjectData(std::string projectFile);
	~ProjectData();

	void readProjectData();
	void processProjectData();

	std::string pathToAirfoilGeoDataFile() const { return _pathToAirfoilGeoDataFile; }
	std::string pathToAirfoilPerfoDataFile() const { return _pathToAirfoilPerfoDataFile; }
	std::string pathToBladeGeoDataFile() const { return _pathToBladeGeoDataFile; }

private:

	std::string _projectFile;
	std::string _projectRevision;
	std::string _projectName;
	std::string _projectNumber;

	std::string _pathToAirfoilGeoDataFile;
	std::string _pathToAirfoilPerfoDataFile;
	std::string _pathToBladeGeoDataFile;

	double _bladeLength;
	double _airDensity;
	double _dynamicViscosity;
	double _hubRadius;
	int _numberOfBlades;
	bool _usePrandtlTipLoss;
	double _driveTrainLosses;
	double _ratedElectricalPower;
	double _ratedRotorSpeed;
	double _minRotorSpeed;
	double _maxFlapMomentAllowed;

	std::vector<double> _TSR;
	std::vector<int> _runModes;
	std::vector<double> _analyseBladeSections;
	std::vector<double> _addonVGBladeSections;
	std::vector<std::string> projectData;

};