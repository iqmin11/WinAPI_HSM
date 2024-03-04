#include "Flower.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"
#include "RaisingSimLevel.h"

Flower::Flower()
{

}

Flower::~Flower()
{

}

void Flower::UpdateFlower()
{
	
}

void Flower::Start()
{
	SetPos({85,285}); 
	SpringFlower = CreateRender("flower_spring.bmp", PM2RenderOrder::BackGroundObj);
	SpringFlower->SetScaleToImage();
	SpringFlower->Off();
	SummerFlower = CreateRender("flower_summer.bmp", PM2RenderOrder::BackGroundObj);
	SummerFlower->SetScaleToImage();
	SummerFlower->Off();
	FallFlower = CreateRender("flower_fall.bmp", PM2RenderOrder::BackGroundObj);
	FallFlower->SetScaleToImage();
	FallFlower->Off();
	WinterFlower = CreateRender("flower_winter.bmp", PM2RenderOrder::BackGroundObj);
	WinterFlower->SetScaleToImage();
	WinterFlower->Off();
	DiseaseFlower = CreateRender("flower_disease.bmp", PM2RenderOrder::BackGroundObj);
	DiseaseFlower->SetScaleToImage();
	DiseaseFlower->Off();

	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());

}

void Flower::Update(float _DeltaTime)
{
	if (TodaySeason != ParentLevel->GetTodaySeason())
	{
		TodaySeason = ParentLevel->GetTodaySeason();
		switch (TodaySeason)
		{
		case Season::Spring:
			SpringFlower->On();
			SummerFlower->Off();
			FallFlower->Off();
			WinterFlower->Off();
			break;
		case Season::Summer:
			SpringFlower->Off();
			SummerFlower->On();
			FallFlower->Off();
			WinterFlower->Off();
			break;
		case Season::Fall:
			SpringFlower->Off();
			SummerFlower->Off();
			FallFlower->On();
			WinterFlower->Off();
			break;
		case Season::Winter:
			SpringFlower->Off();
			SummerFlower->Off();
			FallFlower->Off();
			WinterFlower->On();
			break;
		default:
			break;
		}
	}
}

void Flower::Render(float _Time)
{
}
