#pragma once
#include <Windows.h>

class GameEngineTime
{
private: //Static variable
	static GameEngineTime Inst;
public://Static Function
	static GameEngineTime& GetInst();
	static double GetDelatTime();
private: //Member variable
	LARGE_INTEGER m_SecondTime;
	LARGE_INTEGER m_CurTime;
	LARGE_INTEGER m_PrevTime;
	double m_DeltaTime;

public://Contructer , Destructer
	GameEngineTime();
	~GameEngineTime();
	GameEngineTime(const GameEngineTime& _Other) = delete;
	GameEngineTime(GameEngineTime&& _Other) = delete;
public:
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime& _Other) = delete;

public://Member Function
	void Update();


};

