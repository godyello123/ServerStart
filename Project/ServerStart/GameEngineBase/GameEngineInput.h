#pragma once

#include "GameEngineString.h"
#include <map>
#include <string>
#include <vector>
#include <memory>

class GameEngineInput
{
private: //Static variable
	class EngineKey : public std::enable_shared_from_this<EngineKey>
	{
	private:
		friend GameEngineInput;
	private:
		bool Push;
		bool Press;
		bool Up;
		bool Free;
		float PressTime;

	public:
		std::vector<int> m_vecKey;

	public:
		bool CheckKey();
		void Update();

	public:
		void ReserveKey(size_t _Size)
		{
			m_vecKey.reserve(_Size);
		}

		template <typename ...REST>
		void PushKey(char _Value, REST ..._Arg)
		{
			if (_Value >= 'a' && _Value <= 'z')
			{
				_Value = toupper(_Value);
			}

			m_vecKey.push_back(_Value);
			PushKey(_Arg...);
		}

		void PushKey()
		{

		}

		void SetPressTime(float _time)
		{
			PressTime = _time;
		}


	public:
		EngineKey() :Push(false), Press(false), Free(false), Up(false), PressTime(1.f)
		{

		}

	};

public://Static Function

private: 
	static GameEngineInput BaseInput;

private:
	static std::shared_ptr<EngineKey> FindKey(const EngineString& _KeyName);

public:
	static GameEngineInput& GetInst();
	static bool IsKey(const EngineString& _Name);
	static bool IsUp(const EngineString& _Name);
	static bool IsPress(const EngineString& _Name);
	static bool IsPush(const EngineString& _Name);
	static bool IsFree(const EngineString& _Name);

private:
	std::map<EngineString, std::shared_ptr<EngineKey>> m_AllCheckKey;

public:
	template <typename ...T>
	void CreateKey(const EngineString& _Name, T ..._Arg)
	{
		std::shared_ptr<EngineKey>  NewKey = std::make_shared<EngineKey>();

		NewKey->ReserveKey(sizeof...(_Arg));
		NewKey->PushKey(_Arg...);

		m_AllCheckKey.insert(std::map<EngineString, std::shared_ptr<EngineKey>>::value_type(_Name, NewKey));
	}

public://Contructer , Destructer
	GameEngineInput();
	~GameEngineInput();
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) = delete;
public:
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput& _Other) = delete;

public://Member Function
	void KeyCheck();


};

