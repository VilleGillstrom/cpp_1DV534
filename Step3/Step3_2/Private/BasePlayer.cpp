#include "BasePlayer.h"
#include <iostream>


BasePlayer::BasePlayer(int money, int _betAmount) : _money(money), _betCount(0), _betAmount(_betAmount)
{
}


bool BasePlayer::setGame(IGame* game)
{
	if (!canPlayGame(game)) {
		return false;
	}
	_game = game;
	return true;
}

bool BasePlayer::play(int numberOfTimes)
{
	for (int i = 0; i < numberOfTimes; ++i)
	{

		// Check that player has enough money
		if(_money - _betAmount < 0)
		{
			std::cout << "Player doesn't have enough money to play!" << std::endl;
			return true;
		}

		system("CLS"); /* Clear screen */
		std::cout << "Money: " << _money << ", Rounds left: " << numberOfTimes - i << std::endl << std::endl;

		/* We are able to make a bet */
		_betCount++;

		/* Store the result of the play in result */
		int result;
		if(!playSingle(result))
		{
			return false;
		}


		_money += result;


	}

	return true;
}

int BasePlayer::getMoney() const
{
	return _money;
}

int BasePlayer::getBetCount() const
{
	return _betCount;
}
