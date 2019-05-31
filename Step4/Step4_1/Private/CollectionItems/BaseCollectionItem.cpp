#include <CollectionItems/BaseCollectionItem.h>






BaseCollectionItem::BaseCollectionItem(const std::string& title) : _title(title)
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

std::string BaseCollectionItem::toDisplayString() const
{
	std::stringstream ss;
	ss << "id: " << itemId() << "\n";
	auto foo = getProperties();
	for (auto f : foo)
	{
		std::string propName = f.first;
		std::string propVal = f.second;
		ss << propName << ": " << propVal << "\n";
	}
	return ss.str();
}

std::string BaseCollectionItem::title() const
{
	return _title;
}

void BaseCollectionItem::setTitle(const std::string title)
{
	_title = title;
}
