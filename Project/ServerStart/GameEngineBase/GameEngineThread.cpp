#include "GameEngineThread.h"

//Constructer Destructer=====================================================================
GameEngineThread::GameEngineThread()	:m_pThread(nullptr), m_pThreadFunc(nullptr)
{
}

GameEngineThread::GameEngineThread(std::function<void()> _func)	: m_pThread(nullptr),m_pThreadFunc(_func)
{
}

GameEngineThread::~GameEngineThread()
{
	Stop();
}

void GameEngineThread::Start()
{
	if (!m_pThread)
	{
		Stop();
	}
	m_pThread = new std::thread(ThreadFunc, this);
	//std::thread() : thread 생성자
	//1.스레드에 의해 실행 될 함수,
	//2.해당 함수에 전달할 인자목록
}


void GameEngineThread::Stop()
{
	if (m_pThread)
	{
		//join : 쓰레드가 종료될때까지 차단
		m_pThread->join();
		delete m_pThread;
		m_pThread = nullptr;
	}
}

/* 
* GameEngineThread::GameEngineThread(const GameEngineThread& _Other) {}
* Bsee::GameEngineThread(GameEngineThread&& _Other) {}
*/

/*operator ==================================================================================
*GameEngineThread& GameEngineThread::operator(const GameEngineThread& _Other) {}
*GameEngineThread& GameEngineThread::operator(GameEngineThread&& _Other) {}
*/

//Member Function============================================================================

void ThreadFunc(GameEngineThread* _threadptr)
{
	//만약 인자로 들어온 게임엔진 쓰레드 객체의
	//m_pThreadFunc 함수가 바인딩 되어 있다면
	//해당 함수를 호출한다.
	if (_threadptr->m_pThreadFunc)
	{
		_threadptr->m_pThreadFunc();
	}
}
