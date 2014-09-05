#include "game.h"
#include <QDebug>
#include <QFile>

Game::Game()
{

}

QString Game::parseWorldInput(QString Text)
{
	QList<QString> words = Text.split(" ");
	if(words[0] == "hi"){
		return "Why, hello there!";
	} else if(words[0] == "north"){
		return movePlayer(Area::NORTH);
	} else if(words[0] == "east"){
		return movePlayer(Area::EAST);
	} else if(words[0] == "south"){
		return movePlayer(Area::SOUTH);
	} else if(words[0] == "west"){
		return movePlayer(Area::WEST);
	}
	return "Unknown command!";
}

QString Game::parseInvenInput(QString Text)
{
	QList<QString> words = Text.split(" ");
	QString verb = words[0];
	QString noun;
	for(int i = 1; i < words.count(); i++){
		noun = noun + words[i] + " ";
	}
	noun = noun.left(noun.length() - 1);

	if(verb == "take" && words.size() > 1){
		return take(noun);
	}
	if(verb == "drop" && words.size() > 1){
		return drop(noun);
	}
	return "Unknown command!";
}

QString Game::movePlayer(Area::Direction dir)
{
	QString nextArea;
	Area *thisArea = theAreas.find(thePlayer.Location);
	nextArea = thisArea->connectedTo[dir];
	if(nextArea != ""){
		thePlayer.setLocation(nextArea, &theAreas);
		thePlayer.moved = true;
		return "Moved to " + nextArea;
	}
	return "Can't move that way!";
}

QString Game::drop(QString Name)
{
	if(thePlayer.inven.hasItem(Name)){
		thePlayer.inven.removeItem(Name);
		theAreas.find(thePlayer.Location)->inven.addItem(Name);
		return "Dropped";
	}
	return "You don't have that item";

}

QString Game::take(QString Name)
{
	if(theAreas.find(thePlayer.Location)->inven.hasItem(Name)){
		thePlayer.inven.addItem(Name);
		theAreas.find(thePlayer.Location)->inven.removeItem(Name);
		return "Took";
	}
	return "That item isn't nearby";
}

QString Game::curDescription()
{
	return theAreas.find(thePlayer.Location)->Description;
}


QString Game::Save(QString fileName)
{
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly)){
		return "Could not open file!";
	} else {
		QDataStream out(&file);
		out.setVersion(QDataStream::Qt_5_2);
		out << thePlayer;
		int numAreas = theAreas.theAreas.size();
		out << numAreas;
		for(int i = 0; i < numAreas; i++){
			out << theAreas.theAreas[i];
		}
		file.flush();
		file.close();
	}
	return "Saved";
}

QString Game::Load(QString fileName)
{
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly)){
		return "Could not open file!";
	} else {
		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_5_2);
		in >> thePlayer;
		int numAreas;
		in >> numAreas;
		Area area;
		theAreas.clear();
		for(int i = 0; i < numAreas; i++){
			in >> area;
			theAreas.addArea(area);
		}
		file.flush();
		file.close();
		thePlayer.setLocation(thePlayer.Location, &theAreas);
	}
	return "Loaded";
}

QStandardItemModel *Game::playerInvenModel()
{
	return thePlayer.inven.model;
}

QStandardItemModel *Game::curAreaInvenModel()
{
	return theAreas.find(thePlayer.Location)->inven.model;
}
