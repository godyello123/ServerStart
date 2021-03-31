#include "Actor.h"

//Constructer Destructer=====================================================================
Actor::Actor()
{
}

Actor::~Actor()
{
}

/* 
* Actor::Actor(const Actor& _Other) {}
* Bsee::Actor(Actor&& _Other) {}
*/

/*operator ==================================================================================
*Actor& Actor::operator(const Actor& _Other) {}
*Actor& Actor::operator(Actor&& _Other) {}
*/

//Member Function============================================================================

void Actor::SetPos(const GEVector& _pos)
{
	m_Pos = _pos;
}

void Actor::SetMove(const GEVector& _pos)
{
	m_Pos += _pos;
}

GEVector Actor::GetPos() const
{
	return m_Pos;
}

void Actor::PrevUpdate()
{
}

void Actor::Update()
{
}

void Actor::PostUpdate()
{
}

void Actor::Collison()
{
}

void Actor::Release()
{
}
