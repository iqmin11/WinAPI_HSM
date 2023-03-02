#pragma once
#include "SelectionMenu.h"

class CubeDialog;
class ScheduleSelectionMenu;
class ScheduleCalendar;
class ScheduleFinalConfirm : public SelectionMenu
{
public:
	// construtor destructor
	ScheduleFinalConfirm();
	~ScheduleFinalConfirm();

	// delete Function
	ScheduleFinalConfirm(const ScheduleFinalConfirm& _Other) = delete;
	ScheduleFinalConfirm(ScheduleFinalConfirm&& _Other) noexcept = delete;
	ScheduleFinalConfirm& operator=(const ScheduleFinalConfirm& _Other) = delete;
	ScheduleFinalConfirm& operator=(ScheduleFinalConfirm&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static ScheduleFinalConfirm* AcScheduleFinalConfirm;

	float4 ActorPos = { 670,321 };
	float Xscale = 140;

	static CubeDialog* AcCubeDialog;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;
	static ScheduleCalendar* AcScheduleCalendar;
	
	void SetButtonClick();

	static void Click0(Button* _Button); //스케줄을 실행
	static void Click1(Button* _Button); //취소
};

