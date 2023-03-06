#pragma once
#include "Dialog.h"
class EndingDialog : public Dialog
{
public:
	// construtor destructor
	EndingDialog();
	~EndingDialog();

	// delete Function
	EndingDialog(const EndingDialog& _Other) = delete;
	EndingDialog(EndingDialog&& _Other) noexcept = delete;
	EndingDialog& operator=(const EndingDialog& _Other) = delete;
	EndingDialog& operator=(EndingDialog&& _Other) noexcept = delete;

	void UpdateText(const std::string_view& _Script)
	{
		SetUpdateText(_Script);
		On();
	}

protected:
	void Start() override;

private:
	float4 ActorPos = { 400,400 };

};

