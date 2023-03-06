#include "FourthScene.h"
#include <GameEngineCore/GameEngineRender.h>
#include "Olive.h"

FourthScene::FourthScene()
{

}

FourthScene::~FourthScene()
{

}

void FourthScene::Start()
{
	SetPos(ActorPos);
	BackgroundRedner = CreateRender("FirstSceneBackground.bmp", PM2RenderOrder::BackGround);
	BackgroundRedner->SetScaleToImage();


	TextRender = CreateRender(PM2RenderOrder::Menu0_Display);
	TextRender->SetText((" "), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
	TextRender->SetPosition(TextRenderPos);
	Off();
}

void FourthScene::Update(float _DeltaTime)
{
	TextRender->SetText("18���� �װ��� �θ𿡰Լ� ����, ��ȸ�� ���� ������ �ñ⡦��\n\n" + Olive::OlivePlayer->GetOliveFirstName() + std::string("�� ��ü � ���� ������ ���ΰ�����"), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
}
