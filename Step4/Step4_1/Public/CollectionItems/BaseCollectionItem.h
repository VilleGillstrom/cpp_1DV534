#pragma once
#include <ostream>
#include <vector>


class BaseCollectionItem
{
public:
	struct PropertyString
	{
		std::string name;
		std::string value;
	};


	BaseCollectionItem(const std::string& itemTypeName, const std::string& title);
	virtual ~BaseCollectionItem() = default;

	friend std::ostream& operator<<(std::ostream& os, const BaseCollectionItem& item)
	{
		os << item.toDisplayString();
		return os;
	}

	void setItemId(int itemId);
	bool hasItemId(int itemId) const;
	int itemId() const;

	virtual std::string toDisplayString() const = 0;
	virtual std::string getItemTypeName() const = 0;

	virtual std::vector<PropertyString> getProperties() const = 0;
	virtual void setProperties(std::vector<PropertyString> propertiyStrings) = 0;
	virtual bool equalTo(BaseCollectionItem* item) const = 0;


	std::string title() const { return _title; }
	void setTitle(const std::string title) { _title = title; }



protected:
	std::string _title;


	const std::string _itemTypeName;


private:
	int _itemId; //Id when stored
};

