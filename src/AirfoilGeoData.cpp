#include "AirfoilGeoData.h"

AirfoilGeoData::AirfoilGeoData(std::string geoFile):_airfoilGeoDataFile(geoFile){
	_airfoilName = "";
	_relThickness = 0.0;
	_hasPerfoData = false;

	readAirfoilGeoData();
}

AirfoilGeoData::AirfoilGeoData() {
	_airfoilName = "";
	_relThickness = 0.0;
	_hasPerfoData = false;
}

AirfoilGeoData::~AirfoilGeoData(){}

void AirfoilGeoData::readAirfoilGeoData()
{
	std::fstream file;
	std::string key;
	file.open(_airfoilGeoDataFile);

	while (file.good()) {
		std::string line;
		std::getline(file, line);
		if (line.starts_with("#")) {
			continue;
		}
		std::stringstream tokens(line);
		if (line.starts_with("RELTHICK")) {
			
			tokens >> key >> _relThickness;
			continue;
		}
		if (line.starts_with("NAME")) {
			tokens >> key >> _airfoilName;
			continue;
		}
		double x, y;
		tokens >> x >> y;
		_x.push_back(x);
		_y.push_back(y);
	}

	file.close();

}

void AirfoilGeoData::processAirfoilGeoData()
{
}
