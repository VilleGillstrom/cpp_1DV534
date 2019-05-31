#pragma once

#include "BaseCollectionItem.h"
#include <string>

class StampItem : public BaseCollectionItem
{
public:
	StampItem();
	StampItem(const std::string& title, const std::string& note, int releaseYear);
	~StampItem() = default;

	std::map<std::string, std::string> getProperties() const override;			// Get properties as name, value string pair
	void setProperties(std::vector<PropertyString> propertyString) override;    // Set properties by strings
	bool equalTo(BaseCollectionItem* item) const override;						// Are equal ?

	std::string getItemTypeName() const override;;								// Get the name
	static std::string getItemType();;											// Static get name

	/* Setters and getters */
	void setNote(const std::string& note);
	void setRelaseYear(int releaseYear);
	std::string note() const;
	int releaseYear() const;

private:
	std::string _note;
	int _releaseYear;
};
