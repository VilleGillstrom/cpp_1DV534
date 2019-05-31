#include "SortItemsMenu.h"




SortItemsMenu::SortItemsMenu(CollectionRegistry& collectionRegistry) : OptionsMenu("Sort items Menu", false), _collectionRegistry(collectionRegistry)
{

	addMenuOption(
		"1",
		{
			"Sort by releaseYear",
			std::bind(&SortItemsMenu::sortPropertyDecided<int>, this, "releaseYear")
		}
	);
	addMenuOption(
		"2",
		{
			"Sort by title",
			std::bind(&SortItemsMenu::sortPropertyDecided<std::string>, this, "title")
		}
	);
	addMenuOption(
		"3",
		{
			"Sort by note",
			std::bind(&SortItemsMenu::sortPropertyDecided<std::string>, this, "note")
		}
	);
	addMenuOption(
		"4",
		{
			"Sort by studio",
			std::bind(&SortItemsMenu::sortPropertyDecided<std::string>, this, "studio")
		}
	);
	addMenuOption(
		"5",
		{
			"Sort by price",
			std::bind(&SortItemsMenu::sortPropertyDecided<int>, this, "price")
		}
	);

	addMenuOption(
		"6",
		{
			"Sort by song",
			std::bind(&SortItemsMenu::sortPropertyDecided<int>, this, "song")
		}
	);


	addMenuOption(
		"7",
		{
			"Sort by playlength",
			std::bind(&SortItemsMenu::sortPropertyDecided<int>, this, "playlength")
		}
	);


}


