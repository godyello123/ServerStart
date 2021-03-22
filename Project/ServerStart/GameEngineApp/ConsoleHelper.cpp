#include "ConsoleHelper.h"
#include <Windows.h>
#include <iostream>

GEVector ConsoleHelper::m_Size;
int ConsoleHelper::m_LineSize;

GEVector ConsoleHelper::GetCenter()
{
	return {m_Size.CenterX()+m_LineSize,m_Size.CenterY() + m_LineSize };
}

void ConsoleHelper::Init(const GEVector& _Size, int _LineSize, wchar_t _Line)
{
	setlocale(LC_ALL, "KOR");

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	m_Size = _Size;
	m_LineSize = _LineSize;

	//À­ÂÊ º®
	for (int y = 0; y < _LineSize; ++y)
	{
		for (int x = 0; x < _Size.ix() + _LineSize * 2; ++x)
		{
			ConsolePosPrint({ x,y }, _Line);
			ConsolePosPrint({ x,y + _Size.ix() + _LineSize }, _Line);
		}
	}

	for (int x = 0; x < _LineSize; ++x)
	{
		for (int y = 0; y < _Size.iy() + _LineSize * 2; ++y)
		{
			ConsolePosPrint({ x,y }, _Line);
			ConsolePosPrint({ x + _Size.iy() + _LineSize,y  }, _Line);
		}
	}
}

void ConsoleHelper::ConsolePosMove(const GEVector& vPos)
{
	COORD Cur;
	Cur.X = vPos.ix()*2;
	Cur.Y = vPos.iy();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void ConsoleHelper::ConsolePosPrint(const GEVector& vPos,const wchar_t* str)
{
	ConsolePosMove(vPos);

	wprintf_s(str);
}

void ConsoleHelper::ConsolePosPrint(const GEVector& vPos, wchar_t str)
{
	wchar_t Arr[2] = { str, };

	ConsolePosPrint(vPos, Arr);
}

void ConsoleHelper::ConsolePosClear(const GEVector& vPos)
{
	ConsolePosPrint(vPos, L"  ");
}
