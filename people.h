#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>

class People
{
	public:
		People();
		QString Name;
		QList<QString> Prompts;		//These show up in list-view widget
		QList<QString> Responses;	//These show up when list-view item is picked.
};

#endif // PEOPLE_H
