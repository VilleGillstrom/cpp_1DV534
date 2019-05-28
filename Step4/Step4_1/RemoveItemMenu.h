#pragma once

#include "OptionsMenu.h"
#include "CollectionRegistry.h"

class RemoveItemMenu : public OptionsMenu
{
public:
	RemoveItemMenu(CollectionRegistry collectionRegistry);

	~RemoveItemMenu() = default;



	CollectionRegistry& _collectionRegistry;
};

