#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
#include <iostream>

class ShowItemsByTypeMenu : public OptionsMenu
{
public:
	ShowItemsByTypeMenu(CollectionRegistry& collectionRegistry);
	~ShowItemsByTypeMenu() = default;

private:
	void showAllItemsOfType(const std::string& itemType);

	CollectionRegistry& _collectionRegistry;
};

