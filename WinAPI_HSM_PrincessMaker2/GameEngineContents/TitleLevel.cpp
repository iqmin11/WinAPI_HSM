#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include "TitleMenu.h"
#include "TitleBackground.h"
#include "MousePoint.h"

TitleLevel::TitleLevel()
{

}

TitleLevel::~TitleLevel()
{

}

void TitleLevel::Loading()
{
	SoundLoad();
	ImageLoad();

	

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
	}

	if (false == GameEngineInput::IsKey("1"))
	{
		GameEngineInput::CreateKey("1", '1');
	}
	
	CreateActor<TitleBackground>(PM2ActorOrder::BackGround);
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	TitleSelectionMenu = CreateActor<TitleMenu>(PM2ActorOrder::Menu0);

}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("FirstSet");
	}

	if (true == GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}
}

void TitleLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");

}

void TitleLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectButton_Release.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectButton_Hover.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample1.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample2.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample3.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cursor.bmp"));

	Dir.Move("TitleLevel");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BlackBackground.BMP"));
}
