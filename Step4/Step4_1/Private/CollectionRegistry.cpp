#include <CollectionRegistry.h>
#include "CollectionItems/StampItem.h"
#include <iostream>
#include <algorithm>


CollectionRegistry::CollectionRegistry() : CollectionRegistry(nullptr)
{
	//todo TEMPORARY FOR TESTING, REMEMBER TO REMOVE ME

	
}


CollectionRegistry::CollectionRegistry(IItemCollectionStorage* itemStorage) :_storage(itemStorage)
{
	addItem(new StampItem("1 StampItemTitle", "1 A Note", 1992));
	addItem(new StampItem("2 StampItemTitle", "2 A Note", 2003));
}

CollectionRegistry::~CollectionRegistry()
{
}

void CollectionRegistry::addItem(BaseCollectionItem* item)
{
	assignId(item);
	_inMemoryItems.push_back(item);
}

void CollectionRegistry::removeItem(int itemId)
{
	std::vector<BaseCollectionItem*>::const_iterator iter;
	if (findItemByItemId(itemId, iter))
	{
		delete *iter;
		_inMemoryItems.erase(iter);
	}
}

void CollectionRegistry::removeAllItems()
{
	_inMemoryItems.clear();
}


bool CollectionRegistry::findItemByItemId(int itemId, std::vector<BaseCollectionItem*>::const_iterator& iter) const
{
	auto pred = [itemId](const BaseCollectionItem* item) { return item->hasItemId(itemId); };
	iter = std::find_if(_inMemoryItems.begin(), _inMemoryItems.end(), pred);
	return iter != _inMemoryItems.cend();
}

void CollectionRegistry::showItem(int itemId) const
{
	std::vector<BaseCollectionItem*>::const_iterator iter;
	if(findItemByItemId(itemId, iter))
	{
		std::cout << *iter;
	}

}

void CollectionRegistry::showItems()
{
	for (BaseCollectionItem* item : _inMemoryItems)
	{
		std::cout << *item;
	}
}

void CollectionRegistry::sortItems()
{
}


void CollectionRegistry::saveReg()
{
	_storage->save(_inMemoryItems);
}

void CollectionRegistry::loadReg()
{
	_inMemoryItems = _storage->load();
}

void CollectionRegistry::assignId(BaseCollectionItem* item)
{
	for (int freeId = 0; freeId < INT_MAX; freeId++)
	{
		bool foundFreeId = true; // Assume freeId is free
		for (auto _item : _inMemoryItems)
		{
			// Test if freeId is free
			if (_item->hasItemId(freeId))
			{
				//keep looking for an id
				foundFreeId = false;
				break;
			}
		}

		if (foundFreeId)
		{
			item->setItemId(freeId);
			break;
		}
	}
}
