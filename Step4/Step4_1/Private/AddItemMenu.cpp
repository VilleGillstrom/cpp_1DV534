#include "AddItemMenu.h"
#include "CollectionRegistry.h"


AddItemMenu::AddItemMenu(CollectionRegistry& collectionRegistry) : 
OptionsMenu("Add Item Menu"),
_collectionRegistry(collectionRegistry)
{
	addMenuOption(
		'1',
		{
			"Add Stamp",
			std::bind(&AddItemMenu::AddStampFunc, this)
		}
	);
}