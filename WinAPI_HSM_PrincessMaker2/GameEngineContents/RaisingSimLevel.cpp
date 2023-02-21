#include "RaisingSimLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/Button.h>

#include "MousePoint.h"
#include "Olive.h"
#include "Background.h"
#include "Animation.h"
#include "Flower.h"
#include "Paint.h"
#include "DateViewer.h"
#include "BasicInfo.h"
#include "MainMenu.h"
#include "Calendar.h"
#include "DietSelectionMenu.h"
#include "BasicStatusWindow.h"
#include "EstimateStatusWindow.h"
#include "FighterAndMagicalStatusWindow.h"
#include "SocialAndHouseworkStatusWindow.h"
#include "ConverstionSelectionMenu.h"
#include "CubeDialog.h"
#include "ContentsEnums.h"

MainMenu* RaisingSimLevel::AcMainMenu = nullptr;
BasicStatusWindow* RaisingSimLevel::AcBasicStatusWindow = nullptr;
EstimateStatusWindow* RaisingSimLevel::AcEstimateStatusWindow = nullptr;
FighterAndMagicalStatusWindow* RaisingSimLevel::AcFighterAndMagicalStatusWindow = nullptr;
SocialAndHouseworkStatusWindow* RaisingSimLevel::AcSocialAndHouseworkStatusWindow = nullptr;

ConverstionSelectionMenu* RaisingSimLevel::AcConverstionSelectionMenu = nullptr;
DietSelectionMenu* RaisingSimLevel::AcDietSelectionMenu = nullptr;

CubeDialog* RaisingSimLevel::AcCubeDialog = nullptr;

RaisingSimLevel::RaisingSimLevel()
{

}

RaisingSimLevel::~RaisingSimLevel()
{

}

void RaisingSimLevel::Loading()
{
	SoundLoad();
	ImageLoad();

	AcBackground = CreateActor<Background>(static_cast<int>(PM2ActorOrder::BackGround));
	CreateActor<DateViewer>(PM2ActorOrder::Menu0);
	CreateActor<BasicInfo>(PM2ActorOrder::Menu0);
	AcMainMenu = CreateActor<MainMenu>(PM2ActorOrder::Menu0);
	AcCubeDialog = CreateActor<CubeDialog>(PM2ActorOrder::Dialog);
	AcBasicStatusWindow = CreateActor<BasicStatusWindow>(PM2ActorOrder::Menu1);
	AcEstimateStatusWindow = CreateActor<EstimateStatusWindow>(PM2ActorOrder::Menu1);
	AcFighterAndMagicalStatusWindow = CreateActor<FighterAndMagicalStatusWindow>(PM2ActorOrder::Menu1);
	AcSocialAndHouseworkStatusWindow = CreateActor<SocialAndHouseworkStatusWindow>(PM2ActorOrder::Menu1);
	AcConverstionSelectionMenu = CreateActor<ConverstionSelectionMenu>(PM2ActorOrder::Menu1);
	AcDietSelectionMenu = CreateActor<DietSelectionMenu>(PM2ActorOrder::Menu1);

	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	CreateActor<Olive>(PM2ActorOrder::Olive);
	CreateActor<Flower>(PM2ActorOrder::BackGround);
	CreateActor<Paint>(PM2ActorOrder::BackGround);
	//CreateActor<Calendar>(PM2ActorOrder::Menu1);
	//CreateActor<EstimateStatusWindow>(PM2ActorOrder::Menu1);
	//CreateActor<FemininityStatusWindow>(PM2ActorOrder::Menu1);
	//CreateActor<Animation>(2);

	ButtonAndKeyLoad();
}
//800,0 ~ 800,320
void RaisingSimLevel::Update(float _DeltaTime)
{
	//AcCubeDialog->UpdateCubeDialog(CubeFace::Anger, "우아아아앙");

	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RPG");
		// Player::MainPlayer->Death()p;
	}

	if (GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}

	if (GameEngineInput::IsDown("ESC"))
	{
		if (AcBasicStatusWindow->IsUpdate())
		{
			AcMainMenu->On();
			AcBasicStatusWindow->Off();
			AcEstimateStatusWindow->Off();
			AcFighterAndMagicalStatusWindow->Off();
			AcSocialAndHouseworkStatusWindow->Off();
		}
		else if (AcConverstionSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcConverstionSelectionMenu->Off();
		}
		else if (AcDietSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcDietSelectionMenu->Off();
			AcCubeDialog->Off();
		}
	}

	/*if (GameEngineInput::IsUp("EngineMouseLeft") && AcBasicStatusWindow->IsUpdate())
	{
		AcMainMenu->On();
		AcBasicStatusWindow->Off();
		AcEstimateStatusWindow->Off();
		AcFighterAndMagicalStatusWindow->Off();
		AcSocialAndHouseworkStatusWindow->Off();
	}
	else if (GameEngineInput::IsUp("EngineMouseLeft") && AcConverstionSelectionMenu->IsUpdate())
	{
		AcMainMenu->On();
		AcConverstionSelectionMenu->Off();
	}*/
}

void RaisingSimLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	AcOlive = Olive::OlivePlayer;
	Olive::OlivePlayer->On();
}


void RaisingSimLevel::ClickStatusWindowButton(Button* _Button)
{
	AcMainMenu->Off();
	AcBasicStatusWindow->On();
	AcEstimateStatusWindow->On();
	AcFighterAndMagicalStatusWindow->On();
	AcSocialAndHouseworkStatusWindow->On();
}

void RaisingSimLevel::ClickConversationButton(Button* _Button)
{
	AcMainMenu->Off();
	AcConverstionSelectionMenu->On();
}

void RaisingSimLevel::ClickDietButton(Button* _Button)
{
	AcMainMenu->Off();
	AcDietSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「주인님, 아가씨의 건강관리는\n어떤 방침으로 하시겠습니까?」");
}

void RaisingSimLevel::SoundLoad()
{
}

void RaisingSimLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("RaisingLevel");
	
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("paint_default.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_spring.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_summer.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_fall.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_winter.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("flower_disease.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("background.BMP"));

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobbackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("parttimejobanimation.BMP"))->Cut(13, 2);

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DateViewer.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_WeekDay.BMP"))->Cut(7, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Month.BMP"))->Cut(12, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Day.BMP"))->Cut(10, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num.BMP"))->Cut(10, 1);

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BasicInfo.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Age.BMP"))->Cut(10, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MainMenu.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MainMenu_Buttons.bmp"))->Cut(4,2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MainMenu_Schedule.bmp"));

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer1.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer1_Detail.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer1_Estemate.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer1_Physical.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer2.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer2_Detail.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer2_Estemate.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGaugeFrame_Layer2_Physical.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StatusGauge.bmp"))->Cut(2, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Status.bmp"))->Cut(10, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Status_etc.bmp"))->Cut(2, 1);
	
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Icon.bmp"))->Cut(15, 7);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BloodTypeRender.bmp"))->Cut(4, 1);

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Calendar.bmp"));

	Dir.Move("Cube");
	
	std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}
}

void RaisingSimLevel::ButtonAndKeyLoad()
{
	AcMainMenu->GetMainMenuButton()[0][0]->SetClickCallBack(ClickStatusWindowButton);
	AcMainMenu->GetMainMenuButton()[0][1]->SetClickCallBack(ClickConversationButton);
	AcMainMenu->GetMainMenuButton()[0][2]->SetClickCallBack(ClickDietButton);
}


