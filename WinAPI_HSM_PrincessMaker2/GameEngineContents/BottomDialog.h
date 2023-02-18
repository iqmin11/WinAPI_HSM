#pragma once
#include "Dialog.h"
class BottomDialog : public Dialog
{
public:
	// construtor destructor
	BottomDialog();
	~BottomDialog();

	// delete Function
	BottomDialog(const BottomDialog& _Other) = delete;
	BottomDialog(BottomDialog&& _Other) noexcept = delete;
	BottomDialog& operator=(const BottomDialog& _Other) = delete;
	BottomDialog& operator=(BottomDialog&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

