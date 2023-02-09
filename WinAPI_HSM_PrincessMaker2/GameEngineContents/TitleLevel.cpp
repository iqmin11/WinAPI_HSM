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
	
	//if (false == GameEngineInput::IsKey("MouseLeftClick"))
	//{
	//	GameEngineInput::CreateKey("MouseLeftClick", VK_LBUTTON);
	//}
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
	//
	//if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[0])
	//{
	//	GameEngineCore::GetInst()->ChangeLevel("FirstSet");
	//}
	//
	//if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[1])
	//{
	//	GameEngineCore::GetInst()->ChangeLevel("Opening");
	//}
	//
	//if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[2])
	//{
	//	GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	//}
}
