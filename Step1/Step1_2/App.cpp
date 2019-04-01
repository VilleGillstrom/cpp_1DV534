#include <iostream>
#include "App.h"


using std::cout;
using std::cin;
using std::move;


App::App(CashRegister&& cashRegister) : mCash(move(cashRegister))
{
}

App::~App()
{
}

void App::run() {
	bool isRunning = true;
	char choice;

	while (isRunning) {

		system("cls"); /* Clear screen */
		cout << "\n\nMENU\n----\n\n1. Enter product information to register.\n2. Exit\n\n";

		cin.get(choice);
		cin.get(); /* Press enter to continue prompt */

		/* Handle user input */
		switch (choice) {
		case '1':
			handleUserInputItem(); /* Get and register a user inputed item */
			break;
		case '2':
			isRunning = false; /* Exit program */
			break;
		default:
			cout << "\n\nUnknown input!";
			break;
		}
		cout << "\n\nPress Enter to continue:";
		cin.get();
	}
	cout << "\n\nTerminating the program.";
}


bool App::handleUserInputItem() {
	int category; /* User input category*/
	char articleName[100] = { 0 }; /*User input name */
	double price; /* User input price */
	bool success = true; /* Is set to false when user input is bad */

	cin.clear();

	/* Get and validate the category */
	cout << "Category: ";
	cin >> category;
	if (cin.fail() || !mCash.validCategory(category)) {
		std::cout << "Bad category\n";
		success = false;
	}

	/* Get article name */
	cout << "Article Name: ";
	cin >> articleName;
	if (success && cin.fail()) {
		std::cout << "Bad article name\n";
		success = false;
	}

	/* Get price */
	cout << "Price: ";
	cin >> price;
	if (success && cin.fail()) {
		std::cout << "Bad price\n";
		success = false;
	}

	if (success) {
		std::cout << "Registering: " << category << " " << articleName << " " << price << "\n";
	}

	/* Clean cin (i think) */
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	mCash.registerItem(category, articleName, price);
	return success;
}
