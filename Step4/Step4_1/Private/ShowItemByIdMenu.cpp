#include "ShowItemByIdMenu.h"
#include "CollectionRegistry.h"
#include <iostream>


ShowItemByIdMenu::ShowItemByIdMenu(CollectionRegistry& collectionRegistry) : _collectionRegistry(collectionRegistry)
{

	choiceCBMap.insert({
		'1',
		{
		}
	});
}

void ShowItemByIdMenu::show()
{
	int id;
	do
	{
		std::cout << "---------- Find item ------------\n";
		std::cout << "Show item with id: ";

		std::cin >> id;
		//todo validity check
		break;
	}
	while (true);

	_collectionRegistry.showItem(id);

}
