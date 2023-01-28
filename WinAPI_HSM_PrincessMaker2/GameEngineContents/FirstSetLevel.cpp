#include "FirstSetLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "SetPlayerName.h"
#include "SetOliveName.h"
#include "OliveCalendar.h"
#include "PlayerCalendar.h"
#include "SetPlayerAge.h"
#include "SetOliveBooldType.h"

FirstSetLevel::FirstSetLevel()
{

}

FirstSetLevel::~FirstSetLevel()
{

}

void FirstSetLevel::Loading()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("FirstSetLevel");

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BirthNum.BMP"));
		Image->Cut(10, 1);
	}

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveCalendarNum.BMP"));
		Image->Cut(32, 3);
	}

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveYearNum.BMP"));
		Image->Cut(10, 3);
	}

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerYearNum.BMP"));
		Image->Cut(10, 3);
	}

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerCalendarNum.BMP"));
		Image->Cut(32, 3);
	}

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("OliveWeek.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("PlayerWeek.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetOliveBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetOliveBirth.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetPlayerBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SetPlayerBirth.BMP"));

	if (false == GameEngineInput::IsKey("ActorChange"))
	{
		GameEngineInput::CreateKey("ActorChange", 'R');
	}

	CreateActor<SetPlayerName>(static_cast<int>(ActorState::SetPlayerName));
	CreateActor<SetOliveName>(static_cast<int>(ActorState::SetOliveName));
	CreateActor<OliveCalendar>(static_cast<int>(ActorState::OliveCalendar));
	CreateActor<PlayerCalendar>(static_cast<int>(ActorState::PlayerCalendar));
	CreateActor<SetOliveBooldType>(static_cast<int>(ActorState::SetOliveBloodType));
	CreateActor<SetPlayerAge>(static_cast<int>(ActorState::SetPlayerAge));

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

void FirstSetLevel::ChangeActor(int _Order)
{
	if (GetActors()->find(_Order) == GetActors()->end())
	{
		MsgAssert("존재하지 않는 액터를 실행시키려고 했습니다 Order" + _Order);
		return;
	}

	//해당 오더안에있는 액터 리스트를 순회하면서 업데이트하는게 내 목적
	//이전에 실행되던 액터는 끄고..

	UpdateActor = &(GetActors()->find(_Order)->second);
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

	for (auto i : *UpdateActor)
	{
		i->On();
	}
}

void FirstSetLevel::OffUpdateActor()
{
	if (nullptr == UpdateActor)
	{
		return;
	}

	for (auto i : *UpdateActor)
	{
		i->Off();
	}
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

void FirstSetLevel::SetPlayerNameUpdate()
{
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

void FirstSetLevel::SetOliveNameUpdate()
{
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

void FirstSetLevel::OliveCalendarUpdate()
{
	int a = 0;
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

void FirstSetLevel::SetPlayerAgeUpdate()
{
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

void FirstSetLevel::PlayerCalendarUpdate()
{
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

void FirstSetLevel::SetOliveBloodTypeUpdate()
{
}

void FirstSetLevel::SetOliveBloodTypeEnd()
{
}
