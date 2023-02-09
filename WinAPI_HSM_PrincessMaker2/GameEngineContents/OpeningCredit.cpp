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

void OpeningCredit::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	CreditRender = CreateRender("Credit.BMP", PM2RenderOrder::BackGround);
	CreditRender->SetScaleToImage();
	StartPos = { 0, 900 };
	EndPos = { 0, -300 };
	GameEngineRender* TopBox = CreateRender("BlackBox.BMP", PM2RenderOrder::BackGroundObj);
	TopBox->SetPosition({0, -200});
	GameEngineRender* BotBox = CreateRender("BlackBox.BMP", PM2RenderOrder::BackGroundObj);
	BotBox->SetPosition({ 0, 200 });

}

void OpeningCredit::Update(float _DeltaTime)
{
	Time += _DeltaTime / ScrollTime; 
	CreditRender->SetPosition(float4::LerpClamp(StartPos, EndPos, Time));
	if (EndPos.y >= CreditRender->GetPosition().y)
	{
		Off();
	}
}

void OpeningCredit::Render(float _Time)
{
}
