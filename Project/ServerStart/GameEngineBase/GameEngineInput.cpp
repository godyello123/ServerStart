#include "GameEngineInput.h"
#include "GameEngineTime.h"
#include <Windows.h>

GameEngineInput GameEngineInput::BaseInput;

//Constructer Destructer=====================================================================
GameEngineInput::GameEngineInput()
{
}

GameEngineInput::~GameEngineInput()
{
}


/* 
* GEInput::GEInput(const GEInput& _Other) {}
* Bsee::GEInput(GEInput&& _Other) {}
*/

/*operator ==================================================================================
*GEInput& GEInput::operator(const GEInput& _Other) {}
*GEInput& GEInput::operator(GEInput&& _Other) {}
*/

//Member Function============================================================================

bool GameEngineInput::EngineKey::CheckKey()
{
	bool bCheck = false;
	size_t iSize = m_vecKey.size();
	for (size_t i = 0; i < iSize; ++i)
	{
		if (GetAsyncKeyState(m_vecKey[i]) == 0)
		{
			return false;
		}
	}

	return true;
}

void GameEngineInput::EngineKey::Update()
{
	if (CheckKey())
	{
		if (!Press)
		{
			Push = true;
			Press = true;
			Up = false;
			Free = false;
		}
		else
		{
			Push = false;
			Press = true;
			Up = false;
			Free = false;
		}
	}
	else
	{
		if (!Press)
		{
			Push = false;
			Press = false;
			Up = true;
			Free = false;
		}
		else
		{
			Push = false;
			Press = false;
			Up = false;
			Free = true;
		}
	}
}

GameEngineInput& GameEngineInput::GetInst()
{
	return BaseInput;
}

std::shared_ptr<GameEngineInput::EngineKey> GameEngineInput::FindKey(const EngineString& _KeyName)
{
	auto iter = GetInst().m_AllCheckKey.find(_KeyName);

	if (iter != GetInst().m_AllCheckKey.end())
	{
		return iter->second;
	}

	return nullptr;
}

bool GameEngineInput::IsKey(const EngineString& _Name)
{
	std::shared_ptr<GameEngineInput::EngineKey> Key = FindKey(_Name);

	if (!Key)
	{
		return false;
	}

	return true;
}

bool GameEngineInput::IsUp(const EngineString& _Name)
{
	std::shared_ptr<GameEngineInput::EngineKey> Key = FindKey(_Name);

	if (!Key)
	{
		return false;
	}

	return Key->Up;
}

bool GameEngineInput::IsPress(const EngineString& _Name)
{
	std::shared_ptr<GameEngineInput::EngineKey> Key = FindKey(_Name);

	if (!Key)
	{
		return false;
	}

	return Key->Press;
}

bool GameEngineInput::IsPush(const EngineString& _Name)
{
	std::shared_ptr<GameEngineInput::EngineKey> Key = FindKey(_Name);

	if (!Key)
	{
		return false;
	}

	return Key->Push;
}

bool GameEngineInput::IsFree(const EngineString& _Name)
{
	std::shared_ptr<GameEngineInput::EngineKey> Key = FindKey(_Name);

	if (!Key)
	{
		return false;
	}

	return Key->Free;
}


void GameEngineInput::KeyCheck()
{
	for (auto& _Key : m_AllCheckKey)
	{
		_Key.second->Update();
	}
}
