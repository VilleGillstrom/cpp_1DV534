#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
class CollectionRegistry;

class SortItemsMenu :public OptionsMenu
{
public:
	SortItemsMenu(CollectionRegistry& collectionRegistry);
	~SortItemsMenu() = default;



private:
	CollectionRegistry& _collectionRegistry;

	void sortByTitle()
	{
		const auto lambda = [](BaseCollectionItem * A, BaseCollectionItem * B) {return A->title() > B->title(); };
		_collectionRegistry.sortItems(lambda);
	}

	void sortByReleaseYear()
	{
		const auto lambda = [](BaseCollectionItem * A, BaseCollectionItem * B)
		{
			return A->title() > B->title();
		};
		_collectionRegistry.sortItems(lambda);
	}


};

