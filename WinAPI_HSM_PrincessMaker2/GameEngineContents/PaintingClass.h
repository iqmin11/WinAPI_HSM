#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class PaintingClass : public ClassesAndJobs
{
public:
	// construtor destructor
	PaintingClass();
	~PaintingClass();

	// delete Function
	PaintingClass(const PaintingClass& _Other) = delete;
	PaintingClass(PaintingClass&& _Other) noexcept = delete;
	PaintingClass& operator=(const PaintingClass& _Other) = delete;
	PaintingClass& operator=(PaintingClass&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

