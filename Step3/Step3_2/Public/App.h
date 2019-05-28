#pragma once
#include <string>
#include <map>


class App
{


public:
	
	App();
	~App() = default;

	void openMenu();														// Let the user change settings
	int getNumberOfRounds();												// Get user input for _numberOfRounds
	int getStartMoney();													// Get user input for _startMoney
	int getSelectedGame();

	int run();																// Runs the app, will play game _numberOfRounds times, or exit if chosen in openMenu
private:
	int getIntFromUser(const std::string& promptStr, int min, int max);		// Helper class to get int from user


	int _numberOfRounds;													// How many round the player will play
	int _startMoney;														// How much money the player will start with
	int _selectedGame;														// The game selected
	bool _isDone;															// True when want to terminate app 

};

