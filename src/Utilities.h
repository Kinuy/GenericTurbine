#pragma once

#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <direct.h>
#include <errno.h>
#include <iostream>
#include <numbers>
#include <filesystem>


template <typename T>
std::vector<T> line2Vector(const std::string& line)
{
	std::istringstream is(line);
	return std::vector<T>(std::istream_iterator<T>(is), std::istream_iterator<T>());
}

template <typename T>
T line2SingleValue(const std::string& line)
{
	std::istringstream is(line);
	T value;
	is >> value;
	return value;
}

static std::vector<double> makeVector(std::vector<double> vInput)
{
	double end = vInput[1];
	double start = vInput[0];
	double step = vInput[2];
	double value = vInput[0];
	std::vector<double> result;

	while (value != end + step)
	{
		result.push_back(value);
		value += step;
	}

	return result;
}

static void dirHandler(const std::string& folder) {
	namespace fs = std::filesystem;

	try {
		if (fs::exists(folder)) {
			fs::remove_all(folder);
		}

		if (!fs::create_directory(folder)) {
			std::cerr << "Could not create log folder " << folder << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error handling directory " << folder << ": " << e.what() << std::endl;
	}
}

static bool findKeyAndReturnValue(std::string key, const std::string& inputLine, std::string& tempLine)
{
	bool validLine = false;

	if (inputLine.find(key.append(" ")) == 0)
	{
		tempLine.assign(inputLine);
		tempLine = tempLine.erase(0, key.size());

		if (tempLine != "")
		{
			validLine = true;
		}
	}
	return validLine;
}

static void stripCommentsFromLine(std::string& line)
{
	size_t startPosition = line.find_first_not_of(" \t");
	size_t find = line.find("#");
	if (find < 10000)
	{
		line.erase(find, std::string::npos);
		return;
	}

	if (std::string::npos != startPosition)
	{
		line = line.substr(startPosition);
	}

}

static double interpolateLinear(std::vector<double> x, std::vector<double> y, double xTarget)
{
	if (y.size() != x.size()){
		std::cout << "Error: x and y vectors have not the same length" << std::endl;
	}
	if (xTarget < x.at(0)) {
		return y.at(0);
	}
	if (xTarget > x.back()) {
		return y.back();
	}
	else {
		for (int i = 0; i < x.size() - 1; i++) {
			if ((x.at(i) <= xTarget) && x.at(i + 1) >= xTarget) {
				break;
			}
			return y.at(i) + (xTarget - x.at(i)) * (y.at(i + 1) - y.at(i)) / (x.at(i + 1) - x.at(i));
		}
	}
	return 0;
}