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

#include "UIManager.h"
#include "MainMenu.h"

#include "Flower.h"
#include "Paint.h"
#include "DateViewer.h"
#include "BasicInfo.h"

#include "CubeDialog.h"
#include "ScheduleDialog.h"
#include "ContentsEnums.h"

#include "IconButton.h"

#include "PersonalInformationWindow.h"
#include "HelthInformationWindow.h"

#include "DanceClass.h"
#include "FencingClass.h"
#include "FightingClass.h"
#include "MagicClass.h"
#include "PaintingClass.h"
#include "PoetryClass.h"
#include "ProtocolClass.h"
#include "ScienceClass.h"
#include "StrategyClass.h"
#include "TheologyClass.h"

CubeDialog* RaisingSimLevel::AcCubeDialog = nullptr;
ScheduleDialog* RaisingSimLevel::AcScheduleDialog = nullptr;

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

	AcCubeDialog = CreateActor<CubeDialog>(PM2ActorOrder::Dialog1);
	AcScheduleDialog = CreateActor<ScheduleDialog>(PM2ActorOrder::Dialog2);
	AcBackground = CreateActor<Background>(static_cast<int>(PM2ActorOrder::BackGround));
	CreateActor<DateViewer>(PM2ActorOrder::Menu0);
	CreateActor<BasicInfo>(PM2ActorOrder::Menu0);
	
	AcDanceClass = CreateActor<DanceClass>(PM2ActorOrder::Menu2);
	AcFencingClass = CreateActor<FencingClass>(PM2ActorOrder::Menu2);
	AcFightingClass = CreateActor<FightingClass>(PM2ActorOrder::Menu2);
	AcMagicClass = CreateActor<MagicClass>(PM2ActorOrder::Menu2);
	AcPaintingClass = CreateActor<PaintingClass>(PM2ActorOrder::Menu2);
	AcPoetryClass = CreateActor<PoetryClass>(PM2ActorOrder::Menu2);
	AcProtocolClass = CreateActor<ProtocolClass>(PM2ActorOrder::Menu2);
	AcScienceClass = CreateActor<ScienceClass>(PM2ActorOrder::Menu2);
	AcStrategyClass = CreateActor<StrategyClass>(PM2ActorOrder::Menu2);
	AcTheologyClass = CreateActor<TheologyClass>(PM2ActorOrder::Menu2);

	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	CreateActor<Olive>(PM2ActorOrder::Olive);
	CreateActor<Flower>(PM2ActorOrder::BackGround);
	CreateActor<Paint>(PM2ActorOrder::BackGround);

	
	AcUIManager = CreateActor<UIManager>();
	GameEngineInput::CreateKey("3", '3');
	GameEngineInput::CreateKey("4", '4');
	GameEngineInput::CreateKey("5", '5');
	GameEngineInput::CreateKey("q", 'q');
	GameEngineInput::CreateKey("w", 'w');
	GameEngineInput::CreateKey("e", 'e');
	GameEngineInput::CreateKey("r", 'r');
	GameEngineInput::CreateKey("a", 'a');
	GameEngineInput::CreateKey("s", 's');
}

void RaisingSimLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("Ending");
	}

	if (GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}

	if (GameEngineInput::IsDown("2"))
	{
		++Today;
	}

	if (GameEngineInput::IsDown("3"))
	{
		GoToBeforBirthDay();
	}

	if (GameEngineInput::IsDown("4"))
	{
		OliveAllStatMax();
	}

	if (GameEngineInput::IsDown("5"))
	{
		OliveAllStatMaxExeptSin();
	}

	if (Today.GetMonth() == AcOlive->GetOliveBirthDay().GetMonth() && Today.GetDay() == AcOlive->GetOliveBirthDay().GetDay() && AcOlive->GetOliveAge() == 18)
	{
		GameEngineCore::GetInst()->ChangeLevel("Ending");
	}
	
	OliveStateChange();
	UpdateSeason();
}

void RaisingSimLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	AcOlive = Olive::OlivePlayer;
	Olive::OlivePlayer->On();
	AcUIManager->GetMainMenu()->Off();
	AcCubeDialog->On();
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
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FoodCost.bmp"));
	

	Dir.Move("Cube");
	
	std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}

	Dir.MoveParentToDirectory("Cube");
	Dir.Move("Classes");

	AllFile.clear();
	AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}

	Dir.Move("Object");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Dance.bmp"))->Cut(13,2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Fencing.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Fighting.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Magic.bmp"))->Cut(13, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Painting.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Poetry.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Protocol.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Science.bmp"))->Cut(13, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Strategy.bmp"))->Cut(13, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Animation_Object_Theology.bmp"))->Cut(13, 2);

	Dir.MoveParentToDirectory("Object");
	Dir.Move("Mug");
	AllFile.clear();
	AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}
}

