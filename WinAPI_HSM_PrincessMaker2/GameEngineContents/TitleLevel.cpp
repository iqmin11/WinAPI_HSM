#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "SelectionMenu.h"
#include "TitleBackground.h"

TitleLevel::TitleLevel()
{

}

TitleLevel::~TitleLevel()
{

}

void TitleLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample1.BMP"));
		Image->Cut(3, 3);
	}
	
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample2.BMP"));
		Image->Cut(3, 3);
	}
	
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample3.BMP"));
		Image->Cut(3, 3);
	}

	Dir.Move("TitleLevel");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleBackground.BMP"));


	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
	}
	CreateActor<TitleBackground>(0);
	CreateActor<SelectionMenu>(1);

}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))	
	{
		GameEngineCore::GetInst()->ChangeLevel("FirstSet");
	}
}
