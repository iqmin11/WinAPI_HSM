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
class SetOliveBloodType;
class Olive;
class FirstSetLevel : public GameEngineLevel
{
public:
	static void SetStateValue(ActorState _State)
	{
		CurStateValue = _State;
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
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	
protected:


private:
	static ActorState CurStateValue;
	static ActorState PrevStateValue;
	
	GameEngineActor* UpdateActor = nullptr;

	Olive* AcOlive = nullptr;
	SetPlayerName* AcSetPlayerName = nullptr;
	SetOliveName* AcSetOliveName = nullptr; 
	OliveCalendar* AcOliveCalendar = nullptr; 
	SetPlayerAge* AcSetPlayerAge = nullptr;
	PlayerCalendar* AcPlayerCalendar = nullptr;
	SetOliveBloodType* AcSetOliveBloodType = nullptr;

	void SoundLoad();
	void ImageLoad();

};

