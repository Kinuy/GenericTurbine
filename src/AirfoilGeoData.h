#pragma once
#include <string>
#include <vector>
#include "ProjectData.h"

class AirfoilGeoData {

public:

	AirfoilGeoData(std::string geoFile);
	AirfoilGeoData();
	~AirfoilGeoData();

	void readAirfoilGeoData();
	void processAirfoilGeoData();

	double getRelThickness()const { return _relThickness; };
	double setHasPerfoData(double hasPerfoData) { return _hasPerfoData = hasPerfoData; };
	double getHasPerfoData() { return _hasPerfoData; };

protected:

	std::string _airfoilGeoDataFile;
	std::string _airfoilName;
	bool _hasPerfoData;
	double _relThickness;
	std::vector<double> _x;
	std::vector<double> _y;
};