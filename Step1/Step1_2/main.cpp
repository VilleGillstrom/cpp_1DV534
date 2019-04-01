#include <atltime.h>
#include <iostream>
#include "CashRegister.h"
#include "App.h"

using std::move;

using ATL::CTime;


int main() {
	CashRegister cash("Register.txt", 5);
	App app(move(cash)); /* Let app take control over the cash register */
	app.run();
}