#pragma once
#include "CollectionRegistry.h"
#include "MainMenu.h"
#include "FileItemCollectionStorage.h"
#include "MovieItem.h"
#include "CollectionItems/StampItem.h"

class ItemFactory
{
	ItemFactory() {};
};

class App
{
public:
	App() 
	{
		
	}
	~App();


	void fillDummyData(FileItemCollectionStorage& storage)
	{
		std::vector<BaseCollectionItem*> items;
		StampItem* item1 = new StampItem("MyTitle", "My Note", 1932);
		StampItem* item2 = new StampItem("MyTitle2", "My Note 2", 2000);
		MovieItem* item3 = new MovieItem("Avengers", "Disney", 2009, 20);
		MovieItem* item4 = new MovieItem("Titanic", "No idea", 1995, 20);
		MovieItem* item5 = new MovieItem("Avatar", "Disney", 2005, 20);

		item1->setItemId(0);
		item2->setItemId(1);
		item3->setItemId(2);
		item4->setItemId(3);
		item5->setItemId(4);
		
		items.push_back(item1);
		items.push_back(item2);
		items.push_back(item3);
		items.push_back(item4);
		items.push_back(item5);

		storage.save(items);

	}

	int run()
	{
		FileItemCollectionStorage itemStorage("items.txt");
		fillDummyData(itemStorage);

		CollectionRegistry registry(&itemStorage);
		registry.loadReg();
		MainMenu menu(registry);


		menu.show();

		return 0;
	}




	CollectionRegistry _registry;
	//AddItemMenu* _addItemMenu;
};

