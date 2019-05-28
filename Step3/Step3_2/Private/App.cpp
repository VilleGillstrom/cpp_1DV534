#include <App.h>
#include <ostream>
#include <iostream>
#include "DicePlayer.h"
#include "DiceGame.h"

using std::cin;

App::App() : _isDone(false), _startMoney(100),
_numberOfRounds(10), _selectedGame(1)
{
}


int App::getIntFromUser(const std::string& promptStr, int min, int max)
{
	system("CLS");

	int number;
	while (1)
	{
		std::cout << promptStr << std::endl;
		cin >> number;

		// If valid number, break and return
		if (min <= number && number <= max)
		{
			cin.get(); // Remove the trailing newline
			break;
		}
		system("CLS");

		std::cout << "Invalid number! Must be larger or equal to " << min << " and less or equal to " << max << std::endl;
		cin.get();
	}
	return number;
}

int App::getNumberOfRounds()
{
	return getIntFromUser("Enter number of rounds:", 0, 9999);
}

int App::getStartMoney()
{
	return getIntFromUser("Enter amount of start money:", 0, 999999);
}

int App::getSelectedGame()
{
	return getIntFromUser("1) DiceGame\n2)Placeholder\n3)Placeholder\n\nSelect Game:", 1,1);
}

void App::openMenu()
{
	/* Choosing option 1 will set this to false and thus returning */
	bool isConfiguring = true;
	while (isConfiguring)
	{
		system("CLS");

		std::cout << "Start money: " << _startMoney << ", rounds: " << _numberOfRounds << ", Selected game: " << _selectedGame << std::endl << std::endl;

		std::cout << "1) Play the specified number of rounds and present the results." << std::endl;
		std::cout << "2) Enter the number of rounds to play in Option 1." << std::endl;
		std::cout << "3) Enter how much money the player should have at the beginnng." << std::endl;
		std::cout << "4) Select game." << std::endl;
		std::cout << "5) Quit the program." << std::endl << std::endl;
		std::cout << "Choice: ";

		char choice;
		//	cin.ignore(INT_MAX);
		std::cin.get(choice);
		switch (choice)
		{
		case('1'):
			{
				isConfiguring = false;
				break;
			}
		case('2'):
			{
				_numberOfRounds = getNumberOfRounds();
				break;
			}
		case('3'):
			{
				_startMoney = getStartMoney();
				break;
			}
		case('4'):
			{
				_selectedGame = getSelectedGame();
				break;
			}
		case('5'):
			{
				_isDone = true;
				isConfiguring = false;
				break;
			}
		default:
			{
				std::cout << "Invalid option";
				cin.get();
			}
		}
	}
}

int App::run()
{
	openMenu();

	//Check if user decided to close app
	if (_isDone)
	{
		return 0;
	}

	const int a = DiceGame().getID();


	IGame* game = nullptr;
	IPlayer* player = nullptr;


	// Create the correct game
	switch (_selectedGame)
	{
	case 1:
		{
			game = new DiceGame();
			player = new DicePlayer(_startMoney);
			break;
		}
	default:
		{
		break;
		}
	}

	if(game && player)
	{
		//Play game
		player->setGame(game);
		player->play(_numberOfRounds);

		std::cout << "After " << player->getBetCount() << " number of rounds, the player has " << player->getMoney() <<
			" SEK left!" << std::endl;
	} else
	{
		std::cout << "Unable to start game";
	}



	//Free memory
	delete game;
	delete player;

	return 0;
}
