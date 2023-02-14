#include "FirstSetLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "MousePoint.h"
#include "SetPlayerName.h"
#include "SetOliveName.h"
#include "OliveCalendar.h"
#include "PlayerCalendar.h"
#include "SetPlayerAge.h"
#include "SetOliveBooldType.h"
#include "ContentsEnums.h"

ActorState FirstSetLevel::StateValue = ActorState::NULLSTATE;

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
	

	if (false == GameEngineInput::IsKey("ActorChange"))
	{
		GameEngineInput::CreateKey("ActorChange", 'R');
	}
	
	CreateActor<MousePoint>(PM2ActorOrder::MousePoint);
	AcSetPlayerName = CreateActor<SetPlayerName>(static_cast<int>(ActorState::SetPlayerName));
	AcSetOliveName = CreateActor<SetOliveName>(static_cast<int>(ActorState::SetOliveName));
	AcOliveCalendar = CreateActor<OliveCalendar>(static_cast<int>(ActorState::OliveCalendar));
	AcPlayerCalendar = CreateActor<PlayerCalendar>(static_cast<int>(ActorState::PlayerCalendar));
	AcSetOliveBloodType = CreateActor<SetOliveBooldType>(static_cast<int>(ActorState::SetOliveBloodType));
	AcSetPlayerAge = CreateActor<SetPlayerAge>(static_cast<int>(ActorState::SetPlayerAge));

	AcSetPlayerName->GetCompleteButton()->SetClickCallBack(ChangeStateToSetOliveName);

	ChangeState(ActorState::SetPlayerName);
}

void FirstSetLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("Opening");
	}

	if (true == GameEngineInput::IsDown("ActorChange"))
	{
		ChangeState(NextStateValue);
	}
}

void FirstSetLevel::ChangeActor(int _State)
{
	if (_State < 0 || _State > 6)
	{
		MsgAssert("존재하지 않는 상태의 액터를 실행시키려고 했습니다" + _State);
		return;
	}

	switch (_State)
	{
	case 0:
		UpdateActor = nullptr;
		break;
	case 1:
		UpdateActor = AcSetPlayerName; 
		break;
	case 2:
		UpdateActor = AcSetOliveName; 
		break;
	case 3:
		UpdateActor = AcOliveCalendar; 
		break;
	case 4:
		UpdateActor = AcSetPlayerAge; 
		break;
	case 5:
		UpdateActor = AcPlayerCalendar; 
		break;
	case 6:
		UpdateActor = AcSetOliveBloodType;
		break;

	default:
		break;
	}
}

void FirstSetLevel::ChangeActor(ActorState _State)
{
	FirstSetLevel::ChangeActor(static_cast<int>(_State));
}

void FirstSetLevel::OnUpdateActor()
{
	if (nullptr == UpdateActor)
	{
		return;
	}

	UpdateActor->On();
}

void FirstSetLevel::OffUpdateActor()
{
	if (nullptr == UpdateActor)
	{
		return;
	}

	UpdateActor->Off();
}


void FirstSetLevel::ChangeState(ActorState _State)
{
	ActorState PrevState = StateValue;
	ActorState NextState = _State;
	StateValue = NextState;

	switch (PrevState)
	{
	case ActorState::NULLSTATE:
		NULLStateEnd();
		break;
	case ActorState::SetPlayerName:
		SetPlayerNameEnd();
		break;
	case ActorState::SetOliveName:
		SetOliveNameEnd();
		break;
	case ActorState::OliveCalendar:
		OliveCalendarEnd();
		break;
	case ActorState::SetPlayerAge:
		SetPlayerAgeEnd();
		break;
	case ActorState::PlayerCalendar:
		PlayerCalendarEnd();
		break;
	case ActorState::SetOliveBloodType:
		SetOliveBloodTypeEnd();
		break;
	default:
		break;
	}

	switch (NextState)
	{
	case ActorState::NULLSTATE:
		break;
	case ActorState::SetPlayerName:
		SetPlayerNameStart();
		break;
	case ActorState::SetOliveName:
		SetOliveNameStart();
		break;
	case ActorState::OliveCalendar:
		OliveCalendarStart();
		break;
	case ActorState::SetPlayerAge:
		SetPlayerAgeStart();
		break;
	case ActorState::PlayerCalendar:
		PlayerCalendarStart();
		break;
	case ActorState::SetOliveBloodType:
		SetOliveBloodTypeStart();
		break;
	default:
		break;
	}
}

void FirstSetLevel::NULLStateStart()
{
}

void FirstSetLevel::NULLStateEnd()
{
}

void FirstSetLevel::SetPlayerNameStart()
{
	ChangeActor(ActorState::SetPlayerName);
	OnUpdateActor();
	NextStateValue = ActorState::SetOliveName;
}

void FirstSetLevel::SetPlayerNameEnd()
{
	OffUpdateActor();
}

void FirstSetLevel::SetOliveNameStart()
{
	ChangeActor(ActorState::SetOliveName);
	OnUpdateActor();
	NextStateValue = ActorState::OliveCalendar;
}

void FirstSetLevel::SetOliveNameEnd()
{
	OffUpdateActor();
}

void FirstSetLevel::OliveCalendarStart()
{
	ChangeActor(ActorState::OliveCalendar);
	OnUpdateActor();
	NextStateValue = ActorState::SetPlayerAge;
}

void FirstSetLevel::OliveCalendarEnd()
{
	OffUpdateActor();
}

void FirstSetLevel::SetPlayerAgeStart()
{
	ChangeActor(ActorState::SetPlayerAge);
	OnUpdateActor();
	NextStateValue = ActorState::PlayerCalendar;
}

void FirstSetLevel::SetPlayerAgeEnd()
{
	OffUpdateActor();
}

void FirstSetLevel::PlayerCalendarStart()
{
	ChangeActor(ActorState::PlayerCalendar);
	OnUpdateActor();
	NextStateValue = ActorState::SetOliveBloodType;
}

void FirstSetLevel::PlayerCalendarEnd()
{
	OffUpdateActor();
}

void FirstSetLevel::SetOliveBloodTypeStart()

{
	ChangeActor(ActorState::SetOliveBloodType);
	OnUpdateActor();
}

void FirstSetLevel::SetOliveBloodTypeEnd()
{
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