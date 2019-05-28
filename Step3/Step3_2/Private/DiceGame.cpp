#include <DiceGame.h>
#include <cstdlib>
#include <string>
#include <iostream>

const int DICE_GAME_ID = 111;

DiceGame::DiceGame() : BaseGame(DICE_GAME_ID)
{
}


int DiceGame::play(char* bet, int amount)
{
	int roll = (rand() % 6) + 1;
	const std::string rollStr = std::to_string(roll);
	const bool won = bet == rollStr;

	// Compute the return value
	const int ret = won ? amount * 6 : -amount;

	// Print for user
	printResult(won, rollStr.c_str(), bet, ret);
	
	return ret;;
}

void DiceGame::printResult(bool won, const char* roll, const char* bet, int amount) const
{
	std::cout << "You chose " << bet << ", dice result is " << roll << std::endl;
	std::cout << "You " << (won ? "won " : "lost ") << std::abs(amount) << " kr\n" << std::endl;
	std::cout << "Press enter to continue" << std::endl;
	std::cin.get();
	system("CLS");
}
