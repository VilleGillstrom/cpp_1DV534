#pragma once
#include <iostream>
#include "CollectionRegistry.h"
#include "ShowItemByIdMenu.h"
#include <AddItemMenu.h>
#include "OptionsMenu.h"
#include "ShowItemsByTypeMenu.h"
#include "UserInputHelper.h"
#include "SharedMenuFunctions.h"
#include "SearchItemMenu.h"
#include "SortItemsMenu.h"

class MainMenu : public OptionsMenu
{
public:
	MainMenu(CollectionRegistry& collectionRegistry);
	~MainMenu() = default;

private:
	CollectionRegistry& _collectionRegistry;		// Reference to the CollectionRegistry acted on by menu functions

	ShowItemByIdMenu _showItemByIdMenu;				// Menu to show an item by its itemId
	AddItemMenu _addItemMenu;						// Menu to add an item
	ShowItemsByTypeMenu _showItemsByTypeMenu;		// Menu to show all items by id
	SearchItemMenu _searchItemsMenu;				// Menu to search for an item by all properties
	SortItemsMenu _sortItemsMenu;					// Menu to sort items by properties



	void showAllItems() const;						// Function to show all items in _collectionRegistry
	void removeItemMenuFunc();						// Function to remove an item by its id
};
