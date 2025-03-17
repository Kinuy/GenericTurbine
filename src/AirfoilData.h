#pragma once
#include <vector>
#include <memory>
#include<string>
#include "AirfoilGeoData.h"
#include "AirfoilPerfoData.h"

class AirfoilData : AirfoilGeoData, AirfoilPerfoData {
public:
	AirfoilData();
	AirfoilData(std::shared_ptr<AirfoilGeoData> ptrGeo, std::shared_ptr<AirfoilPerfoData> ptrPerfo);
	~AirfoilData();

	std::shared_ptr<AirfoilGeoData> getAirfoilGeoData() { return _airfoilGeoData; }
	std::shared_ptr<AirfoilPerfoData> getAirfoilPerfoData() { return _airfoilPerfoData; }

private:
	std::shared_ptr<AirfoilGeoData> _airfoilGeoData;
	std::shared_ptr<AirfoilPerfoData> _airfoilPerfoData;
};