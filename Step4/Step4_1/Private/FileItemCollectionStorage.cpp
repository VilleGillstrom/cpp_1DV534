

#include <FileItemCollectionStorage.h>
#include <iostream>
#include <sstream>

using std::ios;
using std::cerr;

FileItemCollectionStorage::FileItemCollectionStorage(const std::string& filename)
{
	_filename = filename;
}



void FileItemCollectionStorage::save(const std::vector<std::unique_ptr<BaseCollectionItem>>& items) const
{
	std::ofstream ofs(_filename, ios::trunc);

	//delete items[3];
	if (!ofs.good())
	{
		char errmsg[100];
		strerror_s(errmsg, sizeof(errmsg), errno);
		cerr << "Bad file:" << errmsg;
		std::exit(EXIT_FAILURE);
	}

	// Using temporary stringstream so i can debug easier, should write directly to fs
	std::stringstream ss;
	for(auto& item : items)
	{
		ss << item->getItemTypeName() << "\n";
		std::vector<BaseCollectionItem::PropertyString> props = item->getProperties();
		for(auto prop : props)
		{
			ss << prop.name << ":" << prop.value << "\n";
		}
		std::cout << "Saving " << ss.str();
		ofs << ss.str();

		ss.clear();
	}
}

std::vector<BaseCollectionItem*> FileItemCollectionStorage::load()
{

	return { };
}
