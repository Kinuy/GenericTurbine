#include "AirfoilData.h"

AirfoilData::AirfoilData() {

}

AirfoilData::~AirfoilData() {}

AirfoilData::AirfoilData(std::shared_ptr<AirfoilGeoData> ptrGeo, std::shared_ptr<AirfoilPerfoData> ptrPerfo) : _airfoilGeoData(ptrGeo), _airfoilPerfoData(ptrPerfo)
{

}



