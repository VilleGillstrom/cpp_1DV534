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


std::string StampItem::toDisplayString() const
{
	std::stringstream ss;
	ss << "id: " << itemId() << "\n";
	ss << "Title: " << _title << "\n";
	ss << "Release year: " << _releaseYear << "\n";
	ss << "Note: " << _note << "\n";
	return ss.str();
}


std::vector<BaseCollectionItem::PropertyString> StampItem::getProperties() const
{
	std::vector<PropertyString> props;
	props.push_back({"title", _title});
	props.push_back({"note", _note});
	props.push_back({"releaseYear", std::to_string(_releaseYear)});
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
	if (StampItem * mi = dynamic_cast<StampItem*>(item))
	{
		return isSameAs(mi);
	}
	return false;
}

bool StampItem::isSameAs(StampItem* item) const
{
	auto cond = _releaseYear == item->releaseYear();
	auto cond1 = _note == item->note();
	auto cond2 = _title == item->title();
	return cond && cond1 && cond2;
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