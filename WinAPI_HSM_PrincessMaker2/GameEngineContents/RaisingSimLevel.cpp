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

#include "Flower.h"
#include "Paint.h"
#include "DateViewer.h"
#include "BasicInfo.h"

#include "CubeDialog.h"
#include "ContentsEnums.h"

#include "IconButton.h"

#include "PersonalInformationWindow.h"
#include "HelthInformationWindow.h"

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

	AcCubeDialog = CreateActor<CubeDialog>(PM2ActorOrder::Dialog);
	AcBackground = CreateActor<Background>(static_cast<int>(PM2ActorOrder::BackGround));
	CreateActor<DateViewer>(PM2ActorOrder::Menu0);
	CreateActor<BasicInfo>(PM2ActorOrder::Menu0);
	AcMenuManager = CreateActor<UIManager>();

	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	CreateActor<Olive>(PM2ActorOrder::Olive);
	CreateActor<Flower>(PM2ActorOrder::BackGround);
	CreateActor<Paint>(PM2ActorOrder::BackGround);

	
}

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
}

void RaisingSimLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	AcOlive = Olive::OlivePlayer;
	Olive::OlivePlayer->On();
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

}



