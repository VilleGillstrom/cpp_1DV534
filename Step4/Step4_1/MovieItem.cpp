#include "MovieItem.h"
#include <sstream>


MovieItem::MovieItem() : MovieItem("", "", -1, -1)
{
}

MovieItem::MovieItem(const std::string& title, const std::string& studio, int releaseYear, int price):
	BaseCollectionItem(title), _releaseYear(releaseYear), _studio(studio), _price(price)
{
}


std::map<std::string, std::string> MovieItem::getProperties() const
{
	std::map<std::string, std::string> props;
	props.insert({"title", _title});
	props.insert({"releaseYear", std::to_string(_releaseYear)});
	props.insert({"studio", _studio});
	props.insert({"price", std::to_string(_price)});
	return props;
}

void MovieItem::setProperties(std::vector<PropertyString> propertiyStrings)
{
	for (PropertyString ps : propertiyStrings)
	{
		if (ps.name == "title")
		{
			_title = ps.value;
		}
		if (ps.name == "releaseYear")
		{
			std::stringstream(ps.value) >> _releaseYear;;
		}
		if (ps.name == "studio")
		{
			_studio = ps.value;
		}
		if (ps.name == "price")
		{
			std::stringstream(ps.value) >> _price;
		}
	}
}

std::string MovieItem::getItemTypeName() const
{
	return getItemType();
}

std::string MovieItem::getItemType()
{
	return "Movie";
}

bool MovieItem::equalTo(BaseCollectionItem* item) const
{
	if (MovieItem* asMovie = dynamic_cast<MovieItem*>(item))
	{
		auto cond = _releaseYear == asMovie->releaseYear();
		auto cond1 = _price == asMovie->price();
		auto cond2 = _title == asMovie->title();
		auto cond3 = _studio == asMovie->studio();
		return cond && cond1 && cond2 && cond3;
	}
	return false;
}


int MovieItem::releaseYear() const
{
	return _releaseYear;
}

void MovieItem::setReleaseYear(int release_year)
{
	_releaseYear = release_year;
}

std::string MovieItem::studio() const
{
	return _studio;
}

void MovieItem::setStudio(const std::string& cs)
{
	_studio = cs;
}

int MovieItem::price() const
{
	return _price;
}

void MovieItem::setPrice(int price)
{
	_price = price;
}
