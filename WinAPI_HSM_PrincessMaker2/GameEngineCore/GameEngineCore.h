#pragma once
#include <Windows.h>
#include <map>
#include <string_view>
#include <GameEngineBase/GameEngineDebug.h>

class GameEngineLevel;
class GameEngineCore // 순수가상함수가 있는 클래스는 추상클래스
{
private:
	static void GlobalStart();
	static void GlobalUpdate();
	static void GlobalEnd();

public:
	// construtor destructor
	GameEngineCore();
	~GameEngineCore();

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	void CoreStart(HINSTANCE _instance); // Core의 윈도우를 실행

protected:
	template<typename LevelType>
	void CreateLevel(const std::string_view& _Name)
	{
		if (Levels.end() != Levels.find(_Name.data()))
		{
			std::string Name = _Name.data();
			MsgAssert(Name + "이미 존재하는 이름의 레벨을 만들려고 했습니다");
			return;
		}

		GameEngineLevel* Level = new LevelType();
		Levels.insert(std::make_pair(_Name.data(), Level));

	}

	void ChangeLevel(const std::string_view& _Name);

	virtual void Start() = 0; // 순수 가상함수, 자식들은 무조건 구현해야하는 함수
	virtual void Update() = 0;
	virtual void End() = 0;




private:
	// 직관적이어서 map 애용
	std::map<std::string, GameEngineLevel*> Levels;
	
	GameEngineLevel* MainLevel = nullptr;
};

