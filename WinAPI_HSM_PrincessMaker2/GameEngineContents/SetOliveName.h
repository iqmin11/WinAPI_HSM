#pragma once
#include <GameEngineCore/GameEngineActor.h>

class SetOliveName : public GameEngineActor
{
public:
	// construtor destructor
	SetOliveName();
	~SetOliveName();

	// delete Function
	SetOliveName(const SetOliveName& _Other) = delete;
	SetOliveName(SetOliveName&& _Other) noexcept = delete;
	SetOliveName& operator=(const SetOliveName& _Other) = delete;
	SetOliveName& operator=(SetOliveName&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	GameEngineRender* BackgroundRender = nullptr;

};

