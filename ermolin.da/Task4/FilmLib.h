#pragma once
#include "Film.h"
class FilmLib
{
private:
	int num;
	Film *Lib;
	
	Film CreateFilm();
public:
	FilmLib();
	~FilmLib();

	void SortDate();
	void SortMoney();
	void SortName();
	int GetNum() { return num; };
	int SearchFilm(char []);
	int SearchFilm(char a[], int c);
	void SearchFilm(int c);
	void SearchDir(char a[]);
	void SearchMoney(int c);
	void SearchMoney(int c, int y);
	void FormatFilm(char a[]);
	void AddFilm();	
	void DeleteFilm(char a[]);

	friend ofstream& operator<< (ofstream& stream, const FilmLib & b);//перегрузка вывода
	friend ifstream& operator>> (ifstream& stream, FilmLib & b);
};

