#pragma once
#include "Film.h"
class FilmLib
{
private:
	int num;//кол-во фильмов
	int LibCount = 100;//буфер библиотеки
	Film *Lib;// массив фильмов
	
	Film CreateFilm();//функция создания фильма
public:
	FilmLib();
	~FilmLib();

	void SortDate();//сортировка по дате
	void SortMoney();//сортировка по сборам
	void SortName();//сортировка по именам фильмов одного года
	int GetNum() { return num; };//количество фильмов
	int SearchFilm(char []);//поиск фильма по названию
	int SearchFilm(char a[], int c);//поиск по названию и году
	void SearchFilm(int c);//поиск всех фильмов одного года
	void SearchDir(char a[]);//поиск всех фильмов одного режиссера
	void SearchMoney(int c);//первые С фильмов по сборам
	void SearchMoney(int c, int y);//первые С фильмов по сборам в году Y
	void FormatFilm(char a[]);//редактирование фильма по названию
	void AddFilm();//добавление фильма
	void DeleteFilm(char a[]);//удаление по названию

	friend ofstream& operator<< (ofstream& stream, const FilmLib & b);//перегрузка вывода в файл
	friend ifstream& operator>> (ifstream& stream, FilmLib & b);//перегрузка ввода из файла
};

