#include "FirstSetLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineFile.h>

#include "MousePoint.h"
#include "Olive.h"
#include "SetPlayerName.h"
#include "SetOliveName.h"
#include "OliveCalendar.h"
#include "PlayerCalendar.h"
#include "SetPlayerAge.h"
#include "SetOliveBloodType.h"
#include "ContentsEnums.h"

ActorState FirstSetLevel::CurStateValue = ActorState::NULLSTATE;
ActorState FirstSetLevel::PrevStateValue = ActorState::NULLSTATE;

FirstSetLevel::FirstSetLevel()
{

}

FirstSetLevel::~FirstSetLevel()
{

}

void FirstSetLevel::Loading()
{
	SoundLoad();
	ImageLoad();
	
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);

	AcOlive = CreateActor<Olive>(PM2ActorOrder::Olive);

	AcSetPlayerName = CreateActor<SetPlayerName>(static_cast<int>(ActorState::SetPlayerName));
	AcSetOliveName = CreateActor<SetOliveName>(static_cast<int>(ActorState::SetOliveName));
	AcOliveCalendar = CreateActor<OliveCalendar>(static_cast<int>(ActorState::OliveCalendar));
	AcSetPlayerAge = CreateActor<SetPlayerAge>(static_cast<int>(ActorState::SetPlayerAge));
	AcPlayerCalendar = CreateActor<PlayerCalendar>(static_cast<int>(ActorState::PlayerCalendar));
	AcSetOliveBloodType = CreateActor<SetOliveBloodType>(static_cast<int>(ActorState::SetOliveBloodType));

	CurStateValue = ActorState::SetPlayerName;
	PrevStateValue = ActorState::SetPlayerName;

	if (true != GameEngineInput::IsKey("ESC"))
	{
		GameEngineInput::CreateKey("ESC", VK_ESCAPE);
	}
}

void FirstSetLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("Opening");
	}
	
	if (true == GameEngineInput::IsDown("1"))
	{
		GameEngineCore::GetInst()->DebugSwitch();
	}

	switch (CurStateValue)
	{
	case ActorState::NULLSTATE:
		break;
	case ActorState::SetPlayerName:
		AcSetPlayerName->On();
		AcSetOliveName->Off();
		AcOliveCalendar->Off();
		AcSetPlayerAge->Off();
		AcPlayerCalendar->Off();
		AcSetOliveBloodType->Off();
		PrevStateValue = ActorState::SetPlayerName;
		break;
	case ActorState::SetOliveName:
		AcSetPlayerName->Off();
		AcSetOliveName->On();
		AcOliveCalendar->Off();
		AcSetPlayerAge->Off();
		AcPlayerCalendar->Off();
		AcSetOliveBloodType->Off();
		PrevStateValue = ActorState::SetPlayerName;
		if (true == GameEngineInput::IsDown("ESC"))
		{
			CurStateValue = PrevStateValue;
			AcSetPlayerName->FirstUpdate = false;
		}
		break;
	case ActorState::OliveCalendar:
		AcSetPlayerName->Off();
		AcSetOliveName->Off();
		AcOliveCalendar->On();
		AcSetPlayerAge->Off();
		AcPlayerCalendar->Off();
		AcSetOliveBloodType->Off();
		PrevStateValue = ActorState::SetOliveName;
		if (true == GameEngineInput::IsDown("ESC"))
		{
			CurStateValue = PrevStateValue;
			AcSetOliveName->FirstUpdate = false;
		}
		break;
	case ActorState::SetPlayerAge:
		AcSetPlayerName->Off();
		AcSetOliveName->Off();
		AcOliveCalendar->Off();
		AcSetPlayerAge->On();
		AcPlayerCalendar->Off();
		AcSetOliveBloodType->Off();
		PrevStateValue = ActorState::OliveCalendar;
		if (true == GameEngineInput::IsDown("ESC"))
		{
			CurStateValue = PrevStateValue;
			AcOliveCalendar->FirstUpdate = false;
		}
		break;
	case ActorState::PlayerCalendar:
		AcSetPlayerName->Off();
		AcSetOliveName->Off();
		AcOliveCalendar->Off();
		AcSetPlayerAge->Off();
		AcPlayerCalendar->On();
		AcSetOliveBloodType->Off();
		PrevStateValue = ActorState::SetPlayerAge;
		if (true == GameEngineInput::IsDown("ESC"))
		{
			CurStateValue = PrevStateValue;
			AcSetPlayerAge->FirstUpdate = false;
		}
		break;
	case ActorState::SetOliveBloodType:
		AcSetPlayerName->Off();
		AcSetOliveName->Off();
		AcOliveCalendar->Off();
		AcSetPlayerAge->Off();
		AcPlayerCalendar->Off();
		AcSetOliveBloodType->On();
		PrevStateValue = ActorState::PlayerCalendar;
		if (true == GameEngineInput::IsDown("ESC"))
		{
			CurStateValue = PrevStateValue;
			AcPlayerCalendar->FirstUpdate = false;
		}
		break;
	default:
		break;
	}

}

void FirstSetLevel::SoundLoad()
{

}

void FirstSetLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ReleaseButton.BMP"));//Test
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HoverButton.BMP"));//Test
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PressButton.BMP"));//Test`
	
	Dir.Move("Olive");
	Dir.Move("Head");
	std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}

	Dir.MoveParentToDirectory("Body");
	Dir.Move("Body");

	AllFile.clear();
	AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}
	
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("FirstSetLevel");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BirthNum.BMP"))->Cut(10, 1);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveCalendarNum.BMP"))->Cut(32, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveYearNum.BMP"))->Cut(10, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerYearNum.BMP"))->Cut(10, 3);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerCalendarNum.BMP"))->Cut(32, 3);
	
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveWeek.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerWeek.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetOliveBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetOliveBirth.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetPlayerBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetPlayerBirth.BMP"));
}