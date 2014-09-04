#include "inventory.h"

Inventory::Inventory()
{
	model = new QStandardItemModel();
}

void Inventory::addItem(QString Name)
{
	QStandardItem *theItem = new QStandardItem();
	theItem->setText(Name);
	model->appendRow(theItem);
}

void Inventory::removeItem(QString Name)
{
	QList<QStandardItem*> theItem;
	theItem = model->findItems(Name);
	model->removeRow(theItem[0]->row());
}

bool Inventory::hasItem(QString Name)
{
	QList<QStandardItem *> test;
	test = model->findItems(Name);
	if(test.size() > 0){
		return true;
	}
	return false;
}

QDataStream &operator<<(QDataStream &out, const Inventory &inven)
{
	QStandardItem *item;
	out << inven.model->rowCount();
	for(int i = 0; i < inven.model->rowCount(); i++){
		item = inven.model->item(i);
		out << item->text();
	}
	return out;
}

QDataStream &operator>>(QDataStream &in, Inventory &inven)
{
	int rows;
	inven = Inventory();
	QString itemText;
	in >> rows;
	for(int i = 0; i < rows; ++i){
		in >> itemText;
		inven.addItem(itemText);
	}
	return in;
}
