#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <QStandardItemModel>
#include "item.h"

class ItemManager
{
	public:
		ItemManager();
		void addItem(QString Name, QString Description);
		Item *find(QString Name);

		QList<Item> theItems;
};

#endif // ITEMMANAGER_H
