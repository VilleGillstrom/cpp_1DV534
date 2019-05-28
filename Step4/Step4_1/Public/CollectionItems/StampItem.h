#pragma once
#include "BaseCollectionItem.h"
class StampItem :public BaseCollectionItem
{
public:
	StampItem();
	StampItem(const std::string& title, const std::string& note, int releaseYear);

	~StampItem() = default;


	std::string toString() const override;
	void setTitle(const std::string& title) { _title = title; }
	void setNote(const std::string& note) { _note = note; }
	void setRelaseYear(int releaseYear) { _releaseYear = releaseYear; }

private:

	std::string _title;
	std::string _note;
	int _releaseYear;

};

