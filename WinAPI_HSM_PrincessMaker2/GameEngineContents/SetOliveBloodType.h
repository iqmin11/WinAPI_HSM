#pragma once
#include <GameEngineCore/GameEngineActor.h>

#include "ContentsEnums.h"

class Button;
class Button_BloodType;
class SetOliveBloodType : public GameEngineActor
{
public:
	// construtor destructor
	SetOliveBloodType();
	~SetOliveBloodType();

	// delete Function
	SetOliveBloodType(const SetOliveBloodType& _Other) = delete;
	SetOliveBloodType(SetOliveBloodType&& _Other) noexcept = delete;
	SetOliveBloodType& operator=(const SetOliveBloodType& _Other) = delete;
	SetOliveBloodType& operator=(SetOliveBloodType&& _Other) noexcept = delete;

	static bool FirstUpdate;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* BackgroundRender = nullptr;
	Button_BloodType* BloodTypeButton[4] = {};
	GameEngineRender* BloodTypeButtonRender1[4] = {};
	GameEngineRender* BloodTypeButtonRender2[4] = {};
	GameEngineRender* BloodTypeButtonEffect1Render[4] = {};
	GameEngineRender* BloodTypeButtonEffect2Render[4] = {};
	GameEngineRender* BloodTypeButtonEffect3Render[4] = {};
	GameEngineRender* BloodTypeButtonShadowRender[4] = {};
	
	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;

	float4 ButtonScale = { 24,24 };
	float4 ButtonInterval = { 64,0 };
	int LetterRenderHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(192, 120, 178);
	COLORREF TextEffect1Color = RGB(152, 134, 50);
	COLORREF TextEffect2Color = RGB(202, 184, 84);
	COLORREF TextEffect3Color = RGB(236, 212, 98);

	void SetBloodTypeButton();
	void SetBloodTypeButtonRender();

	void SetExplainRender();
	static void ClickBloodType(Button* _Button);
};

