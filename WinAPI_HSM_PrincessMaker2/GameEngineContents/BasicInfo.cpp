#include "BasicInfo.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

BasicInfo::BasicInfo()
{

}

BasicInfo::~BasicInfo()
{

}

void BasicInfo::Start()
{
	SetPos({700, 109});
	SetAge(10);
	SetStar(Zodiac::Leo);
	SetGold(100);
	SetHeight(130.0f);
	SetWeight(27.0f);
	SetBust(20.0f);
	SetWaist(20.0f);
	SetHip(20.0f);
	
	BasicInfoFrame = CreateRender("BasicInfo.bmp",PM2RenderOrder::Menu0);
	/*for (size_t i = 0; i < 2; i++)
	{
		AgeRender[i] = CreateRender("", PM2RenderOrder::Menu0_Display);
		AgeRender[i]->SetScale({20 , 20});
		AgeRender[i]->SetFrame(GameEngineMath::GetDigits());
	}*/
	//StarRender = CreateRender("", PM2RenderOrder::Menu0_Display);
	

}

void BasicInfo::Update(float _DeltaTime)
{
}

void BasicInfo::Render(float _Time)
{
}
