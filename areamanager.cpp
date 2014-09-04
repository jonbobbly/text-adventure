#include "areamanager.h"

AreaManager::AreaManager()
{

}

void AreaManager::addArea(QString dispName, QString refName, QString Description, QString North, QString East, QString South, QString West)
{
	Area newArea;
	newArea.dispName = dispName;
	newArea.refName = refName;
	newArea.Description = Description;
	newArea.connectedTo[Area::NORTH] = North;
	newArea.connectedTo[Area::EAST] = East;
	newArea.connectedTo[Area::SOUTH] = South;
	newArea.connectedTo[Area::WEST] = West;
	theAreas.append(newArea);
}

void AreaManager::addArea(Area area)
{
	theAreas.append(area);
}

Area *AreaManager::find(QString refName)
{
	for(int i = 0; i < theAreas.size(); i++){
		if(theAreas[i].refName == refName){
			return &theAreas[i];
		}
	}
	return NULL;
}

void AreaManager::clear()
{
	theAreas.clear();
}
