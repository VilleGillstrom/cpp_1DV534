#include <sstream>
#include "CollectionItems/StampItem.h"


StampItem::StampItem()
{
}

StampItem::StampItem(const std::string& title, const std::string& note, int releaseYear) :
	_title(title), _note(note), _releaseYear(releaseYear), BaseCollectionItem("Stamp")
{
}

std::string StampItem::toString() const
{
	std::stringstream ss;
	ss << "Title: " << _title << "\n";
	ss << "Release year: " << _releaseYear << "\n";
	ss << "Note: " << _note << "\n";

	return ss.str();
}



