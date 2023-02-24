#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class TheologyClass : public ClassesAndJobs
{
public:
	// construtor destructor
	TheologyClass();
	~TheologyClass();

	// delete Function
	TheologyClass(const TheologyClass& _Other) = delete;
	TheologyClass(TheologyClass&& _Other) noexcept = delete;
	TheologyClass& operator=(const TheologyClass& _Other) = delete;
	TheologyClass& operator=(TheologyClass&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

