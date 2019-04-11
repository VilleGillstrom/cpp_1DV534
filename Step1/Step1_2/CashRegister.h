#pragma once

#include <fstream>


class CashRegister
{
	
public:

	CashRegister(const char* fileName, int nrOfCategories); // constructor
	CashRegister(CashRegister &&OldCashRegister); /* Move constructor */
	~CashRegister(); //	destructor
	bool registerItem(int category, const char* articleName, double amount);
	double batchTotal() {
		double total = _batchTotal;
		_batchTotal = 0; //	batchTotal() is expected to reset _batchTotal;
		return total;
	}

	bool validCategory(int category); /* Is the given category valid ? */

	

private:
	std::ofstream _file;		   // Here will registered items be saved
	int _nrOfCategories;   // Products are organized in categories
	double* _categorySums; // The vector will contain respective sum of each
						   // category sold during the day
	double _batchTotal;    // Sold since the last summation


	void registerItemWrite(int category, const char* articleName, double amount);
	std::string currentTime() const; /* Get current time on format hh:mm */
	std::string currentDate() const; /* Get current date on format yyyy-mm-dd */
	std::string currentDay() const; /* Get current day as string */
}; 

