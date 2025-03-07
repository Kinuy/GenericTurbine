#include <iostream>
#include <memory>
#include "ProjectData.h"
#include "Blade.h"
int main(int argc, char** argv) {

	std::string projectFile = argv[1];
	std::shared_ptr<ProjectData> ptrProjectData = std::make_shared<ProjectData>(projectFile);

	std::shared_ptr<Blade> ptrBlade = std::make_shared<Blade>(ptrProjectData);

	

	return 0;
}