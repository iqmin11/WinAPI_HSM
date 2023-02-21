#pragma once
#include "SelectionMenu.h"
class DietFinalConfirmSelectionMenu : public SelectionMenu
{
public:
	// construtor destructor
	DietFinalConfirmSelectionMenu();
	~DietFinalConfirmSelectionMenu();

	// delete Function
	DietFinalConfirmSelectionMenu(const DietFinalConfirmSelectionMenu& _Other) = delete;
	DietFinalConfirmSelectionMenu(DietFinalConfirmSelectionMenu&& _Other) noexcept = delete;
	DietFinalConfirmSelectionMenu& operator=(const DietFinalConfirmSelectionMenu& _Other) = delete;
	DietFinalConfirmSelectionMenu& operator=(DietFinalConfirmSelectionMenu&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	float4 ActorPos = { 685,320 };
	float Xscale = 140;
};

