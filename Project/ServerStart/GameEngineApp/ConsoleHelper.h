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

	// 함수를 만들때는
	// 작은 기능들의 함수로 만들고
	// 그것들을 혼합해서 큰함수를 만들어
	static void ConsolePosMove(const GEVector& _Pos);
	static void ConsolePosPrint(const GEVector& _Pos, wchar_t _Text, bool _IsWallCheck = true);
	static void ConsolePosPrint(const GEVector& _Pos, const wchar_t* _Text, bool _IsWallCheck = true);
	static void ConsolePosClear(const GEVector& _Pos);

private:
	ConsoleHelper();
	virtual ~ConsoleHelper() = 0;
};