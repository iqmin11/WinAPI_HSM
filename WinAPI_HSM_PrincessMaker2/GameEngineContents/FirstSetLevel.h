#pragma once
#include <GameEngineCore/GameEngineLevel.h>

enum class ActorState
{
	NULLSTATE,
	SetPlayerName,
	SetOliveName,
	OliveCalendar,
	SetPlayerAge,
	PlayerCalendar,
	SetOliveBloodType
};

class GameEngineActor;
class SetPlayerName;
class SetOliveName;
class OliveCalendar;
class SetPlayerAge;
class PlayerCalendar;
class SetOliveBooldType;
class FirstSetLevel : public GameEngineLevel
{
public:
	static void SetStateValue(ActorState _State)
	{
		StateValue = _State;
	}
	
	// construtor destructor
	FirstSetLevel();
	~FirstSetLevel();

	// delete Function
	FirstSetLevel(const FirstSetLevel& _Other) = delete;
	FirstSetLevel(FirstSetLevel&& _Other) noexcept = delete;
	FirstSetLevel& operator=(const FirstSetLevel& _Other) = delete;
	FirstSetLevel& operator=(FirstSetLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {};
	
protected:


private:
	static ActorState StateValue;
	
	GameEngineActor* UpdateActor = nullptr;

	SetPlayerName* AcSetPlayerName = nullptr;
	SetOliveName* AcSetOliveName = nullptr; 
	OliveCalendar* AcOliveCalendar = nullptr; 
	SetPlayerAge* AcSetPlayerAge = nullptr;
	PlayerCalendar* AcPlayerCalendar = nullptr;
	SetOliveBooldType* AcSetOliveBloodType = nullptr;

	void ChangeState(ActorState _State);
	
	void SoundLoad();
	void ImageLoad();
};

