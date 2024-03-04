#pragma once
#include "GlobalButton.h"


class CharButton : public GlobalButton
{
public:
	// constrcuter destructer
	CharButton();
	~CharButton();

	// delete Function
	CharButton(const CharButton& _Other) = delete;
	CharButton(CharButton&& _Other) noexcept = delete;
	CharButton& operator=(const CharButton& _Other) = delete;
	CharButton& operator=(CharButton&& _Other) noexcept = delete;

	char Chracter = 0;

protected:


private:

};

