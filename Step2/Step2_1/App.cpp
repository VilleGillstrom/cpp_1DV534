#include "App.h"
#include <iostream>
#include <MyTime.h>
#include "Compare.h"


const char* SEQUENCE = "abcdefghijklmnopqrstuvwxyz";
const char* SEQUENCETEST = "a";

using std::cout;
using std::cin;

App::App()
{
	stopwatch = new Stopwatch();
}


App::~App()
{
	delete stopwatch;
}

void App::run()
{
	Stopwatch* stopwatch = new Stopwatch();

	cout << "Enter \"" << SEQUENCE << "\" as fast as possible\n";
	cout << "Press return to start:\n";
	cin.ignore(); /* Wait for return key */
	cout << "Start!\n";
	stopwatch->start();

	/*Get input */
	char input[200];
	cin >> input;

	stopwatch->stop();
	
	Compare* compare = new Compare();
	if(compare->equal(input, SEQUENCE))
	{
		const MyTime timeTaken = stopwatch->getTime();
		system("CLS");
		cout << "Time: " << timeTaken;
	} else
	{
		cout << "Wrong input sequence\n";
	}

	/* return resources  */
	delete compare;
	delete stopwatch;
}

