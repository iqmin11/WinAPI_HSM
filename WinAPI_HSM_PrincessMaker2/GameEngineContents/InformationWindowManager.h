#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class HelthInformationWindow;
class PersonalInformationWindow;
class PhysicalStatusWindow;
class InformationWindowManager : public GameEngineActor
{
public:
	// construtor destructor
	InformationWindowManager();
	~InformationWindowManager();

	// delete Function
	InformationWindowManager(const InformationWindowManager& _Other) = delete;
	InformationWindowManager(InformationWindowManager&& _Other) noexcept = delete;
	InformationWindowManager& operator=(const InformationWindowManager& _Other) = delete;
	InformationWindowManager& operator=(InformationWindowManager&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	HelthInformationWindow* AcHelthInformationWindow = nullptr;
	PersonalInformationWindow* AcPersonalInformationWindow = nullptr;
	PhysicalStatusWindow* AcPhysicalStatusWindow = nullptr;
};

