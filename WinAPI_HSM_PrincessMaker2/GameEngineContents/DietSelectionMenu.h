#pragma once
#include "SelectionMenu.h"

class Button;
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

protected:
	void Start() override;


private:
	float4 ActorPos = { 685,366 };
	float Xscale = 170.0f;

	static void Click0(Button* _Button);
	static void Click1(Button* _Button);
	static void Click2(Button* _Button);
	static void Click3(Button* _Button);
};

