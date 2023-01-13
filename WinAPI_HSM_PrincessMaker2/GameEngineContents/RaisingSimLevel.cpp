#include "RaisingSimLevel.h"
#include "Olive.h"
#include "Background.h"
#include "Animation.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("background.BMP"));
	
	//{
	//	GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PartTimeJobAnimation.BMP"));
	//	Image->Cut(13, 2);
	//}

	CreateActor<Background>();
	CreateActor<Olive>(1);
	//CreateActor<Animation>(2);

}

void RaisingSimLevel::Update()
{
}
