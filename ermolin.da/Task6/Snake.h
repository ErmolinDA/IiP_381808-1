#pragma once
#include<iostream>
#include <windows.h>
#include <conio.h>
#include <deque>

class Snake
{
	const unsigned short DARK_BLUE = FOREGROUND_BLUE;
	const unsigned short BRIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;


	void setConsoleColour(unsigned short colour);//цвет консоли
	void setCursorPosition(int y, int x);//позиция курсора
	int EatAdd();//добавить еду на поле
	bool FindEl(int head);//пересечение головы с телом
	void PrintSnake();//отрисовка поля
	int Joy(char a);//управление
	bool StepBool(char a);//возможность шага
	void Step(char ar);//шаг


public:
	Snake();
	~Snake();
	void Start();//запуск
};

