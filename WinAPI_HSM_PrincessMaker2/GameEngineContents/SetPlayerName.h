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
	
	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;
	
	Button* UpperCaseButton[6][5] = {};
	GameEngineRender* UpperCaseLetter1Render[6][5] = {};
	GameEngineRender* UpperCaseLetter2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect1Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect3Render[6][5] = {};
	GameEngineRender* UpperCaseLetterShadowRender[6][5] = {};
	
	Button* LowerCaseButton[6][5] = {};
	GameEngineRender* LowerCaseLetter1Render[6][5] = {};
	GameEngineRender* LowerCaseLetter2Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect1Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect2Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect3Render[6][5] = {};
	GameEngineRender* LowerCaseLetterShadowRender[6][5] = {};

	Button* CompleteButton = nullptr;
	GameEngineRender* CompleteButton1Render = nullptr;
	GameEngineRender* CompleteButton2Render = nullptr;
	GameEngineRender* CompleteButtonEffect1Render = nullptr;
	GameEngineRender* CompleteButtonEffect2Render = nullptr;
	GameEngineRender* CompleteButtonEffect3Render = nullptr;
	GameEngineRender* CompleteButtonShadowRender = nullptr;
	
	Button* LetterEraseButton = nullptr;
	GameEngineRender* LetterEraseButton1Render = nullptr;
	GameEngineRender* LetterEraseButton2Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect1Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect2Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect3Render = nullptr;
	GameEngineRender* LetterEraseButtonShadowRender = nullptr;

	//char LowerCase[5][6] = {};

	float4 ButtonScale = { 24,24 };
	float4 ButtonScale2 = { 48,24 };
	float4 ButtonInterval = { 16,0 };
	int LetterRenderHeight = 18;
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(106, 170, 126);
	COLORREF TextEffect1Color = RGB(152, 134, 50);
	COLORREF TextEffect2Color = RGB(202, 184, 84);
	COLORREF TextEffect3Color = RGB(236, 212, 98);
	std::string TextType = "±¼¸²";

	void SetExplainRender();

	void SetUpperCaseButton();
	void SetUpperCaseRender();

	void SetLowerCaseButton();
	void SetLowerCaseRender();

	void SetCompleteButton();
	void SetCompleteButtonRender();
	
	void SetLetterEraseButton();
	void SetLetterEraseButtonRender();
};

