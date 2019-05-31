/*
 * Input helpers
 *
 * Ville Gillström
 */

#pragma once
#include <string>
#include <iostream>


class UserInputHelper
{
public:
	static bool getIntFromUser(int min, int max, int& number);						// Get an integer between min and max, returns true on success
	static int getIntFromUserLoop(const std::string& promptStr, int min, int max);	// Get an integer between min and max looping till success
	static std::string getStringFromUser(const std::string& promptStr);				// Get a string from user
};
