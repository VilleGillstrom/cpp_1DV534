#pragma once

#include <vector>
#include "CollectionItems/BaseCollectionItem.h"
#include "IItemCollectionStorage.h"
#include <utility>

class Foobar
{
public:
	~Foobar() = default;
};

class CollectionRegistry
{
public:
	CollectionRegistry();
	CollectionRegistry(IItemCollectionStorage* itemStorage);
	~CollectionRegistry();

	// Not sure how to handle unique_ptr member with copy constructor, possibly make deep copies of items? 
	CollectionRegistry(const CollectionRegistry& other)
		: 
		  _inMemoryItems(other._inMemoryItems),
		  _storage(other._storage)
	{
	}

	CollectionRegistry(CollectionRegistry&& other) noexcept
		: _inMemoryItemsNew(std::move(other._inMemoryItemsNew)),
		  _inMemoryItems(std::move(other._inMemoryItems)),
		  _storage(other._storage)
	{
	}


	bool addItem(BaseCollectionItem* item); // Add the item to the register, takes control of item
	void removeItem(int itemId);
	void removeAllItems();
	bool findItemByItemId(int itemId, std::vector<BaseCollectionItem*>::const_iterator& iter) const;
	void showItem(int itemId) const;
	void showItems();
	void sortItems();

	void saveReg();
	void loadReg();

	std::vector<int> getItemConstructors();
private:
	bool assignId(BaseCollectionItem* item);


	std::vector<std::unique_ptr<BaseCollectionItem>> _inMemoryItemsNew;

	std::vector<BaseCollectionItem*> _inMemoryItems;
	IItemCollectionStorage* _storage;
};
