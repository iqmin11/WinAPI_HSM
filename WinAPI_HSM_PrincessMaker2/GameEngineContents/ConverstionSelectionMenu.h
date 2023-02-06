#pragma once
#include "SelectionMenu.h"

class ConverstionSelectionMenu : public SelectionMenu
{
public:
	// construtor destructor
	ConverstionSelectionMenu();
	~ConverstionSelectionMenu();

	// delete Function
	ConverstionSelectionMenu(const ConverstionSelectionMenu& _Other) = delete;
	ConverstionSelectionMenu(ConverstionSelectionMenu&& _Other) noexcept = delete;
	ConverstionSelectionMenu& operator=(const ConverstionSelectionMenu& _Other) = delete;
	ConverstionSelectionMenu& operator=(ConverstionSelectionMenu&& _Other) noexcept = delete;

protected:

	void Start() override;

private:

};

