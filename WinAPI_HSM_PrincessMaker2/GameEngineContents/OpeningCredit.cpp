#include "OpeningCredit.h"
#include "ContentsEnums.h"

OpeningCredit::OpeningCredit()
{

}

OpeningCredit::~OpeningCredit()
{

}

void OpeningCredit::Start()
{
	CreditRender = CreateRender("Credit.BMP", PM2RenderOrder::BackGround);
	StartPos = { 400, 900 };
	EndPos = { 400, -300 };
}

void OpeningCredit::Update(float _DeltaTime)
{
	Time += _DeltaTime / ScrollTime; 
	SetPos(float4::LerpClamp(StartPos, EndPos, Time));
	if (EndPos.y >= GetPos().y)
	{
		Off();
	}
}

void OpeningCredit::Render(float _Time)
{
}
