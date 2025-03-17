#include "Blade.h"
Blade::Blade()
{
}
Blade::~Blade()
{
}

Blade::Blade(std::shared_ptr<ProjectData> projectData): _projectData(projectData)
{
	_bladeGeoData = std::make_shared<BladeGeoData>(
		_projectData->pathToBladeGeoDataFile());

	readAirfoilsGeoDataList();
	readAirfoilsPerfoDataList();

	processAirfoilsGeoPerfoData();
	createAirfoils();
}

void Blade::readAirfoilsGeoDataList() {
	std::fstream file;
	file.open(_projectData->pathToAirfoilGeoDataFile());

	while (file.good()) {
		std::string line;
		std::getline(file, line);
		if (line.starts_with("#"))
		{
			continue;
		}
		std::stringstream tokens(line);
		std::string filePath;
		tokens >> filePath;
		_airfoilGeoFileList.push_back(filePath);
	}
	file.close();
}

void Blade::readAirfoilsPerfoDataList() {
	std::fstream file;
	file.open(_projectData->pathToAirfoilPerfoDataFile());

	while (file.good()) {
		std::string line;
		std::getline(file, line);
		if (line.starts_with("#"))
		{
			continue;
		}
		std::stringstream tokens(line);
		std::string filePath;
		tokens >> filePath;
		_airfoilPolarFileList.push_back(filePath);
	}
	file.close();
}

void Blade::processAirfoilsGeoPerfoData() {
	for (int i = 0; i < _airfoilGeoFileList.size(); i++) {
		std::shared_ptr<AirfoilGeoData> ptrAirfoilGeoData = std::make_shared<AirfoilGeoData>(_airfoilGeoFileList.at(i));
		_sptrAirfoilGeoDataList.push_back(ptrAirfoilGeoData);
	}
	for (int i = 0; i < _airfoilPolarFileList.size(); i++) {
		std::shared_ptr<AirfoilPerfoData> ptrAirfoilPerfoData = std::make_shared<AirfoilPerfoData>(_airfoilPolarFileList.at(i));
		_sptrAirfoilPerfoDataList.push_back(ptrAirfoilPerfoData);
	}

	filterAirfoilsGeoDataList();
}

void Blade::filterAirfoilsGeoDataList() {
	for (int i = 0; i < _airfoilGeoFileList.size(); i++) {
		for (int p = 0; p < _airfoilPolarFileList.size(); p++) {
			if (_sptrAirfoilGeoDataList.at(i)->getRelThickness() == _sptrAirfoilPerfoDataList.at(p)->getRelThickness()) {
				_sptrAirfoilGeoDataList.at(i)->setHasPerfoData(true);
			}
		}
	}
}

void Blade::createAirfoils() {
	for (int i = 0; i < _airfoilGeoFileList.size(); i++) {
		if (!_sptrAirfoilGeoDataList.at(i)->getHasPerfoData()) {
			std::shared_ptr<AirfoilPerfoData> ptrAirfoilEmptyPerfoData = std::make_shared<AirfoilPerfoData>();
			std::shared_ptr<AirfoilData> ptrAirfoilData = std::make_shared<AirfoilData>(_sptrAirfoilGeoDataList.at(i), ptrAirfoilEmptyPerfoData);
			_airfoilsDataDesign.push_back(ptrAirfoilData);
		}
		else {
			for (int p = 0; p < _airfoilPolarFileList.size(); p++) {
				if (_sptrAirfoilGeoDataList.at(i)->getRelThickness() == _sptrAirfoilPerfoDataList.at(p)->getRelThickness()) {
					std::shared_ptr<AirfoilData> ptrAirfoilData = std::make_shared<AirfoilData>(_sptrAirfoilGeoDataList.at(i), _sptrAirfoilPerfoDataList.at(p));
					_airfoilsDataDesign.push_back(ptrAirfoilData);
				}
			}
			continue;
		}

	}
	// we need airfoils from thin to thickest shape for interpolation
	std::reverse(_airfoilsDataDesign.begin(), _airfoilsDataDesign.end());
	for (std::shared_ptr<AirfoilData> num : _airfoilsDataDesign) {
		std::cout << num->getAirfoilPerfoData()->getRelThickness() << " ";
	}
}

double Blade::getCoefficient(double alpha, double relThickness, std::string coefficient) {
	// takes "cl" or "cd" or "cm" as input for coefficient
	// first test edge cases. thickest or thinnest airfoil
	if (relThickness >= _airfoilsDataDesign.at(-1)->getAirfoilPerfoData()->getRelThickness()) {
		return interpolateLinear(
			_airfoilsDataDesign.at(-1)->getAirfoilPerfoData()->getAlpha(),
			_airfoilsDataDesign.at(-1)->getAirfoilPerfoData()->getCoefficients(coefficient),
			alpha);
	}
	if (relThickness <= _airfoilsDataDesign.at(0)->getAirfoilPerfoData()->getRelThickness()) {

		return interpolateLinear(
			_airfoilsDataDesign.at(0)->getAirfoilPerfoData()->getAlpha(),
			_airfoilsDataDesign.at(0)->getAirfoilPerfoData()->getCoefficients(coefficient),
			alpha);
	}

	// second interpolate linear in between thin and thick airfoil data
	int index = 0;
	while (relThickness > _airfoilsDataDesign.at(index)->getAirfoilPerfoData()->getRelThickness()) {
		index++;
		double coefficientThin, coefficientThick;
		coefficientThin = interpolateLinear(
			_airfoilsDataDesign.at(index - 1)->getAirfoilPerfoData()->getAlpha(),
			_airfoilsDataDesign.at(index - 1)->getAirfoilPerfoData()->getCoefficients(coefficient),
			alpha);
		coefficientThick = interpolateLinear(
			_airfoilsDataDesign.at(index)->getAirfoilPerfoData()->getAlpha(),
			_airfoilsDataDesign.at(index)->getAirfoilPerfoData()->getCoefficients(coefficient),
			alpha);

		double relThicknessThin = _airfoilsDataDesign.at(index - 1)->getAirfoilPerfoData()->getRelThickness();
		double relThicknessThick = _airfoilsDataDesign.at(index)->getAirfoilPerfoData()->getRelThickness();

		return coefficientThin + (relThickness - relThicknessThin) * (coefficientThick - coefficientThin) / (relThicknessThick);
	}
}
