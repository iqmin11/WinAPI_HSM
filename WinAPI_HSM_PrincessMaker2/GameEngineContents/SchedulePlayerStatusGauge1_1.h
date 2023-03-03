#pragma once
#include "StatusWindow.h"
class SchedulePlayerStatusGauge1_1 : public StatusWindow
{
public:
	// construtor destructor
	SchedulePlayerStatusGauge1_1();
	~SchedulePlayerStatusGauge1_1();

	// delete Function
	SchedulePlayerStatusGauge1_1(const SchedulePlayerStatusGauge1_1& _Other) = delete;
	SchedulePlayerStatusGauge1_1(SchedulePlayerStatusGauge1_1&& _Other) noexcept = delete;
	SchedulePlayerStatusGauge1_1& operator=(const SchedulePlayerStatusGauge1_1& _Other) = delete;
	SchedulePlayerStatusGauge1_1& operator=(SchedulePlayerStatusGauge1_1&& _Other) noexcept = delete;

	void SetSchedule(ScheduleLabel _Schedule);

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	float* Status1 = nullptr;
	GaugeRenderObject* Render1 = nullptr;
	
	float* Status2 = nullptr;
	GaugeRenderObject* Render2 = nullptr;
	

	GaugeFrameStyle Style = GaugeFrameStyle::Nomal;
};

