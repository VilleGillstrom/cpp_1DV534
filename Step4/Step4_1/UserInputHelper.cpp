
#include <UserInputHelper.h>

int UserInputHelper::getIntFromUser(const std::string& promptStr, int min, int max)
{
	system("CLS");

	int number;
	while (1)
	{
		std::cout << promptStr << std::endl;
		std::cin >> number;

		// If valid number, break and return
		if (min <= number && number <= max)
		{
			std::cin.get(); // Remove the trailing newline
			break;
		}
		system("CLS");

		std::cout << "Invalid number! Must be larger or equal to " << min << " and less or equal to " << max << std::
			endl;
		std::cin.get();
	}
	return number;
}

std::string UserInputHelper::getStringFromUser(const std::string& promptStr)
{
	system("CLS");
	std::string userInputStr;
	std::cout << promptStr << std::endl;
	std::cin >> userInputStr;
	return userInputStr;
}
