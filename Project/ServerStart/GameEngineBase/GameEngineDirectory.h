#pragma once
#include "GameEnginePath.h"

class GameEngineDirectory	: public GameEnginePath
{
private: //Static variable
public://Static Function
	static EngineString GetCurrentDirectoryPath();
private: //Member variable

public://Contructer , Destructer
	GameEngineDirectory();
	GameEngineDirectory(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory(GameEngineDirectory&& _Other) = delete;
	~GameEngineDirectory();

public:
	GameEngineDirectory& operator=(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory& operator=(GameEngineDirectory& _Other) = delete;

public://Member Function
	void SetPath(const EngineString& strPath);


};

