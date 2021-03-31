#include <iostream>
#include "ConsoleHelper.h"
#include "Player.h"
#include "Bullet.h"
#include <GameEngineTime.h>
#include <GameEngineInput.h>
#include <GameEnginePath.h>
#include <GameEngineFile.h>
#include <GameEngineDirectory.h>
#include <World.h>
#include <WorldManager.h>
#include <GameEngineThread.h>

#pragma comment(lib,"GameEngineObject")
#pragma comment(lib,"GameEngineBase")


int main()
{
    ConsoleHelper::Init({ 11, 11 }, 2, L'бс');

    WorldManager WM{};

    std::shared_ptr<World> NewWorld = WM.CreateWorld("PlayWorld");
    std::shared_ptr<Player> NewPlayer = NewWorld->CreateActor<Player>();
    NewPlayer->SetPos(ConsoleHelper::GetCenter());

    WM.AddUpdateWorld("PlayWorld");


    while (true)
    {
        GameEngineTime::GetInst().Update();
        GameEngineInput::GetInst().KeyCheck();

        WM.Progress();

    }

    return 0;
}