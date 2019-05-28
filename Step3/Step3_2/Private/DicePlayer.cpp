#include "DicePlayer.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

DicePlayer::DicePlayer(int money) : BasePlayer(money, 10)
{
}

bool DicePlayer::canPlayGame(IGame* game)
{
	// I don't like this very much
	const int DICE_GAME_ID = 111;
	return game->getID() == DICE_GAME_ID;
}

std::string DicePlayer::getBetFromUser()
{
	int bet;

	while (1)
	{
		cout << "Enter a number between 1 and 6 (inclusive): ";

		cin >> bet;
		cin.get();

		/* Check bet is valid */
		if (bet > 0 && bet < 7)
		{
			break;
		}
	}

	return std::to_string(bet);
}

bool DicePlayer::playSingle(int& result)
{
	string betStr = getBetFromUser();
	char bet[2];
	strncpy_s(bet, betStr.c_str(), 2);

	result = _game->play(bet, _betAmount);
	return true;
}


