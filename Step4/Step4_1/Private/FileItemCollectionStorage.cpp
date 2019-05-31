#include <FileItemCollectionStorage.h>
#include <iostream>
#include <sstream>
#include "CollectionItems/StampItem.h"
#include <sstream>
#include "MovieItem.h"
#include "SongItem.h"

using std::ios;
using std::cerr;

FileItemCollectionStorage::FileItemCollectionStorage() : _itemDelim("###")
{
	
}


void FileItemCollectionStorage::save(const std::vector<BaseCollectionItem*>& items, const std::string& filename) const
{
	std::ofstream ofs(filename, ios::trunc);

	if (!ofs.good())
	{
		char errmsg[100];
		strerror_s(errmsg, sizeof(errmsg), errno);
		cerr << "Bad file:" << errmsg;
		std::exit(EXIT_FAILURE);
	}

	// Using temporary stringstream so i can debug easier, should write directly to fs
	std::stringstream ss;
	for (auto& item : items)
	{
		ss << item->getItemTypeName() << "\n";
		std::map<std::string, std::string> props = item->getProperties();
		ss << item->itemId() << "\n";
		for (auto prop : props)
		{
			ss << prop.first << ":" << prop.second << "\n";
		}

		ss << _itemDelim << "\n";
		ofs << ss.str();
		ss.str("");
	}
	ofs.close();
}

bool FileItemCollectionStorage::readPropertyString(std::ifstream& ifs, BaseCollectionItem::PropertyString& propertyString)
{
	std::string line;
	std::getline(ifs, line);

	if (line == _itemDelim || !ifs.good())
	{
		return false;
	}

	int ind = line.find(':');
	std::string name = line.substr(0, ind);
	std::string value = line.substr(ind + 1, line.size());


	propertyString = {name, value};
	return true;
}

// I don't like this :(
BaseCollectionItem* FileItemCollectionStorage::newItemFromTypeString(const std::string& itemtype)
{
	BaseCollectionItem* item = nullptr;
	if (itemtype == StampItem::getItemType()) { item = new StampItem(); }
	else if (itemtype == MovieItem::getItemType()) { item = new MovieItem(); }
	else if (itemtype == SongItem::getItemType()) { item = new SongItem(); }
	return item;
}

#include <filesystem>

std::vector<BaseCollectionItem*> FileItemCollectionStorage::load(const std::string& filename)
{
	std::ifstream ifs(filename);
	std::vector<BaseCollectionItem*> loadedItems;

	if (!ifs.good())
	{
		if (errno == ENOENT)
		{
			std::cout << "Attempted to load from non-existen file: " << filename << "\n";
		}
		else
		{
			char errmsg[100];
			strerror_s(errmsg, sizeof(errmsg), errno);
			cerr << "Bad file:" << errmsg;
			std::exit(EXIT_FAILURE);
		}
	}
	else
	{
		std::stringstream ss;
		std::string line;
		while (ifs.good())
		{
			std::vector<BaseCollectionItem::PropertyString> properties;
			std::string itemtype;
			std::getline(ifs, itemtype);
			if (ifs.bad())
			{
				continue;
			}
			ifs.clear();

			int itemId;
			ifs >> itemId;
			if (ifs.bad())
			{
				continue;
			}

			BaseCollectionItem::PropertyString propertyString;
			while (readPropertyString(ifs, propertyString))
			{
				properties.push_back(propertyString);
			}

			BaseCollectionItem* item = newItemFromTypeString(itemtype);
			if (item)
			{
				item->setItemId(itemId);
				item->setProperties(properties);
				loadedItems.push_back(item);
			}
		}
	}
	ifs.close();
	return loadedItems;
}
