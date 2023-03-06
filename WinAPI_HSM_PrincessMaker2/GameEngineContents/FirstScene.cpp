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
	TextRender->SetText("8년 간이 꿈처럼 지나갔다…\n\n" + Olive::OlivePlayer->GetOliveLastName() + std::string("의 딸 ") + Olive::OlivePlayer->GetOliveFirstName() + std::string("의 나이도 어느덧 18세, 성인이 된 것이었다."), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
}

