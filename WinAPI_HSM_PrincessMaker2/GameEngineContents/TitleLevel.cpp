#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

#include "SelectionMenu.h"
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

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SelectionHilight.bmp"));

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
	
	if (false == GameEngineInput::IsKey("MouseLeftClick"))
	{
		GameEngineInput::CreateKey("MouseLeftClick", VK_LBUTTON);
	}
	CreateActor<TitleBackground>(0);
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	TitleSelectionMenu = CreateActor<SelectionMenu>(1);
	TitleSelectionMenu->SetSelectionMenu(GameEngineWindow::GetScreenSize().half(), { 230,112 }, 0, 3);
	TitleSelectionMenu->CreateSelectionMenu(10);
}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("FirstSet");
	}

	if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[0])
	{
		GameEngineCore::GetInst()->ChangeLevel("FirstSet");
	}

	if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[1])
	{
		GameEngineCore::GetInst()->ChangeLevel("Opening");
	}

	if (true == GameEngineInput::IsDown("MouseLeftClick") && TitleSelectionMenu->GetIsMouseCollisions()[2])
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}
