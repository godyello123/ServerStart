#include "Bullet.h"
#include "ConsoleHelper.h"
#include <GameEngineTime.h>

class Privateclass
{

};

// Constructer Destructer ----------------------------------------------------
Bullet::Bullet(const GEVector& _Pos, GEVector _Dir, wchar_t _Ch)
	: m_Ch(_Ch), m_Pos(_Pos), m_Dir(_Dir), m_MoveTime(0.2f)
{
	ConsoleHelper::ConsolePosPrint(m_Pos, _Ch);
}

Bullet::~Bullet()
{

}
// Bullet::Bullet(const Bullet& _Other) {}
// Bullet::Bullet(Bullet&& _Other) {}

// operator -----------------------------------------------------------------
// Bullet& Bullet::operator=(const Bullet& _Other) {}
// Bullet& Bullet::operator=(Bullet&& _Other) {}


// member Function -----------------------------------------------------------
void Bullet::Update()
{
	GEVector OldPos = m_Pos;

	//{
	//	return GetInst().m_fDeltaTime;
	//}


	// m_MoveTime -= GetInst().m_fDeltaTime;

	m_MoveTime -= (float)GameEngineTime::GetDelatTime();

	if (0.0f >= m_MoveTime)
	{
		ConsoleHelper::ConsolePosClear(OldPos);
		m_Pos = m_Pos + m_Dir;
		m_MoveTime = 0.2f;
		ConsoleHelper::ConsolePosPrint(m_Pos, m_Ch);
	}

}




