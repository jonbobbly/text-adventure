#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
#include "areamanager.h"
#include <QDataStream>

class Player
{
	public:
		Player();
		bool hasMoved();
		void setLocation(QString refName, AreaManager *mgr);

		QString Location;
		QString dispLocation; //Display name of current area
		Inventory inven;
		bool moved;
};

QDataStream &operator<<(QDataStream &out, const Player &player);
QDataStream &operator>>(QDataStream &in, Player &player);

#endif // PLAYER_H
