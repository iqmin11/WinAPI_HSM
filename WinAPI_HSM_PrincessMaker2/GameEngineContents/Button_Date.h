#pragma once
#include <GameEngineCore/Button.h>
#include "Date.h"

class Button_Date : public Button
{
public:
	// construtor destructor
	Button_Date();
	~Button_Date();

	// delete Function
	Button_Date(const Button_Date& _Other) = delete;
	Button_Date(Button_Date&& _Other) noexcept = delete;
	Button_Date& operator=(const Button_Date& _Other) = delete;
	Button_Date& operator=(Button_Date&& _Other) noexcept = delete;

	Date Value = Date();

protected:


private:

};

