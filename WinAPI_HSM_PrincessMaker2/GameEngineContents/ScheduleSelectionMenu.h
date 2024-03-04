#pragma once
#include "SelectionMenu.h"

class ClassSelectWindow;
class CubeDialog;
class ScheduleCalendar;
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


	static ScheduleSelectionMenu* GetAcScheduleSelectionMenu()
	{
		return AcScheduleSelectionMenu;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float Xscale = 200;
	float4 ActorPos = { 700,347 };

	static ClassSelectWindow* AcClassSelectWindow;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;
	CubeDialog* AcCubeDialog = nullptr;
	ScheduleCalendar* AcScheduleCalendar = nullptr;

	void SetButtonClick();

	static void Click0(Button* _Button);
};

