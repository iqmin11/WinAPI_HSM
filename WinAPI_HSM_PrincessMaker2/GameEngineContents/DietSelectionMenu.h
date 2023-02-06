#pragma once
#include "SelectionMenu.h"

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

};

