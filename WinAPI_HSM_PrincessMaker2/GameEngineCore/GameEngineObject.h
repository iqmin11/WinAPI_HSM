#pragma once
class GameEngineObject
{
public:
	// construtor destructor
	GameEngineObject();
	~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	bool IsUpdate()
	{
		return nullptr != Parent ? (ObjectUpdate && !ObjectDeath && Parent->IsUpdate() == true) : (ObjectUpdate && !ObjectDeath);
	}

	bool IsDeath()
	{
		return nullptr != Parent ? ObjectDeath || Parent->IsDeath() : ObjectDeath;
	}
	
	void Death()
	{
		ObjectDeath = true;
	}

	void On()
	{
		ObjectUpdate = true;
	}
	
	void Off()
	{
		ObjectUpdate = false;
	}

	void OnOffSwtich()
	{
		ObjectUpdate = !ObjectUpdate;
	}

	void SetParent(GameEngineObject* _Parent)
	{
		Parent = _Parent;
	}

protected:


private:
	GameEngineObject* Parent = nullptr; // 오브젝트가 오브젝트를 가지고 있는 경우인거지 ex) 주인공과 주인공의 무기

	bool ObjectDeath = false;
	bool ObjectUpdate = true;


};

