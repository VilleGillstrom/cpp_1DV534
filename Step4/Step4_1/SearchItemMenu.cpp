#include "SearchItemMenu.h"
#include "AddItemMenu.h"
#include "CollectionRegistry.h"

SearchItemMenu::SearchItemMenu(CollectionRegistry& collectionRegistry) : OptionsMenu("Add Item Menu"),
_collectionRegistry(collectionRegistry)
{

	addMenuOption(
		"1",
		{
			"Search Stamp",
			std::bind(&SearchItemMenu::search<StampItem>, this)
		}
	);

	addMenuOption(
		"2",
		{
			"Search Movie",
			std::bind(&SearchItemMenu::search<MovieItem>, this)
		}
	);
}



