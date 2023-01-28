#include "FirstSetLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "SetPlayerName.h"
#include "SetOliveName.h"
#include "OliveCalendar.h"
#include "PlayerCalendar.h"

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

	/*if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
	}*/

	CreateActor<SetOliveName>(0);
	CreateActor<SetPlayerName>(1);
	CreateActor<OliveCalendar>(2);
	CreateActor<PlayerCalendar>(3);

	ChangeState(ActorState::SetPlayerName);
}

void FirstSetLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}

void FirstSetLevel::ChangeActor(int _Order)
{
	std::map<int, std::list<GameEngineActor*>>::iterator FindIter = GetActors().find(_Order);

	if (FindIter == GetActors().end())
	{
		MsgAssert("존재하지 않는 액터를 실행시키려고 했습니다 Order" + _Order);
		return;
	}

	//해당 오더안에있는 액터 리스트를 순회하면서 업데이트하는게 내 목적
	//이전에 실행되던 액터는 끄고..

	//FindIter->second.
}

void FirstSetLevel::ChangeState(ActorState _State)
{
	ActorState PrevState = StateValue;
	ActorState NextState = _State;
	StateValue = NextState;

	switch (PrevState)
	{
	case ActorState::NULLSTATE:
		void NULLStateEnd();
		break;

	case ActorState::SetPlayerName:
		void SetPlayerNameEnd();
		break;

	case ActorState::SetOliveName:
		void SetOliveNameEnd();
		break;

	case ActorState::OliveCalendar:
		void OliveCalendarEnd();
		break;

	case ActorState::PlayerCalendar:
		void PlayerCalendarEnd();
		break;

	default:
		break;
	}

	switch (NextState)
	{
	case ActorState::NULLSTATE:
		break;

	case ActorState::SetPlayerName:
		void SetPlayerNameStart();
		break;

	case ActorState::SetOliveName:
		void SetOliveNameStart();
		break;

	case ActorState::OliveCalendar:
		void OliveCalendarStart();
		break;

	case ActorState::PlayerCalendar:
		void PlayerCalendarStart();
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
	ChangeState(ActorState::SetPlayerName);
}

void FirstSetLevel::SetPlayerNameStart()
{
}

void FirstSetLevel::SetPlayerNameUpdate()
{
}

void FirstSetLevel::SetPlayerNameEnd()
{
	ChangeState(ActorState::SetOliveName);
}

void FirstSetLevel::SetOliveNameStart()
{
}

void FirstSetLevel::SetOliveNameUpdate()
{
}

void FirstSetLevel::SetOliveNameEnd()
{
	ChangeState(ActorState::OliveCalendar);
}

void FirstSetLevel::OliveCalendarStart()
{
}

void FirstSetLevel::OliveCalendarUpdate()
{
}

void FirstSetLevel::OliveCalendarEnd()
{
	ChangeState(ActorState::PlayerCalendar);
}

void FirstSetLevel::PlayerCalendarStart()
{
}

void FirstSetLevel::PlayerCalendarUpdate()
{
}

void FirstSetLevel::PlayerCalendarEnd()
{
}
