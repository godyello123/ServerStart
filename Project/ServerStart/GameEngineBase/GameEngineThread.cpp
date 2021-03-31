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
	//std::thread() : thread ������
	//1.�����忡 ���� ���� �� �Լ�,
	//2.�ش� �Լ��� ������ ���ڸ��
}


void GameEngineThread::Stop()
{
	if (m_pThread)
	{
		//join : �����尡 ����ɶ����� ����
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
	//���� ���ڷ� ���� ���ӿ��� ������ ��ü��
	//m_pThreadFunc �Լ��� ���ε� �Ǿ� �ִٸ�
	//�ش� �Լ��� ȣ���Ѵ�.
	if (_threadptr->m_pThreadFunc)
	{
		_threadptr->m_pThreadFunc();
	}
}
