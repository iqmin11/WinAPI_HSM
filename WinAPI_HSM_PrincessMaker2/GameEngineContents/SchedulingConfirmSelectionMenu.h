#pragma once
#include "SelectionMenu.h"

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

protected:
	void Start() override;

private:
	float4 ActorPos = { 695,371 };
	float Xscale = 190;
};

