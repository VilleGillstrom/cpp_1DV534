#pragma once

#include <vector>
#include "TemperatureLog.h"

class TemperaturePrinter
{
public:
	TemperaturePrinter();
	TemperaturePrinter(TemperatureLog temperatureLog);
	~TemperaturePrinter();


	/* Display the average temperature in */
	void displayAvgTemperature() const;
	void displayTemperatureMinMax() const;
	void displayTemperatures() const;

private:
	TemperatureLog mTemperatureLog;
	int mColumnsDisplayTemps; /* Number of columns when calling displayTemperatures() */
};

