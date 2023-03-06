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
	TextRender->SetText("18세… 그것은 부모에게서 떠나, 사회를 향해 떠나는 시기……\n\n" + Olive::OlivePlayer->GetOliveFirstName() + std::string("은 대체 어떤 길을 선택할 것인가……"), TextHeight, TextType, TextAlign::Center, TextColor, TextBoxScale);
}
