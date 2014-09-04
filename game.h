#ifndef GAME_H
#define GAME_H

#include "itemmanager.h"
#include "areamanager.h"
#include "player.h"

class Game
{
	public:
		Game();
		QString Save();
		QString Load();

		QString parseWorldInput(QString text);
		QString parseInvenInput(QString text);

		QString drop(QString Name);
		QString take(QString Name);
		QString movePlayer(Area::Direction dir);
		QString curDescription(); //Description of current room, i.e. thePlayer.Location
		QStandardItemModel *playerInvenModel();
		QStandardItemModel *curAreaInvenModel();

		ItemManager theItems;
		AreaManager theAreas;
		Player thePlayer;
};

#endif // GAME_H
