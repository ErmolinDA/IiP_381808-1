#include "FilmLib.h"

using namespace std;

FilmLib::FilmLib()
{

}

FilmLib::~FilmLib()
{
}

int FilmLib::SearchFilm(char a[])
{
	for (int i = 0; i < num; i++) 
	{
		if (!strcmp(a,Lib[i].name))
			return i;
	}
	return -1;
}

int FilmLib::SearchFilm(char a[],int c)
{
	for (int i = 0; i < num; i++)
	{
		if (!strcmp(a, Lib[i].name) && c == Lib[i].date.year)
			return i;
	}
	return -1;
}

void FilmLib::SearchFilm(int c)
{
	int k = 0;
	for (int i = 0; i < num; i++)
		if (c == Lib[i].date.year) {
			cout << Lib[i].name << endl;
			k++;
		}
	if (k == 0)
		cout << "Фильмы не найдены" << endl;
}

void FilmLib::SearchDir(char a[])
{
	int k = 0;
	for (int i = 0; i < num; i++) 
	{
		if (!strcmp(a, Lib[i].dir))
			cout << Lib[i].name << endl;
	}
	if (k == 0)
		cout << "Фильмы не найдены" << endl;
}

void FilmLib::SearchMoney(int c)
{
	SortMoney();
	try {
		for (int i = 0; i < c; i++)
			cout << Lib[i].name << endl;
	}
	catch (exception a) {
		cout << "Количество фильмов меньше введенного числа";
	}
}

void FilmLib::SearchMoney(int c, int y)
{
	SortMoney();
	try {
		int k = 0;
		for (int i = 0; i < num&&k<c; i++)
		{
			if (y == Lib[i].date.year) {
				cout << Lib[i].name << endl;
				k++;
			}
		}
		if (k < c)
			throw;
	}
	catch (exception a) {
		cout << "Количество удовлетворяющих фильмов меньше введенного числа";
	}
}

void FilmLib::FormatFilm(char a[])
{	
	Lib[SearchFilm(a)] = CreateFilm();
}

Film FilmLib::CreateFilm() 
{
	char c;
	Film a = Film();
	cout << "Название фильма: ";
	cin >> a.name;	
	cout << "Режиссер: ";
	cin >> a.dir;
	cout << "Сценарист: ";
	cin >> a.script;
	cout << "Композитор: ";
	cin >> a.music;	
	cout << "Финансовые сборы: ";
	cin >> a.money;	
	cout << "Дата выхода: ";
	cin >> a.date.day;
	cin >> c;
	cin >> a.date.month;
	cin >> c;
	cin >> a.date.year;
	return a;
}

void FilmLib::SortDate()
{
	Film x;
	for (int i = 0,j; i < num; i++)
	{
		x = Lib[i];
		for (j = i - 1; j >= 0 && Lib[j].date.year < x.date.year; j--)
		{
			Lib[j + 1] = Lib[j];
		}
		Lib[j + 1] = x;
	}
}

void FilmLib::SortMoney()
{
	Film x;
	for (int i = 0, j; i < num; i++)
	{
		x = Lib[i];
		for (j = i - 1; j >= 0 && Lib[j].money < x.money; j--)
		{
			Lib[j + 1] = Lib[j];
		}
		Lib[j + 1] = x;
	}
}

void FilmLib::SortName()
{
	Film x;
	for (int i = 0, j; i < num; i++)
	{
		x = Lib[i];
		for (j = i - 1; j >= 0 && 0<strcmp(Lib[j].name, x.name)&&Lib[j].date.year==x.date.year; j--)
		{
			Lib[j + 1] = Lib[j];
		}
		Lib[j + 1] = x;
	}
}

void FilmLib::AddFilm()
{
	Film a = CreateFilm();
	if (num >= LibCount) {
		Film *A = new Film[num + 1];
		for (int i = 0; i < num; i++)
			A[i] = Lib[i];
		A[num] = a;
		LibCount++; num++;
		Lib = new Film[num];
		Lib = A;
	}
	else {
		Lib[num] = a;
		num++;
	}
	SortDate();
	SortName();
}

void FilmLib::DeleteFilm(char a[])
{
	int c;
	try 
	{
		c = SearchFilm(a);
		if (c < 0)
			throw 1;
	}
	catch(int a)
	{
		cout << "Фильм не найден" << endl;
		getchar();
		getchar();
		return;
	}
	for (int i = c + 1; i < num; i++)
		Lib[i - 1] = Lib[i];
	num--;
}

ofstream & operator<<(ofstream & stream, const FilmLib & b)
{
	stream << b.num << endl;
	for (int i = 0; i < b.num; i++)
		stream << b.Lib[i];
	return stream;
}

ifstream & operator>>(ifstream & stream, FilmLib & b)
{
	stream >> b.num;
	if (b.num > b.LibCount)
		b.LibCount = b.num;
	b.Lib = new Film[b.LibCount];
	for (int i = 0;i<b.num; i++)
		stream >> b.Lib[i];
	return stream;
}
