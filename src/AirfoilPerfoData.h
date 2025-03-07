#pragma once
#include<vector>
#include<string>
#include "ProjectData.h"
#include "Utilities.h"

class AirfoilPerfoData {

public:

	AirfoilPerfoData(std::string polarFile);
	AirfoilPerfoData();
	~AirfoilPerfoData();

	void readAirfoilPerfoData();
	void processAirfoilPerfoData();

	double getRelThickness()const { return _relThickness; };

private:

	int _xa;
	int _nalpha;
	int _nvals;
	int _depang;
	std::string _airfoilPerfoDataFile;
	std::string _airfoilPolarName;
	double _relThickness;
	double _reynoldsNumber;
	double _machNumber;
	std::vector<double> _alpha;
	std::vector<double> _cl;
	std::vector<double> _cd;
	std::vector<double> _cm;
};