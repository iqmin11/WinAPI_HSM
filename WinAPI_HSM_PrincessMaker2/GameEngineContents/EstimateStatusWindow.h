#pragma once
#include "StatusWindow.h"

class EstimateStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	EstimateStatusWindow();
	~EstimateStatusWindow();

	// delete Function
	EstimateStatusWindow(const EstimateStatusWindow& _Other) = delete;
	EstimateStatusWindow(EstimateStatusWindow&& _Other) noexcept = delete;
	EstimateStatusWindow& operator=(const EstimateStatusWindow& _Other) = delete;
	EstimateStatusWindow& operator=(EstimateStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

