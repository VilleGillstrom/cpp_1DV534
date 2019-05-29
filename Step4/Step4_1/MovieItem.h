#pragma once
#include "CollectionItems/BaseCollectionItem.h"

class MovieItem : public BaseCollectionItem
{
public:
	MovieItem();
	MovieItem(const std::string& title, const std::string& studio, int releaseYear,
	          int price);
	~MovieItem();

	std::string toDisplayString() const override;
	std::vector<PropertyString> getProperties() const override;
	void setProperties(std::vector<PropertyString> propertiyStrings) override;


	std::string getItemTypeName() const override { return getItemType(); };
	static std::string getItemType() { return "Movie"; }
	bool equalTo(BaseCollectionItem* item) const override;
	bool isSameAs(MovieItem* item) const;


	int releaseYear() const;
	void setReleaseYear(int release_year);
	std::string studio() const;
	void setStudio(const std::string& studio);
	int price() const;
	void setPrice(int price);


private:
	std::string _title;
	std::string _studio;
	int _releaseYear;
	int _price;
};
