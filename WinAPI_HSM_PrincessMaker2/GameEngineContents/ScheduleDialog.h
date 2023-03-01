#pragma once
#include "Dialog.h"
#include "ContentsEnums.h"
#include <map>

class ScheduleDialog : public Dialog
{
public:
	// construtor destructor
	ScheduleDialog();
	~ScheduleDialog();

	// delete Function
	ScheduleDialog(const ScheduleDialog& _Other) = delete;
	ScheduleDialog(ScheduleDialog&& _Other) noexcept = delete;
	ScheduleDialog& operator=(const ScheduleDialog& _Other) = delete;
	ScheduleDialog& operator=(ScheduleDialog&& _Other) noexcept = delete;

	void UpdateCubeDialog(const ScheduleLabel& _Mug, const std::string_view& _Dialog);

protected:
	void Start() override;


private:
	float4 ActorPos = {253, 400}; 
	std::map<ScheduleLabel, std::string> ScheduleMugshot = std::map<ScheduleLabel, std::string>();
	void SetScheduleMugshot();
};

