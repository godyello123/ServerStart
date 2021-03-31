#include "GEString.h"

//Constructer Destructer=====================================================================
GEString::GEString()
{
}

GEString::GEString(const wchar_t* _Str) :m_String(_Str)
{
}

GEString::GEString(const GEString& _Other)  :m_String(_Other.m_String)
{
}

GEString::~GEString()
{
}

//Member Function============================================================================
size_t GEString::GetSize()
{
    return m_String.size();
}

const wchar_t& GEString::At(size_t _Index)
{
    return m_String.at(_Index);
}

/* 
* GEString::GEString(const GEString& _Other) {}
* Bsee::GEString(GEString&& _Other) {}
*/

/*operator ==================================================================================
*GEString& GEString::operator(const GEString& _Other) {}
*GEString& GEString::operator(GEString&& _Other) {}
*/

