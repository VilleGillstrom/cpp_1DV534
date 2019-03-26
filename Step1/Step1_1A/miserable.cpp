/**********************************************************************/
// File:	miserable.cpp
// Summary: Read and present temperatures from a file.
// Owner:	No idea
// -------------------------------------------
// Log:	2019-03-26 Began refactoring the file	
//		
/**********************************************************************/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::setw;
using std::endl;
using std::vector;
using std::max;


void displayTemperatures(const std::vector<double>& temperatures, int columns);
void displayTemperatureMinMax(const std::vector<double>& temperatures);
void displayAvgTemperature(const std::vector<double>& temperatures);
bool readTemperaturesFromFile(const std::string &filename, std::vector<double>& temperatures);


const char* FILENAME = "templog.txt"; /* File containing temperatures */
const int COLUMNS_DISPLAY_TEMPS = 6;  /* Number of columns when displaying temperatures */

int main()
{
	bool isRunning = true; /* Determines when to exit main loop (terminates application) */
	char choice;		   /* Store user input */

	vector<double> temperatures;

	/* Read temperatures */
	if (!readTemperaturesFromFile(FILENAME, temperatures)) { 
		cout << "\n\nUnable to read file: " << std::strerror(errno) << "\nTerminating the program. ";
		cin.get();
		return -1; /* Multiple returns, but I think it's fine sometimes */
	}

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.get();

	while (isRunning)
	{
		system("cls"); /* Clear screen */
		cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";

		cin.get(choice);
		cin.get(); /* Press enter to continue prompt */

		/* Handle user input */
		switch (choice) {
		case '1':
			displayTemperatures(temperatures, COLUMNS_DISPLAY_TEMPS);
			break;
		case '2':
			displayTemperatureMinMax(temperatures);
			break;
		case '3':
			displayAvgTemperature(temperatures);
			break;
		case '4':
			isRunning = false; /* Exit program */
			cout << "\n\nTerminating the program.";
			break;
		default:
			cout << "\n\nUnknown input!";
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
	const auto minmax = std::minmax_element(begin(temperatures), end(temperatures));
	double min = *minmax.first;
	double max = *minmax.second;

	/* Display result */
	cout << "\nCalculating the maximum and minimum temperature...\n";
	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

void displayTemperatures(const vector<double>& temperatures, int columns)
{
	cout << "\nDisplaying the latest 24 temperature values:\n\n";

	for (int i = 0; i < temperatures.size(); i++) {
		double temperature = temperatures[i];
		if (i % columns == 0) { 
			cout << endl;
		}
		cout << fixed << setprecision(2) << setw(8) << temperature;
	}
}

bool readTemperaturesFromFile(const std::string &filename, std::vector<double>& temperatures)
{
	ifstream file(filename);
	if (file.fail()) {
		return false; /* Unable to open file */
	}

	double temperature; /* Temprarily store temperatures read from file */

	/* Read the file content into temperatures*/
	while (file >> temperature) {
		temperatures.push_back(temperature);
	}

	file.close();
	return true;
}
