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
			std::bind(&AddItemMenu::addItem<StampItem>, this)
		}
	);

	addMenuOption(
		"2",
		{
			"Add Movie",
			std::bind(&AddItemMenu::addItem<MovieItem>, this)
		}
	);
}

