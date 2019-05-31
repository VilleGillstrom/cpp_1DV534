#pragma once

#include <vector>
#include "CollectionItems/BaseCollectionItem.h"
#include "IItemCollectionStorage.h"
#include <utility>
#include "CollectionItems/StampItem.h"
#include <functional>
#include <map>
#include "MovieItem.h"


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

	void saveReg();
	void loadReg();

	std::vector<int> getItemConstructors();
	std::vector<BaseCollectionItem*> getItemsOfType(const std::string& itemType);
	BaseCollectionItem* getItem(int itemId) const;
	std::vector<BaseCollectionItem*> getAllItems() const;
	BaseCollectionItem* search(BaseCollectionItem* searchItem);
	void sortItems(const std::function<bool(BaseCollectionItem*, BaseCollectionItem*)>& predicate);




private:
	bool assignId(BaseCollectionItem* item);

	std::vector<BaseCollectionItem*> _inMemoryItems;
	IItemCollectionStorage* _storage;
};
