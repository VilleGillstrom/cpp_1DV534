#include "ItemBuilderMenu.h"
#include  "CollectionRegistry.h"


ItemBuilderMenu::ItemBuilderMenu(CollectionRegistry& collectionRegistry) : _collectionRegistry(collectionRegistry)
{
}

void ItemBuilderMenu::show()
{
	BaseCollectionItem* NewItem = UserIemCreator.make();
	_collectionRegistry.addItem(NewItem);
}
