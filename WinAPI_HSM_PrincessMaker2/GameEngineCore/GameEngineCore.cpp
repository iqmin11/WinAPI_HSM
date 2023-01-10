#include "GameEngineCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include "GameEngineLevel.h"
#include "GameEngineResources.h"

GameEngineCore* Core; // 전역변수 선언이지 이건, CPP파일을 전처리기로 include하지 않을거기때문에 괜찮지 이건

void GameEngineCore::GlobalStart()
{
	Core->Start();
}

void GameEngineCore::GlobalUpdate()
{
	Core->Update();
	if (nullptr == Core->MainLevel)
	{
		MsgAssert("레벨을 지정해주지 않은 상태로 코어를 실행했습니다");
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
		MsgAssert(Name + "존재하지 않는 레벨을 실행시키려고 했습니다.");
		return;
	}
	
	MainLevel = FindIter->second;
}

void GameEngineCore::LevelLoading(GameEngineLevel* _Level)
{
	if (nullptr == _Level)
	{
		MsgAssert("nullptr 인 레벨을 로딩하려고 했습니다.");
		return;
	}

	_Level->Loading();
}

