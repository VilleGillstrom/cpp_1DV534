#pragma once

#include <vector>
#include "Public/CollectionItems/BaseCollectionItem.h"

class IItemCollectionStorage
{
public:
	virtual void save(const std::vector<BaseCollectionItem*>& vector) = 0;
	virtual  std::vector<BaseCollectionItem*> load() = 0;
};
