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
#include "DietSelectionMenu.h"
#include "DietFinalConfirmSelectionMenu.h"
#include "BasicStatusWindow.h"
#include "EstimateStatusWindow.h"
#include "FighterAndMagicalStatusWindow.h"
#include "SocialAndHouseworkStatusWindow.h"
#include "ConverstionSelectionMenu.h"
#include "ScheduleCalendar.h"
#include "ScheduleSelectionMenu.h"
#include "ClassSelectWindow.h"

#include "CubeDialog.h"
#include "ContentsEnums.h"

#include "IconButton.h"

MainMenu* RaisingSimLevel::AcMainMenu = nullptr;
BasicStatusWindow* RaisingSimLevel::AcBasicStatusWindow = nullptr;
EstimateStatusWindow* RaisingSimLevel::AcEstimateStatusWindow = nullptr;
FighterAndMagicalStatusWindow* RaisingSimLevel::AcFighterAndMagicalStatusWindow = nullptr;
SocialAndHouseworkStatusWindow* RaisingSimLevel::AcSocialAndHouseworkStatusWindow = nullptr;

ConverstionSelectionMenu* RaisingSimLevel::AcConverstionSelectionMenu = nullptr;
DietSelectionMenu* RaisingSimLevel::AcDietSelectionMenu = nullptr;
DietFinalConfirmSelectionMenu* RaisingSimLevel::AcDietFinalConfirmSelectionMenu = nullptr;

ScheduleCalendar* RaisingSimLevel::AcScheduleCalendar = nullptr;
ScheduleSelectionMenu* RaisingSimLevel::AcScheduleSelectionMenu = nullptr;
ClassSelectWindow* RaisingSimLevel::AcClassSelectWindow = nullptr;

Diet RaisingSimLevel::DietSetConfirm = Diet::Null;

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
	AcDietFinalConfirmSelectionMenu = CreateActor<DietFinalConfirmSelectionMenu>(PM2ActorOrder::Menu2);
	AcDietSelectionMenu = CreateActor<DietSelectionMenu>(PM2ActorOrder::Menu1);
	AcScheduleCalendar = CreateActor<ScheduleCalendar>(PM2ActorOrder::Menu1);
	AcScheduleSelectionMenu = CreateActor<ScheduleSelectionMenu>(PM2ActorOrder::Menu1);
	AcClassSelectWindow = CreateActor<ClassSelectWindow>(PM2ActorOrder::Menu2);

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

	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RPG");
	}

	if (GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}

	ESCdown();

	

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

void RaisingSimLevel::ESCdown()
{
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
		else if (AcDietFinalConfirmSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcDietFinalConfirmSelectionMenu->Off();
			AcCubeDialog->Off();
		}
		else if (AcScheduleSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcScheduleCalendar->Off();
			AcScheduleSelectionMenu->Off();
			AcCubeDialog->Off();
		}
		else if (AcClassSelectWindow->IsUpdate())
		{
			AcClassSelectWindow->Off();
			AcScheduleCalendar->On();
			AcScheduleSelectionMenu->On();
			AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
		}
	}
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

void RaisingSimLevel::ClickScheduleButton(Button* _Button)
{
	AcMainMenu->Off();
	AcScheduleCalendar->On();
	AcScheduleSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
}

void RaisingSimLevel::ClickDiet_0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n30G 들어갑니다. 무리 없는 식\n생활을 보낼 수 있습니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::무리하지_않는다;
}


void RaisingSimLevel::ClickDiet_1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n80G 들어갑니다. 체력이 올라가\n겠죠」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::어쨌든_튼튼하게;
}

void RaisingSimLevel::ClickDiet_2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n10G 들어갑니다. 약간 건강에 부\n담이 갈지도 모릅니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::얌전한_아이로;
}

void RaisingSimLevel::ClickDiet_3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n5G 밖에 들지 않습니다. 아가씨의\n몸무게를 줄이고 싶다면, 이 방\n침으로 가시죠. 단, 체력을 상\n당히 소모하므로 주의하시기 바\n랍니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::다이어트_시킨다;
}

void RaisingSimLevel::ClickDietFinalConfirm_0(Button* _Button)
{
	switch (DietSetConfirm)
	{
	case Diet::무리하지_않는다:
		Olive::OlivePlayer->SetOliveDiet(Diet::무리하지_않는다);
		break;
	case Diet::어쨌든_튼튼하게:
		Olive::OlivePlayer->SetOliveDiet(Diet::어쨌든_튼튼하게);
		break;
	case Diet::얌전한_아이로:
		Olive::OlivePlayer->SetOliveDiet(Diet::얌전한_아이로);
		break;
	case Diet::다이어트_시킨다:
		Olive::OlivePlayer->SetOliveDiet(Diet::다이어트_시킨다);
		break;
	default:
		break;
	}
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void RaisingSimLevel::ClickDietFinalConfirm_1(Button* _Button)
{
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void RaisingSimLevel::ClickClass(Button* _Button)
{
	AcScheduleSelectionMenu->Off();
	AcClassSelectWindow->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "딸에게 무엇을 가르치시겠습니까?");
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Num_Status_etc.bmp"))->Cut(3, 1);
	
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Icon.bmp"))->Cut(15, 7);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BloodTypeRender.bmp"))->Cut(4, 1);

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Calendar.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IconButton_Hover.bmp"));

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
	AcMainMenu->GetScheduleButton()->SetClickCallBack(ClickScheduleButton);

	AcDietSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickDiet_0);
	AcDietSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickDiet_1);
	AcDietSelectionMenu->GetSelectButtons()[2]->SetClickCallBack(ClickDiet_2);
	AcDietSelectionMenu->GetSelectButtons()[3]->SetClickCallBack(ClickDiet_3);

	AcDietFinalConfirmSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickDietFinalConfirm_0);
	AcDietFinalConfirmSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickDietFinalConfirm_1);

	AcScheduleSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickClass);
}


