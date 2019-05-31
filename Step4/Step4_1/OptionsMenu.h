/*
 * Base class for a menu that provides options
 * for the user. Add options with addMenuOption
 * with a string the will pick the options, and 
 * a function that will be called if option is
 * picked
 *
 * Ville Gillström
 */

#pragma once
#include <map>
#include <string>


#include <functional>

class OptionsMenu
{
protected:
	// Is an option in the menu
// if user enters optionText, method is called
	struct MenuOption
	{
		std::string optionText;
		std::function<void()> method;
	};
public:

	OptionsMenu(const std::string& menuTitle);								// Title of menu, displayed on top
	OptionsMenu(const std::string& menuTitle, bool isLoopingMenu);			// if isLoopingMenu  is true then an option must be set to quit looping
	~OptionsMenu() = default;
	void show();															// call to show the menu

	void addMenuOption(const std::string& userInput, MenuOption option);	// Add an option to the menu
	void setLooping(bool isLooping);										// Can be called to change looping state

protected:

	std::string _menuTitle;							// title of menu
	std::map<std::string, MenuOption> menuOptions;  // All options

	bool isValidChoice(const std::string& choice) const; // Check if a selected option is valid( in menuOptions map)
	bool _isLooping; // will loop menu while this one is true

private:
	void show_internal(); //runs the logic

};
