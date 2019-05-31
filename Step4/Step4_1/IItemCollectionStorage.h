#pragma once

#include <vector>
#include "Public/CollectionItems/BaseCollectionItem.h"

class IItemCollectionStorage
{
public:
	virtual void save(const std::vector<BaseCollectionItem*>& items, const std::string& filename) const = 0;
	virtual  std::vector<BaseCollectionItem*> load(const std::string& filename) = 0;
};
