#pragma once
#include <memory>
#include <GEMath.h>

class Actor : public std::enable_shared_from_this<Actor>
{
private: //Static variable
public://Static Function
private: //Member variable
	GEVector m_Pos;

public://Contructer , Destructer
	Actor();
	Actor(const Actor& _Other) = delete;
	Actor(Actor&& _Other) = delete;
	~Actor();

public:
	Actor& operator=(const Actor& _Other) = delete;
	Actor& operator=(Actor& _Other) = delete;

public:
	void SetPos(const GEVector& _pos);
	void SetMove(const GEVector& _pos);
	GEVector GetPos() const;

public://Member Function
	virtual void PrevUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void Collison();
	virtual void Release();


};

