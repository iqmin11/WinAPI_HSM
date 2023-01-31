#include "RaisingSimLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Olive.h"
#include "Background.h"
#include "Animation.h"
#include "Flower.h"
#include "Paint.h"
#include "ContentsEnums.h"

RaisingSimLevel::RaisingSimLevel()
{

}

RaisingSimLevel::~RaisingSimLevel()
{

}

void RaisingSimLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("RaisingLevel");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("body_10_nomal.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("head_10_nomal.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("paint_default.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_spring.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_summer.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_fall.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_winter.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_disease.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("background.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobbackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobanimation.BMP"))->Cut(13,2);
	

	AcBackground = CreateActor<Background>(static_cast<int>(PM2ActorOrder::BackGround));
	CreateActor<Olive>(static_cast<int>(PM2ActorOrder::Player));
	CreateActor<Flower>(static_cast<int>(PM2ActorOrder::BackGround));
	CreateActor<Paint>(static_cast<int>(PM2ActorOrder::BackGround));

	//CreateActor<Animation>(2);

}
//800,0 ~ 800,320
void RaisingSimLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RPG");
		// Player::MainPlayer->Death()p;
	}


}
