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

	AcCubeDialog->SetUpdateText("�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��");
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
			if (AcCubeDialog->GetUpdateText() == "�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��")
			{
				AcCubeDialog->SetUpdateText("���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���");
			}
			else if (AcCubeDialog->GetUpdateText() == "���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
			else if (AcCubeDialog->GetUpdateText() == "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
		}
	}
}


