#pragma once
#include <GEMath.h>

enum class PLAYERINPUT
{
	SLEFE = 'A',
	SRIGHT = 'D',
	SUP = 'W',
	SDOWN = 'S',
	LLEFE = 'a',
	LRIGHT = 'd',
	LUP = 'w',
	LDOWN = 's'
};

class Player
{
private: //Static variable
	wchar_t m_Char;
	GEVector m_Pos;

public://Static Function
private: //Member variable

public://Contructer , Destructer
	Player() = delete;
	Player(const GEVector& vPos, wchar_t _char);
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) = delete;
	~Player();

public:
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player& _Other) = delete;

public://Member Function
	void Render();


};

