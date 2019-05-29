#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
#include "SharedMenuFunctions.h"

class SearchItemMenu :
	public OptionsMenu
{
public:
	SearchItemMenu(CollectionRegistry collectionRegistry);
	~SearchItemMenu() = default;

private:

	void searchStamp()
	{
		StampItem* item = SharedMenuFunctions::makeStamp();
		_collectionRegistry.search(item);
	}

	CollectionRegistry _collectionRegistry;
};

