#pragma once
#include <list>
#include <memory>
#include <GEMath.h>


class World	: public std::enable_shared_from_this<World>
{
private: //Static variable
public://Static Function
private: //Member variable
	std::list<std::shared_ptr<class Actor>> m_ActorList;

public:
	template<typename T>
	std::shared_ptr<T> CreateActor()
	{
		std::shared_ptr<T> actor= std::make_shared<T>();
		m_ActorList.push_back(actor);
		return actor;
	}

public://Contructer , Destructer
	World();
	World(const World& _Other) = delete;
	World(World&& _Other) = delete;
	~World();

public:
	World& operator=(const World& _Other) = delete;
	World& operator=(World& _Other) = delete;

public://Member Function
	void PrevUpdate();
	void Update();
	void PostUpdate();
	void Collision();
	void Release();


};

