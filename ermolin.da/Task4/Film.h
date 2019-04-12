#pragma once
#include <fstream>
#include <iostream>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};
class Film
{
public:
	char name[200];
	char dir[100];
	char script[100];
	char music[100];
	long long int money;
	Date date;

	Film();
	~Film();

	friend ofstream& operator<< (ofstream& stream, const Film & b);//перегрузка вывода
	friend ifstream& operator>> (ifstream& stream, Film & b);
};

