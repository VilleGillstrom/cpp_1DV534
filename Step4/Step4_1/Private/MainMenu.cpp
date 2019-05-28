#include "..\Public\MainMenu.h"


MainMenu::MainMenu(CollectionRegistry& collectionRegistry) : 
OptionsMenu("Main Menu", true),
_collectionRegistry((collectionRegistry)),
_addItemMenu( _collectionRegistry ),
_showItemByIdMenu(_collectionRegistry)
{

	addMenuOption('1',
		{
			"Show item by item ID", 
			std::bind(&MainMenu::showItemMenuFunc, this)
		}
	);

	addMenuOption('2',
		{
			"Show all items ",
			std::bind(&CollectionRegistry::showItems, _collectionRegistry)

		}
	);
	addMenuOption('3', {"Show all by type"});



	addMenuOption(
		'4',
		{
			"Add item",
			std::bind(&MainMenu::showAddItemMenuFunc, this)
		}
	);


	addMenuOption('5', 
		{
			"Remove item",
			std::bind(&MainMenu::removeItemMenuFunc, this)

		}
	);
	addMenuOption('6', {"search for item "});
	
	
	addMenuOption('7', 
		{
			"sort items",
			std::bind(&CollectionRegistry::sortItems, _collectionRegistry)

		}
	);


	addMenuOption('q', { "Exit", std::bind(&OptionsMenu::setLooping, this, false) });
}



