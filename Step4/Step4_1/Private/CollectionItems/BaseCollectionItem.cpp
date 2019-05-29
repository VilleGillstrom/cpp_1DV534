#include <CollectionItems/BaseCollectionItem.h>






BaseCollectionItem::BaseCollectionItem(const std::string& itemTypeName) : _itemTypeName(itemTypeName)
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

int BaseCollectionItem::itemId() const
{
	return _itemId;
}
