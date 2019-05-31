/*
 * UI for showing items by type
 * 
 * Ville Gillström
 */


#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"

class ShowItemsByTypeMenu : public OptionsMenu
{
public:
	ShowItemsByTypeMenu(CollectionRegistry& collectionRegistry);
	~ShowItemsByTypeMenu() = default;

private:
	void showAllItemsOfType(const std::string& itemType) const;
	CollectionRegistry& _collectionRegistry;
};

