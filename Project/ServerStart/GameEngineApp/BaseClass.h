#pragma once

class BaseClass
{
private: //Static variable
public://Static Function
private: //Member variable

public://Contructer , Destructer
	BaseClass();
	BaseClass(const BaseClass& _Other) = delete;
	BaseClass(BaseClass&& _Other) = delete;
	~BaseClass();

public:
	BaseClass& operator=(const BaseClass& _Other) = delete;
	BaseClass& operator=(BaseClass& _Other) = delete;

public://Member Function



};

