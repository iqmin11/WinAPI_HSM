#pragma once
#include "SelectionMenu.h"

class SelectDialog;
class CubeDialog;
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

	void On() override;
	void Off() override;

	void SetDietState(Diet _State);

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	float4 ActorPos = { 685,320 };
	float Xscale = 140;
	
	static Diet DietState;
	SelectDialog* AcSelectDialog = nullptr;
	static CubeDialog* AcCubeDialog;
	static DietFinalConfirmSelectionMenu* AcDietFinalConfirmSelectionMenu;

	void SetButtonClick();
	static void Click0(Button* _Button); // 이 방침으로
	static void Click1(Button* _Button); // 지금까지 대로
};

