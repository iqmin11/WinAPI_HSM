#pragma once
#include "StatusWindow.h"

class PhysicalStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	PhysicalStatusWindow();
	~PhysicalStatusWindow();

	// delete Function
	PhysicalStatusWindow(const PhysicalStatusWindow& _Other) = delete;
	PhysicalStatusWindow(PhysicalStatusWindow&& _Other) noexcept = delete;
	PhysicalStatusWindow& operator=(const PhysicalStatusWindow& _Other) = delete;
	PhysicalStatusWindow& operator=(PhysicalStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 664, 350 };
	
	GaugeRenderObject* HeightRender = nullptr;
	GaugeRenderObject* WeightRender = nullptr;
	GaugeRenderObject* BustRender = nullptr;
	GaugeRenderObject* WaistRender = nullptr;
	GaugeRenderObject* HipRender = nullptr;

	float Height = 0.0f;
	float Weight = 0.0f;
	float Bust = 0.0f;
	float Waist = 0.0f;
	float Hip = 0.0f;
	
	float Max = 200.0f;

	GaugeFrameStyle Style = GaugeFrameStyle::Physical;

	void UpdatePhysicalStatusWindow();
};

