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

	//CreateActor<SetOliveName>(9);
	//CreateActor<SetPlayerName>(10);
	//CreateActor<OliveCalendar>(11);
	CreateActor<PlayerCalendar>(11);

}

void FirstSetLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}
