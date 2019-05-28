#pragma once
#include <iostream>
#include <map>
#include <functional>
#include "CollectionRegistry.h"
#include "ShowItemByIdMenu.h"
#include <AddItemMenu.h>
#include "OptionsMenu.h"

class MainMenu : public OptionsMenu
{
public:
	MainMenu(CollectionRegistry& collectionRegistry);
	~MainMenu() = default;

	void showItemMenuFunc()
	{
		_showItemByIdMenu.show();
	}

	void showAddItemMenuFunc()
	{
		_addItemMenu.show();
	}

	void removeItemMenuFunc()
	{
		int itemId = UserInputHelper::getIntFromUser("Enter item id to remove: ", 0, 9999);
		_collectionRegistry.removeItem(itemId);
	}


	CollectionRegistry& _collectionRegistry;
	

private:
	ShowItemByIdMenu _showItemByIdMenu;
	AddItemMenu _addItemMenu;
};
