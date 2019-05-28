#pragma once
#include "IItemCollectionStorage.h"

class FileItemCollectionStorage : public IItemCollectionStorage
{
public:
	FileItemCollectionStorage(const std::string& filename);
	~FileItemCollectionStorage() = default;


	void save(const std::vector<BaseCollectionItem*>& vector) override;
	std::vector<BaseCollectionItem*> load() override;
};

