#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "StatusWindow.h"

class SchedulePlayerGuage : public GameEngineActor
{
public:
	// construtor destructor
	SchedulePlayerGuage();
	~SchedulePlayerGuage();

	// delete Function
	SchedulePlayerGuage(const SchedulePlayerGuage& _Other) = delete;
	SchedulePlayerGuage(SchedulePlayerGuage&& _Other) noexcept = delete;
	SchedulePlayerGuage& operator=(const SchedulePlayerGuage& _Other) = delete;
	SchedulePlayerGuage& operator=(SchedulePlayerGuage&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

	void SetSchedule(ScheduleLabel _Schedule);

protected:
	void Start() override; 
	void Update(float _DeltaTime) override;
private:
	int CountStatus = 6;


	StatusWindow* AcGauge11 = nullptr;
	StatusWindow* AcGauge12 = nullptr;
	StatusWindow* AcGauge13 = nullptr;

	StatusWindow* AcGauge21 = nullptr;
	StatusWindow* AcGauge22 = nullptr;
	StatusWindow* AcGauge23 = nullptr;

	GaugeRenderObject* Render1 = nullptr;
	GaugeRenderObject* Render11 = nullptr;
	GaugeRenderObject* Render12 = nullptr;
	GaugeRenderObject* Render3 = nullptr;
	GaugeRenderObject* Render33 = nullptr;
	GaugeRenderObject* Render34 = nullptr;
	GaugeRenderObject* Render5 = nullptr;
	GaugeRenderObject* Render55 = nullptr;
	GaugeRenderObject* Render56 = nullptr;

	const float* Status1 = nullptr;
	const float* Status2 = nullptr;
	const float* Status3 = nullptr;
	const float* Status4 = nullptr;
	const float* Status5 = nullptr;
	const float* Status6 = nullptr;

	void SetAcGauge();
	void SetActorCount(int _Count);
	void SetGaugeRender(int _Count, const std::string_view& _Name1 = " ", const float* _OliveStatusPtr1 = nullptr , const std::string_view& _Name2 = " ", const float* _OliveStatusPtr2 = nullptr, const std::string_view& _Name3 = " ", const float* _OliveStatusPtr3 = nullptr, const std::string_view& _Name4 = " ", const float* _OliveStatusPtr4 = nullptr, const std::string_view& _Name5 = " ", const float* _OliveStatusPtr5 = nullptr, const std::string_view& _Name6 = " ", const float* _OliveStatusPtr6 = nullptr);
	float FindMax(const float* _OliveStatusPtr);
	void InitGauge();
};