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
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
	
	if (AcOpeningCredit->IsUpdate() == false)
	{
		AcCutScene->OnRenderScene();
		UpperDialog->On();
		BottomDialog->On();
	}
}
