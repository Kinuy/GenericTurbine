#pragma once
#include<memory>

#include "ProjectData.h"
#include "Blade.h"

class Turbine {
public:
	Turbine();
	Turbine(std::shared_ptr<ProjectData>, std::shared_ptr<Blade>);
	~Turbine();
	void calcPowerCurve();


private:

};