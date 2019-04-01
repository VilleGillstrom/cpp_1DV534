#include <iostream>
#include "TemperatureReading.h"
#include "TemperaturePrinter.h"

using std::cin;
using std::cout;

const char* FILENAME = "templog.txt"; /* File containing temperatures */
const int COLUMNS_DISPLAY_TEMPS = 6;  /* Number of columns when displaying temperatures */

int main() {
	std::cout << "Hello world";

	/* Construct and initialize a temperature reading*/
	TemperatureLog temperatureReading;
	if (!temperatureReading.loadReadingsFromFile(FILENAME)) {
		return -1; /* Unable to read file, exit failure */
	}

	/* Construct temperature printer with above made reading */
	TemperaturePrinter temperaturePrinter(temperatureReading);

	cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
	cin.get();

	bool isRunning;
	char choice;

	while (isRunning)
	{
		system("cls"); /* Clear screen */
		cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";

		cin.get(choice);
		cin.get(); /* Press enter to continue prompt */

		/* Handle user input */
		switch (choice) {
		case '1':
			temperaturePrinter.displayTemperatures(COLUMNS_DISPLAY_TEMPS);
			break;
		case '2':
			temperaturePrinter.displayTemperatureMinMax(temperatures);
			break;
		case '3':
			temperaturePrinter.displayAvgTemperature(temperatures);
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