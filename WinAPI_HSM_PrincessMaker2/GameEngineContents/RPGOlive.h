#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
enum class PlayerState
{
	IDLE,
	MOVE,
};


class RPGOlive : public GameEngineActor
{
public:
	static RPGOlive* MainPlayer;
	
	// construtor destructor
	RPGOlive();
	~RPGOlive();

	// delete Function
	RPGOlive(const RPGOlive& _Other) = delete;
	RPGOlive(RPGOlive&& _Other) noexcept = delete;
	RPGOlive& operator=(const RPGOlive& _Other) = delete;
	RPGOlive& operator=(RPGOlive&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 100.0f;
	GameEngineRender* AnimationRender = nullptr;
	PlayerState StateValue = PlayerState::IDLE;
	std::string DirString = "Right_";

	void DirCheck(const std::string_view& _AnimationName);


	void ChangeState(PlayerState _State);
	void UpdateState(float _DeltaTime);

	void IdleStart();
	void IdleUpdate(float _DeltaTime);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _DeltaTime);
	void MoveEnd();
};

