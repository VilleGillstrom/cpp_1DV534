#include <App.h>


void App::fillDummyData(FileItemCollectionStorage& storage)
{
	std::vector<BaseCollectionItem*> items;
	StampItem* item1 = new StampItem("MyTitle", "My Note", 1932);
	StampItem* item2 = new StampItem("MyTitle2", "My Note 2", 2000);
	MovieItem* item3 = new MovieItem("Avengers", "Disney", 2009, 20);
	MovieItem* item4 = new MovieItem("Titanic", "No idea", 1995, 20);
	MovieItem* item5 = new MovieItem("Avatar", "Disney", 2005, 20);
	SongItem* item6 = new SongItem("Imagine ", "John Lennon", 183);
	SongItem* item7 = new SongItem("Billie Jean", "Michael Jackson", 294);

	item1->setItemId(0);
	item2->setItemId(1);
	item3->setItemId(2);
	item4->setItemId(3);
	item5->setItemId(4);
	item6->setItemId(5);
	item7->setItemId(6);

	items.push_back(item1);
	items.push_back(item2);
	items.push_back(item3);
	items.push_back(item4);
	items.push_back(item5);
	items.push_back(item6);
	items.push_back(item7);

	storage.save(items, "items.txt");
}

int App::run()
{
	FileItemCollectionStorage fileStorage;
	CollectionRegistry registry(&fileStorage);
	//registry.loadReg("items.txt");
	MainMenu menu(registry);

	menu.show();
	return 0;
}
