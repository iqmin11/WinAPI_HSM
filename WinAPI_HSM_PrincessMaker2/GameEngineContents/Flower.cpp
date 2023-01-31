#include "Flower.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

Flower::Flower()
{

}

Flower::~Flower()
{

}

void Flower::Start()
{
	SetPos({85,285}); // 위치 고정
	SpringFlower = CreateRender("flower_spring.bmp", PM2RenderOrder::BackGroundObj);
	SpringFlower->Off();
	SummerFlower = CreateRender("flower_summer.bmp", PM2RenderOrder::BackGroundObj);
	SummerFlower->Off();
	FallFlower = CreateRender("flower_fall.bmp", PM2RenderOrder::BackGroundObj);
	FallFlower->Off();
	WinterFlower = CreateRender("flower_winter.bmp", PM2RenderOrder::BackGroundObj);
	WinterFlower->Off();
	DiseaseFlower = CreateRender("flower_disease.bmp", PM2RenderOrder::BackGroundObj);
	DiseaseFlower->Off();
	FlowerRender = SpringFlower;

}

void Flower::Update(float _DeltaTime)
{
	FlowerRender->On();
}

void Flower::Render(float _Time)
{
}
