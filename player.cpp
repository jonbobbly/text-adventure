#include "player.h"

Player::Player()
{
	moved = false;
}

bool Player::hasMoved()
{
	if(moved){
		moved = false;
		return true;
	}
	return false;
}
void Player::setLocation(QString refName, AreaManager *mgr)
{
	Location = refName;
	dispLocation = mgr->find(refName)->dispName;
}

QDataStream &operator<<(QDataStream &out, const Player &player)
{
	out << player.Location;
	out << player.inven;
	return out;
}
QDataStream &operator>>(QDataStream &in, Player &player)
{
	player = Player();
	in >> player.Location;
	in >> player.inven;
	return in;
}
