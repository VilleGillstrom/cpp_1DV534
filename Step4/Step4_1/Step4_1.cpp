// Step4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <App.h>
#include "MovieItem.h"

bool assertStamp(StampItem* item, std::string title, std::string note, int year)
{
	if (item->title() != title) { std::cerr << "Bad Title"; return false; };
	if (item->note() != note) { std::cerr << "Bad note"; return false; }
	if (item->releaseYear() != year) { std::cerr << "Bad release year"; return false; }
	return true;
}
bool assertMovie(MovieItem* item, std::string title, std::string studio, int releaseYear, int price)
{
	if (item->title() != title) { std::cerr << "Bad Title"; return false; };
	if (item->studio() != studio) { std::cerr << "Bad studio"; return false; }
	if (item->releaseYear() != releaseYear) { std::cerr << "Bad release year"; return false; }
	if (item->price() != price) { std::cerr << "Bad price"; return false; }
	return true;
}

void TestFileStorage()
{
	FileItemCollectionStorage storage("testfile.txt");

	std::vector<BaseCollectionItem*> items;
	items.push_back(new StampItem("MyTitle", "My Note", 1932));
	items.push_back(new StampItem("MyTitle2", "My Note 2", 2000));
	items.push_back(new MovieItem("Avengers", "Disney", 2009, 20));
	storage.save(items);

	std::vector<BaseCollectionItem*> loaded = storage.load();
	if (loaded.size() < 3) { std::cerr << "Didn't load all items"; return; };

	auto item = static_cast<StampItem*>(loaded.at(0));
	auto item2 = static_cast<StampItem*>(loaded.at(1));
	auto item3 = static_cast<MovieItem*>(loaded.at(2));

	if (!assertStamp(item, "MyTitle", "My Note", 1932)) return;
	if (!assertStamp(item2, "MyTitle2", "My Note 2", 2000)) return;
	if (!assertMovie(item3, "Avengers", "Disney", 2009,20)) return;


	std::cout << "Test passed!";
}


int main()
{

	App app;
	app.run();
}
