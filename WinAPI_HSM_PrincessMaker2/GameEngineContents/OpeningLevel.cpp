#include "OpeningLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "Dialog.h"
#include "Cutscene.h"
#include "OpeningCredit.h"

OpeningLevel::OpeningLevel()
{

}

OpeningLevel::~OpeningLevel()
{

}

void OpeningLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");


	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MugShotFrame_God.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MugShotFrame_Nomal.BMP"));


	Dir.Move("OpeningLevel");
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DayNum.BMP"));
		Image->Cut(20, 1);
	}
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonthNum.BMP"));
		Image->Cut(10, 1);
	}
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Credit.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene1.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene2.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene3.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene4.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene5.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene6.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Cutscene7.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OpeningDate.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleLogo.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mug_Devil.BMP"));
	UpperDialog = CreateActor<Dialog>();
	UpperDialog->SetDialog(MugShotStyle::Nomal, MugShotLR::Left, GameEngineWindow::GetScreenSize().half());
	UpperDialog->Off();
	BottomDialog = CreateActor<Dialog>();
	BottomDialog->SetDialog(MugShotStyle::Nomal, MugShotLR::Right, GameEngineWindow::GetScreenSize().half());
	BottomDialog->SetMove({ 0, 176 });
	BottomDialog->Off();
	AcCutScene = CreateActor<Cutscene>();
	AcOpeningCredit = CreateActor<OpeningCredit>();
	
}

void OpeningLevel::Update(float _DeltaTime)
{
	Time += _DeltaTime;

	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
	
	//if (AcOpeningCredit->IsUpdate() == false)
	//{
	//	AcCutScene->OnRenderScene();
	//	//UpperDialog->On();
	//	//BottomDialog->On();
	//}
	
	// ¿ÀÇÁ´× Å¸ÀÓ¶óÀÎ
	// 0~20 ¿ÀÇÁ´× Å©·¹µ÷, ~35 ÄÆ½Å1,  ~75 ÄÆ½Å2, ~115 ÄÆ½Å3, ~119 °ËÀºÈ­¸é, ~122 ¿Õ±¹·Â ³¯Â¥,
	// ~143 ÄÆ½Å4, ~148 °ËÀºÈ­¸é, ~ 172 ÄÆ½Å5, ~200 ÄÆ½Å6, ~205 °ËÀºÈ­¸é, ~215 ÄÆ½Å7
	if (0 <= Time && 5 > Time)//(0 <= Time && 20 > Time)
	{
		AcCutScene->OnBlackBackground();
		AcCutScene->ChangeRenderScene(0);
	}
	else if (5 <= Time && 10 > Time)//(20 <= Time && 35 > Time)
	{
		AcCutScene->OffBlackBackground();
		AcCutScene->ChangeRenderScene(1);
	}
	else if (10 <= Time && 15 > Time)//(35 <= Time && 75 > Time)
	{
		AcCutScene->ChangeRenderScene(2);
	}
	else if (15 <= Time && 20 > Time)//(75 <= Time && 115 > Time)
	{
		AcCutScene->ChangeRenderScene(3);
	}
	else if (20 <= Time && 25> Time)//(115 <= Time && 119> Time)
	{
		AcCutScene->OnBlackBackground();
		AcCutScene->ChangeRenderScene(0);
	}
	else if (25 <= Time && 30> Time)//(119 <= Time && 122 > Time)
	{
		AcCutScene->ChangeRenderScene(0);
	}
	else if (30 <= Time && 35> Time)//(122 <= Time && 143 > Time)
	{
		AcCutScene->ChangeRenderScene(4);
	}
	else if (35 <= Time && 40> Time)//(143 <= Time && 148 > Time)
	{
		AcCutScene->ChangeRenderScene(0);
	}
	else if (40 <= Time && 45> Time)//(148 <= Time && 172 > Time)
	{
		AcCutScene->ChangeRenderScene(5);
	}
	else if (45 <= Time && 50> Time)//(172 <= Time && 200 > Time)
	{
		AcCutScene->ChangeRenderScene(6);
	}
	else if (50 <= Time && 55> Time)//(200 <= Time && 205 > Time)
	{
		AcCutScene->ChangeRenderScene(0);
	}
	else if (55 <= Time && 60> Time)//(205 <= Time && 215> Time)
	{
		AcCutScene->ChangeRenderScene(7);
	}
	else
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}
