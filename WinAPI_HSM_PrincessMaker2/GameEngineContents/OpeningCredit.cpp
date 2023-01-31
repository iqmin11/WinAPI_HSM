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
	SetPos({400, 900});
}

void OpeningCredit::Update(float _DeltaTime)
{
	SetMove(float4::Up * (MoveSpeed * _DeltaTime));
	if (GetPos().y <= -300.0f)
	{
		Off(); // 다음 컷신으로 넘어가기
	}
}

void OpeningCredit::Render(float _Time)
{
}
