#pragma once
#include <GEMath.h>

class ConsoleHelper
{
private:
	static GEVector m_Size;
	static int m_LineSize;

public:
	static GEVector GetSize();
	static GEVector GetCenter();
	static bool IsWall(GEVector _Pos);

public:
	static void Init(const GEVector& _Size, int _LineSize, wchar_t _Line);

	// �Լ��� ���鶧��
	// ���� ��ɵ��� �Լ��� �����
	// �װ͵��� ȥ���ؼ� ū�Լ��� �����
	static void ConsolePosMove(const GEVector& _Pos);
	static void ConsolePosPrint(const GEVector& _Pos, wchar_t _Text, bool _IsWallCheck = true);
	static void ConsolePosPrint(const GEVector& _Pos, const wchar_t* _Text, bool _IsWallCheck = true);
	static void ConsolePosClear(const GEVector& _Pos);

private:
	ConsoleHelper();
	virtual ~ConsoleHelper() = 0;
};