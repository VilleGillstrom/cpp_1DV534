#pragma once

#include <vector>
class TemperatureLog
{
public:
	TemperatureLog();
	~TemperatureLog();

	/* Load temperatures from file */
	bool loadReadingsFromFile(const std::string& filename);

	/* Get average temperature */
	double avgTemperature() const;

	/* Get min of temperatures */
	double minTemperature() const;

	/* Get max of temperatures */
	double maxTemperature() const;

	/* Get a single temperature reading */
	double getTemperature(int Index) const;

	/* Get number of readings */
	size_t numberOfReadings() const;


private:

	/* Loaded temperatures */
	std::vector<double> mTemperatures;
};

