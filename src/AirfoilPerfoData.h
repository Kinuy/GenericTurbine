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
	double getReynoldsNumber()const { return _reynoldsNumber; };
	double getMachNumber()const { return _machNumber; };
	std::vector<double> getAlpha() const {return _alpha; };
	std::vector<double> getCl() const { return _cl; };
	std::vector<double> getCd() const { return _cd; };
	std::vector<double> getCm() const { return _cm; };

	std::vector<double> getCoefficients(std::string coefficient) const;

private:

	int _xa;
	size_t _nalpha;
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