#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"

class AddItemMenu : public OptionsMenu
{
public:

	AddItemMenu(CollectionRegistry& collectionRegistry);
	~AddItemMenu() = default;


	void addStampFunc();
	void addMovieFunc();


private:
	CollectionRegistry& _collectionRegistry;

};