void RaisingSimLevel::GoToBeforBirthDay()
{
	Today.SetDate(Today.GetYear() + 1, AcOlive->GetOliveBirthDay().GetMonth(), AcOlive->GetOliveBirthDay().GetDay()-1);
}

void RaisingSimLevel::OliveAllStatMax()
{
	Olive::OlivePlayer->OliveStatus.Constitution = Olive::OlivePlayer->OliveStatus.MaxConstitution;
	Olive::OlivePlayer->OliveStatus.Strength = Olive::OlivePlayer->OliveStatus.MaxStrength;
	Olive::OlivePlayer->OliveStatus.Intelligence = Olive::OlivePlayer->OliveStatus.MaxIntelligence;
	Olive::OlivePlayer->OliveStatus.Refinement = Olive::OlivePlayer->OliveStatus.MaxRefinement;
	Olive::OlivePlayer->OliveStatus.Charisma = Olive::OlivePlayer->OliveStatus.MaxCharisma;
	Olive::OlivePlayer->OliveStatus.Morality = Olive::OlivePlayer->OliveStatus.MaxMorality;
	Olive::OlivePlayer->OliveStatus.Faith = Olive::OlivePlayer->OliveStatus.MaxFaith;
	Olive::OlivePlayer->OliveStatus.Sin = Olive::OlivePlayer->OliveStatus.MaxSin;
	Olive::OlivePlayer->OliveStatus.Sensitivity = Olive::OlivePlayer->OliveStatus.MaxSensitivity;
	//Olive::OlivePlayer->OliveStatus.Stress = Olive::OlivePlayer->OliveStatus.MaxStress;
	Olive::OlivePlayer->OliveStatus.CombatSkill = Olive::OlivePlayer->OliveStatus.MaxCombatSkill;
	Olive::OlivePlayer->OliveStatus.CombatAttack = Olive::OlivePlayer->OliveStatus.MaxCombatAttack;
	Olive::OlivePlayer->OliveStatus.CombatDefense = Olive::OlivePlayer->OliveStatus.MaxCombatDefense;
	Olive::OlivePlayer->OliveStatus.MagicSkill = Olive::OlivePlayer->OliveStatus.MaxMagicSkill;
	Olive::OlivePlayer->OliveStatus.MagicAttack = Olive::OlivePlayer->OliveStatus.MaxMagicAttack;
	Olive::OlivePlayer->OliveStatus.MagicDefense = Olive::OlivePlayer->OliveStatus.MaxMagicDefense;
	Olive::OlivePlayer->OliveStatus.Decorum = Olive::OlivePlayer->OliveStatus.MaxDecorum;
	Olive::OlivePlayer->OliveStatus.Art = Olive::OlivePlayer->OliveStatus.MaxArt;
	Olive::OlivePlayer->OliveStatus.Conversation = Olive::OlivePlayer->OliveStatus.MaxConversation;
	Olive::OlivePlayer->OliveStatus.Cooking = Olive::OlivePlayer->OliveStatus.MaxCooking;
	Olive::OlivePlayer->OliveStatus.Cleaning = Olive::OlivePlayer->OliveStatus.MaxCleaning;
	Olive::OlivePlayer->OliveStatus.Temperament = Olive::OlivePlayer->OliveStatus.MaxTemperament;
}

