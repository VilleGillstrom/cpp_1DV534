/*
 * UI for searching for an item
 *
 * Ville Gillström
 */

#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
#include "SharedMenuFunctions.h"

class SearchItemMenu :
	public OptionsMenu
{
public:
	SearchItemMenu(CollectionRegistry& collectionRegistry);
	~SearchItemMenu() = default;

private:

	template <typename T>
	void search()
	{
		T* item = SharedMenuFunctions::make<T>()		;
		BaseCollectionItem* foundItem = _collectionRegistry.search(item);

		system("CLS");
		if (foundItem)
		{
			std::cout << "Found:\n" << *foundItem << std::endl;
		}
		else
		{
			std::cout << "Didn't find item.\n";
		}
		std::cin.get();
	}

	CollectionRegistry& _collectionRegistry;
};
