#include "InformationWindowManager.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "HelthInformationWindow.h"
#include "PersonalInformationWindow.h"
#include "PhysicalStatusWindow.h"
#include "MainMenu.h"

InformationWindowManager::InformationWindowManager()
{

}

InformationWindowManager::~InformationWindowManager()
{

}

void InformationWindowManager::On()
{
	GameEngineObject::On();
	AcHelthInformationWindow->On();
	AcPersonalInformationWindow->On();
	AcPhysicalStatusWindow->On();
}

void InformationWindowManager::Off()
{
	GameEngineObject::Off();
	AcHelthInformationWindow->Off();
	AcPersonalInformationWindow->Off();
	AcPhysicalStatusWindow->Off();
}

void InformationWindowManager::Start()
{
	AcHelthInformationWindow = GetLevel()->CreateActor<HelthInformationWindow>(PM2ActorOrder::Menu1);
	AcPersonalInformationWindow = GetLevel()->CreateActor<PersonalInformationWindow >(PM2ActorOrder::Menu1);
	AcPhysicalStatusWindow = GetLevel()->CreateActor<PhysicalStatusWindow>(PM2ActorOrder::Menu1);

	Off();
}

void InformationWindowManager::Update(float _DeltaTime)
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		MainMenu::GetAcMainMenu()->On();
	}
}
