#pragma once
#include "StatusWindow.h"

class FemininityStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	FemininityStatusWindow();
	~FemininityStatusWindow();

	// delete Function
	FemininityStatusWindow(const FemininityStatusWindow& _Other) = delete;
	FemininityStatusWindow(FemininityStatusWindow&& _Other) noexcept = delete;
	FemininityStatusWindow& operator=(const FemininityStatusWindow& _Other) = delete;
	FemininityStatusWindow& operator=(FemininityStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

