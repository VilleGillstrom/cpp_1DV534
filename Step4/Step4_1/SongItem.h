#pragma once
#include "CollectionItems/BaseCollectionItem.h"

class SongItem : public BaseCollectionItem
{
public:
	SongItem();
	SongItem(const std::string& title, const std::string& singer, int playlength);
	~SongItem() = default;


	static std::string getItemType();
	std::string getItemTypeName() const override;;
	std::map<std::string, std::string> getProperties() const override;;

	void setProperties(std::vector<PropertyString> propertiyStrings) override;;
	bool equalTo(BaseCollectionItem* item) const override;;


private:
	std::string _singer;
	int _playlength;
};
