#pragma once
#include <ostream>


class BaseCollectionItem
{


public:
	BaseCollectionItem();
	BaseCollectionItem(const std::string& itemTypeName);;
	virtual ~BaseCollectionItem() = default;

	friend std::ostream& operator<<(std::ostream& os, const BaseCollectionItem& item)
	{
		os << item.toString();
		return os;
	}

	void setItemId(int itemId);
	bool hasItemId(int itemId) const;

	virtual std::string toString() const = 0;

	std::string getItemTypeName()const { return _itemTypeName; }


protected:
	static std::string _itemTypeName;


private:
	int _itemId; //Id when stored
};

