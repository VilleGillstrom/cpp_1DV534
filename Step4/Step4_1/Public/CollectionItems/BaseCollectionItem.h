#pragma once
#include <ostream>
#include <vector>
#include <map>
#include <sstream>


class BaseCollectionItem
{
public:
	//Used to contain a propertys name and value
	struct PropertyString {
		std::string name;
		std::string value;
	};

	BaseCollectionItem() = default;			
	BaseCollectionItem(const std::string& title);
	virtual ~BaseCollectionItem() = default;

	friend std::ostream& operator<<(std::ostream& os, const BaseCollectionItem& item)
	{
		os << item.toDisplayString();
		return os;
	}

	void setItemId(int itemId);														// set itemId
	bool hasItemId(int itemId) const;												// has itemId
	int itemId() const;																// get itemId
	virtual std::string toDisplayString() const;									// Get a string that can be presented to the user
	virtual std::string getItemTypeName() const = 0;								// Get the name of the item, must be unique between items
	virtual std::map<std::string,std::string> getProperties() const = 0;			//Get a map of <property name, property value
	virtual void setProperties(std::vector<PropertyString> propertiyStrings) = 0;	// Set the properties from strings
	virtual bool equalTo(BaseCollectionItem* item) const = 0;						// Return true if items are equal, false if not

	std::string title() const; 
	void setTitle(const std::string title);

	template <typename T>
	bool getProperty(const std::string& name, T& result) const;						// Get a property by name

protected:
	std::string _title;	// Title of the property

private:
	int _itemId; //Id when stored
};

// Get a property by name
template <typename T>
bool BaseCollectionItem::getProperty(const std::string& name, T& value) const
{
	auto properties = getProperties();
	auto property = properties.find(name);
	if (property == properties.end())
	{
		return false;
	}
	std::stringstream ss(property->second);
	ss >> value;
	return true;
}

