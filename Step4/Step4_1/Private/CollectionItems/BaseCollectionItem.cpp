#include <CollectionItems/BaseCollectionItem.h>






BaseCollectionItem::BaseCollectionItem(const std::string& itemTypeName, const std::string& title) : _itemTypeName(itemTypeName), _title(title)
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
