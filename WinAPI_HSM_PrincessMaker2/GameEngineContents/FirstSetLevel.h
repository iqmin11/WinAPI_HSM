#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <list>

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
	GameEngineActor* UpdateActor = nullptr;

	static ActorState StateValue;
	ActorState NextStateValue = ActorState::NULLSTATE;

	SetPlayerName* AcSetPlayerName = nullptr;
	SetOliveName* AcSetOliveName = nullptr; 
	OliveCalendar* AcOliveCalendar = nullptr; 
	SetPlayerAge* AcSetPlayerAge = nullptr;
	PlayerCalendar* AcPlayerCalendar = nullptr;
	SetOliveBooldType* AcSetOliveBloodType = nullptr;

	void ChangeState(ActorState _State);
	void ChangeActor(int _Order);
	void ChangeActor(ActorState _State);

	void OnUpdateActor();
	void OffUpdateActor();

	void NULLStateStart();
	void NULLStateEnd();

	void SetPlayerNameStart();
	void SetPlayerNameEnd();

	void SetOliveNameStart();
	void SetOliveNameEnd();

	void OliveCalendarStart();
	void OliveCalendarEnd();

	void SetPlayerAgeStart();
	void SetPlayerAgeEnd();

	void PlayerCalendarStart();
	void PlayerCalendarEnd();

	void SetOliveBloodTypeStart();
	void SetOliveBloodTypeEnd();

	void SoundLoad();
	void ImageLoad();

	static void ChangeStateToSetOliveName()
	{
		StateValue = ActorState::SetOliveName;
	}
};

