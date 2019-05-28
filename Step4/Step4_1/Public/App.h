#pragma once
#include "CollectionRegistry.h"
#include "MainMenu.h"
#include "FileItemCollectionStorage.h"

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




	int run()
	{
		FileItemCollectionStorage itemStorage("items.txt");
		CollectionRegistry registry(&itemStorage);
		MainMenu menu(registry);


		menu.show();

		return 0;
	}




	CollectionRegistry _registry;
	//AddItemMenu* _addItemMenu;
};

