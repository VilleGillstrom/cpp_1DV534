#pragma once
#include "IPlayer.h"
class BasePlayer : public IPlayer
{
public:

	BasePlayer(int money, int betAmount);		// Create character with money and how much to bet per play
	virtual ~BasePlayer() = default;

	bool setGame(IGame* game) override;			// Set the game to be played
	bool play(int numberOfTimes) override final;// Play the game numerOfTimes times
	int getMoney() const override;				// How much money the player have
	int getBetCount() const override;			// Get how many time bet has been made



protected:
	virtual bool canPlayGame(IGame* game) = 0;
	virtual bool playSingle(int& result) = 0;	// Play one iteration the the game, result is money won/lost

	IGame* _game;								// The game being played
	int _money;									// Amount of money
	int _betCount;								// How many times play has been done
	int _betAmount;								// How much to bet per play

};

