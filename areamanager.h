#ifndef AREAMANAGER_H
#define AREAMANAGER_H

#include "area.h"

class AreaManager
{
	public:
		AreaManager();
		void addArea(QString dispName, QString refName, QString Description, QString North, QString East, QString South, QString West);
		void addArea(Area area);
		Area *find(QString refName);
		void clear();

		QList<Area> theAreas;
};

#endif // AREAMANAGER_H
