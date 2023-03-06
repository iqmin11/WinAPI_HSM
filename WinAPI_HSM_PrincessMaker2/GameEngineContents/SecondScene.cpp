#include "SecondScene.h"
#include <GameEngineCore/GameEngineRender.h>

SecondScene::SecondScene()
{

}

SecondScene::~SecondScene()
{

}

void SecondScene::Start()
{
	SetPos(ActorPos);
	BackgroundRedner = CreateRender("SecondSceneBackground.bmp", PM2RenderOrder::BackGround);
	BackgroundRedner->SetScaleToImage();

	TextRender = CreateRender(PM2RenderOrder::Menu0_Display);
	TextRender->SetText(" ", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
	TextRender->SetPosition(TextRenderPos);

	TextRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	TextRenderShadow->SetText(" ", TextHeight, TextType, TextAlign::Left, TextShadowColor, TextBoxScale);
	TextRenderShadow->SetPosition(TextShadowRenderPos);
	Off();
}

void SecondScene::Update(float _DeltaTime)
{
	TextRender->SetText(Script, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
	TextRenderShadow->SetText(Script, TextHeight, TextType, TextAlign::Left, TextShadowColor, TextBoxScale);
}
