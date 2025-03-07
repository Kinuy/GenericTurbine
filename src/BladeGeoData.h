#pragma once
#include<vector>
#include<string>
#include <fstream>
#include<sstream>

class BladeGeoData{

public:

	BladeGeoData();
	BladeGeoData(std::string);
	~BladeGeoData();

	void readBladeGeoData();
	void processBladeGeoData();

private:

	std::string _bladeGeoDataFile;

	std::vector<double> _absBladeRadius;
	std::vector<double> _chord;
	std::vector<double> _twist;
	std::vector<double> _relThickness;
	std::vector<double> _xt4;
	std::vector<double> _yt4;
	std::vector<double> _pcbax;
	std::vector<double> _pcbay;
	std::vector<double> _relTwistAxis;
};