#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
	public:
		enum ItemType {USEABLE, KEY};

		Item();
		QString Name;
		QString Description;
		ItemType Type;
		bool Stackable;

};

#endif // ITEM_H
