#pragma once
#include <GameEngineCore/Button.h>

#include "ContentsEnums.h"
class Button_BloodType : public Button
{
public:
	// construtor destructor
	Button_BloodType();
	~Button_BloodType();

	// delete Function
	Button_BloodType(const Button_BloodType& _Other) = delete;
	Button_BloodType(Button_BloodType&& _Other) noexcept = delete;
	Button_BloodType& operator=(const Button_BloodType& _Other) = delete;
	Button_BloodType& operator=(Button_BloodType&& _Other) noexcept = delete;

	BloodType BloodTypeValue = BloodType::Null;

protected:


private:


};

