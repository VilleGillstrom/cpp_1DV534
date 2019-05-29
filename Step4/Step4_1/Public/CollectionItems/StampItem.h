#pragma once

#include "BaseCollectionItem.h"
#include <string>
class StampItem : public BaseCollectionItem
{
public:
	StampItem(const std::string& title, const std::string& note, int releaseYear);

	~StampItem() = default;


	std::string toDisplayString() const override;
	void setTitle(const std::string& title) { _title = title; }
	void setNote(const std::string& note) { _note = note; }
	void setRelaseYear(int releaseYear) { _releaseYear = releaseYear; }


	std::vector<PropertyString> getProperties() const override
	{
		std::vector<PropertyString> props;
		props.push_back({ "title", _title });
		props.push_back({ "note", _note });
		props.push_back({ "releaseYear", std::to_string(_releaseYear)});
		return props;
	};
private:

	std::string _title;
	std::string _note;
	int _releaseYear;

};

