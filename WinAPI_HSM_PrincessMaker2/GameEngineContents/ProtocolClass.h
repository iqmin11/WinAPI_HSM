#pragma once
#include "ClassesAndJobs.h"
#include "ContentsEnums.h"

class ProtocolClass : public ClassesAndJobs
{
public:
	// construtor destructor
	ProtocolClass();
	~ProtocolClass();

	// delete Function
	ProtocolClass(const ProtocolClass& _Other) = delete;
	ProtocolClass(ProtocolClass&& _Other) noexcept = delete;
	ProtocolClass& operator=(const ProtocolClass& _Other) = delete;
	ProtocolClass& operator=(ProtocolClass&& _Other) noexcept = delete;

protected:
	void Start() override;


private:

};

