//miserable.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include "miserable.h"



using std::cout;
using std::cin;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::setw;
using std::endl;

int main()
{
	bool isRunning = true; /* Determines when to exit main loop (terminates application) */
	double temperature;
	double s;
	double m;
	char choice;

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.get();

	while (isRunning)
	{
		system("cls"); /* Clear screen */
		cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";

		cin.get(choice);
		cin.get(); /* Press enter to continue prompt */

		switch (choice) {
		case '1': 
			displayTemperature(temperature);
			break;       
		case '2': 
			displayTemperatureMinMax(temperature);
			break;
		case '3':
			displayAvgTemperature(s, temperature, m);
			break;
		default:
			isRunning = 0;
			cout << "\n\nTerminating the program.";
			break;
		}
		cout << "\n\nPress Enter to continue:";
		cin.get();
	}
	return 0;
}

void displayAvgTemperature(double &s, double &temperature, double &m)
{
	cout << "\nCalculating average temperature...\n";
	s = 0.0;
	ifstream fil("templog.txt");
	for (int i = 0; i < 24; i++)
	{
		fil >> temperature;
		s += temperature;
	}
	fil.close();
	m = s / 24;
	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << m << " degrees Celcius\n";
}

void displayTemperatureMinMax(double &temperature)
{
	cout << "\nCalculating the maximum and minimum temperature...\n";
	double max = 0, min = 0;
	ifstream fil("templog.txt");
	fil >> temperature;
	max = min = temperature;
	for (int i = 1; i < 24; i++)
	{
		fil >> temperature;
		if (temperature > max)
			max = temperature;
		if (temperature < min)
			min = temperature;
	}
	fil.close();
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void displayTemperature(double &t)
{
	cout << "\nDisplaying the latest 24 temperature values:\n\n";
	ifstream fil("templog.txt");
	for (int i = 0; i < 24; i++)
	{
		if (i % 6 == 0)
			cout << endl;
		fil >> t;
		cout << fixed << setprecision(2) << setw(8) << t;
	}
	fil.close();
}

