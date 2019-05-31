#pragma once
#include "IItemCollectionStorage.h"
#include <fstream>

class FileItemCollectionStorage : public IItemCollectionStorage
{
public:
	FileItemCollectionStorage();
	~FileItemCollectionStorage() = default;

	void save(const std::vector<BaseCollectionItem*>& items, const std::string& filename) const override;				// Save the list into a _filename
	BaseCollectionItem* newItemFromTypeString(const std::string& itemtype);
	std::vector<BaseCollectionItem*> load(const std::string& filename) override;

private:
	bool readPropertyString(std::ifstream& ifs, BaseCollectionItem::PropertyString& propertyString);   // read a line into a propertystring


	const std::string _itemDelim; 
};

