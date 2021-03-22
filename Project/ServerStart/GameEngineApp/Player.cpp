#include <conio.h>
#include "Player.h"
#include "ConsoleHelper.h"
#include "GameEngineInput.h"
//Constructer Destructer=====================================================================
//Player::Player()
//{
//}

Player::Player(const GEVector& vPos, wchar_t _char)	:m_Pos(vPos),m_Char(_char)
{
	ConsoleHelper::ConsolePosPrint(vPos, _char);
	
}

Player::~Player()
{
}


/* 
* Player::Player(const Player& _Other) {}
* Bsee::Player(Player&& _Other) {}
*/

/*operator ==================================================================================
*Player& Player::operator(const Player& _Other) {}
*Player& Player::operator(Player&& _Other) {}
*/

//Member Function============================================================================
void Player::Render()
{
	GEVector vOldPos = m_Pos;

	int iDir = _getch();

	PLAYERINPUT eDir = (PLAYERINPUT)iDir;

	switch (eDir)
	{
	case PLAYERINPUT::SLEFE:
	case PLAYERINPUT::LLEFE:
		m_Pos.x -= 1;
		break;
	case PLAYERINPUT::SRIGHT:
	case PLAYERINPUT::LRIGHT:
		m_Pos.x += 1;
		break;
	case PLAYERINPUT::SUP:
	case PLAYERINPUT::LUP:
		m_Pos.y -= 1;
		break;
	case PLAYERINPUT::SDOWN:
	case PLAYERINPUT::LDOWN:
		m_Pos.y += 1;
		break;
	default:
		break;
	}

	ConsoleHelper::ConsolePosClear(vOldPos);

	ConsoleHelper::ConsolePosPrint(m_Pos, m_Char);

}