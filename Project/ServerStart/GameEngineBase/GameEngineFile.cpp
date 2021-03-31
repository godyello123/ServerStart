#include <iostream>
#include "GameEngineFile.h"
#include "GameEngineDirectory.h"

//Constructer Destructer=====================================================================
GameEngineFile::GameEngineFile()	:m_File(nullptr), m_OpenMode(FILEOPENMODE::NONE)
{
}

GameEngineFile::GameEngineFile(const EngineString& _str) 
    : m_File(nullptr), m_OpenMode(FILEOPENMODE::NONE),GameEnginePath(GameEngineDirectory::GetCurrentDirectoryPath() + _str)
{
}

GameEngineFile::GameEngineFile(const wchar_t* _str) 
    : m_File(nullptr), m_OpenMode(FILEOPENMODE::NONE), GameEnginePath(GameEngineDirectory::GetCurrentDirectoryPath() + _str)
{
}

GameEngineFile::~GameEngineFile()
{
    Close();
}

/* 
* GameEngineFile::GameEngineFile(const GameEngineFile& _Other) {}
* Bsee::GameEngineFile(GameEngineFile&& _Other) {}
*/

/*operator ==================================================================================
*GameEngineFile& GameEngineFile::operator(const GameEngineFile& _Other) {}
*GameEngineFile& GameEngineFile::operator(GameEngineFile&& _Other) {}
*/

//Member Function============================================================================

bool GameEngineFile::IsExit()
{
    if (GetPath()!=nullptr)
    {
        if (_waccess_s(GetPath().ConstStringPtr(), 0)==0)
        {
            return true;
        } 
    }
    
    return false;
}

bool GameEngineFile::FileCreateWriteOpen()
{
    if (false == IsExit())
    {
        return FileOpen(L"w");
    }
    else
    {
        return FileOpen(L"r");
    }
}

bool GameEngineFile::FileOpen(const wchar_t* _mode)
{
    Close();

    int iCount = 0;

    while (_mode[iCount] != 0)
    {
        if (toupper(_mode[iCount] == L'W'))
        {
            m_OpenMode = FILEOPENMODE::WRITE;
            break;
        }
        else if (toupper(_mode[iCount] == L'r'))
        {
            m_OpenMode = FILEOPENMODE::READ;
            break;
        }
    }

    _wfopen_s(&m_File, m_Path.ConstStringPtr(), _mode);

    if (!m_File)
    {
        return false;
    }

    return true;
}

void GameEngineFile::Close()
{
    if (m_File)
    {
        fclose(m_File);
        m_File = nullptr;
    }
}

void GameEngineFile::Read(void* _buffer, size_t _buffersize, size_t _elementsize, size_t _elementcount) const
{
    fread_s(_buffer, _buffersize, _elementsize, _elementcount, m_File);
}

void GameEngineFile::Write(const void* _buffer, size_t _elementsize, size_t _elementcount) const
{
    fwrite(_buffer, _elementsize, _elementcount, m_File);
}
