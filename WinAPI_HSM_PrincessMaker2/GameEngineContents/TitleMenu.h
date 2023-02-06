#pragma once
#include "SelectionMenu.h"

class TitleMenu : public SelectionMenu
{
public:
	// construtor destructor
	TitleMenu();
	~TitleMenu();

	// delete Function
	TitleMenu(const TitleMenu& _Other) = delete;
	TitleMenu(TitleMenu&& _Other) noexcept = delete;
	TitleMenu& operator=(const TitleMenu& _Other) = delete;
	TitleMenu& operator=(TitleMenu&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

