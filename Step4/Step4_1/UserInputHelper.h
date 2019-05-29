#pragma once
#include <string>
#include <iostream>


class UserInputHelper
{
public:
	static bool getIntFromUser(int min, int max, int& number);
	static int getIntFromUserLoop(const std::string& promptStr, int min, int max);
	static std::string getStringFromUser(const std::string& promptStr);
};
