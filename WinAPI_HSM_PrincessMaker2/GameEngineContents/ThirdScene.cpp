#include "ThirdScene.h"
#include <GameEngineCore/GameEngineRender.h>

ThirdScene::ThirdScene()
{

}

ThirdScene::~ThirdScene()
{

}

void ThirdScene::Start()
{
	SetPos(ActorPos);
	BackgroundRedner = CreateRender("ThirdSceneBackground.bmp", PM2RenderOrder::BackGround);
	BackgroundRedner->SetScaleToImage();

	TextRender = CreateRender(PM2RenderOrder::Menu0_Display);
	TextRender->SetText(" ", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
	TextRender->SetPosition(TextRenderPos);

	TextRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	TextRenderShadow->SetText(" ", TextHeight, TextType, TextAlign::Left, TextShadowColor, TextBoxScale);
	TextRenderShadow->SetPosition(TextShadowRenderPos);
	Off();
}

void ThirdScene::Update(float _DeltaTime)
{
	TextRender->SetText(Script, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
	TextRenderShadow->SetText(Script, TextHeight, TextType, TextAlign::Left, TextShadowColor, TextBoxScale);
}
