#pragma once
#include "StatusWindow.h"

class BasicStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	BasicStatusWindow();
	~BasicStatusWindow();

	// delete Function
	BasicStatusWindow(const BasicStatusWindow& _Other) = delete;
	BasicStatusWindow(BasicStatusWindow&& _Other) noexcept = delete;
	BasicStatusWindow& operator=(const BasicStatusWindow& _Other) = delete;
	BasicStatusWindow& operator=(BasicStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 130, 260 };

	float Constitution = 0;
	GaugeRenderObject* ConstitutionRender = nullptr;

	float Strength = 0;
	GaugeRenderObject* StrengthRender = nullptr;
	
	float Intelligence = 0;
	GaugeRenderObject* IntelligenceRender = nullptr;
	
	float Refinement = 0;
	GaugeRenderObject* RefinementRender = nullptr;
	
	float Charisma = 0;
	GaugeRenderObject* CharismaRender = nullptr;
	
	float Morality = 0;
	GaugeRenderObject* MoralityRender = nullptr;
	
	float Faith = 0;
	GaugeRenderObject* FaithRender = nullptr;
	
	float Sin = 0;
	GaugeRenderObject* SinRender = nullptr;
	
	float Sensitivity = 0;
	GaugeRenderObject* SensitivityRender = nullptr;
	
	float Stress = 0;
	GaugeRenderObject* StressRender = nullptr;
	
	float Max = 999;
	
	GaugeFrameStyle Style = GaugeFrameStyle::Nomal;
};

