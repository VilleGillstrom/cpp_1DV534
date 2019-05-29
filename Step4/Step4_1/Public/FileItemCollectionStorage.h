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


	void save(const std::vector<std::unique_ptr<BaseCollectionItem>>& items) const override;
	std::vector<BaseCollectionItem*> load() override;

	


private:
	std::string _filename;
};

