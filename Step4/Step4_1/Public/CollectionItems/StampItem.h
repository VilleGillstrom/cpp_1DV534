#pragma once

#include "BaseCollectionItem.h"
#include <string>

class StampItem : public BaseCollectionItem
{
public:
	StampItem();
	StampItem(const std::string& title, const std::string& note, int releaseYear);
	~StampItem() = default;


	std::vector<PropertyString> getProperties() const override;
	void setProperties(std::vector<PropertyString> propertyString) override;
	bool equalTo(BaseCollectionItem* item) const override;
	bool isSameAs(StampItem* item) const;


	std::string getItemTypeName() const override { return getItemType(); };
	static std::string getItemType() { return "Stamp"; };


	std::string toDisplayString() const override;
	void setNote(const std::string& note);
	void setRelaseYear(int releaseYear);
	std::string note() const;
	int releaseYear() const;

private:
	std::string _note;
	int _releaseYear;
};
