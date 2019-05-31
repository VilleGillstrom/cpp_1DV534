/*
 * UI for showing item by id
 *
 * Ville Gillström
 */


#pragma once
#include <CollectionRegistry.h>
class ShowItemByIdMenu
{
public:

	ShowItemByIdMenu(CollectionRegistry& collectionRegistry);
	~ShowItemByIdMenu() = default;

	void show();

private:
	CollectionRegistry& _collectionRegistry;

};

