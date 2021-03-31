#include "GameEngineTime.h"

GameEngineTime GameEngineTime::Inst;

GameEngineTime& GameEngineTime::GetInst()
{
    return Inst;
}

double GameEngineTime::GetDelatTime()
{
    return GetInst().m_DeltaTime;
}

//Constructer Destructer=====================================================================
GameEngineTime::GameEngineTime() :m_SecondTime(), m_CurTime(), m_PrevTime(), m_DeltaTime(0.f)
{
    QueryPerformanceFrequency(&m_SecondTime);
    QueryPerformanceCounter(&m_PrevTime);
    QueryPerformanceCounter(&m_CurTime);
}

GameEngineTime::~GameEngineTime()
{
}

void GameEngineTime::Update()
{
    QueryPerformanceCounter(&m_CurTime);

    __int64 InterCount = m_CurTime.QuadPart - m_PrevTime.QuadPart;

    m_DeltaTime = (double)InterCount / (double)m_SecondTime.QuadPart;

    m_PrevTime.QuadPart = m_CurTime.QuadPart;
}

/* 
* GameEngineTime::GameEngineTime(const GameEngineTime& _Other) {}
* Bsee::GameEngineTime(GameEngineTime&& _Other) {}
*/

/*operator ==================================================================================
*GameEngineTime& GameEngineTime::operator(const GameEngineTime& _Other) {}
*GameEngineTime& GameEngineTime::operator(GameEngineTime&& _Other) {}
*/

//Member Function============================================================================