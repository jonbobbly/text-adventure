#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>
#include <QList>
#include <QDataStream>


class People
{
	public:
		People();
		QString Name;
		QList<QString> Prompts;		//These show up in list-view widget
		QList<QString> Responses;	//These show up when list-view item is picked.
};

QDataStream &operator<<(QDataStream &out, const People &people);
QDataStream &operator>>(QDataStream &in, People &people);

#endif // PEOPLE_H
