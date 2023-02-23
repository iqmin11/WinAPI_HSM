#include "StatusWindowManager.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "BasicStatusWindow.h"
#include "EstimateStatusWindow.h"
#include "FighterAndMagicalStatusWindow.h"
#include "SocialAndHouseworkStatusWindow.h"
#include "GlobalButton.h"


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

	AcBasicStatusWindow = Level->CreateActor<BasicStatusWindow>(PM2ActorOrder::Menu1);
	AcEstimateStatusWindow = Level->CreateActor<EstimateStatusWindow>(PM2ActorOrder::Menu1);
	AcFighterAndMagicalStatusWindow = Level->CreateActor<FighterAndMagicalStatusWindow>(PM2ActorOrder::Menu1);
	AcSocialAndHouseworkStatusWindow = Level->CreateActor<SocialAndHouseworkStatusWindow>(PM2ActorOrder::Menu1);
	Off();
}
