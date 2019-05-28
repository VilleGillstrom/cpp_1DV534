#include <CollectionItems/BaseCollectionItem.h>





BaseCollectionItem::BaseCollectionItem()
{
}

BaseCollectionItem::BaseCollectionItem(const std::string& itemTypeName)
{
}

void BaseCollectionItem::setItemId(int itemId)
{
	_itemId = itemId;
}


bool BaseCollectionItem::hasItemId(int itemId) const
{
	return itemId == _itemId;
}