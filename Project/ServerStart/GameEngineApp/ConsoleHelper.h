#pragma once
#include <GEMath.h>

class ConsoleHelper
{
private:
	static GEVector m_Size;//���� �ٴҼ� �ִ� ũ��

public:
	static void Init(const GEVector& _vSize, int _isize, char _ch);
	static void MoveConsolePos(const GEVector& _vPos);
	static void MoveConsolePrint(const GEVector& vPos, char _ch);
};

