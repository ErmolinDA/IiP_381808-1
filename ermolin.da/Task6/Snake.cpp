#include "Snake.h"
using namespace std;


const int m = 20;
const int n = 40;
char a[m][n];
deque<int> sn;
bool st = true;
int head, eat;

Snake::Snake()
{
}


Snake::~Snake()
{
}

void Snake::setConsoleColour(unsigned short colour)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleTextAttribute(hOut, colour);
}

void Snake::setCursorPosition(int y, int x)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

int Snake::EatAdd() {
	int x;
	do {
		x = rand() % (m*n);
	} while (a[x / n][x%n] != ' ' || x == head);
	return x;
}

bool Snake::FindEl(int head) {
	for (int i = 1; i < sn.size(); i++)
		if (head == sn[i])
			return true;
	return false;
}

void Snake::PrintSnake() {
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

int Snake::Joy(char a) {
	if (a == 72)
		return -n;
	if (a == 80)
		return n;
	if (a == 75)
		return -1;
	if (a == 77)
		return 1;
	return 0;
}

bool Snake::StepBool(char a) {
	head += Joy(a);
	if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
		cout << "Error";
		return false;
	}
	return true;
}

void Snake::Step(char ar) {

	head += Joy(ar);
	setCursorPosition(m + 2, 0);
	cout << head;
	if (head<n || head>(m - 1)*n || head % n == 0 || head % n == n - 1 || FindEl(head)) {
		st = false;
		cout << "Error";
	}
	else {
		if (head == eat) {
			eat = EatAdd();
			setCursorPosition(eat / n, eat % n);
			cout << '&';
			setCursorPosition(sn.front() / n, sn.front() % n);
			cout << '@';
			sn.push_front(head);
			setCursorPosition(sn.front() / n, sn.front() % n);
			cout << '0';

			setCursorPosition(m + 1, 0);
			cout << "            ";
			setCursorPosition(m + 1, 0);
			for (int i = 0; i < sn.size(); i++) {
				cout << sn[i] << ' ';
			}
		}
		else {
			setCursorPosition(sn.front() / n, sn.front() % n);
			cout << '@';	
			sn.push_front(head);
			setCursorPosition(sn.back() / n, sn.back() % n);
			cout << ' ';
			sn.pop_back();
			setCursorPosition(sn.back() / n, sn.back() % n);
			cout << '@';
			
			setCursorPosition(sn.front() / n, sn.front() % n);
			cout << '0';

			setCursorPosition(m + 1, 0);
			cout << "            ";
			setCursorPosition(m + 1, 0);
			for (int i = 0; i < sn.size(); i++) {
				cout << sn[i] << ' ';
			}
		}

		setCursorPosition(m + 1, 0);
		cout << "            ";
		setCursorPosition(m + 1, 0);
		for (int i = 0; i < sn.size(); i++) {
			cout << sn[i] << ' ';
		}
	}
}

void Snake::Start()
{
	system("chcp 1251");//подключение кириллицы
	system("cls");
	head = n+1;
	sn.push_front(head);
	head = sn.front();
	PrintSnake();
	eat = EatAdd();

	setConsoleColour(BRIGHT_BLUE);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << endl;
	}

	setCursorPosition(eat / n, eat % n);
	cout << '&';
	//Step(' ');
	while (st) {
		char ax;
		ax = _getch();
		Step(ax);
	}
	system("cls");
	cout << "End Game";
}
