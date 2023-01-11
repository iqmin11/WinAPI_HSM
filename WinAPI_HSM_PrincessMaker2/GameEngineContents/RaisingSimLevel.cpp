#include "RaisingSimLevel.h"
#include "Olive.h"
#include "Background.h"
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

	CreateActor<Background>();
	CreateActor<Olive>();

}

void RaisingSimLevel::Update()
{
}
