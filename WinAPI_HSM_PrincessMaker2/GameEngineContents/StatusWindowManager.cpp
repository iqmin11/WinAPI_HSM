#include "StatusWindowManager.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "BasicStatusWindow.h"
#include "EstimateStatusWindow.h"
#include "FighterAndMagicalStatusWindow.h"
#include "SocialAndHouseworkStatusWindow.h"
#include "GlobalButton.h"
#include "MainMenu.h"

StatusWindowManager::StatusWindowManager()
{

}

StatusWindowManager::~StatusWindowManager()
{

}

void StatusWindowManager::On()
{
	GameEngineObject::On();
	AcBasicStatusWindow->On();
	AcEstimateStatusWindow->On();
	AcFighterAndMagicalStatusWindow->On();
	AcSocialAndHouseworkStatusWindow->On();
}

void StatusWindowManager::Off()
{
	GameEngineObject::Off();
	AcBasicStatusWindow->Off();
	AcEstimateStatusWindow->Off();
	AcFighterAndMagicalStatusWindow->Off();
	AcSocialAndHouseworkStatusWindow->Off();
}

void StatusWindowManager::Start()
{
	GameEngineLevel* Level = GetLevel();
	AcMainMenu = MainMenu::GetAcMainMenu();

	AcBasicStatusWindow = Level->CreateActor<BasicStatusWindow>(PM2ActorOrder::Menu1);
	AcEstimateStatusWindow = Level->CreateActor<EstimateStatusWindow>(PM2ActorOrder::Menu1);
	AcFighterAndMagicalStatusWindow = Level->CreateActor<FighterAndMagicalStatusWindow>(PM2ActorOrder::Menu1);
	AcSocialAndHouseworkStatusWindow = Level->CreateActor<SocialAndHouseworkStatusWindow>(PM2ActorOrder::Menu1);
	Off();
}

void StatusWindowManager::Update(float _DeltaTime)
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		AcMainMenu->On();
	}
}
