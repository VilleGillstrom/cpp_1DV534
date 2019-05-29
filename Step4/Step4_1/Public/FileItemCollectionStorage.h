#pragma once
#include "IItemCollectionStorage.h"
#include <fstream>
#include <iostream>
#include <sstream>

class FileItemCollectionStorage : public IItemCollectionStorage
{
public:
	FileItemCollectionStorage(const std::string& filename);
	~FileItemCollectionStorage() = default;


	void save(const std::vector<BaseCollectionItem*>& items) const override;
	bool readPropertyString(std::ifstream& ifs, BaseCollectionItem::PropertyString& foo);
	BaseCollectionItem* newItemFromTypeString(const std::string& itemtype);
	std::vector<BaseCollectionItem*> load() override;

	


private:
	std::string _filename;
	const std::string _itemDelim; 
};

