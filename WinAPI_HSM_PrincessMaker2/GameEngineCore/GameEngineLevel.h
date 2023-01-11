#pragma once
#include <list>
#include <map>

// �߻�Ŭ������ ����� ��ü���� ���� ������ ���������� ����


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
	void CreateActor(int _Order = 0) // ����Ʈ ���� ������ ���ڸ� ���� ���� �Լ��� �ڵ����� ����Ʈ ���ڰ� ��
	{
		GameEngineActor* Actor = new ActorType();

		ActorStart(Actor, _Order);

		//���� ���ο� ���� [key]�� ���� ��尡 ������ insert, ������ find
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

