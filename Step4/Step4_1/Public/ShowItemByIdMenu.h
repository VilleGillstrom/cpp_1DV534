#pragma once
#include <map>
#include <functional>

class CollectionRegistry;
class ShowItemByIdMenu
{
public:

	ShowItemByIdMenu(CollectionRegistry& collectionRegistry);
	~ShowItemByIdMenu() = default;


	void show();

	std::map<char, std::function<void()>> choiceCBMap;
private:
	CollectionRegistry& _collectionRegistry;

};

