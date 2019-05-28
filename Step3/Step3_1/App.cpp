#include "App.h"
#include "Texthandler.h"
#include <iostream>


App::App()
{
}


App::~App()
{
}

using namespace std;
int App::run()
{

	Texthandler textHandler("Stories.txt", 40);

	const char* foo = textHandler.text(4);
	//foo[2] = '1';

	int maximalNumberOfTexts = 20;
	int check[] = { 6, 207, 424, 113, 148, 84, 105 };				// For test purpose

	try {
		Texthandler th("Stories.txt", maximalNumberOfTexts); // Assumes the text file in the project folder

		if (th.nrOfTexts() != check[0]) {
			cout << "Number of saved stories is " << th.nrOfTexts()
				<< " but should be " << check[0] << "!" << endl;
			cout << "Program cancelled!" << endl;
			return -1;
		}

		if (th.maxNrOfTexts() != maximalNumberOfTexts) {
			cout << "Number of stories that can be saved into the texthandler is " << th.maxNrOfTexts()
				<< " but should be " << maximalNumberOfTexts << "!" << endl;
			cout << "Program cancelled!" << endl;
			return -1;
		}

		int currentNrOfTexts = th.nrOfTexts();
		int nrOfChars;

		for (int i = 0; i < currentNrOfTexts; ++i) {
			nrOfChars = (int)strlen(th.text(i));
			cout << "Text nr " << i + 1 << " contains " << nrOfChars << " characters.\n";

			if (nrOfChars != check[i + 1]) {
				cout << "ERROR: Length of text should have been " << check[i]
					<< "!" << endl;
			}
			cout << "----------------------------------------------------\n";
			cout << th.text(i) << endl << endl;
		}

		if (th.text(6) != 0)
			cout << "ERROR: You should return NULL when trying to retrieve a text that does not exist!" << endl;
		cout << "Press Enter to quit the program";

		char buf[20];
		cin.getline(buf, 20);
	}
	catch (...) {
		// Catches all... If any exception thrown in Texthandler class, it will be caught here.
		cout << "An error occured during program execution. Program ended!" << endl;
		return 1;
	}
	return 0;
}
