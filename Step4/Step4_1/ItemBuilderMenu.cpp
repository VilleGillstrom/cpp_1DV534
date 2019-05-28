#include "ItemBuilderMenu.h"
#include  "CollectionRegistry.h"


ItemBuilderMenu::ItemBuilderMenu(CollectionRegistry& collectionRegistry) : _collectionRegistry(collectionRegistry)
{
}

void ItemBuilderMenu::show()
{
	BaseCollectionItem* NewItem = UserIemCreator.build();
	_collectionRegistry.addItem(NewItem);
}
