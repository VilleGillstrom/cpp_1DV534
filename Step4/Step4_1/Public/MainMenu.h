#pragma once
#include <iostream>
#include "CollectionRegistry.h"
#include "ShowItemByIdMenu.h"
#include <AddItemMenu.h>
#include "OptionsMenu.h"
#include "ShowItemsByTypeMenu.h"
#include "UserInputHelper.h"
#include "SharedMenuFunctions.h"

class MainMenu : public OptionsMenu
{
public:
	MainMenu(CollectionRegistry& collectionRegistry);
	~MainMenu() = default;




	void showAllItems()
	{
		std::vector<BaseCollectionItem*> items = _collectionRegistry.getAllItems();
		for (BaseCollectionItem* item : items)
		{
			std::cout << *item << std::endl;
		}
		std::cin.get();
	}

	void removeItemMenuFunc()
	{
		int itemId = UserInputHelper::getIntFromUserLoop("Enter item id to remove: ", 0, 9999);
		_collectionRegistry.removeItem(itemId);
	}
	void searchItemMenuFunc()
	{
		//int itemId = SharedMenuFunctions::
		//_collectionRegistry.removeItem(itemId);
	}



	void showShowItemByTypeMenuFunc()
	{
		_showItemsByTypeMenu.show();
	}


	CollectionRegistry& _collectionRegistry;
	

private:
	ShowItemByIdMenu _showItemByIdMenu;
	AddItemMenu _addItemMenu;
	ShowItemsByTypeMenu _showItemsByTypeMenu;
};
