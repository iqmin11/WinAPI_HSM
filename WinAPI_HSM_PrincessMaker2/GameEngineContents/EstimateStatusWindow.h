#pragma once
#include "StatusWindow.h"

class EstimateStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	EstimateStatusWindow();
	~EstimateStatusWindow();

	// delete Function
	EstimateStatusWindow(const EstimateStatusWindow& _Other) = delete;
	EstimateStatusWindow(EstimateStatusWindow&& _Other) noexcept = delete;
	EstimateStatusWindow& operator=(const EstimateStatusWindow& _Other) = delete;
	EstimateStatusWindow& operator=(EstimateStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 130, 455 };

	float Fighter = 0;
	GaugeRenderObject* FighterRender = nullptr;
	float Magical = 0;
	GaugeRenderObject* MagicalRender = nullptr;
	float Social = 0;
	GaugeRenderObject* SocialRender = nullptr;
	float HouseWork = 0;
	GaugeRenderObject* HouseWorkRender = nullptr;

	float Max = 300;

	GaugeFrameStyle Style = GaugeFrameStyle::Estemate;
};

