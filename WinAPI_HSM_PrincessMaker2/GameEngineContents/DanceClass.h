#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class DanceClass : public ClassesAndJobs
{
public:
	// construtor destructor
	DanceClass();
	~DanceClass();

	// delete Function
	DanceClass(const DanceClass& _Other) = delete;
	DanceClass(DanceClass&& _Other) noexcept = delete;
	DanceClass& operator=(const DanceClass& _Other) = delete;
	DanceClass& operator=(DanceClass&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

