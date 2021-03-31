#pragma once
#include <string>

class GameEngineString
{
private: //Static variable
public://Static Function
private: //Member variable
	std::wstring m_string;

public://Contructer , Destructer
	GameEngineString();
	GameEngineString(const wchar_t* _str);
	GameEngineString(std::wstring _str);
	GameEngineString(const GameEngineString& _Other);
	GameEngineString(GameEngineString&& _Other) noexcept;
	~GameEngineString();


public://Member Function
	void resize(size_t _size);
	size_t GetSize() const;
	wchar_t& at(size_t _Index);
	const wchar_t* ConstStringPtr() const;

	/*Operator*/
public:
	GameEngineString& operator=(GameEngineString&& _Other) noexcept
	{
		m_string = _Other.m_string;
		return *this;
	}
	GameEngineString& operator=(GameEngineString& _Other)
	{
		m_string = _Other.m_string;
		return *this;
	}
	GameEngineString& operator=(const std::wstring& _str)
	{
		m_string = _str;
		return *this;
	}
	GameEngineString& operator=(const std::wstring&& _str)
	{
		m_string = _str;
		return *this;
	}
	GameEngineString& operator=(const wchar_t* _str)
	{
		m_string = _str;
		return *this;
	}
	GameEngineString& operator+(const GameEngineString& _Other)
	{
		GameEngineString Str = m_string + _Other.m_string;
		return Str;
	}
	GameEngineString& operator+=(const GameEngineString& _Other)
	{
		m_string += _Other.m_string;
		return *this;
	}
	bool operator <(const GameEngineString& _Other) const
	{
		return m_string < _Other.m_string;
	}
	bool operator >(const GameEngineString& _Other) const
	{
		return m_string > _Other.m_string;
	}
	bool operator==(const GameEngineString& _Other) const
	{
		return m_string == _Other.m_string;
	}
	bool operator!=(const GameEngineString& _Other) const
	{
		return m_string != _Other.m_string;
	}

	operator std::wstring& ()
	{
		return m_string;
	}
};

typedef GameEngineString EngineString;