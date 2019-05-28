#pragma once
#include <string>
#include <iostream>


class UserInputHelper
{
public:
	static int getIntFromUser(const std::string& promptStr, int min, int max);
	static std::string getStringFromUser(const std::string& promptStr);
};
