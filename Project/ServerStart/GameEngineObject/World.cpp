#include "World.h"
#include "Actor.h"

//Constructer Destructer=====================================================================
World::World()
{
}

World::~World()
{
}

/* 
* World::World(const World& _Other) {}
* Bsee::World(World&& _Other) {}
*/

/*operator ==================================================================================
*World& World::operator(const World& _Other) {}
*World& World::operator(World&& _Other) {}
*/

//Member Function============================================================================

void World::PrevUpdate()
{
	for (std::shared_ptr<Actor>& actor : m_ActorList)
	{
		actor->PrevUpdate();
	}
}

void World::Update()
{
	for (std::shared_ptr<Actor>& actor : m_ActorList)
	{
		actor->Update();
	}
}

void World::PostUpdate()
{
	for (std::shared_ptr<Actor>& actor : m_ActorList)
	{
		actor->PostUpdate();
	}
}

void World::Collision()
{
	for (std::shared_ptr<Actor>& actor : m_ActorList)
	{
		actor->Collison();
	}
}

void World::Release()
{
	for (std::shared_ptr<Actor>& actor : m_ActorList)
	{
		actor->Release();
	}
}
