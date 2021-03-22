#pragma once
#include <GEMath.h>

class ConsoleHelper
{
private:
	static GEVector m_Size;//���� �ٴҼ� �ִ� ũ��
	static int m_LineSize;

public:
	static GEVector GetCenter();

public:
	static void Init(const GEVector& _vSize, int _isize, wchar_t _ch);
	static void ConsolePosMove(const GEVector& vPos);
	static void ConsolePosPrint(const GEVector& vPos,const wchar_t* str);
	static void ConsolePosPrint(const GEVector& vPos, wchar_t str);
	static void ConsolePosClear(const GEVector& vPos);
	
private:
	ConsoleHelper();
	virtual ~ConsoleHelper() = 0;
};

