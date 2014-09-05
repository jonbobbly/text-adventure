#include "people.h"

People::People()
{
}

QDataStream &operator<<(QDataStream &out, const People &people)
{
	out << people.Name;
	out << people.Prompts.size();
	for(int i = 0; i < people.Prompts.size(); i++){
		out << people.Prompts[i];
	}
	out << people.Responses.size();
	for(int i = 0; i < people.Responses.size(); i++){
		out << people.Responses[i];
	}
	return out;

}

QDataStream &operator>>(QDataStream &in, People &people)
{
	int size;
	in >> people.Name;
	in >> size;
	for(int i = 0; i < size; i++){
		QString text;
		in >> text;
		people.Prompts.append(text);
	}
	in >> size;
	for(int i = 0; i < size; i++){
		QString text;
		in >> text;
		people.Responses.append(text);
	}
	return in;
}
