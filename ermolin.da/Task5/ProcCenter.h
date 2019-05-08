#pragma once
#include <string>
#include <vector>
#include "Deposit.h"

using namespace std;
class Client
{
public:
	int num;//номер карты
	string Name;//имя клиента
	string Pass;//пароль
	vector<Deposit> Dep;//список всех депозитов
	double Money;//количество денег клиента
	void NewDep(string n, double m, int d);//функция добавления нового депозита
};

class ProcCenter
{	
public:
	vector<Client> arr;//список клиентов
	void ActualData();//функция работы с датой
	void ActualDep();//обновление депозитов в соответствии с датой
	bool CorrectData(Data a);//перевод дней в месяцы и тд.
	Data st;//актуальная дата
	int Login(int num, string pass);//функция входа пользователя
	void NewClient(int n,string name,string pass,double money);//функция добавления клиента
	ProcCenter();
	~ProcCenter();
};