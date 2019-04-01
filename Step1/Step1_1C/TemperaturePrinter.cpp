#include "TemperaturePrinter.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

TemperaturePrinter::TemperaturePrinter():
	mColumnsDisplayTemps(6)
{
}

TemperaturePrinter::TemperaturePrinter(TemperatureLog temperatureReading) :
	mTemperatureLog(temperatureReading),
	mColumnsDisplayTemps(6)
{
}


TemperaturePrinter::~TemperaturePrinter()
{
}


void TemperaturePrinter::displayAvgTemperature() const
{
	double temperatureAvg = mTemperatureLog.avgTemperature();
	
	/* Display result */
	cout << "\nCalculating average temperature...\n";
	cout << fixed << setprecision(2) << "\nAverage temperature: " << temperatureAvg << " degrees Celcius\n";
}


void TemperaturePrinter::displayTemperatureMinMax() const
{
	double min = mTemperatureLog.minTemperature();
	double max = mTemperatureLog.maxTemperature();

	/* Display result */
	cout << "\nCalculating the maximum and minimum temperature...\n";
	cout << fixed << setprecision(2) << "\nMaximum temperature: " << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void TemperaturePrinter::displayTemperatures() const
{
	cout << "\nDisplaying the latest 24 temperature values:\n\n";

	for (int i = 0; i < mTemperatureLog.numberOfReadings(); i++) {
		double temperature = mTemperatureLog.getTemperature(i);
		if (i % mColumnsDisplayTemps == 0) {
			cout << endl;
		}
		cout << fixed << setprecision(2) << setw(8) << temperature;
	}
}

