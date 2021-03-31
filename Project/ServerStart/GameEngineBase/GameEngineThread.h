#pragma once
#include <thread>
#include <functional>

class GameEngineThread;
void ThreadFunc(GameEngineThread* _threadptr);

class GameEngineThread	: public std::enable_shared_from_this<GameEngineThread>
{
private: //Static variable
public://Static Function
private: //Member variable
	std::thread* m_pThread;
	std::function<void()> m_pThreadFunc;

	friend void ThreadFunc(GameEngineThread* _threadptr);
	
public://Contructer , Destructer
	GameEngineThread();
	GameEngineThread(std::function<void()> _func);
	GameEngineThread(const GameEngineThread& _Other) = delete;
	GameEngineThread(GameEngineThread&& _Other) = delete;
	~GameEngineThread();

public:
	GameEngineThread& operator=(const GameEngineThread& _Other) = delete;
	GameEngineThread& operator=(GameEngineThread& _Other) = delete;

public://Member Function
	void Start();
	void Stop();


};

