#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"
class FencingClass : public ClassesAndJobs
{
public:
	// construtor destructor
	FencingClass();
	~FencingClass();

	// delete Function
	FencingClass(const FencingClass& _Other) = delete;
	FencingClass(FencingClass&& _Other) noexcept = delete;
	FencingClass& operator=(const FencingClass& _Other) = delete;
	FencingClass& operator=(FencingClass&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

