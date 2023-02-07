#pragma once
#include "StatusWindow.h"

class FightStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	FightStatusWindow();
	~FightStatusWindow();

	// delete Function
	FightStatusWindow(const FightStatusWindow& _Other) = delete;
	FightStatusWindow(FightStatusWindow&& _Other) noexcept = delete;
	FightStatusWindow& operator=(const FightStatusWindow& _Other) = delete;
	FightStatusWindow& operator=(FightStatusWindow&& _Other) noexcept = delete;

protected:
	void Start();

private:

};

