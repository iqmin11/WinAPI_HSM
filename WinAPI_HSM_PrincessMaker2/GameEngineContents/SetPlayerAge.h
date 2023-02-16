#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Button;
class CharButton;
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

	static bool FirstUpdate;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	GameEngineRender* BackgroundRender = nullptr;
	CharButton* AgeNumButton[10] = {};
	GameEngineRender* AgeNumButtonRender1[10] = {};
	GameEngineRender* AgeNumButtonRender2[10] = {};
	GameEngineRender* AgeNumButtonEffect1Render[10] = {};
	GameEngineRender* AgeNumButtonEffect2Render[10] = {};
	GameEngineRender* AgeNumButtonEffect3Render[10] = {};
	GameEngineRender* AgeNumButtonShadowRender[10] = {};

	static std::string PrintLetter;
	GameEngineRender* PrintLetterRender1 = nullptr;
	GameEngineRender* PrintLetterRender2 = nullptr;
	GameEngineRender* PrintLetterRender3 = nullptr;

	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;

	Button* CompleteButton = nullptr;
	GameEngineRender* CompleteButton1Render = nullptr;
	GameEngineRender* CompleteButton2Render = nullptr;
	GameEngineRender* CompleteButtonEffect1Render = nullptr;
	GameEngineRender* CompleteButtonEffect2Render = nullptr;
	GameEngineRender* CompleteButtonEffect3Render = nullptr;
	GameEngineRender* CompleteButtonShadowRender = nullptr;

	float4 ButtonScale = { 24,24 };
	float4 ButtonScale2 = { 48,24 };
	float4 ButtonInterval = { 8,0 };
	int LetterRenderHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(106, 170, 126);
	COLORREF TextEffect1Color = RGB(152, 134, 50);
	COLORREF TextEffect2Color = RGB(202, 184, 84);
	COLORREF TextEffect3Color = RGB(236, 212, 98);

	void SetAgeNumButton();
	void SetAgeNumRender();

	void SetPrintLetterRender();

	void SetExplainRender();

	void SetCompleteButton();
	void SetCompleteButtonRender();

	static void PushBack_Button(Button* _Button);

	static void ClickCompleteButton(Button* _Button);
};

