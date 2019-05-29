#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
#include "SharedMenuFunctions.h"

class AddItemMenu : public OptionsMenu
{
public:

	AddItemMenu(CollectionRegistry& collectionRegistry);
	~AddItemMenu() = default;





private:
	CollectionRegistry& _collectionRegistry;
	template<typename T>
	void addItem()
	{
		_collectionRegistry.addItem(SharedMenuFunctions::make<T>());
	}

};

