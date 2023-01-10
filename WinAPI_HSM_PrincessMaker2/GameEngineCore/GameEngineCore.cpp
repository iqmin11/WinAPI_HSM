#include "GameEngineCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineLevel.h"
#include "GameEngineResources.h"

GameEngineCore* Core; // �������� �������� �̰�, CPP������ ��ó����� include���� �����ű⶧���� ������ �̰�

void GameEngineCore::GlobalStart()
{
	Core->Start();
}

void GameEngineCore::GlobalUpdate()
{
	Core->Update();
	if (nullptr == Core->MainLevel)
	{
		MsgAssert("������ ���������� ���� ���·� �ھ �����߽��ϴ�");
		return;
	}
	Core->MainLevel->ActorsUpdate();
	Core->MainLevel->ActorsRender();
}

void GameEngineCore::GlobalEnd()
{
	Core->End();
	GameEngineResources::GetInst().Relase();
}

GameEngineCore::GameEngineCore()
{
	GameEngineDebug::LeakCheck();
	Core = this;
}

GameEngineCore::~GameEngineCore()
{
	std::map<std::string, GameEngineLevel*>::iterator StartIter = Levels.begin();
	std::map<std::string, GameEngineLevel*>::iterator EndIter = Levels.end();

	for (size_t i = 0; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
		}
	}

	Levels.clear();
}

void GameEngineCore::CoreStart(HINSTANCE _instance)
{
	GameEngineWindow::WindowCreate(_instance, "PrincessMaker2", { 800, 640 }, { 0, 0 });
	GameEngineWindow::WindowLoop(GameEngineCore::GlobalStart, GameEngineCore::GlobalUpdate, GameEngineCore::GlobalEnd);
}

void GameEngineCore::ChangeLevel(const std::string_view& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = Levels.find(_Name.data());

	if (FindIter == Levels.end()) 
	
	{
		std::string Name = _Name.data();
		MsgAssert(Name + "�������� �ʴ� ������ �����Ű���� �߽��ϴ�.");
		return;
	}
	
	MainLevel = FindIter->second;
}

void GameEngineCore::LevelLoading(GameEngineLevel* _Level)
{
	if (nullptr == _Level)
	{
		MsgAssert("nullptr �� ������ �ε��Ϸ��� �߽��ϴ�.");
		return;
	}

	_Level->Loading();
}

