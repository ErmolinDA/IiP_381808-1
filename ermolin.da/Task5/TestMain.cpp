#include<iostream>
#include<fstream>
#include <windows.h>
#include "ProcCenter.h"

using namespace std;
ProcCenter center;

void DepMenu(int cl,int d) {//работа с депозитом
	int x;
	while (1) {
		system("cls");
		cout << center.arr[cl].Dep[d].name << endl;
		cout << "Количество средств  - " << center.arr[cl].Dep[d].GetMoney()<<endl;
		cout << "1)Снять проценты\n";
		cout << "2)Закрыть счет\n";
		cout << "3)Назад\n";
		cin >> x;
		switch (x)
		{
		case(1): {//снятие процентов с открытого депозита
			system("cls");
			double s = center.arr[cl].Dep[d].Procent();
			center.arr[cl].Money += s;
			cout << "Средства переведены " << s << endl;
			getchar();
			getchar();
			break;
		}
		case(2)://закрытие депозита
			if (!center.arr[cl].Dep[d].op) {
				cout << "Счет " << center.arr[cl].Dep[d].name << " закрыт";
				center.arr[cl].Money += center.arr[cl].Dep[d].GetMoney();
				center.arr[cl].Dep.erase(center.arr[cl].Dep.begin() + d);
				getchar();
				getchar();
				return;
			}
			else cout << "Счет не может быть закрыт";
			getchar();
			getchar();
			break;
		case(3):
			return;
			break;
		default:
			break;
		}
	}
}

void Menu2(int l) {
	int n;
	while (1) {
		system("cls");
		cout << "Клиент - " << center.arr[l].Name << endl;
		cout << "1) Денег на счете\n";
		cout << "2) Открытые депозиты\n";
		cout << "3) Новый депозит\n";
		cout << "0) Назад\n";
		cin >> n;
		switch (n)
		{
		case(1)://сумма на счете
			system("cls");
			cout << "Количество средств  - " << center.arr[l].Money;
			getchar();
			getchar();
			break;
		case(2)://меню открытых депозитов
			int i, m;
			system("cls");
			for (i = 0; i < center.arr[l].Dep.size(); i++)
				cout << i+1<<")" <<center.arr[l].Dep[i].name<<endl;
			cout << i+1 << ") Назад\n";
			cout << "Выберите депозит\n";
			cin >> m;
			if (m - 1 < center.arr[l].Dep.size())
				DepMenu(l, m-1);
			break;
		case(3): {//создание нового депозита
			int x;
			double y;
			system("cls");//выбор срока депозита
			cout << "1)На 3 месяца\n";
			cout << "2)На 6 месяцев\n";
			cout << "3)На 1 год\n";
			cout << "4)На 3 года\n";
			cin >> x;
			if (!(x > 0 && x < 5)) {
				cout << "Ошибка ввода";
				break;
			}

			system("cls");//выбор суммы и процентнов годовых
			cout << "Вклад до 100 тыс. процент - " << 5 + x * 0.2 << "%" << endl;
			if (center.arr[l].Money > 100000)
				cout << "Вклад от 100 до 500 тыс. процент - " << 5 + x * 0.4 << "%" << endl;
			if (center.arr[l].Money > 500000)
				cout << "Вклад от 500 тыс. до 1 млн. процент - " << 5 + x * 0.6 << "%" << endl;
			if (center.arr[l].Money > 1000000)
				cout << "Вклад от 1 млню процент - " << 5 + x * 0.8 << "%" << endl;
			cout << "Введите сумму\n";
			cin >> y;
			if (y<0 || y>center.arr[l].Money) {
				cout << "Некорректная сумма";
				break;
			}
			system("cls");
			string nam;
			cout << "Введите название депозита\n";
			cin >> nam;
			center.arr[l].NewDep(nam, y, x);
			break; 
		}
		case(0):
			return;
			break;
		default:
			break;
		}
	}
}

int main()
{
	int x;
	system("chcp 1251");//подключение кириллицы
	center.st.day = 1;
	center.st.month = 1;
	center.st.year = 2000;
	center.ActualData();
	while (true) {
		system("cls");
		cout << "Текущая дата - " << center.st.day << "." << center.st.month << "." << center.st.year << endl;
		cout << "1) Создать пользователя\n";
		cout << "2) Войти в аккаунт\n";
		cout << "3) Перейти к дате\n";
		cout << "0) Выход\n";
		cin >> x;
		switch (x)
		{
		case(1): {//Создание пользователя
			system("cls");
			string a, b;
			double m;
			int n;
			cout <<"Введите имя пользователя\n";
			getline(cin,a);
			cout<<"Придумайте пароль\n";
			cin >> b;
			cout << "Введите номер карты\n";
			cin >> n;
			cout<<"Введите количество средст на карте\n";
			cin >> m;
			center.NewClient(n,a,b,m);
			break; 
		}
		case(2): {//вход в аккаунт
			int a;
			string b1;
			system("cls");
			cout << "Введите номер карты\n";
			cin >> a;
			cout << "Введите пароль\n";
			cin >> b1;
			int l = center.Login(a, b1);
			if (l < 0) {
				cout << "\nОшибка входа";
				getchar();
				getchar();
			}
			else Menu2(l);
			break; 
		}
		case(3)://ввод новой даты
			Data a1;
			char a2;
			system("cls");
			cout << "Введите дату\n";
			cin >> a1.day >> a2 >> a1.month >> a2 >> a1.year;
			if (center.CorrectData(a1)) {
				while (!(center.st == a1)) {
					center.st.day++;
					center.ActualData();
					center.ActualDep();
				}
			}
			getchar();
			break;
		case(0):
			return 0;
		default:
			break;
		}
	}
	return 0;
}