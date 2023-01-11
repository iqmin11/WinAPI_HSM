#pragma once
#include <list>
#include <map>

// 추상클래스로 만들고 구체적인 게임 레벨을 콘텐츠에서 구현


class GameEngineCore;
class GameEngineActor;
class GameEngineLevel
{
	friend GameEngineCore;
public:
	// constrcuter destructer
	GameEngineLevel();
	virtual ~GameEngineLevel() = 0;

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType>
	void CreateActor(int _Order = 0) // 디폴트 인자 설정시 인자를 넣지 않은 함수는 자동으로 디폴트 인자가 들어감
	{
		GameEngineActor* Actor = new ActorType();

		ActorStart(Actor, _Order);

		//맵의 새로운 문법 [key]를 가진 노드가 없으면 insert, 있으면 find
		Actors[_Order].push_back(Actor);
	}

protected:
	virtual void Loading() = 0;
	virtual void Update() = 0;

private:
	std::map<int, std::list<GameEngineActor*>> Actors;

	void ActorStart(GameEngineActor* _Actor, int _Order);
	void ActorsUpdate();
	void ActorsRender();

};

