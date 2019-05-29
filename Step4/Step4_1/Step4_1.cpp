// Step4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <App.h>

void TestFileStorage()
{
	FileItemCollectionStorage storage("testfile.txt");

	std::vector<std::unique_ptr<BaseCollectionItem>> items;
	items.push_back(std::make_unique<StampItem>(StampItem("MyTitle", "MyNote", 1932)));
	storage.save(items);
}

int main()
{
	std::cout << "Hello World!\n";

	App app;
	//app.run();


	TestFileStorage();
}
