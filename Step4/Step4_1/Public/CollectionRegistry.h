#pragma once

#include <vector>
#include "CollectionItems/BaseCollectionItem.h"
#include "IItemCollectionStorage.h"
#include "FileItemCollectionStorage.h"


class CollectionRegistry
{
public:
	CollectionRegistry();
	CollectionRegistry(IItemCollectionStorage* itemStorage);
	~CollectionRegistry();


	void addItem(BaseCollectionItem* item);
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
	void assignId(BaseCollectionItem* item);


	std::vector<BaseCollectionItem*> _inMemoryItems;
	IItemCollectionStorage* _storage;
};
