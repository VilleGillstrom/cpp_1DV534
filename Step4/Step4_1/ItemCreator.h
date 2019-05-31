#pragma once
#include <functional>
#include "CollectionItems/BaseCollectionItem.h"
#include <map>

class ItemCreator
{
public:
	ItemCreator();
	~ItemCreator();


	void registerCreate(const std::string& name, std::function<BaseCollectionItem*()> createMethod)
	{
		auto registeredPair = registeredFunctions.insert({name.c_str(), createMethod});
	}

	BaseCollectionItem* create(const std::string& name)
	{
		const auto registeredPair = registeredFunctions.find(name);

		if (registeredPair == registeredFunctions.end())
		{
			return nullptr;
		}
		return registeredPair->second();
	}

	template<typename T>
	void foo() {};
	std::map<std::string, std::function<BaseCollectionItem*()>> registeredFunctions;
};
