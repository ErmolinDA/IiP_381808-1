#include "Deposit.h"
void Deposit::Recomend(double a, int b, Data x)
{
	koef = 0.05;
	if (a < 100000) {
		e.day = x.day;
		e.month = x.month+3;
		e.year = x.year;
		if (x.month + 3 > 12) {
			e.year = x.year - 12;
			e.month = x.month + 3 - 12;
		}
		koef += 0.002;
	}
	else if (a < 500000) {
		e.day = x.day;
		e.month = x.month+6;
		e.year = x.year;
		if (x.month + 6 > 12) {
			e.year = x.year - 12;
			e.month = x.month + 6 - 12;
		}
		koef += 0.004;
	}
	else if (a < 1000000) {
		koef += 0.06;
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 1;
	}
	else {
		koef += 0.008;
		e.day = x.day;
		e.month = x.month;
		e.year = x.year + 3;
	}
	switch (b)
	{
	case(1):
		koef += 0.002;
		break;
	case(2):
		koef += 0.004;
		break;
	case(3):
		koef += 0.006;
		break;
	case(4):
		koef += 0.008;
		break;
	default:
		break;
	}

}

double Deposit::Procent()
{
	double a = money - St_money;
	money -= a;
	return a;
}

void Deposit::Actual(Data a)
{
	per++;
	if (op) {
		if (a.day == 1) {
			money = money + (St_money * koef*per / 365);
			per = 0;
		}
	}
	if (e.day == a.day&&e.month == a.month&&e.year==a.year) {
		money = money + (St_money * koef*per / 365);
		per = 0;
		op = false;
	} 
}

Deposit::Deposit()
{
	
}

Deposit::~Deposit()
{
}

bool Data::operator==(const Data &a)
{
	if(this->day == a.day&&month==a.month&&year==a.year)
		return true;
	else return false;
}