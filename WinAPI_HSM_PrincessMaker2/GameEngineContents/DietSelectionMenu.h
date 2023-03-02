#pragma once
#include "SelectionMenu.h"

class MainMenu;
class Button;
class CubeDialog;
class DietFinalConfirmSelectionMenu;
class DietSelectionMenu : public SelectionMenu
{
public:
	// construtor destructor
	DietSelectionMenu();
	~DietSelectionMenu();

	// delete Function
	DietSelectionMenu(const DietSelectionMenu& _Other) = delete;
	DietSelectionMenu(DietSelectionMenu&& _Other) noexcept = delete;
	DietSelectionMenu& operator=(const DietSelectionMenu& _Other) = delete;
	DietSelectionMenu& operator=(DietSelectionMenu&& _Other) noexcept = delete;

	static DietSelectionMenu* GetAcDietSelectionMenu()
	{
		return AcDietSelectionMenu;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	MainMenu* AcMainMenu = nullptr;
	static DietSelectionMenu* AcDietSelectionMenu;
	static DietFinalConfirmSelectionMenu* AcDietFinalConfirmSelectionMenu;
	static CubeDialog* AcCubeDialog;

	float4 ActorPos = { 685,346 };
	float Xscale = 170.0f;

	void SetButton();

	static void Click0(Button* _Button); // 무리하지 않는다
	static void Click1(Button* _Button); // 어쨌든 튼튼하게
	static void Click2(Button* _Button); // 얌전한 아이로
	static void Click3(Button* _Button); // 다이어트 시킨다
};

