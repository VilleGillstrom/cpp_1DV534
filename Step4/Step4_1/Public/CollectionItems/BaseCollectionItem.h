#pragma once
#include <ostream>
#include <istream>
#include <vector>


class BaseCollectionItem
{
public:
	struct PropertyString
	{
		std::string name;
		std::string value;
	};


	BaseCollectionItem(const std::string& itemTypeName);;
	virtual ~BaseCollectionItem() = default;

	friend std::ostream& operator<<(std::ostream& os, const BaseCollectionItem& item)
	{
		os << item.toDisplayString();
		return os;
	}

	void setItemId(int itemId);
	bool hasItemId(int itemId) const;

	virtual std::string toDisplayString() const = 0;

	std::string getItemTypeName()const { return _itemTypeName; }

	virtual std::vector<PropertyString> getProperties() const { return {}; };
	


protected:
	const std::string _itemTypeName;


private:
	int _itemId; //Id when stored
};

