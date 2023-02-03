#include "RPGLevel.h"
#include "RPGOlive.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>

#include "MousePoint.h"
#include "ContentsEnums.h"

RPGLevel::RPGLevel()
{

}

RPGLevel::~RPGLevel()
{

}

void RPGLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("RPGLevel");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Olive.BMP"))->Cut(8,1);

	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	CreateActor<RPGOlive>();
}

void RPGLevel::Update(float _DeltaTime)
{
}
