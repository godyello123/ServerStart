#pragma once
#include <GEMath.h>

// Ό³Έν : 
class Bullet
{
private:	// static Var
public:		// static Func
private:	// Member Var
	GEVector m_Pos;
	GEVector m_Dir;
	wchar_t m_Ch;
	float m_MoveTime;

public:	// Constructer Destructer
	~Bullet();
	Bullet(const GEVector& _Pos, GEVector _Dir, wchar_t _Ch);
	Bullet(const Bullet& _Other) = delete;
	Bullet(Bullet&& _Other) = delete;

public:	// operator
	Bullet& operator=(const Bullet& _Other) = delete;
	Bullet& operator=(Bullet&& _Other) = delete;

public: // member Function
	void Update();

};
