#pragma once
#include <ostream>
#include <vector>
#include <map>
#include <sstream>


class BaseCollectionItem
{
public:
	struct PropertyString
	{
		std::string name;
		std::string value;
	};

	BaseCollectionItem() = default;
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

	virtual std::string toDisplayString() const
	{
		std::stringstream ss;
		ss << "id: " << itemId() << "\n";
		auto foo = getProperties();
		for(auto f : foo)
		{
			std::string propName = f.first;
			std::string propVal = f.second;
			ss << propName << ": " << propVal << "\n";
		}
		return ss.str();
	}
	virtual std::string getItemTypeName() const = 0;

	virtual std::map<std::string,std::string> getProperties() const = 0;

	virtual void setProperties(std::vector<PropertyString> propertiyStrings) = 0;
	virtual bool equalTo(BaseCollectionItem* item) const = 0;

	std::string title() const { return _title; }
	void setTitle(const std::string title) { _title = title; }


	template <typename T>
	bool getProperty(const std::string& name, T& result) const;;

	


protected:
	std::string _title;
	const std::string _itemTypeName;


private:
	int _itemId; //Id when stored
};

template <typename T>
bool BaseCollectionItem::getProperty(const std::string& name, T& result) const
{
	auto properties = getProperties();
	auto property = properties.find(name);
	if (property == properties.end())
	{
		return false;
	}
	std::stringstream ss(property->second);
	ss >> result;
	return true;
}

