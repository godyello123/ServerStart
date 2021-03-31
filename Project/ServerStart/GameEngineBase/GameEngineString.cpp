#include "GameEngineString.h"

//Constructer Destructer=====================================================================
GameEngineString::GameEngineString()
{
}

GameEngineString::GameEngineString(const wchar_t* _str)	:m_string(_str)
{
}

GameEngineString::GameEngineString(std::wstring _str): m_string(_str)
{
}

GameEngineString::GameEngineString(const GameEngineString& _Other): m_string(_Other.m_string)
{
}

GameEngineString::GameEngineString(GameEngineString&& _Other) noexcept:m_string(_Other.m_string)
{
}

GameEngineString::~GameEngineString()
{
}

void GameEngineString::resize(size_t _size)
{
	m_string.resize(_size);
}

size_t GameEngineString::GetSize() const
{
	return m_string.size();
}

wchar_t& GameEngineString::at(size_t _Index)
{
	return m_string.at(_Index);
}

const wchar_t* GameEngineString::ConstStringPtr() const
{
	return m_string.c_str();
}

/*operator ==================================================================================
*GameEngineString& GameEngineString::operator(const GameEngineString& _Other) {}
*GameEngineString& GameEngineString::operator(GameEngineString&& _Other) {}
*/

//Member Function============================================================================