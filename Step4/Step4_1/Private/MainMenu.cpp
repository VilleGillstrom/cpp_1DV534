#include "MainMenu.h"


MainMenu::MainMenu(CollectionRegistry& collectionRegistry) : 
OptionsMenu("Main Menu", true),
_collectionRegistry((collectionRegistry)),
_addItemMenu( _collectionRegistry ),
_showItemByIdMenu(_collectionRegistry),
_showItemsByTypeMenu(_collectionRegistry),
_searchItemsMenu(_collectionRegistry),
_sortItemsMenu(_collectionRegistry){

	addMenuOption("1",
		{
			"Show item by item ID", 
			std::bind(&ShowItemByIdMenu::show, _showItemByIdMenu)
		}
	);

	addMenuOption("2",
		{
			"Show all items ",
			std::bind(&MainMenu::showAllItems, this)

		}
	);
	addMenuOption("3",
		{
		"Show all by type",
			std::bind(&ShowItemsByTypeMenu::show, _showItemsByTypeMenu)
	}
	);



	addMenuOption(
		"4",
		{
			"Add item",
			std::bind(&AddItemMenu::show, _addItemMenu)
		}
	);


	addMenuOption("5",
		{
			"Remove item",
			std::bind(&MainMenu::removeItemMenuFunc, this)

		}
	);

	addMenuOption("6", 
		{
		"search for item",
			std::bind(&SearchItemMenu::show, _searchItemsMenu)

	}
	);
	
	
	addMenuOption("7",
		{
			"sort items",
			std::bind(&SortItemsMenu::show, _sortItemsMenu)

		}
	);


	addMenuOption("q", { "Exit", std::bind(&OptionsMenu::setLooping, this, false) });
}



