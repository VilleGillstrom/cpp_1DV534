#pragma once
#include "OptionsMenu.h"
#include "ItemBuilderMenu.h"

class AddItemMenu : public OptionsMenu
{
public:
	//AddItemMenu() : AddItemMenu (nullptr) {}

	AddItemMenu(CollectionRegistry& collectionRegistry);



	~AddItemMenu() = default;


	void AddStampFunc()
	{
		std::cout << "I GOT HERE";
		ItemBuilderMenu ibm(_collectionRegistry);
		ibm.show();
	}





private:
	CollectionRegistry& _collectionRegistry;

};

