#ifndef INVENTORY_H
#define INVENTORY_H

#include <QStandardItemModel>

class Inventory
{
	public:
		Inventory();
		QStandardItemModel *model;

		void addItem(QString Name);
		void removeItem(QString Name);
		bool hasItem(QString Name);
};

QDataStream &operator<<(QDataStream &out, const Inventory &inven);
QDataStream &operator>>(QDataStream &in, Inventory &inven);

#endif // INVENTORY_H
