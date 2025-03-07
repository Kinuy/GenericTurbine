#include "AirfoilData.h"

AirfoilData::AirfoilData() {

}

AirfoilData::~AirfoilData() {}

AirfoilData::AirfoilData(std::shared_ptr<AirfoilGeoData> ptrGeo, std::shared_ptr<AirfoilPerfoData> ptrPerfo) : _airfoilGeoData(ptrGeo), _airfoilPerfoData(ptrPerfo)
{
	//_airfoilGeoData = std::make_shared<AirfoilGeoData>(geoFile);
	//_airfoilPerfoData = std::make_shared<AirfoilPerfoData>(polarFile);

	_airfoilGeoData->readAirfoilGeoData();
	_airfoilGeoData->processAirfoilGeoData();

	_airfoilPerfoData->readAirfoilPerfoData();
	_airfoilPerfoData->processAirfoilPerfoData();
}



