#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>

class GameEngineRender;
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
	//start {175, 305}
	Button* UpperCaseButton[5][6] = {};
	GameEngineRender* UpperCaseLetter1Render[5][6] = {};
	GameEngineRender* UpperCaseLetter2Render[5][6] = {};
	GameEngineRender* UpperCaseLetterEffect1Render[5][6] = {};
	GameEngineRender* UpperCaseLetterEffect2Render[5][6] = {};
	GameEngineRender* UpperCaseLetterEffect3Render[5][6] = {};
	GameEngineRender* UpperCaseLetterShadowRender[5][6] = {};
	
	Button* LowerCaseButton[5][6] = {};
	GameEngineRender* LowerCaseLetter1Render[5][6] = {};
	GameEngineRender* LowerCaseLetter2Render[5][6] = {};
	GameEngineRender* LowerCaseLetterEffect1Render[5][6] = {};
	GameEngineRender* LowerCaseLetterEffect2Render[5][6] = {};
	GameEngineRender* LowerCaseLetterEffect3Render[5][6] = {};
	GameEngineRender* LowerCaseLetterShadowRender[5][6] = {};
	
	//char LowerCase[5][6] = {};

	float4 ButtonScale = { 24,24 };
	float4 ButtonInterval = { 16,0 };
	int LetterRenderHeight = 18;

	void SetUpperCaseButton();
	void SetUpperCaseRender();

	void SetLowerCaseButton();
	void SetLowerCaseRender();
};

