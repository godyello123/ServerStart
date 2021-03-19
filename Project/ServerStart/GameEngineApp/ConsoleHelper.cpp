#include "ConsoleHelper.h"
#include <Windows.h>
#include <iostream>

GEVector ConsoleHelper::m_Size;

void ConsoleHelper::Init(const GEVector& _Size, int _LineSize, char _Line)
{
	//À­ÂÊ º®
	for (int i = 0; i < _Size.ix() + _LineSize * 2; ++i)
	{
		for (int j = 0; j < _LineSize; ++j)
		{
			MoveConsolePrint({ i,j }, _Line);
		}
	}


	for (int i = 0; i < _LineSize; ++i)
	{
		for (int j = 0; j < _Size.iy() + _LineSize * 2; ++j)
		{
			MoveConsolePrint({ i + _Size.iy() + _LineSize,j }, _Line);
		}
	}


	//¿ÞÂÊ
	for (int j = 0; j < _LineSize; ++j)
	{
		for (int i = 0; i < _Size.iy() + _LineSize * 2; ++i)
		{
			MoveConsolePrint({ j ,i }, _Line);
		}
	}

	for (int i = 0; i < _Size.ix() + _LineSize * 2; ++i)
	{
		for (int j = 0; j < _LineSize; ++j)
		{
			MoveConsolePrint({ i,j + _Size.ix() + _LineSize }, _Line);
		}
	}
}

void ConsoleHelper::MoveConsolePos(const GEVector& _vPos)
{
	COORD Cur;
	Cur.X = _vPos.ix();
	Cur.Y = _vPos.iy();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ConsoleHelper::MoveConsolePrint(const GEVector& vPos, char _ch)
{
	MoveConsolePos(vPos);

	char Arr[2] = { _ch, };

	printf_s(Arr);
}
