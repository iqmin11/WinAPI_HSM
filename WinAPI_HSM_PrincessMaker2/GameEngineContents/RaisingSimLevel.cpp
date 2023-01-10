#include "RaisingSimLevel.h"
#include "Olive.h"
#include <GameEngineBase/GameEngineDirectory.h>

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
	Dir.GetPlusFileName("Background.BMP");

	CreateActor<Olive>();
}

void RaisingSimLevel::Update()
{
}
