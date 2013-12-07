#ifndef _UTILS_H_
#define _UTILS_H_

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

	static void GoToXY(int x, int y)
	{
		COORD pos = {x, y};
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}

	static void HideCursor(void) 
	{
		HANDLE hdl;
		hdl = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO t;
		t.bVisible = false;
		SetConsoleCursorInfo(hdl, &t);
	}

	static bool RandomDecision(int prob)
	{
		int aux = rand() % 100;
		return (aux <= prob);
	}

	static int RandomInt(int min, int max)
	{
		int aux = (rand() % (max - min)) + min;
		return aux;
	}

	static void Color(int X)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
	}
		
#endif