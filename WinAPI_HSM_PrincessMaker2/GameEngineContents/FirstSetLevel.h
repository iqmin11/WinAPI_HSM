#pragma once
#include <GameEngineCore/GameEngineLevel.h>

enum class ActorState
{
	NULLSTATE,
	SetPlayerName,
	SetOliveName,
	OliveCalendar,
	PlayerCalendar
};

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
	void ChangeActor(int _Order);
protected:


private:
	

	ActorState StateValue = ActorState::NULLSTATE;

	void ChangeState(ActorState _State);

	void NULLStateStart();
	void NULLStateEnd();

	void SetPlayerNameStart();
	void SetPlayerNameUpdate();
	void SetPlayerNameEnd();

	void SetOliveNameStart();
	void SetOliveNameUpdate();
	void SetOliveNameEnd();

	void OliveCalendarStart();
	void OliveCalendarUpdate();
	void OliveCalendarEnd();

	void PlayerCalendarStart();
	void PlayerCalendarUpdate();
	void PlayerCalendarEnd();
};

