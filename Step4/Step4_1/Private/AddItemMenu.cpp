#include "AddItemMenu.h"
#include "MovieItem.h"
#include "UserInputHelper.h"
#include "CollectionItems/StampItem.h"
#include "SharedMenuFunctions.h"


AddItemMenu::AddItemMenu(CollectionRegistry& collectionRegistry) : 
OptionsMenu("Add Item Menu"),
_collectionRegistry(collectionRegistry)
{

	addMenuOption(
		"1",
		{
			"Add Stamp",
			std::bind(&AddItemMenu::addStampFunc, this)
		}
	);

	addMenuOption(
		"2",
		{
			"Add Movie",
			std::bind(&AddItemMenu::addStampFunc, this)
		}
	);
}

void AddItemMenu::addStampFunc()
{
	StampItem* item = SharedMenuFunctions::makeStamp();
	_collectionRegistry.addItem(item);
}

void AddItemMenu::addMovieFunc()
{
	MovieItem* item = SharedMenuFunctions::makeMovie();
	_collectionRegistry.addItem(item);
}