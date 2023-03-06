#include "FirstScene.h"
#include <GameEngineCore/GameEngineRender.h>
#include "Olive.h"

FirstScene::FirstScene()
{

}

FirstScene::~FirstScene()
{

}

void FirstScene::Start()
{
	SetPos(ActorPos);
	BackgroundRedner = CreateRender("FirstSceneBackground.bmp", PM2RenderOrder::BackGround);
	BackgroundRedner->SetScaleToImage();

	TextRender = CreateRender(PM2RenderOrder::Menu0_Display);
	TextRender->SetText((" "), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	TextRender->SetPosition(TextRenderPos);
	Off();
}

void FirstScene::Update(float _DeltaTime)
{
	TextRender->SetText("8�� ���� ��ó�� �������١�\n\n" + Olive::OlivePlayer->GetOliveLastName() + std::string("�� �� ") + Olive::OlivePlayer->GetOliveFirstName() + std::string("�� ���̵� ����� 18��, ������ �� ���̾���."), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
}

