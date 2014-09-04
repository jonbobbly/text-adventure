#ifndef AREA_H
#define AREA_H

#include <QString>
#include "inventory.h"
#include "people.h"

class Area
{
	public:
		Area();
		QString dispName;  //Display Name, the name that the player sees
		QString refName;   //Reference Name, the name that is used internally to identify the area.
		QString Description;
		Inventory inven;
		QList<People> people;  //TODO: add to save and load functions.
		QList<QString> connectedTo;

		enum Direction {NORTH = 0, EAST, SOUTH, WEST};

};

QDataStream &operator<<(QDataStream &out, const Area &area);
QDataStream &operator>>(QDataStream &in, Area &area);

#endif // AREA_H
