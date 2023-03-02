#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class MainMenu;

class GlobalButton;
class BasicStatusWindow;
class EstimateStatusWindow;
class FighterAndMagicalStatusWindow;
class SocialAndHouseworkStatusWindow;
class StatusWindowManager : public GameEngineActor
{
public:
	// construtor destructor
	StatusWindowManager();
	~StatusWindowManager();

	// delete Function
	StatusWindowManager(const StatusWindowManager& _Other) = delete;
	StatusWindowManager(StatusWindowManager&& _Other) noexcept = delete;
	StatusWindowManager& operator=(const StatusWindowManager& _Other) = delete;
	StatusWindowManager& operator=(StatusWindowManager&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	MainMenu* AcMainMenu = nullptr;

	BasicStatusWindow* AcBasicStatusWindow = nullptr;
	EstimateStatusWindow* AcEstimateStatusWindow = nullptr;
	FighterAndMagicalStatusWindow* AcFighterAndMagicalStatusWindow = nullptr;
	SocialAndHouseworkStatusWindow* AcSocialAndHouseworkStatusWindow = nullptr;
};

