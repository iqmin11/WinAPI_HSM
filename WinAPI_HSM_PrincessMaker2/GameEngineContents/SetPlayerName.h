#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>

class NameButton;
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

	Button* GetCompleteButton()
	{
		return CompleteButton;
	}
	
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
	GameEngineRender* PrintLetterShadow = nullptr;

	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;
	
	NameButton* UpperCaseButton[6][5] = {};
	GameEngineRender* UpperCaseLetter1Render[6][5] = {};
	GameEngineRender* UpperCaseLetter2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect1Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect2Render[6][5] = {};
	GameEngineRender* UpperCaseLetterEffect3Render[6][5] = {};
	GameEngineRender* UpperCaseLetterShadowRender[6][5] = {};
	
	NameButton* LowerCaseButton[6][5] = {};
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

	static void PushBack_Button(Button* _Btn);

	static void PushBack_A();
	static void PushBack_B();
	static void PushBack_C();
	static void PushBack_D();
	static void PushBack_E();
	static void PushBack_F();
	static void PushBack_G();
	static void PushBack_H();
	static void PushBack_I();
	static void PushBack_J();
	static void PushBack_K();
	static void PushBack_L();
	static void PushBack_M();
	static void PushBack_N();
	static void PushBack_O();
	static void PushBack_P();
	static void PushBack_Q();
	static void PushBack_R();
	static void PushBack_S();
	static void PushBack_T();
	static void PushBack_U();
	static void PushBack_V();
	static void PushBack_W();
	static void PushBack_X();
	static void PushBack_Y();
	static void PushBack_Z();

	static void PushBack_a();
	static void PushBack_b();
	static void PushBack_c();
	static void PushBack_d();
	static void PushBack_e();
	static void PushBack_f();
	static void PushBack_g();
	static void PushBack_h();
	static void PushBack_i();
	static void PushBack_j();
	static void PushBack_k();
	static void PushBack_l();
	static void PushBack_m();
	static void PushBack_n();
	static void PushBack_o();
	static void PushBack_p();
	static void PushBack_q();
	static void PushBack_r();
	static void PushBack_s();
	static void PushBack_t();
	static void PushBack_u();
	static void PushBack_v();
	static void PushBack_w();
	static void PushBack_x();
	static void PushBack_y();
	static void PushBack_z();

	static void PopBack_PrintLetter(Button* Button);

};

