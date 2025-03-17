#include <iostream>
#include <memory>
#include "ProjectData.h"
#include "Blade.h"
#include "Turbine.h"

int main(int argc, char** argv) {

	std::string projectFile = argv[1];
	std::shared_ptr<ProjectData> ptrProjectData = std::make_shared<ProjectData>(projectFile);

	std::shared_ptr<Blade> ptrBlade = std::make_shared<Blade>(ptrProjectData);

	std::shared_ptr<Turbine> ptrTurbine = std::make_shared<Turbine>(ptrProjectData, ptrBlade);

	

	return 0;
}