void RaisingSimLevel::OliveAllStatMaxExeptSin()
{
	Olive::OlivePlayer->OliveStatus.Constitution = Olive::OlivePlayer->OliveStatus.MaxConstitution;
	Olive::OlivePlayer->OliveStatus.Strength = Olive::OlivePlayer->OliveStatus.MaxStrength;
	Olive::OlivePlayer->OliveStatus.Intelligence = Olive::OlivePlayer->OliveStatus.MaxIntelligence;
	Olive::OlivePlayer->OliveStatus.Refinement = Olive::OlivePlayer->OliveStatus.MaxRefinement;
	Olive::OlivePlayer->OliveStatus.Charisma = Olive::OlivePlayer->OliveStatus.MaxCharisma;
	Olive::OlivePlayer->OliveStatus.Morality = Olive::OlivePlayer->OliveStatus.MaxMorality;
	Olive::OlivePlayer->OliveStatus.Faith = Olive::OlivePlayer->OliveStatus.MaxFaith;
	Olive::OlivePlayer->OliveStatus.Sin = 0;
	Olive::OlivePlayer->OliveStatus.Sensitivity = Olive::OlivePlayer->OliveStatus.MaxSensitivity;
	//Olive::OlivePlayer->OliveStatus.Stress = Olive::OlivePlayer->OliveStatus.MaxStress;
	Olive::OlivePlayer->OliveStatus.CombatSkill = Olive::OlivePlayer->OliveStatus.MaxCombatSkill;
	Olive::OlivePlayer->OliveStatus.CombatAttack = Olive::OlivePlayer->OliveStatus.MaxCombatAttack;
	Olive::OlivePlayer->OliveStatus.CombatDefense = Olive::OlivePlayer->OliveStatus.MaxCombatDefense;
	Olive::OlivePlayer->OliveStatus.MagicSkill = Olive::OlivePlayer->OliveStatus.MaxMagicSkill;
	Olive::OlivePlayer->OliveStatus.MagicAttack = Olive::OlivePlayer->OliveStatus.MaxMagicAttack;
	Olive::OlivePlayer->OliveStatus.MagicDefense = Olive::OlivePlayer->OliveStatus.MaxMagicDefense;
	Olive::OlivePlayer->OliveStatus.Decorum = Olive::OlivePlayer->OliveStatus.MaxDecorum;
	Olive::OlivePlayer->OliveStatus.Art = Olive::OlivePlayer->OliveStatus.MaxArt;
	Olive::OlivePlayer->OliveStatus.Conversation = Olive::OlivePlayer->OliveStatus.MaxConversation;
	Olive::OlivePlayer->OliveStatus.Cooking = Olive::OlivePlayer->OliveStatus.MaxCooking;
	Olive::OlivePlayer->OliveStatus.Cleaning = Olive::OlivePlayer->OliveStatus.MaxCleaning;
	Olive::OlivePlayer->OliveStatus.Temperament = Olive::OlivePlayer->OliveStatus.MaxTemperament;
}

void RaisingSimLevel::OliveStateChange()
{
	if (GameEngineInput::IsDown("q"))
	{
		Olive::OlivePlayer->OliveStatus.Constitution = 100;
		Olive::OlivePlayer->OliveStatus.Stress = 150; // 아픈상태
		Olive::OlivePlayer->OliveStateUpdate();
		Olive::OlivePlayer->OliveRenderUpdate();
	}
	
	if (GameEngineInput::IsDown("w"))
	{
		Olive::OlivePlayer->OliveStatus.Constitution = 100;
		Olive::OlivePlayer->OliveStatus.Stress = 50;
		Olive::OlivePlayer->OliveStatus.Morality = 0; // 불량상태
		Olive::OlivePlayer->OliveStatus.Faith = 0; // 불량상태
		Olive::OlivePlayer->OliveStateUpdate();
		Olive::OlivePlayer->OliveRenderUpdate();
	}

	if (GameEngineInput::IsDown("e"))
	{
		Olive::OlivePlayer->OliveStatus.Stress = 0; //행복상태
		Olive::OlivePlayer->OliveStateUpdate();
		Olive::OlivePlayer->OliveRenderUpdate();
	}

	if (GameEngineInput::IsDown("r"))
	{
		Olive::OlivePlayer->OliveStatus.Stress = 1; // 일반상태
		Olive::OlivePlayer->OliveStatus.Morality = 100; // 일반상태
		Olive::OlivePlayer->OliveStatus.Faith = 100; // 일반상태
		Olive::OlivePlayer->OliveStateUpdate();
		Olive::OlivePlayer->OliveRenderUpdate();
	}

}

void RaisingSimLevel::UpdateSeason()
{
	int Month = Today.GetMonth();
	if (Month >= 3 && Month < 6)
	{
		TodaySeason = Season::Spring;
	}
	else if (Month >= 6 && Month < 9)
	{
		TodaySeason = Season::Summer;
	}
	else if (Month >= 9 && Month < 12)
	{
		TodaySeason = Season::Fall;
	}
	else if (Month >= 1 && Month < 3 || Month == 12)
	{
		TodaySeason = Season::Winter;
	}
}



