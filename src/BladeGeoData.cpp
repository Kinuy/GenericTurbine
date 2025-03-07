#include "BladeGeoData.h"
BladeGeoData::BladeGeoData() {

}

BladeGeoData::BladeGeoData(std::string bladeGeoFile):_bladeGeoDataFile(bladeGeoFile){

	readBladeGeoData();
}
BladeGeoData::~BladeGeoData() {

}

void BladeGeoData::readBladeGeoData()
{
	std::ifstream file;
	file.open(_bladeGeoDataFile);
	while (file.good())
	{
		std::string line;
		std::getline(file, line);

		if (line.starts_with("#"))
		{
			continue;
		}

		std::istringstream tokens(line);
		double radius, chord, twist, relThickness, xt4, yt4, pcbax, pcbay, relTwistAxis;
		tokens 
			>> radius 
			>> chord 
			>> twist 
			>> relThickness 
			>> xt4 
			>> yt4 
			>> pcbax 
			>> pcbay 
			>> relTwistAxis;

		_absBladeRadius.push_back(radius);
		_chord.push_back(chord);
		_twist.push_back(twist);
		_relThickness.push_back(relThickness);
		_xt4.push_back(xt4);
		_yt4.push_back(yt4);
		_pcbax.push_back(pcbax);
		_pcbay.push_back(pcbay);
		_relTwistAxis.push_back(relTwistAxis);
	}
	file.close();
}

void BladeGeoData::processBladeGeoData()
{
}
