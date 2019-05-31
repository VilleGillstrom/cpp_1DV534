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

	template <typename T>
	void sort(const std::string& propertyName, SortMode sortMode)
	{
		const auto lambda = [&sortMode, &propertyName](BaseCollectionItem* A, BaseCollectionItem* B)
		{
			T AVal;
			T BVal;
			bool bAVal = A->getProperty(propertyName, AVal);
			bool bBVal = B->getProperty(propertyName, BVal);
			bool result = false;

			if (bAVal && bBVal)
			{
				result = sortMode == ascending ? AVal < BVal : AVal > BVal;
			}
			else if (bAVal)
			{
				result = true; //Will move A above B since A has the property
			}
			else if (bBVal)
			{
				result = false; //Will move B above A since B has the property
			}
			return result;
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
};
