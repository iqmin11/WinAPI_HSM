#pragma once
#include "Dialog.h"
#include <GameEngineCore/NumberRenderObject.h>
#include "Olive.h"

class GameEngineRender;
class FoodCostDialog : public Dialog
{
public:
	// construtor destructor
	FoodCostDialog();
	~FoodCostDialog();

	// delete Function
	FoodCostDialog(const FoodCostDialog& _Other) = delete;
	FoodCostDialog(FoodCostDialog&& _Other) noexcept = delete;
	FoodCostDialog& operator=(const FoodCostDialog& _Other) = delete;
	FoodCostDialog& operator=(FoodCostDialog&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	Diet OliveDiet = Diet::무리하지_않는다;
	
	float4 ActorPos = { 235,475 }; // 206 239 -> 41, 64
	float4 ActorScale = { 390, 124 };
	
	GameEngineRender* FoodCostRedner = nullptr;
	float4 FoodCostRednerPos = {-95, -91};// 95 91

	NumberRenderObject FoodCostNumRender = NumberRenderObject();
	float4 FoodCostNumRenderPos = {-48,-92}; // 47, 92

	GameEngineRender* TextRender = nullptr;
	int TextHeight = 18;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 80, 21 };
	float4 TextRenderPos = { -175, -103 };

	void SetRender();
};

