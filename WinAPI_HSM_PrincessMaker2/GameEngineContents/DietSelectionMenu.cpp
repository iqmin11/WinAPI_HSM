#include "DietSelectionMenu.h"
#include <GameEngineCore/Button.h>
#include "Olive.h"

DietSelectionMenu::DietSelectionMenu()
{

}

DietSelectionMenu::~DietSelectionMenu()
{

}

void DietSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(4, ActorPos, Xscale, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "�������� �ʴ´�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "��·�� ưư�ϰ�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "������ ���̷�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "���̾�Ʈ ��Ų��");
	
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
	GetSelectButtons()[2]->SetClickCallBack(Click2);
	GetSelectButtons()[3]->SetClickCallBack(Click3);

	Off();
}

void DietSelectionMenu::Click0(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::��������_�ʴ´�);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::��·��_ưư�ϰ�);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::������_���̷�);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::���̾�Ʈ_��Ų��);
}
