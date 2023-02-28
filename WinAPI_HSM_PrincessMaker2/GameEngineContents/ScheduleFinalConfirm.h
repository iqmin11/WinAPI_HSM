#pragma once
#include "SelectionMenu.h"

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

private:
	float4 ActorPos = { 670,321 };
	float Xscale = 140;

};

