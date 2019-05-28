#pragma once
#include <string>
#include <iostream>
#include "CollectionItems/StampItem.h"
#include "UserInputHelper.h"

class CollectionRegistry;
class ItemBuilderFromUser
{
public:
	ItemBuilderFromUser() {};


	BaseCollectionItem* build()
	{
		StampItem* item = new StampItem();

		std::string title = UserInputHelper::getStringFromUser("Title: ");
		std::string note = UserInputHelper::getStringFromUser("Note: ");
		int releaseYear = UserInputHelper::getIntFromUser("Release year: ", 0, 9999);

		item->setTitle(title);
		item->setNote(note);
		item->setRelaseYear(releaseYear);
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
	ItemBuilderFromUser UserIemCreator;
	CollectionRegistry& _collectionRegistry;
};





