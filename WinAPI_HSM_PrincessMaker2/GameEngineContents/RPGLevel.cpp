#include "RPGLevel.h"
#include "RPGOlive.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>

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

	CreateActor<RPGOlive>();
}

void RPGLevel::Update(float _DeltaTime)
{
}
