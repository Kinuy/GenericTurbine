#include <iostream>
#include <memory>
#include "ProjectData.h"
int main(int argc, char** argv) {
	//todo: read project data file and parse data to obj
	std::string projectFile = argv[1];
	std::shared_ptr<ProjectData> ptrProjectData = std::make_shared<ProjectData>(projectFile);
	return 0;
}