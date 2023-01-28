#pragma once
#include <GameEngineCore/GameEngineActor.h>

class SetPlayerName : public GameEngineActor
{
public:
	// construtor destructor
	SetPlayerName();
	~SetPlayerName();

	// delete Function
	SetPlayerName(const SetPlayerName& _Other) = delete;
	SetPlayerName(SetPlayerName&& _Other) noexcept = delete;
	SetPlayerName& operator=(const SetPlayerName& _Other) = delete;
	SetPlayerName& operator=(SetPlayerName&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	GameEngineRender* BackgroundRender = nullptr;

};

