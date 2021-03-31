#include "ConsoleHelper.h"
#include <Windows.h>
#include <iostream>

GEVector ConsoleHelper::m_Size = { 3, 3 };
int ConsoleHelper::m_LineSize = 1;

GEVector ConsoleHelper::GetSize()
{
	return m_Size;
}

GEVector ConsoleHelper::GetCenter()
{
	return { m_Size.hix() + m_LineSize, m_Size.hiy() + m_LineSize };
}


// 012345678
//0&&&&&&&&&
//1&&&&&&&&&
//2&&*****&&
//3&&*****&&
//4&&*****&&
//5&&*****&&
//6&&*****&&
//7&&&&&&&&&
//8&&&&&&&&&
// Line2

bool ConsoleHelper::IsWall(GEVector _Pos)
{
	if (m_LineSize - 1 >= _Pos.ix())
	{
		return true;
	}

	if (m_LineSize - 1 >= _Pos.iy())
	{
		return true;
	}

	//    5              2
	if (m_Size.ix() + m_LineSize <= _Pos.ix())
	{
		return true;
	}

	if (m_Size.iy() + m_LineSize <= _Pos.iy())
	{
		return true;
	}

	return false;
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

	// 벽이 그려져야죠?

	// 윗벽만 생각한다.

	// 위 아래
	for (int y = 0; y < _LineSize; y++)
	{
		for (int x = 0; x < _Size.ix() + _LineSize * 2; x++)
		{
			ConsolePosPrint({ x,y }, _Line, false);
			ConsolePosPrint({ x,_Size.iy() + _LineSize + y }, _Line, false);
		}
	}

	// 오른쪽 왼쪽
	for (int x = 0; x < _LineSize; x++)
	{
		for (int y = 0; y < _Size.ix() + _LineSize * 2; y++)
		{
			ConsolePosPrint({ x,y }, _Line, false);
			ConsolePosPrint({ _Size.ix() + _LineSize + x , y }, _Line, false);
		}
	}

}

void ConsoleHelper::ConsolePosMove(const GEVector& _Pos)
{
	COORD Cur;
	Cur.X = _Pos.ix() * 2;
	Cur.Y = _Pos.iy();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}




void ConsoleHelper::ConsolePosPrint(const GEVector& _Pos, const wchar_t* _Text, bool _IsWallCheck)
{
	if (true == _IsWallCheck && true == IsWall(_Pos))
	{
		return;
	}

	ConsolePosMove(_Pos);
	wprintf_s(_Text);
}

void ConsoleHelper::ConsolePosPrint(const GEVector& _Pos, wchar_t _Text, bool _IsWallCheck)
{
	wchar_t Arr[2] = { _Text, };
	ConsolePosPrint(_Pos, Arr, _IsWallCheck);
}

void ConsoleHelper::ConsolePosClear(const GEVector& _Pos)
{
	ConsolePosPrint(_Pos, L"□");
}