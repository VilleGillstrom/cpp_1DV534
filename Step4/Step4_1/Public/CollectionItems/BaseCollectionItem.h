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
	virtual std::string getItemTypeName() const = 0;

	virtual std::vector<PropertyString> getProperties() const = 0;
	virtual void setProperties(std::vector<PropertyString> propertiyStrings) = 0;
	virtual bool isSameAs(BaseCollectionItem* item) const = 0;


	//template<typename T>
	//bool isSameAs(T item)
	//{
	//	if (T * mi = dynamic_cast<T*>(item))
	//	{
	//		return isSameAs(mi);
	//	}
	//	return false;
	//}

	int itemId() const;


protected:
	const std::string _itemTypeName;


private:
	int _itemId; //Id when stored
};

