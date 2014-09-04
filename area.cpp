#include "area.h"

Area::Area()
{
	for(int i = 0; i < 4; i++){
		connectedTo.append("");
	}
}

QDataStream &operator<<(QDataStream &out, const Area &area)
{
	out << area.dispName;
	out << area.refName;
	out << area.Description;
	out << area.connectedTo[Area::NORTH];
	out << area.connectedTo[Area::EAST];
	out << area.connectedTo[Area::WEST];
	out << area.connectedTo[Area::SOUTH];
	out << area.inven;
	return out;
}

QDataStream &operator>>(QDataStream &in, Area &area)
{
	area = Area();
	in >> area.dispName;
	in >> area.refName;
	in >> area.Description;
	in >> area.connectedTo[Area::NORTH];
	in >> area.connectedTo[Area::EAST];
	in >> area.connectedTo[Area::WEST];
	in >> area.connectedTo[Area::SOUTH];
	in >> area.inven;
	return in;
}
