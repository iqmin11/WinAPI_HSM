#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>

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

	void On() override;
	void Off() override;
private:
	GameEngineRender* BackgroundRender = nullptr;
	Button* UpperCaseButton[5][6] = {};
	char UpperCase[5][6] = {};
	Button* LowerCaseButton[5][6] = {};
	char LowerCase[5][6] = {};

	float4 ButtonScale = { 30,30 };
	float4 ButtonInterval = { 40,0 };

	void SetUpperCaseButton();
	void SetLowerCaseButton();
};

