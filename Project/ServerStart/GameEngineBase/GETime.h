#pragma once
#include <Windows.h>


class GETime
{
private: //Static variable
	static GETime Inst;
public://Static Function
	static GETime& GetInst();
	static double GetDeltaTime_D();
	static float GetDeltaTime_F();

private: //Member variable
	LARGE_INTEGER m_SecondTime;
	LARGE_INTEGER m_CurTime;
	LARGE_INTEGER m_PrevTime;
	double m_DeltaTime;
	float m_fDeltaTime;

public://Contructer , Destructer
	GETime();
	GETime(const GETime& _Other) = delete;
	GETime(GETime&& _Other) = delete;
	~GETime();

public:
	GETime& operator=(const GETime& _Other) = delete;
	GETime& operator=(GETime& _Other) = delete;

public://Member Function
	void Update();



};

