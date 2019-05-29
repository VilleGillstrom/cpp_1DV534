#include "ShowItemsByTypeMenu.h"
#include "CollectionItems/StampItem.h"
#include "MovieItem.h"


ShowItemsByTypeMenu::ShowItemsByTypeMenu(CollectionRegistry& collectionRegistry):
	OptionsMenu("Show all items of type Menu", false), _collectionRegistry(
		collectionRegistry)
{
	addMenuOption(
		"1",
		{
			"Stamp",
			std::bind(&ShowItemsByTypeMenu::showAllItemsOfType, this, StampItem::getItemType())
		}
	);
	addMenuOption(
		"2",
		{
			"Movie",
			std::bind(&ShowItemsByTypeMenu::showAllItemsOfType, this, MovieItem::getItemType())

		});
}


void ShowItemsByTypeMenu::showAllItemsOfType(const std::string& itemType)
{
	std::vector<BaseCollectionItem*> items = _collectionRegistry.getItemsOfType(itemType);
	for (auto item : items)
	{
		std::cout << *item << std::endl;
	}
	std::cin.get();
}
