#include <sstream>
#include "CollectionItems/StampItem.h"
#include "MovieItem.h"


StampItem::StampItem() : StampItem("", "", 0000)
{
}

StampItem::StampItem(const std::string& title, const std::string& note, int releaseYear) :
	 _note(note), _releaseYear(releaseYear), BaseCollectionItem(getItemType(), title)
{
}



std::map<std::string, std::string> StampItem::getProperties() const
{
	std::map<std::string, std::string> props;
	props.insert({"title", _title});
	props.insert({"note", _note});
	props.insert({"releaseYear", std::to_string(_releaseYear)});
	return props;
}

void StampItem::setProperties(std::vector<PropertyString> propertyString)
{
	for (PropertyString& p : propertyString)
	{
		if (p.name == "title")
		{
			_title = p.value;
		}
		else if (p.name == "note")
		{
			_note = p.value;
		}
		else if (p.name == "releaseYear")
		{
			std::stringstream(p.value) >> _releaseYear;
		}
	}
}

bool StampItem::equalTo(BaseCollectionItem* item) const
{
	if (StampItem * asStamp = dynamic_cast<StampItem*>(item))
	{
		auto cond = _releaseYear == asStamp->releaseYear();
		auto cond1 = _note == asStamp->note();
		auto cond2 = _title == asStamp->title();
		return cond && cond1&& cond2;
	}
	return false;
}




void StampItem::setNote(const std::string& note)
{
	_note = note;
}

void StampItem::setRelaseYear(int releaseYear)
{
	_releaseYear = releaseYear;
}



std::string StampItem::note() const
{
	return _note;
}

int StampItem::releaseYear() const
{
	return _releaseYear;
}