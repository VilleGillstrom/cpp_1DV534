#pragma once

#include "CashRegister.h";


class App
{
public:
	App(CashRegister&& cashRegister);
	~App();
	void run(); /* Run the application loop */

private:
	bool handleUserInputItem(); /* Handle user input for registering an item */

	/* Get info from user */
	bool FetchPrice(double &price);
	bool FetchCategory(int &category);
	bool FetchArticleName(char* articleName);
	CashRegister mCash;
};


