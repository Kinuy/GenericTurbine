#include "AirfoilPerfoData.h"


AirfoilPerfoData::AirfoilPerfoData(std::string polarFile){
	_airfoilPerfoDataFile = polarFile;
	_airfoilPolarName = "";
	_relThickness = 0.0;
	_reynoldsNumber = 0.0;
	_machNumber = 0.0;
	_xa = 25;
	_nalpha = 0;
	_nvals = 3;
	_depang = 0;

	readAirfoilPerfoData();
}

AirfoilPerfoData::AirfoilPerfoData() {
	_airfoilPolarName = "";
	_relThickness = 0.0;
	_reynoldsNumber = 0.0;
	_machNumber = 0.0;
	_xa = 25;
	_nalpha = 0;
	_nvals = 3;
	_depang = 0;
}

AirfoilPerfoData::~AirfoilPerfoData(){}

void AirfoilPerfoData::readAirfoilPerfoData()
{
	std::fstream file;
	file.open(_airfoilPerfoDataFile);
	while (file.good()) {
		std::string line;
		std::getline(file, line);
		std::string temp = "";
		std::string& tempLine = temp;
		std::stringstream token(line);
		std::string key;
		
		if (line.starts_with("#")) {
			continue;
		}
		if (line.starts_with("REFNUM"))
		{
			std::string val;
			token >> key >> val;
			_airfoilPolarName = val;
			continue;
		}
		if (line.starts_with("XA"))
		{
			int val;
			token >> key >> val;
			_xa = val;
			continue;
		}
		if (line.starts_with("RELTHICK"))
		{
			double val;
			token >> key >> val;
			_relThickness = val;
			continue;
		}
		if (line.starts_with("NAME"))
		{
			double val;
			token >> key >> val;
			_airfoilPolarName = val;
			continue;
		}
		if (line.starts_with("REYN"))
		{
			double val;
			token >> key >> val;
			_reynoldsNumber = val;
			continue;
		}
		if (line.starts_with("DEPANG"))
		{
			int val;
			token >> key >> val;
			_depang = val;
			continue;
		}
		if (line.starts_with("NALPHA"))
		{
			int val;
			token >> key >> val;
			_nalpha = val;
			continue;
		}
		if (line.starts_with("NVALS"))
		{
			int val;
			token >> key >> val;
			_nvals = val;
			continue;
		}
		if (line.starts_with("ENDSECTION"))
		{
			break;
		}
		else {
			double alpha, cl, cd, cm;
			token >> alpha >> cl >> cd >> cm;
			_alpha.push_back(alpha);
			_cl.push_back(cl);
			_cd.push_back(cd);
			_cm.push_back(cm);
		}
	}
	_nalpha = _alpha.size();
	file.close();
}

void AirfoilPerfoData::processAirfoilPerfoData()
{
}
