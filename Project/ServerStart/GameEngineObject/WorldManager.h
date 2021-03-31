#pragma once
#include "World.h"
#include <map>
#include <string>

class WorldManager
{
private: //Static variable
public://Static Function
private: //Member variable
	std::map<std::string, std::shared_ptr<World>> m_AllWorld;
	std::list<std::shared_ptr<World>> m_UpdateWorldList;
	std::map<std::string, std::shared_ptr<World>> m_UpdateWorldmap;

public:
	std::shared_ptr<World> CreateWorld(std::string _name);
	std::shared_ptr<World> FindWorld(std::string _name);
	void AddUpdateWorld(std::string _name);

public://Contructer , Destructer
	WorldManager();
	WorldManager(const WorldManager& _Other) = delete;
	WorldManager(WorldManager&& _Other) = delete;
	~WorldManager();

public:
	WorldManager& operator=(const WorldManager& _Other) = delete;
	WorldManager& operator=(WorldManager& _Other) = delete;

public://Member Function
	void Progress();


};

