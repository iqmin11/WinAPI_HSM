#pragma once
#include <GameEngineCore/GameEngineActor.h>
class SetPlayerAge : public GameEngineActor
{
public:
	// construtor destructor
	SetPlayerAge();
	~SetPlayerAge();

	// delete Function
	SetPlayerAge(const SetPlayerAge& _Other) = delete;
	SetPlayerAge(SetPlayerAge&& _Other) noexcept = delete;
	SetPlayerAge& operator=(const SetPlayerAge& _Other) = delete;
	SetPlayerAge& operator=(SetPlayerAge&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	GameEngineRender* BackgroundRender = nullptr;

};

