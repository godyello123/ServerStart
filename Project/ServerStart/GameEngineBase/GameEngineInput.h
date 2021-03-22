#pragma once

class GameEngineInput
{
private: //Static variable
	static GameEngineInput BaseInput;
public://Static Function
	static GameEngineInput& GetInst();
private: //Member variable

public://Contructer , Destructer
	GameEngineInput();
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) = delete;
	~GameEngineInput();

public:
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput& _Other) = delete;

public://Member Function



};

