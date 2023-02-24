#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class MagicClass : public ClassesAndJobs
{
public:
	// construtor destructor
	MagicClass();
	~MagicClass();

	// delete Function
	MagicClass(const MagicClass& _Other) = delete;
	MagicClass(MagicClass&& _Other) noexcept = delete;
	MagicClass& operator=(const MagicClass& _Other) = delete;
	MagicClass& operator=(MagicClass&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

