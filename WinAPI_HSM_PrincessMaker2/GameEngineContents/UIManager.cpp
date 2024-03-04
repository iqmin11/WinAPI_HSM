#include "UIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "RaisingSimLevel.h"
#include "Olive.h"

#include "MainMenu.h"
#include "CubeDialog.h"

RaisingSimLevel* UIManager::ParentLevel = nullptr;
MainMenu* UIManager::AcMainMenu = nullptr;
CubeDialog* UIManager::AcCubeDialog = nullptr;

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Start()
{
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	AcMainMenu = ParentLevel->CreateActor<MainMenu>(PM2ActorOrder::Menu0);
	AcCubeDialog = ParentLevel->GetAcCubeDialog();

	AcCubeDialog->SetUpdateText("「주인님, 안녕하십니까. 집사 \n큐브 입니다.」");
}

void UIManager::Update(float _DeltaTime)
{
	SetEngineRightClick();
}

void UIManager::SetEngineRightClick()
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		if (AcCubeDialog->IsUpdate())
		{
			if (AcCubeDialog->GetUpdateText() == "「주인님, 안녕하십니까. 집사 \n큐브 입니다.」")
			{
				AcCubeDialog->SetUpdateText("「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」");
			}
			else if (AcCubeDialog->GetUpdateText() == "「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
			else if (AcCubeDialog->GetUpdateText() == "예, 알겠습니다. 다음달부터 그\n렇게 하겠습니다")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
		}
	}
}


