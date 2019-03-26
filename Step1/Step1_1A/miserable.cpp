//miserable.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "miserable.h"



using std::cout;
using std::cin;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::setw;
using std::endl;
using std::vector;

int main()
{
	bool isRunning = true; /* Determines when to exit main loop (terminates application) */
	double temperature;

	char choice;

	vector<double> temperatures = readTemperaturesFromFile("templog.txt"); /* Read file only once to avoid slow file reads */

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
			displayTemperature(temperatures);
			break;       
		case '2': 
			displayTemperatureMinMax(temperatures);
			break;
		case '3':
			displayAvgTemperature(temperatures);
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

void displayAvgTemperature(const vector<double>& temperatures)
{

	/* Sum temperatures */
	double temperatureTotal = 0.0;
	for (double t : temperatures) {
		temperatureTotal += t;
	}


	double temperatureAvg = temperatureTotal / temperatures.size();

	/* Display result */
	cout << "\nCalculating average temperature...\n";
	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << temperatureAvg << " degrees Celcius\n";
}


void displayTemperatureMinMax(const vector<double>& temperatures)
{
	double temperature;
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

	/* Display result */
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void displayTemperature(const vector<double>& temperatures)
{
	double temperature;
	cout << "\nDisplaying the latest 24 temperature values:\n\n";
	ifstream fil("templog.txt");
	for (int i = 0; i < 24; i++)
	{
		if (i % 6 == 0)
			cout << endl;
		fil >> temperature;
		cout << fixed << setprecision(2) << setw(8) << temperature;
	}
	fil.close();
}


vector<double> readTemperaturesFromFile(const std::string &filename)
{
	ifstream file(filename);
	double temperature = 0.0; /* Temprarily store temperatures read from file */
	vector<double> temperatures;

	/* Read the file content into temperatures*/
	while (file >> temperature) {
		temperatures.push_back(temperature);
	}

	file.close();
	return temperatures;
}
