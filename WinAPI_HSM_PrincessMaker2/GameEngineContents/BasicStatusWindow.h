#pragma once
#include "StatusWindow.h"

class BasicStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	BasicStatusWindow();
	~BasicStatusWindow();

	// delete Function
	BasicStatusWindow(const BasicStatusWindow& _Other) = delete;
	BasicStatusWindow(BasicStatusWindow&& _Other) noexcept = delete;
	BasicStatusWindow& operator=(const BasicStatusWindow& _Other) = delete;
	BasicStatusWindow& operator=(BasicStatusWindow&& _Other) noexcept = delete;

protected:
	void Start();

private:
	GaugeFrameStyle St = GaugeFrameStyle::Null;
};

