#include "OptionsMenu.h"
#include <iostream>


OptionsMenu::OptionsMenu(const std::string& menuTitle) : OptionsMenu(menuTitle, false)
{
}

OptionsMenu::OptionsMenu(const std::string& menuTitle, bool isLoopingMenu) :
	_menuTitle(menuTitle),
	_isLooping(isLoopingMenu)
{
}



void OptionsMenu::show()
{
	do
	{
		show_internal();;
	} while (_isLooping);
}

void OptionsMenu::show_internal()
{
	std::string choice;
	MenuOption ChosenMenuOption;

	while (true)
	{
		system("CLS");
		std::cout << _menuTitle << "\n";

		// Show the various options
		for (auto option : menuOptions)
		{
			std::string optionInput = option.first;
			MenuOption menuOption = option.second;
			std::cout << optionInput << ") " << menuOption.optionText << std::endl;
		}
		std::cout << std::endl;

		std::cin.clear();
		std::cin >> choice;
		std::cin.ignore();

		if (isValidChoice(choice))
		{
			auto option = menuOptions.find(choice);
			if (option != menuOptions.end())
			{
				ChosenMenuOption = option->second;
			}
			else
			{
				std::cerr << "Bad option passed validation incorrectly, exiting.";
				std::exit(EXIT_FAILURE);
			}
			break;
		}

		std::cout << "Invalid choice\n";
		std::cin.get();
	}

	if (ChosenMenuOption.method)
	{
		ChosenMenuOption.method();
	}
	else
	{
		std::cerr << "Bad function! Bad programmer!";
		std::exit(EXIT_FAILURE);
	}
}


//void OptionsMenu::addMenuOption(char userInput, MenuOption option)
//{
//	addMenuOption(std::to_string(userInput), option);
//}

void OptionsMenu::addMenuOption(const std::string& userInput, MenuOption option)
{
	menuOptions.insert({ userInput, option });
}


void OptionsMenu::setLooping(bool isLooping)
{
	_isLooping = isLooping;
}

bool OptionsMenu::isValidChoice(const std::string& choice) const
{
	for (auto o : menuOptions)
	{
		if (o.first == choice)
		{
			return true;
		}
	}
	return false;
}
