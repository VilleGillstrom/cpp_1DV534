#include "CashRegister.h"
#include <stdexcept>
#include <iostream>
#include <atltime.h>

using std::memcpy;
using std::ios;
using std::move;
using ATL::CTime;

CashRegister::CashRegister(const char* fileName, int nrOfCategories) : _nrOfCategories(nrOfCategories)
{
	_categorySums = new double[nrOfCategories](); /* Store sums till cashregister destroyed */

	_file.exceptions(ios::badbit| ios::failbit); /* Throw exception at failure to open or writing to */
	_file.open(fileName, ofstream::out | ofstream::app); /* Open for writing appendingly */

	/* File opened succesfully, add title*/
	const char* date = currentDate().c_str();
	const char* day = currentDate().c_str();
	const char* time = currentDate().c_str();
	_file << ">>>> > Register opened : "<< date << " " << day << " at " << time << "\n";
}


CashRegister::CashRegister(CashRegister && OldCashRegister) :
	_nrOfCategories(OldCashRegister._nrOfCategories),
	_batchTotal(OldCashRegister._batchTotal),
	_file(move(OldCashRegister._file))
{
	/* Allocate memory and copy values */
	_categorySums = new double[_nrOfCategories]; 
	memcpy(_categorySums, OldCashRegister._categorySums, sizeof(double) * _nrOfCategories); 
}


CashRegister::~CashRegister()
{
	/* Write last info to file */
	const char* date = currentDate().c_str();
	const char* day = currentDate().c_str();
	const char* time = currentDate().c_str();

	std::cout << ">>>>> Register closed: " << date << " " << day << " at " << time << "\n";

	_file << "Totals for the last opening period : \n"
		<< "----------------------------------------\n";

	double sum = 0;

	for (int i = 0; i < _nrOfCategories; ++i) {
		_file << "Category " << i + 1 << " : " << _categorySums[i] << " Kr.\n";
		sum += _categorySums[i];
	}
	_file << "Total sales within all categories : " << sum << "Kr.\n";
	_file << "==========================================================================\n";

	/* Return resources */
	delete _categorySums; 
	_file.close(); 
}

bool CashRegister::registerItem(int category, const char * articleName, double amount)
{
	if (!validCategory(category)) { /* Assuming categories are 1 to _nrOfCategories (including) */
		return false; /* Invalid category */
	}

	_categorySums[category - 1] += amount; /* Add to category's sum */
	_batchTotal += amount;

	/* Write register */
	registerItemWrite(category, articleName, amount);
	
	return true;
}

bool CashRegister::validCategory(int category)
{
	return (category > 0 || category <= _nrOfCategories); /* Assuming categories are 1 to _nrOfCategories (including) */
}

void CashRegister::registerItemWrite(int category, const char * articleName, double amount)
{
	std::string timeNow = currentTime();;
	
	if (_file.good()) {
		_file << timeNow.c_str() << " : " << "Cat. " << category << " : " << amount << " Kr.[" << articleName << "]\n";
	}
	else {
		std::cerr << "FILE IS NOT OPEN FOR WRITING!\n";
	}
}

std::string CashRegister::currentTime() const
{
	CTime now(time(NULL));
	return now.Format("%H:%m").GetString();	 
}

std::string CashRegister::currentDate() const
{
	CTime now(time(NULL));
	return now.Format("%Y-%m-%d").GetString();
}


std::string CashRegister::currentDay() const
{
	CTime now(time(NULL));
	return now.Format("%A").GetString();
}

