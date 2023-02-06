#pragma once
#include "Dialog.h"

class UpperDialog : public Dialog
{
public:
	// construtor destructor
	UpperDialog();
	~UpperDialog();

	// delete Function
	UpperDialog(const UpperDialog& _Other) = delete;
	UpperDialog(UpperDialog&& _Other) noexcept = delete;
	UpperDialog& operator=(const UpperDialog& _Other) = delete;
	UpperDialog& operator=(UpperDialog&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

