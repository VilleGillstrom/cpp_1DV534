// Step2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "App.h"

int main()
{
	App* app = new App();
	app->run();
	delete app;
}
