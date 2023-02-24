#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class FightingClass : public ClassesAndJobs
{
public:
	// construtor destructor
	FightingClass();
	~FightingClass();

	// delete Function
	FightingClass(const FightingClass& _Other) = delete;
	FightingClass(FightingClass&& _Other) noexcept = delete;
	FightingClass& operator=(const FightingClass& _Other) = delete;
	FightingClass& operator=(FightingClass&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

