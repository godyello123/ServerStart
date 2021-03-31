#include "GETime.h"

GETime GETime::Inst;

GETime::GETime()    
    :m_DeltaTime(0.0), m_fDeltaTime(0.f),
m_SecondTime(), m_CurTime(), m_PrevTime()
{
    QueryPerformanceFrequency(&m_SecondTime);
    QueryPerformanceCounter(&m_CurTime);
    QueryPerformanceCounter(&m_PrevTime);
}

GETime::~GETime()
{

}

GETime& GETime::GetInst()
{
    return Inst;
}

double GETime::GetDeltaTime_D()
{
    return GetInst().m_DeltaTime;
}

float GETime::GetDeltaTime_F()
{
    return GetInst().m_fDeltaTime;
}

//Constructer Destructer=====================================================================
void GETime::Update()
{
    QueryPerformanceCounter(&m_CurTime);

    __int64 InterCount = m_CurTime.QuadPart - m_PrevTime.QuadPart;
    m_DeltaTime = (double)InterCount / (double)m_SecondTime.QuadPart;
    m_fDeltaTime = static_cast<float>(m_DeltaTime);
    m_PrevTime.QuadPart = m_CurTime.QuadPart;

}

/* 
* GETime::GETime(const GETime& _Other) {}
* Bsee::GETime(GETime&& _Other) {}
*/

/*operator ==================================================================================
*GETime& GETime::operator(const GETime& _Other) {}
*GETime& GETime::operator(GETime&& _Other) {}
*/

//Member Function============================================================================