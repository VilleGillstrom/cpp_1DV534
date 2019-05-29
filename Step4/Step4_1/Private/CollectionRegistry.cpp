#include <CollectionRegistry.h>
#include "CollectionItems/StampItem.h"
#include <iostream>
#include <algorithm>
#include "FileItemCollectionStorage.h"

using std::unique_ptr;
CollectionRegistry::CollectionRegistry() : CollectionRegistry(nullptr)
{

	
}


CollectionRegistry::CollectionRegistry(IItemCollectionStorage* itemStorage) :_storage(itemStorage)
{
}

CollectionRegistry::~CollectionRegistry()
{
}

bool CollectionRegistry::addItem(BaseCollectionItem* item)
{
	if(!assignId(item))
		return false;
	
	_inMemoryItems.push_back(item);
	return true;

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


BaseCollectionItem* CollectionRegistry::getItem(int itemId) const 
{
	std::vector<BaseCollectionItem*>::const_iterator iter;
	if (findItemByItemId(itemId, iter))
	{
		return *iter;
	}
	return nullptr;
}

std::vector<BaseCollectionItem*> CollectionRegistry::getAllItems() const
{
	return _inMemoryItems;
}

void CollectionRegistry::search(BaseCollectionItem* item)
{
	for(auto _item : _inMemoryItems)
	{
		item->isSameAs(_item);
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

std::vector<BaseCollectionItem*> CollectionRegistry::getItemsOfType(const std::string& itemType)
{
	std::vector<BaseCollectionItem*> items;
	for(BaseCollectionItem* item : _inMemoryItems)
	{
		if(item->getItemTypeName() == itemType)
		{
			items.push_back(item);
		}
	}
	return items;
}



bool CollectionRegistry::assignId(BaseCollectionItem* item)
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
			return true;
		}
	}
	return false;
}
