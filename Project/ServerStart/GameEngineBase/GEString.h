#pragma once
#include <string> 

class GEString
{
private: //Static variable
public://Static Function
private: //Member variable
	std::wstring m_String;

public://Contructer , Destructer
	GEString();
	GEString(const wchar_t* _Str);
	GEString(const GEString& _Other);
	GEString(GEString&& _Other) = delete;
	~GEString();

public:
	GEString& operator=(const GEString& _Other) = delete;
	GEString& operator=(GEString& _Other) = delete;

public://Member Function
	size_t GetSize();
	const wchar_t& At(size_t _Index);

public:
	GEString& operator=(const GEString& _Other)
	{
		m_String = _Other.m_String;
	}

	GEString& operator=(const wchar_t* _Str)
	{
		m_String = _Str;
	}
	
	GEString& operator=(GEString&& _Other) = delete;

	GEString& operator=(std::wstring&& _Str)
	{
		m_String = _Str;
	}

	bool operator < (const GEString& _Other) const
	{
		return m_String < _Other.m_String;
	}

	bool operator > (const GEString& _Other) const
	{
		return m_String > _Other.m_String;
	}

	bool operator ==(const GEString& _Other) const
	{
		return m_String == _Other.m_String;
	}

	bool operator !=(const GEString& _Other) const
	{
		return m_String != _Other.m_String;
	}

	operator std::wstring& ()
	{
		return m_String;
	}
};

