
#include <UserInputHelper.h>

bool UserInputHelper::getIntFromUser(int min, int max, int& number)
{
	std::cin >> number;
	if(std::cin.bad())
	{
		std::cin.clear();
		return false;
	}

	// Check if in valid range
	if (min <= number && number <= max)
	{
		std::cin.get(); // Remove the trailing newline
		return true;
	}
	return false;
}

int UserInputHelper::getIntFromUserLoop(const std::string& promptStr, int min, int max)
{
	system("CLS");
	int number;
	while (1)
	{
		std::cout << promptStr << std::endl;
		if (getIntFromUser(min, max, number))
		{
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
