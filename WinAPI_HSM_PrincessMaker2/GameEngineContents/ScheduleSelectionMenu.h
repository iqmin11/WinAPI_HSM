#pragma once
#include "SelectionMenu.h"
class ScheduleSelectionMenu : public SelectionMenu
{
public:
	// construtor destructor
	ScheduleSelectionMenu();
	~ScheduleSelectionMenu();

	// delete Function
	ScheduleSelectionMenu(const ScheduleSelectionMenu& _Other) = delete;
	ScheduleSelectionMenu(ScheduleSelectionMenu&& _Other) noexcept = delete;
	ScheduleSelectionMenu& operator=(const ScheduleSelectionMenu& _Other) = delete;
	ScheduleSelectionMenu& operator=(ScheduleSelectionMenu&& _Other) noexcept = delete;

	void Start() override;

protected:


private:
	float Xscale = 200;
	float4 ActorPos = { 700,347 };
};

