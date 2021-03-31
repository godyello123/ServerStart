#include "WorldManager.h"

std::shared_ptr<World> WorldManager::CreateWorld(std::string _name)
{
    if (m_AllWorld.end() != m_AllWorld.find(_name))
    {
        return m_AllWorld[_name];
    }

    std::shared_ptr<World> NewWorld = std::make_shared<World>();

    m_AllWorld.insert(std::make_pair(_name, NewWorld));

    return NewWorld;
}

std::shared_ptr<World> WorldManager::FindWorld(std::string _name)
{
    if (m_AllWorld.end() == m_AllWorld.find(_name))
    {
        return nullptr;
    }

    return m_AllWorld[_name];
}

void WorldManager::AddUpdateWorld(std::string _name)
{
    if (m_AllWorld.end() == m_AllWorld.find(_name))
    {
        return;
    }

    if (m_UpdateWorldmap.end() == m_UpdateWorldmap.find(_name))
    {
        return;
    }

    std::shared_ptr<World> UpdateWorld = m_AllWorld[_name];
    m_UpdateWorldList.push_back(UpdateWorld);
    m_UpdateWorldmap.insert(std::make_pair(_name, UpdateWorld));
}

//Constructer Destructer=====================================================================
WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
}

void WorldManager::Progress()
{
    for (auto& UpdateWorld : m_UpdateWorldList)
    {
        UpdateWorld->PrevUpdate();
    }
    for (auto& UpdateWorld : m_UpdateWorldList)
    {
        UpdateWorld->Update();
    }
    for (auto& UpdateWorld : m_UpdateWorldList)
    {
        UpdateWorld->PostUpdate();
    }
    for (auto& UpdateWorld : m_UpdateWorldList)
    {
        UpdateWorld->Collision();
    }
    for (auto& UpdateWorld : m_UpdateWorldList)
    {
        UpdateWorld->Release();
    }
}

/* 
* WorldManager::WorldManager(const WorldManager& _Other) {}
* Bsee::WorldManager(WorldManager&& _Other) {}
*/

/*operator ==================================================================================
*WorldManager& WorldManager::operator(const WorldManager& _Other) {}
*WorldManager& WorldManager::operator(WorldManager&& _Other) {}
*/

//Member Function============================================================================