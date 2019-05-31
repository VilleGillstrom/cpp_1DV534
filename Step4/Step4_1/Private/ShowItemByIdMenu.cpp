#include "ShowItemByIdMenu.h"
#include "CollectionRegistry.h"
#include <iostream>
#include "UserInputHelper.h"


ShowItemByIdMenu::ShowItemByIdMenu(CollectionRegistry& collectionRegistry) : _collectionRegistry(collectionRegistry)
{

	
}

void ShowItemByIdMenu::show()
{
	int id;
	std::cout << "---------- Find item ------------\n";
	std::cout << "Item id: ";
	if(UserInputHelper::getIntFromUser(0, 99999, id))
	{
		BaseCollectionItem* item = _collectionRegistry.getItem(id);
		item ? std::cout << *item : std::cout << "Item not found";
	}
	std::cin.get();
}
