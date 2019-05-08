#pragma once
#include <string>

using namespace std;
class Data {
public:
	int day;
	int month;
	int year;
	bool operator==(const Data &);//перегрузка операция сравнения
};

class Deposit
{		
	Data e;//дата окончания депозита
	int per = 0;//кол-во дней с прошлого зачисления процентов
	double money;//количество денег на депозите
	double St_money;//сумма вклада
	double koef;//процент денег за день
public:
	string name;//название счета
	bool op;//можно ли закрыть счет
	void Recomend(double a,int b,Data x);//функция определения процентной ставки
	double Procent();//функция списания процентов
	void Actual(Data a);//функция начисления процентов проценты начисляются каждый первый день месяца и в день окончания депозита
	void SetMoney(double a) {money = St_money = a; }//ввод начальной суммы
	double GetMoney() { return money; }//вывод текущего количества средств
	Deposit();
	~Deposit();
};