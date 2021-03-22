#include <iostream>
#include "ConsoleHelper.h"
#include "Player.h"

#pragma comment(lib,"..\\x64\\Debug\\GameEngineBase")

int main()
{
	ConsoleHelper::Init({ 5,5 }, 2, L'°·');
	Player NewPlayer = { ConsoleHelper::GetCenter(),L'» ' };

	while (true)
	{
		NewPlayer.Render();
	}

	return 0;
}