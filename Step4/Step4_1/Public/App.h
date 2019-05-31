#pragma once
#include "CollectionRegistry.h"
#include "MainMenu.h"
#include "FileItemCollectionStorage.h"
#include "MovieItem.h"
#include "CollectionItems/StampItem.h"
#include "ItemCreator.h"
#include "SongItem.h"


class App
{
public:
	App() = default;
	~App() = default;

	void fillDummyData(FileItemCollectionStorage& storage);

	int run();
};
