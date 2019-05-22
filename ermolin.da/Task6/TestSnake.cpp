#include<iostream>
#include <windows.h>
#include "Snake.h"

using namespace std;
/*
const unsigned short DARK_BLUE = FOREGROUND_BLUE;
const unsigned short BRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

const int m = 20;
const int n = 30;
char a[m][n];
deque<int> sn;
bool st = true;
int head,eat;

void setConsoleColour(unsigned short colour)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleTextAttribute(hOut, colour);
}

void setCursorPosition(int y, int x)
{
	y++;
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

int EatAdd() {
	int x;
	do {
		x = rand()%(m*n);
	} while (a[x / n][x%n] != ' ' || x == head);
	return x;
}

bool FindEl(int head) {
	for (int i = 1; i < sn.size(); i++)
		if (head == sn[i])
			return true;
	return false;
}

void PrintSnake() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = ' ';
	for (int i = 0; i < n; i++)
	{
		a[0][i] = '#';
		a[m - 1][i] = '#';
	}
	for (int j = 0; j < m; j++) {
		a[j][0] = '#';
		a[j][n - 1] = '#';
	}

}

int Joy(char a) {
	if (a == 'w')
		return -n;
	if (a == 's')
		return n;
	if (a == 'a')
		return -1;
	if (a == 'd')
		return 1;
	return 0;
}

bool StepBool(char a) {
	head += Joy(a);
	if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
		cout << "Error";
		return false;
	}
	return true;
}

void Step(char ar) {

	head += Joy(ar);
	if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
		st = false;
		cout << "Error";
	}
	else {
		if (head == eat) {
			eat = EatAdd();
			setCursorPosition(eat / n, eat%n);
			cout << '&';
			setCursorPosition(sn.front() / n, sn.front()%n);
			cout << '@';
			sn.push_front(head);
			setCursorPosition(sn.front() / n, sn.front()%n);
			cout << '0';
		}
		else {
			setCursorPosition(eat / n, eat%n);
			cout << '&';
			setCursorPosition(sn.front() / n, sn.front() % n);
			cout << '@';
			sn.push_front(head);
			setCursorPosition(sn.front() / n, sn.front()%n);
			cout << '0';
			setCursorPosition(sn.back() / n, sn.back()%n);
			cout << ' ';
			sn.pop_back();
		}

		setCursorPosition(m+1, 0);
	}
}

void ModArray() {

}
*/
int main()
{

	int x;
	/*sn.push_front(37);

	head = sn.front();
	PrintSnake();
	eat = EatAdd();

	setConsoleColour(BRIGHT_BLUE);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << endl;
	}

	while(st) {
		//system("cls");

		char ax;
		ax = _getch();
		Step(ax);
	}
	system("cls");
	cout<<"End Game";

		
	*/
	Snake a;
	a.Start();
	return 0;
}