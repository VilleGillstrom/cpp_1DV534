#include <iostream>
#include "TemperatureLog.h"
#include "TemperaturePrinter.h"

using std::cin;
using std::cout;

const char* FILENAME = "templog.txt"; /* File containing temperatures */
const int COLUMNS_DISPLAY_TEMPS = 6;  /* Number of columns when displaying temperatures */

class App {
public:
	App(TemperaturePrinter temperaturePrinter) : mTemperaturePrinter(temperaturePrinter) {}

	void run() {
		cout << "\n\nTemperature Statistics\n----------------------\n\nReading logged values for processing and presentation...\n\nPress Enter for menu: ";
		cin.get();

		bool isRunning = true;
		char choice = '\0';

		while (isRunning)
		{
			system("cls"); /* Clear screen */
			cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. View maximum and minimum temperatures\n3. View average temperature\n4. Quit\n\nMake your choice: ";

			cin.get(choice);
			cin.get(); /* Press enter to continue prompt */

					   /* Handle user input */
			switch (choice) {
			case '1':
				mTemperaturePrinter.displayTemperatures();
				break;
			case '2':
				mTemperaturePrinter.displayTemperatureMinMax();
				break;
			case '3':
				mTemperaturePrinter.displayAvgTemperature();
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
	}

private:
	TemperaturePrinter mTemperaturePrinter;
};


int main() {
	/* Construct and initialize a temperature reading*/
	TemperatureLog temperatureLog;
	if (!temperatureLog.loadReadingsFromFile(FILENAME)) {
		return -1; /* Unable to read file, exit failure */
	}

	/* Construct temperature printer with above made log */
	TemperaturePrinter temperaturePrinter(temperatureLog);

	/* Run the application */
	App app(temperaturePrinter);
	app.run();
	
	return 0;
}
