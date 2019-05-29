#pragma once
#include <map>
#include <string>
#include <functional>

class OptionsMenu
{
public:

	struct MenuOption
	{
		std::string optionText;
		std::function<void()> method;
	};

	OptionsMenu(const std::string& menuTitle);
	OptionsMenu(const std::string& menuTitle, bool isLoopingMenu);
	~OptionsMenu() = default;
	void show();
	void show_internal();

	//void addMenuOption(char userInput, MenuOption option);
	void addMenuOption(const std::string& userInput, MenuOption option);


	void setLooping(bool isLooping);

protected:
	std::string _menuTitle;
	std::map<std::string, MenuOption> menuOptions;

	bool isValidChoice(const std::string& choice) const;
	bool _isLooping; // will loop menu while this one is true
};
