#include "TitleMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>

TitleMenu::TitleMenu()
{

}

TitleMenu::~TitleMenu()
{

}

void TitleMenu::LevelChangeToFirstSet(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("FirstSet");
}

void TitleMenu::LevelChangeToOpening(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("Opening");
}

void TitleMenu::LevelChangeToRaisingSim(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
}

void TitleMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(3, { 400,250 }, 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	//GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	//GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "���� ������");		     //Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "(��Ȱ��ȭ)������ ������");			//Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "(��Ȱ��ȭ)Ű��� ������");	     //Test
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "ó������ ����");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "ó������ (������ ��ŵ)");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "�ð��� �ǵ�����");
}


