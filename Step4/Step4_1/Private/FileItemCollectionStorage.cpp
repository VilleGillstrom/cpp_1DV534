

#include <FileItemCollectionStorage.h>
#include <fstream>
#include <iostream>

using std::ios;
using std::cerr;

FileItemCollectionStorage::FileItemCollectionStorage(const std::string& filename)
{
	std::fstream fs;
	fs.open(filename.c_str(), ios::out|ios::in);
	if(!fs.good())
	{
		cerr << "Bad file";
		std::exit(EXIT_FAILURE);
	}
}



void FileItemCollectionStorage::save(const std::vector<BaseCollectionItem*>& vector)
{
}

std::vector<BaseCollectionItem*> FileItemCollectionStorage::load()
{

	return { };
}
