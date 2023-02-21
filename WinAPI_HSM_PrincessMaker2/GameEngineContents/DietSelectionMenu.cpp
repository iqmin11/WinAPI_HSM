#include "DietSelectionMenu.h"
#include <GameEngineCore/Button.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "RaisingSimLevel.h"
#include "CubeDialog.h"
#include "Olive.h"

CubeDialog* DietSelectionMenu::AcCubeDialog = nullptr;

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

	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->AcCubeDialog;

	Off();
}

void DietSelectionMenu::Click0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n30G ���ϴ�. ���� ���� ��\n��Ȱ�� ���� �� �ֽ��ϴ١�");
	Olive::OlivePlayer->SetOliveDiet(Diet::��������_�ʴ´�);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n80G ���ϴ�. ü���� �ö�\n���ҡ�");
	Olive::OlivePlayer->SetOliveDiet(Diet::��·��_ưư�ϰ�);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n10G ���ϴ�. �ణ �ǰ��� ��\n���� ������ �𸨴ϴ١�");
	Olive::OlivePlayer->SetOliveDiet(Diet::������_���̷�);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n5G �ۿ� ���� �ʽ��ϴ�. �ư�����\n�����Ը� ���̰� �ʹٸ�, �� ��\nħ���� ������. ��, ü���� ��\n���� �Ҹ��ϹǷ� �����Ͻñ� ��\n���ϴ١�");
	Olive::OlivePlayer->SetOliveDiet(Diet::���̾�Ʈ_��Ų��);
}
