#include "Player.h"
#include "ConsoleHelper.h"
#include <conio.h>
#include <GameEngineInput.h>
#include <GameEngineTime.h>


//{
//GameEngineFile NewFile(L"TestData.txt");
////if (false == NewFile.IsExist())
////{
//NewFile.FileOpen(L"wb");

//std::list<int> Vector;
//for (size_t i = 0; i < 10; i++)
//{
//	Vector.push_back(i * 10);
//}

//NewFile << (Vector);

//int Value = 200;
//NewFile << Value;
//EngineString Str = L"AAAA BBB CCD DDERFERWER";
//NewFile << Str;

//int a = 0;
////}

//}

// Constructer Destructer ----------------------------------------------------
// Player::Player() {}

Player::Player() : m_CharactorCh(L'■'), m_MoveTime(0.2f), m_FireTime(0.5f)
{
	if (false == GameEngineInput::IsKey(L"LeftMove"))
	{
		GameEngineInput::GetInst().CreateKey(L"LeftMove", 'a');
		GameEngineInput::GetInst().CreateKey(L"RightMove", 'd');
		GameEngineInput::GetInst().CreateKey(L"UpMove", 'w');
		GameEngineInput::GetInst().CreateKey(L"DownMove", 's');
	}
}

Player::~Player()
{

}
// Player::Player(const Player& _Other) {}
// Player::Player(Player&& _Other) {}

// operator -----------------------------------------------------------------
// Player& Player::operator=(const Player& _Other) {}
// Player& Player::operator=(Player&& _Other) {}


// member Function -----------------------------------------------------------

void Player::InputCheck()
{
	GEVector OldPos = GetPos();

	if (GameEngineInput::IsPush(L"LeftMove"))
	{
		SetMove(GEVector::LEFT);
	}

	if (GameEngineInput::IsPush(L"RightMove"))
	{
		SetMove(GEVector::RIGHT);
	}

	if (GameEngineInput::IsPush(L"UpMove"))
	{
		SetMove(GEVector::UP);
	}

	if (GameEngineInput::IsPush(L"DownMove"))
	{
		SetMove(GEVector::DOWN);
	}

	//// Value 누른 키의 코드
	ConsoleHelper::ConsolePosClear(OldPos);

	ConsoleHelper::ConsolePosPrint(GetPos(), m_CharactorCh);

}

void Player::Update()
{
	m_MoveTime -=(float)GameEngineTime::GetDelatTime();
	m_FireTime -=(float)GameEngineTime::GetDelatTime();

	if (0.0f >= m_MoveTime || 0.0f >= m_FireTime)
	{
		InputCheck();
	}
}