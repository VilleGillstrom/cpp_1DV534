#include "SongItem.h"



SongItem::SongItem() :SongItem("","",-1)
{
}

SongItem::SongItem(const std::string& title, const std::string& singer, int playlength):
	BaseCollectionItem(title), _singer(singer), _playlength(playlength)
{
}

std::string SongItem::getItemType()
{
	return "Song";
}

std::string SongItem::getItemTypeName() const
{
	return getItemType();
}

std::map<std::string, std::string> SongItem::getProperties() const
{
	return {
		{"title", _title},
		{"singer", _singer},
		{"playlength", std::to_string(_playlength)}
	};
}

void SongItem::setProperties(std::vector<PropertyString> propertiyStrings)
{
	for (PropertyString ps : propertiyStrings)
	{
		if (ps.name == "title")
		{
			_title = ps.value;
		}
		if (ps.name == "playlength")
		{
			std::stringstream(ps.value) >> _playlength;;
		}
		if (ps.name == "singer")
		{
			_singer = ps.value;
		}
	}
}

bool SongItem::equalTo(BaseCollectionItem* item) const
{
	if (SongItem* asSong = dynamic_cast<SongItem*>(item))
	{
		auto cond = _singer == asSong->_singer;
		auto cond1 = _playlength == asSong->_playlength;
		auto cond2 = _title == asSong->_title;
		return cond && cond1 && cond2;
	}
	return false;
}


