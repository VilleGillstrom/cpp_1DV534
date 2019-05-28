#pragma once
#include "BaseGame.h"


class DiceGame : public BaseGame
{
public:
	DiceGame();
	virtual ~DiceGame() = default;
	int play(char* bet, int amount) override; // Play game with bet for amount money

private:
	void printResult(bool won, const char* roll, const char* bet, int amount) const; // Print result for user
};
