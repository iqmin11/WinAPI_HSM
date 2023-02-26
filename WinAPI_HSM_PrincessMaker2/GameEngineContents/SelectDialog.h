#pragma once
#include "Dialog.h"

class SelectDialog : public Dialog
{
public:
	// construtor destructor
	SelectDialog();
	~SelectDialog();

	// delete Function
	SelectDialog(const SelectDialog& _Other) = delete;
	SelectDialog(SelectDialog&& _Other) noexcept = delete;
	SelectDialog& operator=(const SelectDialog& _Other) = delete;
	SelectDialog& operator=(SelectDialog&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	float4 ActorScale = { 310, 76 };
	float4 ActorPos = { 170, 300 };
};
