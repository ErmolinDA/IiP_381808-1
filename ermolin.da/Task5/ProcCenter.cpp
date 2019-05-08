#include "ProcCenter.h"

Data s;
void ProcCenter::ActualData()
{
	if (st.month == 1 || st.month == 3 || st.month == 5 || st.month == 7 || st.month == 8 || st.month == 10 || st.month == 12) {
		if (st.day == 32) {
			st.day = 1;
			st.month++;
			if (st.month == 13) {
				st.year++;
				st.month = 1;
			}
		}
	}
	else if (st.month == 4 || st.month == 6 || st.month == 9 || st.month == 11) {
		if (st.day == 31) {
			st.day = 1;
			st.month++;
		}
	}
	else if (!st.year % 4) {
		if (st.day == 30) {
			st.day = 1;
			st.month++;
		}
	}
	else if (st.day == 29) {
		st.day = 1;
		st.month++;
	}
	s.day = st.day;
	s.month = st.month;
	s.year = st.year;
}

void ProcCenter::ActualDep()
{
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[i].Dep.size(); j++) {
			arr[i].Dep[j].Actual(st);
		}
}

bool ProcCenter::CorrectData(Data a)
{
	if (a.year < st.year)
		return false;
	else if (a.month < st.month&&a.year==st.year)
		return false;
	else if (a.day < st.day&&a.month == st.month&&a.year == st.year)
		return false;
	if (a.month > 12)
		return false;
	if (st.month == 1 || st.month == 3 || st.month == 5 || st.month == 7 || st.month == 8 || st.month == 10 || st.month == 12) {
		if (st.day > 31) {
			return false;
		}
	}
	else if (st.month == 4 || st.month == 6 || st.month == 9 || st.month == 11) {
		if (st.day > 30) {
			return false;
		}
	}
	else if (!st.year % 4) {
		if (st.day > 29) {
			return false;
		}
	}
	else if (st.day > 28) {
		return false;
	}
	return true;
}

int ProcCenter::Login(int num, string pass)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].num == num)
			if (arr[i].Pass == pass)
				return i;
			else return -1;
	}
	return -1;
}

void ProcCenter::NewClient(int n, string name, string pass, double money)
{
	Client a1;
	a1.Money = money;
	a1.Name = name;
	a1.Pass = pass;
	a1.num = n;
	arr.push_back(a1);
}


ProcCenter::ProcCenter()
{
}

ProcCenter::~ProcCenter()
{
}

void Client::NewDep(string n, double m, int d)
{
	Deposit a;
	a.name = n;
	a.Recomend(m,d,s);
	a.SetMoney(m);
	Dep.push_back(a);
	Money -= m;
}