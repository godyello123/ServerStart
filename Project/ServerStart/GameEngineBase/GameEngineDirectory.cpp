#include "GameEngineDirectory.h"
#include <Windows.h>

EngineString GameEngineDirectory::GetCurrentDirectoryPath()
{
	wchar_t Arr[_MAX_PATH];

	GetCurrentDirectoryW(_MAX_PATH, Arr);
	EngineString str = Arr;
	str += L"\\";
	return str;
}

//Constructer Destructer=====================================================================
GameEngineDirectory::GameEngineDirectory()
{
	m_Path = GetCurrentDirectoryPath();
}

GameEngineDirectory::~GameEngineDirectory()
{
}

void GameEngineDirectory::SetPath(const EngineString& strPath)
{
	GameEnginePath::SetPath(strPath);
}

/* 
* GameEngineDirectory::GameEngineDirectory(const GameEngineDirectory& _Other) {}
* Bsee::GameEngineDirectory(GameEngineDirectory&& _Other) {}
*/

/*operator ==================================================================================
*GameEngineDirectory& GameEngineDirectory::operator(const GameEngineDirectory& _Other) {}
*GameEngineDirectory& GameEngineDirectory::operator(GameEngineDirectory&& _Other) {}
*/

//Member Function============================================================================