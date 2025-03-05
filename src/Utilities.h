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