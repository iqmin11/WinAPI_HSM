#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include "GlobalButton.h"

class CharButton;
class GameEngineRender;
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

	static bool FirstUpdate;

	static std::string GetPrintLetter()
	{
		return PrintLetter;
	}

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	GameEngineRender* BackgroundRender = nullptr;

	static std::string PrintLetter;
	GameEngineRender* PrintLetterRender1 = nullptr;
	GameEngineRender* PrintLetterRender2 = nullptr;
	GameEngineRender* PrintLetterRender3 = nullptr;
	float4 PrintLetterBoxScale = { 120 , 18 };

	static GameEngineRender* ExplainRender1;
	static GameEngineRender* ExplainRender2;
	static GameEngineRender* ExplainRenderShadow;
	static std::string ExplainText;
	static std::string ErrorText;
	static float4 ExplainTextBoxScale;
	static float4 ErrorTextBoxScale;

	CharButton* UpperCaseButton[6][5] = {};
	GameEngineRender* UpperCaseLetter1Render[6][5] = {};
	GameEngineRender* UpperCaseLetter2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect1Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect3Render[6][5] = {};
	GameEngineRender* UpperCaseLetterShadowRender[6][5] = {};

	CharButton* LowerCaseButton[6][5] = {};
	GameEngineRender* LowerCaseLetter1Render[6][5] = {};
	GameEngineRender* LowerCaseLetter2Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect1Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect2Render[6][5] = {};
	GameEngineRender* LowerCaseLetterEffect3Render[6][5] = {};
	GameEngineRender* LowerCaseLetterShadowRender[6][5] = {};

	GlobalButton* CompleteButton = nullptr;
	GameEngineRender* CompleteButton1Render = nullptr;
	GameEngineRender* CompleteButton2Render = nullptr;
	GameEngineRender* CompleteButtonEffect1Render = nullptr;
	GameEngineRender* CompleteButtonEffect2Render = nullptr;
	GameEngineRender* CompleteButtonEffect3Render = nullptr;
	GameEngineRender* CompleteButtonShadowRender = nullptr;

	GlobalButton* LetterEraseButton = nullptr;
	GameEngineRender* LetterEraseButton1Render = nullptr;
	GameEngineRender* LetterEraseButton2Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect1Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect2Render = nullptr;
	GameEngineRender* LetterEraseButtonEffect3Render = nullptr;
	GameEngineRender* LetterEraseButtonShadowRender = nullptr;

	float4 ButtonScale = { 24,24 };
	float4 ButtonScale2 = { 48,24 };
	float4 ButtonInterval = { 16,0 };
	int LetterRenderHeight = 18;
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(192, 120, 178);
	COLORREF TextEffect1Color = RGB(152, 134, 50);
	COLORREF TextEffect2Color = RGB(202, 184, 84);
	COLORREF TextEffect3Color = RGB(236, 212, 98);
	std::string TextType = "±¼¸²";

	void SetPrintLetterRender();

	void SetExplainRender();

	void SetUpperCaseButton();
	void SetUpperCaseRender();

	void SetLowerCaseButton();
	void SetLowerCaseRender();

	void SetCompleteButton();
	void SetCompleteButtonRender();

	void SetLetterEraseButton();
	void SetLetterEraseButtonRender();

	static void PushBack_Button(Button* _Button);

	static void PopBack_PrintLetter(Button* _Button);

	static void ClickCompleteButton(Button* _Button);
};

