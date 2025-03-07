#include "AirfoilGeoData.h"

AirfoilGeoData::AirfoilGeoData(std::string geoFile){
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

}

void AirfoilGeoData::processAirfoilGeoData()
{
}
