#pragma once
#include <GEMath.h>
#include <Actor.h>

enum class PLAYERINPUT
{
	SLEFT = 'a',
	BLEFT = 'A',
	SRIGHT = 'd',
	BRIGHT = 'D',
	SDOWN = 's',
	BDOWN = 'S',
	SUP = 'w',
	BUP = 'W',
};

// Ό³Έν : 
class Player : public Actor
{
private:	// static Var
public:		// static Func
private:	// Member Var
	wchar_t m_CharactorCh;
	float m_MoveTime;
	float m_FireTime;

public:	// Constructer Destructer
	Player();
	~Player();
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) = delete;

public:	// operator
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) = delete;

public: // member Function
	void Update() override;

private:
	void InputCheck();


};