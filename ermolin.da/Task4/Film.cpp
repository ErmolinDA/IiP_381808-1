#include "Film.h"

Film::Film()
{
}

Film::~Film()
{
}

ofstream& operator<<(ofstream & stream, const Film & b)
{
	stream << b.name << endl;
	stream << b.dir << endl;
	stream << b.script << endl;
	stream << b.music << endl;
	stream << b.money << endl;
	stream << b.date.day << '.' << b.date.month << '.' << b.date.year << endl;
	return stream;
}

ifstream& operator>>(ifstream & stream, Film & b)
{
	char a;
	stream >> b.name;
	stream >> b.dir;
	stream >> b.script;
	stream >> b.music;
	stream >> b.money;
	stream >> b.date.day;
	stream >> a;
	stream >> b.date.month;
	stream >> a;
	stream >> b.date.year;
	return stream;
}
