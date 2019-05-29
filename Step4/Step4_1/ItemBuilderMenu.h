#pragma once
#include <string>
#include <iostream>
#include "CollectionItems/StampItem.h"
#include "UserInputHelper.h"

class CollectionRegistry;
class ItemMakerFromUser
{
public:
	ItemMakerFromUser() {};

	BaseCollectionItem* make()
	{

		std::string  title = UserInputHelper::getStringFromUser("Title: ");
		std::string note = UserInputHelper::getStringFromUser("Note: ");
		int releaseYear = UserInputHelper::getIntFromUser("Release year: ", 0, 9999);
		StampItem* item = new StampItem(title, note, releaseYear);

		return item;
	}
};

class ItemBuilderMenu
{
public:
	ItemBuilderMenu(CollectionRegistry& collectionRegistry);
	~ItemBuilderMenu() = default;


	virtual void show();

private:
	ItemMakerFromUser UserIemCreator;
	CollectionRegistry& _collectionRegistry;
};





