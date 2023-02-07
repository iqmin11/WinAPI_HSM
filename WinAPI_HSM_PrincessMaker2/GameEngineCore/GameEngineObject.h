#pragma once
class GameEngineObject
{
public:
	// construtor destructor
	GameEngineObject();
	virtual ~GameEngineObject();

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	bool IsUpdate()
	{
		return nullptr != Parent ? ((ObjectUpdate && false == IsDeath()) && Parent->IsUpdate()) : (ObjectUpdate && false == IsDeath());
	}

	bool IsDeath()
	{
		return nullptr != Parent ? (true == ObjectDeath || Parent->IsDeath()) : (true == ObjectDeath);
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

	virtual void SetOwner(GameEngineObject* _Parent)
	{
		Parent = _Parent;
	}
	
	template<typename ConvertType>
	ConvertType* GetOwner()
	{
		return dynamic_cast<ConvertType*>(Parent);
	}

	GameEngineObject* GetOwner()
	{
		return Parent;
	}

	virtual void SetOrder(int _Order)
	{
		Order = _Order;
	}

	int GetOrder()
	{
		return Order;
	}

protected:


private:
	int Order =-123123;

	GameEngineObject* Parent = nullptr; // 오브젝트가 오브젝트를 가지고 있는 경우인거지 ex) 주인공과 주인공의 무기

	bool ObjectDeath = false;
	bool ObjectUpdate = true;


};

