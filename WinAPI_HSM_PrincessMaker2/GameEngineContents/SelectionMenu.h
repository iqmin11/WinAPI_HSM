#pragma once
#include "MenuFrame.h"
class SelectionMenu : public MenuFrame
{
public:
	// construtor destructor
	SelectionMenu();
	~SelectionMenu();

	// delete Function
	SelectionMenu(const SelectionMenu& _Other) = delete;
	SelectionMenu(SelectionMenu&& _Other) noexcept = delete;
	SelectionMenu& operator=(const SelectionMenu& _Other) = delete;
	SelectionMenu& operator=(SelectionMenu&& _Other) noexcept = delete;

	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

protected:


private:

};

