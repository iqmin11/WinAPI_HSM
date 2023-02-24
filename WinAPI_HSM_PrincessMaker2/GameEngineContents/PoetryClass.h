#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class PoetryClass : public ClassesAndJobs
{
public:
	// construtor destructor
	PoetryClass();
	~PoetryClass();

	// delete Function
	PoetryClass(const PoetryClass& _Other) = delete;
	PoetryClass(PoetryClass&& _Other) noexcept = delete;
	PoetryClass& operator=(const PoetryClass& _Other) = delete;
	PoetryClass& operator=(PoetryClass&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

