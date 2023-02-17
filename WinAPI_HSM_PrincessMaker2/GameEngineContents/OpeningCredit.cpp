#include "OpeningCredit.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

OpeningCredit::OpeningCredit()
{

}

OpeningCredit::~OpeningCredit()
{

}

void OpeningCredit::UpdateScroll(float _DeltaTime)
{
	Time += _DeltaTime / ScrollTime;
	CreditRender->SetPosition(float4::LerpClamp(StartPos, EndPos, Time));
}

void OpeningCredit::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	CreditRender = CreateRender("Credit.BMP", PM2RenderOrder::BackGroundObj);
	CreditRender->SetScaleToImage();
	StartPos = { 0, 700 };
	EndPos = { 0, -700 };
	GameEngineRender* TopBox = CreateRender("BlackBox.BMP", PM2RenderOrder::CaptionBox);
	TopBox->SetScale({800, 100});
	TopBox->SetPosition({0, -250});
	GameEngineRender* BotBox = CreateRender("BlackBox.BMP", PM2RenderOrder::CaptionBox);
	BotBox->SetScale({ 800, 100 });
	BotBox->SetPosition({ 0, 250 });
	Off();
}

void OpeningCredit::Update(float _DeltaTime)
{
	
}

void OpeningCredit::Render(float _Time)
{
}
