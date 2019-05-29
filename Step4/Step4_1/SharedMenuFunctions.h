#pragma once
#include "CollectionItems/StampItem.h"
#include "UserInputHelper.h"
#include "MovieItem.h"


class SharedMenuFunctions
{

public:
	static StampItem* makeStamp()
	{
		std::string title = UserInputHelper::getStringFromUser("Title: ");
		std::string note = UserInputHelper::getStringFromUser("Note: ");
		int releaseYear = UserInputHelper::getIntFromUserLoop("Release year: ", 0, 9999);
		StampItem* item = new StampItem(title, note, releaseYear);
		return item;
	}

	static MovieItem* makeMovie()
	{
		std::string title = UserInputHelper::getStringFromUser("Title: ");
		std::string studio = UserInputHelper::getStringFromUser("Studio: ");
		int releaseYear = UserInputHelper::getIntFromUserLoop("Release year: ", 0, 9999);
		int price = UserInputHelper::getIntFromUserLoop("Price: ", 0, 9999);
		MovieItem* item = new MovieItem(title, studio, releaseYear, price);
		return item;
	}
};
