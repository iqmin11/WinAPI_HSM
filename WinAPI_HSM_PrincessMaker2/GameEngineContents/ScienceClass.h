#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class ScienceClass : public ClassesAndJobs
{
public:
	// construtor destructor
	ScienceClass();
	~ScienceClass();

	// delete Function
	ScienceClass(const ScienceClass& _Other) = delete;
	ScienceClass(ScienceClass&& _Other) noexcept = delete;
	ScienceClass& operator=(const ScienceClass& _Other) = delete;
	ScienceClass& operator=(ScienceClass&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	
};

