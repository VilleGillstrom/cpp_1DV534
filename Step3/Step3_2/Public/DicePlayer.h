#pragma once
#include "IPlayer.h"
#include "BasePlayer.h"
#include <string>

class DicePlayer : public BasePlayer
{
public:
	explicit DicePlayer(int money); // Construct player with money 

protected:
	bool canPlayGame(IGame* game) override; // Verify that the player can play the game
	bool playSingle(int& result) override; // This will run a single iteration of the game

private:
	std::string getBetFromUser();	/* Prompt the user for a bet */
};
