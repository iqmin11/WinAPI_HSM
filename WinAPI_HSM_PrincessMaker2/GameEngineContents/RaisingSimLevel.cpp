#include "RaisingSimLevel.h"
#include "Olive.h"
#include "Background.h"
#include "Animation.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobbackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobanimation.BMP"))->Cut(13,2);
	

	CreateActor<Background>();
	CreateActor<Olive>(1);
	CreateActor<Animation>(2);

	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}

}
//800,0 ~ 800,320
void RaisingSimLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Olive::OlivePlayer->OnOffSwtich();
		// Player::MainPlayer->Death()p;
	}

	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RPG");
		// Player::MainPlayer->Death()p;
	}
}
