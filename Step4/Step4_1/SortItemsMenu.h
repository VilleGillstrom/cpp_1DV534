#pragma once
#include "OptionsMenu.h"
#include "CollectionRegistry.h"
class CollectionRegistry;

class SortItemsMenu : public OptionsMenu
{
	enum SortMode { ascending, descending };


public:
	SortItemsMenu(CollectionRegistry& collectionRegistry);
	~SortItemsMenu() = default;


private:
	CollectionRegistry& _collectionRegistry;

	void sortByTitle()
	{
		const auto lambda = [](BaseCollectionItem* A, BaseCollectionItem* B) { return A->title() > B->title(); };
		_collectionRegistry.sortItems(lambda);
	}


	template <typename T>
	void sort(const std::string& propertyName, SortMode sortMode)
	{
		const auto lambda = [&sortMode, &propertyName](BaseCollectionItem* A, BaseCollectionItem* B)
		{
			T AVal;
			T BVal;
			if (A->getProperty(propertyName, AVal) && B->getProperty(propertyName, BVal))
			{
				return sortMode == ascending ? AVal < BVal : AVal > BVal;
			}
			return false;
		};
		_collectionRegistry.sortItems(lambda);
	}

	template <typename T>
	void sortPropertyDecided(const std::string& propertyName)
	{
		OptionsMenu foo("Sort ascending/descending?");
		foo.addMenuOption("1",
		                  {
			                  "Sort ascending",
			                  std::bind(&SortItemsMenu::sort<T>, this, propertyName, ascending)
		                  });

		foo.addMenuOption("2",
		                  {
			                  "Sort descending",
			                  std::bind(&SortItemsMenu::sort<T>, this, propertyName, descending)
		                  });
		foo.show(); 
	}

	template <typename T>
	void sortItemDecided(const std::string& item)
	{
		OptionsMenu foo("Select what item's property (will sort other items that have same property)");
		foo.addMenuOption("1",
			{
				"Sort ascending",
				std::bind(&SortItemsMenu::sortPropertyDecided<T>, this, item)
			});

		
		foo.show();
	}


};
