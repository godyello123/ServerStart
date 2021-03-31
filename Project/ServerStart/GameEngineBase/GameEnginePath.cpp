#include "GameEnginePath.h"

//Constructer Destructer=====================================================================
GameEnginePath::GameEnginePath()
{
}

GameEnginePath::GameEnginePath(const EngineString& _Path):m_Path(_Path)
{
}

GameEnginePath::GameEnginePath(const wchar_t* _Path) : m_Path(_Path)
{
}

GameEnginePath::~GameEnginePath()
{
}

void GameEnginePath::MoveParent()
{
}

IOTYPE GameEnginePath::GetIOType()
{
	wchar_t Arr = m_Path.at(m_Path.GetSize() - 1);

	if (Arr == L'\\')
	{
		return IOTYPE::DIRECTORY;
	}

	return IOTYPE::FILE;
}

GameEngineString GameEnginePath::GetPath() const
{
	return m_Path;
}

void GameEnginePath::SetPath(GameEngineString str)
{
	m_Path = str;
}

/* 
* GameEnginePath::GameEnginePath(const GameEnginePath& _Other) {}
* Bsee::GameEnginePath(GameEnginePath&& _Other) {}
*/

/*operator ==================================================================================
*GameEnginePath& GameEnginePath::operator(const GameEnginePath& _Other) {}
*GameEnginePath& GameEnginePath::operator(GameEnginePath&& _Other) {}
*/

//Member Function============================================================================