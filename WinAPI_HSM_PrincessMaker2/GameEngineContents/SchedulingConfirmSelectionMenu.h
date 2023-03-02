#pragma once
#include "SelectionMenu.h"

class CubeDialog;
class ScheduleSelectionMenu;
class ScheduleCalendar;
class ScheduleFinalConfirm;
class SchedulingConfirmSelectionMenu : public SelectionMenu
{
public:
	// construtor destructor
	SchedulingConfirmSelectionMenu();
	~SchedulingConfirmSelectionMenu();

	// delete Function
	SchedulingConfirmSelectionMenu(const SchedulingConfirmSelectionMenu& _Other) = delete;
	SchedulingConfirmSelectionMenu(SchedulingConfirmSelectionMenu&& _Other) noexcept = delete;
	SchedulingConfirmSelectionMenu& operator=(const SchedulingConfirmSelectionMenu& _Other) = delete;
	SchedulingConfirmSelectionMenu& operator=(SchedulingConfirmSelectionMenu&& _Other) noexcept = delete;

	void SetScheduleState(ScheduleLabel _State)
	{
		ScheduleState = _State;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	float4 ActorPos = { 695,371 };
	float Xscale = 190;

	static CubeDialog* AcCubeDialog;
	static ScheduleLabel ScheduleState;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;
	static SchedulingConfirmSelectionMenu* AcSchedulingConfirmSelectionMenu;
	static ScheduleCalendar* AcScheduleCalendars;
	static ScheduleFinalConfirm* AcScheduleFinalConfirm;
	

	void SetButtonClick();

	static void Click0(Button* _Button);
	static void Click1(Button* _Button);
};

