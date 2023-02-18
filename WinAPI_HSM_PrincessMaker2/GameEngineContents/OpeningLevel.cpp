#include "OpeningLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "MousePoint.h"
#include "Caption.h"
#include "UpperDialog.h"
#include "Cutscene.h"
#include "OpeningCredit.h"
#include "ContentsEnums.h"

OpeningLevel::OpeningLevel()
{

}

OpeningLevel::~OpeningLevel()
{

}

void OpeningLevel::Loading()
{
	SoundLoad();
	ImageLoad();
	
	AcCaption = CreateActor<Caption>();
	AcUpperDialog = CreateActor<UpperDialog>();
	//UpperDialog->SetDialog(MugShotLR::Left, GameEngineWindow::GetScreenSize().half(), "Mug_Devil.BMP");
	
	//BottomDialog = CreateActor<Dialog>();
	//BottomDialog->SetDialog(MugShotLR::Right, GameEngineWindow::GetScreenSize().half() + float4{0, 176}, "Mug_Devil.BMP");
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	AcCutScene = CreateActor<Cutscene>();
	AcOpeningCredit = CreateActor<OpeningCredit>();

	if (!GameEngineInput::IsKey("2"))
	{
		GameEngineInput::CreateKey("2", '2');
	}
}

void OpeningLevel::Update(float _DeltaTime)
{

	if (true == GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}
	
	float LocalDeltaTime = _DeltaTime;
	
	if (GameEngineInput::IsPress("2"))
	{
		LocalDeltaTime *= 16;
		Time += LocalDeltaTime;
	}
	else
	{
		Time += LocalDeltaTime;
	}

	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
	
	// 오프닝 타임라인
	// 0~20 오프닝 크레딧, ~35 컷신1,  ~75 컷신2, ~115 컷신3, ~119 검은화면, ~122 왕국력 날짜,
	// ~143 컷신4, ~148 검은화면, ~ 172 컷신5, ~200 컷신6, ~205 검은화면, ~215 컷신7 
	if (0 <= Time && 20 > Time)//(0 <= Time && 20 > Time)
	{
		AcCutScene->On();
		AcCutScene->SelectBackgroundColor(BackgroundColor::Black);
		AcCutScene->OffCutScene();

		AcOpeningCredit->On();
		AcOpeningCredit->UpdateScroll(LocalDeltaTime);
	}
	else if (20 <= Time && 35 > Time)//(20 <= Time && 35 > Time)
	{
		AcOpeningCredit->Off();
		AcCutScene->SelectBackgroundColor(BackgroundColor::White);
		AcCutScene->OnCutScene(0);
		if (22 <= Time && 26 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("그것은 일방적인 싸움이었다…");
		}
		else if (26 <= Time && 27 > Time)
		{
			AcCaption->Off();
		}
		else if (27 <= Time && 31 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("평화에 길들여진 수도의 군대는\n막강한 마왕군 앞에 추풍낙엽처럼 쓰러져갔다.");
		}
		else if (31 <= Time && 32 > Time)
		{
			AcCaption->Off();
		}
		else if (32 <= Time && 35 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("성벽은 무너지고 거리는 불길에 휩싸였다.\n수도의 함락은 목전까지 닥친 상황이었다.");
		}
	}
	else if (35 <= Time && 75 > Time)//(35 <= Time && 75 > Time)
	{
		AcCaption->Off();
		AcCutScene->OnCutScene(1);

		if (37 <= Time && 41 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText(std::string("그때 그 참상을 목격한 방랑검사가 있었다. 그의 이름은 ") + std::string("용사이름.") + std::string("그는 스스로 마왕과의 싸움에 몸을 던졌다"));
		}
		else if (41 <= Time && 42 > Time)
		{
			AcCaption->Off();
		}
		else if (42 <= Time && 46 > Time)
		{
			AcCaption->On();
			AcCaption->SetUpdateText("초승달이 뜬 밤, 마왕의 진영에 잠입한" + std::string("용사이름") + std::string(".") + std::string("그는 1대1의 결투 끝에 마왕에게 승리했다."));
		}
		else if (46 <= Time && 47 > Time)
		{
			AcCaption->Off();
		}
		else if (47 <= Time && 51 > Time)
		{
			AcUpperDialog->On();
			AcUpperDialog->SetMugPic("Mug_Devil.bmp");
			AcUpperDialog->SetMugLoc(MugShotLR::Left);
		}

		//AcCutScene->ChangeRenderScene(2);
		//AcUpperDialog->SetMugPic("Mug_Uranos_God.bmp");
		//AcUpperDialog->SetMugLoc(MugShotLR::Right);
	}
	else if (75 <= Time && 115 > Time)//(75 <= Time && 115 > Time)
	{
		AcCutScene->OnCutScene(2);
		//AcCutScene->ChangeRenderScene(3);
		//AcUpperDialog->SetMugLoc(MugShotLR::Non);
	}
	else if (115 <= Time && 119 > Time)//(115 <= Time && 119> Time)
	{
		AcCutScene->SelectBackgroundColor(BackgroundColor::Black);
		AcCutScene->OffCutScene();
		//AcCutScene->OnBlackBackground();
		//AcCutScene->ChangeRenderScene(0);
		//AcUpperDialog->Off();
	}
	else if (119 <= Time && 122 > Time)//(119 <= Time && 122 > Time)
	{
		AcCutScene->OffCutScene();
		//AcCutScene->ChangeRenderScene(0);
	}
	else if (122 <= Time && 143 > Time)//(122 <= Time && 143 > Time)
	{
		AcCutScene->OnCutScene(3);
		//AcCutScene->ChangeRenderScene(4);
	}
	else if (143 <= Time && 148 > Time)//(143 <= Time && 148 > Time)
	{
		AcCutScene->OffCutScene();
		//AcCutScene->ChangeRenderScene(0);
	}
	else if (148 <= Time && 172 > Time)//(148 <= Time && 172 > Time)
	{
		AcCutScene->OnCutScene(4);
		//AcCutScene->ChangeRenderScene(5);
	}
	else if (172 <= Time && 200 > Time)//(172 <= Time && 200 > Time)
	{
		AcCutScene->OnCutScene(5);
		//AcCutScene->ChangeRenderScene(6);
	}
	else if (200 <= Time && 205 > Time)//(200 <= Time && 205 > Time)
	{
		AcCutScene->OffCutScene();
		//AcCutScene->ChangeRenderScene(0);
	}
	else if (205 <= Time && 215 > Time)//(205 <= Time && 215> Time)
	{
		AcCutScene->OnCutScene(6);
		//AcCutScene->ChangeRenderScene(7);
	}
	else
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}

void OpeningLevel::SoundLoad()
{
}

void OpeningLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");


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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mug_Uranos_God.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BlackBox.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("WhiteBackground.BMP"));
}
