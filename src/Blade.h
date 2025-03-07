#pragma once
#include<memory>
#include<vector>
#include "BladeGeoData.h"
#include "AirfoilData.h"

class Blade{

public:
	Blade();
	Blade(std::shared_ptr<ProjectData>);
	~Blade();

	void readAirfoilsGeoDataList();
	void readAirfoilsPerfoDataList();
	void processAirfoilsGeoPerfoData();

	void filterAirfoilsGeoDataList();

	void createAirfoils();

private:
	std::vector<std::string> _airfoilGeoFileList;
	std::vector<std::string> _airfoilPolarFileList;

	std::shared_ptr<ProjectData> _projectData;
	std::shared_ptr<BladeGeoData> _bladeGeoData;
	std::vector<std::shared_ptr<AirfoilData>> _airfoilsData;

	std::vector< std::shared_ptr<AirfoilGeoData>> _sptrAirfoilGeoDataList;
	std::vector< std::shared_ptr<AirfoilPerfoData>> _sptrAirfoilPerfoDataList;

};
