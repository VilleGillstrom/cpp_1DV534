#pragma once
#include "IGame.h"
class BaseGame : public IGame
{
public:
	virtual ~BaseGame() = default;

	int getID() const override;		// Get _ID

protected:
	BaseGame(int id);				// Called by derived class, sets _ID

	const int _ID;
};

