#pragma once
#include <iostream>
#include "GameEngineString.h"

enum class IOTYPE
{
	NONE,
	FILE,
	DIRECTORY
};

enum IOCONSTVALUE
{
	MAXPATHLEN=256
};

class GameEnginePath
{
private: //Static variable
public://Static Function
protected: //Member variable
	GameEngineString m_Path;

public://Contructer , Destructer
	GameEnginePath();
	GameEnginePath(const EngineString& _Path);
	GameEnginePath(const wchar_t* _Path);

	GameEnginePath(const GameEnginePath& _Other) = delete;
	GameEnginePath(GameEnginePath&& _Other) = delete;
	~GameEnginePath();

public:
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath& _Other) = delete;

public://Member Function
	void MoveParent();
	IOTYPE GetIOType();

public:
	GameEngineString GetPath() const;
	void SetPath(GameEngineString str);
};

