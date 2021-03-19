#pragma once
#include <GEMath.h>

class ConsoleHelper
{
private:
	static GEVector m_Size;//돌아 다닐수 있는 크기

public:
	static void Init(const GEVector& _vSize, int _isize, char _ch);
	static void MoveConsolePos(const GEVector& _vPos);
	static void MoveConsolePrint(const GEVector& vPos, char _ch);
};

