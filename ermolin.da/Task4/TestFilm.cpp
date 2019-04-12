#include<iostream>
#include<fstream>
#include <windows.h>
#include "FilmLib.h"

using namespace std;

void PrintMenu() {
	cout << "1) добавить фильм\n";
	cout << "2) изменить данные фильма выбранного по названию\n";
	cout << "3) найти фильм по названию и году\n";
	cout << "4) выдать все фильмы заданного режиссера\n";
	cout << "5) выдать все фильмы, вышедшие в прокат в выбранном году\n";
	cout << "6) выдать заданное число фильмов с наибольшими сборами\n";
	cout << "7) выдать заданное число фильмов с наибольшими сборами в выбранном году\n";
	cout << "8) узнать текущее число фильмов\n";
	cout << "9) удалить фильм по названию\n";
	cout << "10) выгрузить библиотеку в файл\n";
	cout << "0) выход\n\n\n\n\n";
}

int main()
{
	system("chcp 1251");//подключение кириллицы
	FilmLib a;
	ifstream fi("text1.txt");
	fi >> a;
	fi.close();
	a.SortDate();
	a.SortName();
	ofstream fo("text1.txt");
	while (1) {
		int k;
		system("cls");
		PrintMenu();
		cin >> k;
		getchar();
		system("cls");
		switch (k)
		{
		case(1):
			a.AddFilm();
			a.SortDate();
			a.SortName();
			getchar();
			break;
		case(2): {
			cout << "Введите название фильма: ";
			char n[200];
			cin >> n;
			a.FormatFilm(n);
			getchar();
			getchar();
			break; }
		case(3): {
			cout << "Введите название фильма: ";
			char n[200];
			cin >> n;
			cout << "Введите год";
			int y;
			cin >> y;
			a.SearchFilm(n, y);
			getchar();
			getchar();
			break; }
		case(4): {
			cout << "Введите имя режиссера: ";
			char n[200];
			cin >> n;
			a.SearchDir(n);
			getchar();
			getchar();
			break; }
		case(5): {
			cout << "Введите год: ";
			int y;
			cin >> y;
			a.SearchFilm(y);
			getchar();
			getchar();
			break; }
		case(6): {
			cout << "Введите число фильмов: ";
			int y;
			cin >> y;
			a.SearchMoney(y);
			getchar();
			getchar();
			break; }
		case(7): {
			cout << "Введите год: ";
			int y;
			cin >> y;
			cout << "Введите число фильмов: ";
			int x;
			cin >> x;
			a.SearchMoney(x, y);
			getchar();
			getchar();
			break; }
		case(8):			
			cout << "Количество фильмов: " << a.GetNum();
			getchar();
			getchar();
			break;
		case(9): {
			cout << "Введите название фильма: ";
			char n[200];
			cin >> n;
			a.DeleteFilm(n);
			a.SortDate();
			a.SortName();
			getchar();
			getchar();
			break; }
		case(10):
			a.SortDate();
			a.SortName();
			fo << a;
			break;
		case(0):
			a.SortDate();
			a.SortName();
			fo.clear();
			fo << a;
			fo.close();
			return 0;
		default:
			break;
		}
	}
	return 0;
}