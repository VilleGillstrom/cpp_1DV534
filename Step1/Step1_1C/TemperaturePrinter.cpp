#include "TemperaturePrinter.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

TemperaturePrinter::TemperaturePrinter()
{
}

TemperaturePrinter::TemperaturePrinter(TemperatureLog temperatureReading) :
	mTemperatureReading(temperatureReading)
{
}


TemperaturePrinter::~TemperaturePrinter()
{
}


void TemperaturePrinter::displayAvgTemperature()
{
	double temperatureAvg = mTemperatureReading.getAvgTemperature();
	
	/* Display result */
	cout << "\nCalculating average temperature...\n";
	cout << fixed << setprecision(2) << "\nAverage temperature: " << temperatureAvg << " degrees Celcius\n";
}


void TemperaturePrinter::displayTemperatureMinMax()
{
	double min = mTemperatureReading.getMinTemperature();
	double max = mTemperatureReading.getMaxTemperature();

	/* Display result */
	cout << "\nCalculating the maximum and minimum temperature...\n";
	cout << fixed << setprecision(2) << "\nMaximum temperature: " << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void TemperaturePrinter::displayTemperatures( int columns)
{
	cout << "\nDisplaying the latest 24 temperature values:\n\n";

	for (int i = 0; i < mTemperatureReading.numberOfReadings(); i++) {
		double temperature = mTemperatureReading.getTemperature(i);
		if (i % columns == 0) {
			cout << endl;
		}
		cout << fixed << setprecision(2) << setw(8) << temperature;
	}
}

