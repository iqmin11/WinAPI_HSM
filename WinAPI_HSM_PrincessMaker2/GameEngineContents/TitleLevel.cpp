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
	
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectButton_Release.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectButton_Hover.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample1.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample2.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FrameSample3.BMP"))->Cut(3, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cursor.bmp"));

	Dir.Move("TitleLevel");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BlackBackground.BMP"));

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
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
}
