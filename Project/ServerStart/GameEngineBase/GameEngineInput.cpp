#include "GameEngineInput.h"

GameEngineInput GameEngineInput::BaseInput;

GameEngineInput& GameEngineInput::GetInst()
{
	return BaseInput;
}

//Constructer Destructer=====================================================================
GameEngineInput::GameEngineInput()
{
}

GameEngineInput::~GameEngineInput()
{
}

/* 
* GameEngineInput::GameEngineInput(const GameEngineInput& _Other) {}
* Bsee::GameEngineInput(GameEngineInput&& _Other) {}
*/

/*operator ==================================================================================
*GameEngineInput& GameEngineInput::operator(const GameEngineInput& _Other) {}
*GameEngineInput& GameEngineInput::operator(GameEngineInput&& _Other) {}
*/

//Member Function============================================================================