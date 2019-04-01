#pragma once

#include <vector>
#include "TemperatureReading.h"

class TemperaturePrinter
{
public:
	TemperaturePrinter();
	TemperaturePrinter(TemperatureLog temperatureReading);
	~TemperaturePrinter();


	/* Display the average temperature in */
	void displayAvgTemperature();
	void displayTemperatureMinMax();
	void displayTemperatures(int columns);

private:
	TemperatureLog mTemperatureReading;
};

