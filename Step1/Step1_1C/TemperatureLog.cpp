#include "TemperatureLog.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

TemperatureLog::TemperatureLog()
{
}


TemperatureLog::~TemperatureLog()
{
}

bool TemperatureLog::loadReadingsFromFile(const std::string & filename)
{
	mTemperatures.clear();

	ifstream file(filename);
	if (file.fail()) {
		return false; /* Unable to open file */
	}

	double temperature; /* Temporarily store temperature read from file */

	/* Read file content into temperatures*/
	while (file >> temperature) {
		mTemperatures.push_back(temperature);
	}

	file.close();
	return true;
}

double TemperatureLog::avgTemperature() const
{
	double temperatureTotal = 0.0;
	for (double t : mTemperatures) {
		temperatureTotal += t;
	}

	double temperatureAvg = temperatureTotal / mTemperatures.size();
	return temperatureAvg;
}

double TemperatureLog::minTemperature() const
{
	return *min_element(begin(mTemperatures), end(mTemperatures));
}

double TemperatureLog::maxTemperature() const
{
	return *max_element(begin(mTemperatures), end(mTemperatures));
}

double TemperatureLog::getTemperature(int Index) const
{
	return mTemperatures.at(Index);
}

size_t TemperatureLog::numberOfReadings() const
{
	return mTemperatures.size();;
}
