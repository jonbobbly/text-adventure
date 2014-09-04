#include "itemmanager.h"

ItemManager::ItemManager()
{
}

void ItemManager::addItem(QString Name, QString Description)
{
	Item newItem;
	newItem.Name = Name;
	newItem.Description = Description;
	theItems.append(newItem);
}

Item *ItemManager::find(QString Name)
{
	for(int i = 0; i < theItems.size(); i++){
		if(theItems[i].Name == Name){
			return &theItems[i];
		}
	}
	return NULL;
}
