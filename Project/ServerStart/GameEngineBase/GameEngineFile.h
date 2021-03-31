#pragma once
#include "GameEnginePath.h"
#include <vector>
#include <list>
#include <map>

enum class FILEOPENMODE
{
	NONE,
	READ,
	WRITE
};

class GameEngineFile : public GameEnginePath
{
private: //Static variable
public://Static Function
private: //Member variable
	FILEOPENMODE m_OpenMode;
	FILE* m_File;

public://Contructer , Destructer
	GameEngineFile();
	GameEngineFile(const EngineString& _str);
	GameEngineFile(const wchar_t* _str);
	GameEngineFile(const GameEngineFile& _Other) = delete;
	GameEngineFile(GameEngineFile&& _Other) = delete;
	~GameEngineFile();

public:
	GameEngineFile& operator=(const GameEngineFile& _Other) = delete;
	GameEngineFile& operator=(GameEngineFile& _Other) = delete;

public://operator 
	template <typename T>
	void operator <<(const std::vector<T>& _value)
	{
		int iSize = (int)_value.size();
		Write(&iSize, sizeof(int), 1);

		for (size_t i = 0; i < _value.size(); i++)
		{
			Write(&_value[i], sizeof(T), 1);
		}
	}
	template <typename T>
	void operator <<(const std::list<T>& _value)
	{
		int iSize = (int)_value.size();

		Write(&iSize, sizeof(int), 1);

		auto iter = _value.cbegin();
		auto iterEnd = _value.cend();

		for (; iter != iterEnd; ++iter)
		{
			Write(&(*iter), sizeof(T), 1);
		}
	}
	template <typename KEY, typename VALUE>
	void operator <<(const std::map<KEY, VALUE>& _value)
	{
		int iSize = (int)_value.size();

		Write(&iSize, sizeof(int), 1);

		auto iter = _value.cbegin();
		auto iterEnd = _value.cend();

		for (; iter != iterEnd; ++iter)
		{
			Write(&iter->first, sizeof(KEY), 1);
			Write(&iter->second, sizeof(VALUE), 1);
		}
	}

	template <typename T>
	void operator >>(std::vector<T> _value)
	{
		int iSize = 0;
		Read(&iSize, sizeof(int), sizeof(int), 1);
		_value.resize(iSize);

		for (size_t i = 0; i < _value.size(); ++i)
		{
			Read(&_value[i], sizeof(T), sizeof(T), 1);
		}
	}
	template <typename T>
	void operator >>(std::list<T> _value)
	{
		int iSize = 0;
		Read(&iSize, sizeof(int), sizeof(int), 1);

		for (int i = 0; i < iSize; ++i)
		{
			std::shared_ptr<T> NewT = std::make_shared<T>();
			Read(&NewT, sizeof(T), sizeof(int), 1);
			_value.push_back(NewT);
		}
	}

	template <typename KEY, typename VALUE>
	void operator >>(std::map<KEY, VALUE>& _value)
	{
		int iSize = 0;
		Read(&iSize, sizeof(int), sizeof(int), 1);

		for (int i = 0; i < iSize; ++i)
		{
			KEY key;
			Read(&key, sizeof(KEY), sizeof(KEY), 1);
			VALUE Value;
			Read(&Value, sizeof(VALUE), sizeof(VALUE), 1);

			_value.insert(std::make_pair(key, Value));
		}
	}
public:
	template<typename T>
	void operator << (const T& _Value)
	{
		Write(&_Value, sizeof(T), 1);
	}

	template<>
	void operator << (const EngineString& _Value)
	{
		int Size = (int)_Value.GetSize();
		Write(&Size, sizeof(int), 1);
		Write(_Value.ConstStringPtr(), _Value.GetSize() * sizeof(wchar_t), 1);
	}

	template<typename T>
	void operator >> (T& _Value)
	{
		Read(&_Value, sizeof(T), sizeof(T), 1);
	}

	template<>
	void operator >> (EngineString& _Value)
	{
		int Size = (int)_Value.GetSize();
		Read(&Size, sizeof(int), sizeof(int), 1);

		_Value.resize(Size);
		Read(&_Value.at(0), Size * sizeof(wchar_t), Size * sizeof(wchar_t), 1);
	}

public://Member Function
	bool IsExit();
	bool FileCreateWriteOpen();
	bool FileOpen(const wchar_t* _mode);
	void Close();
	void Read(void* _buffer, size_t _buffersize, size_t _elementsize, size_t _elementcount) const;
	void Write(const void* _buffer, size_t _elementsize, size_t _elementcount) const;
};

