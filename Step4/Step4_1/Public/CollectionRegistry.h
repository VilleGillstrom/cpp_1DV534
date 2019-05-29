#pragma once

#include <vector>
#include "CollectionItems/BaseCollectionItem.h"
#include "IItemCollectionStorage.h"
#include <utility>
#include "CollectionItems/StampItem.h"

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




	bool addItem(BaseCollectionItem* item); // Add the item to the register, takes control of item
	void removeItem(int itemId);
	void removeAllItems();
	bool findItemByItemId(int itemId, std::vector<BaseCollectionItem*>::const_iterator& iter) const;
	void showItems();
	void sortItems();

	void saveReg();
	void loadReg();

	std::vector<int> getItemConstructors();
	std::vector<BaseCollectionItem*> getItemsOfType(const std::string& itemType);
	BaseCollectionItem* getItem(int itemId) const;
	std::vector<BaseCollectionItem*> getAllItems() const;
	void search(BaseCollectionItem* item);
private:
	bool assignId(BaseCollectionItem* item);

	std::vector<BaseCollectionItem*> _inMemoryItems;
	IItemCollectionStorage* _storage;
};
