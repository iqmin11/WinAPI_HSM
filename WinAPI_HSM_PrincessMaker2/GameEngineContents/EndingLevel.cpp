#include "EndingLevel.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include "FirstScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"
#include "FourthScene.h"
#include "EndingPortrait.h"
#include "Olive.h"


EndingLevel::EndingLevel()
{

}

EndingLevel::~EndingLevel()
{

}

void EndingLevel::Loading()
{
	ImageLoad();
	SoundLoad();
	AcFirstScene = CreateActor<FirstScene>(PM2ActorOrder::BackGround);
	AcSecondScene = CreateActor<SecondScene>(PM2ActorOrder::BackGround);
	AcThirdScene = CreateActor<ThirdScene>(PM2ActorOrder::BackGround);
	AcFourthScene = CreateActor<FourthScene>(PM2ActorOrder::BackGround);
	AcEndingPortrait = CreateActor<EndingPortrait>(PM2ActorOrder::BackGround);

}

void EndingLevel::Update(float _DeltaTime)
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

	Time += _DeltaTime;
	if (Time >= 0 && Time < 10)
	{
		AcFirstScene->On();
	}
	else if (Time >= 10 && Time < 25)
	{
		AcFirstScene->Off();
		AcSecondScene->On();
	}
	else if (Time >= 25 && Time < 40)
	{
		AcSecondScene->Off();
		AcThirdScene->On();
	}
	else if (Time >= 40 && Time < 50)
	{
		AcThirdScene->Off();
		AcFourthScene->On();
	}
	else if (Time >= 50)
	{
		AcFourthScene->Off();
		AcEndingPortrait->On();
	}

	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
	}
}

void EndingLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	Time = 0;
	AcFirstScene->Off();
	AcSecondScene->Off();
	AcThirdScene->Off();
	AcFourthScene->Off();
	AcEndingPortrait->Off();
	BGMPlayer.Stop();
	AcOlive->SetOliveAge(17);
}

void EndingLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("30_Ending.mp3");
	AcOlive = Olive::OlivePlayer;
	if (AcOlive->OliveStatus.Fighter >= 300 && AcOlive->OliveStatus.Magical >= 200 && AcOlive->OliveStatus.Sin >= 500)
	{
		OliveEnding = Ending::¸¶¿Õ;
	}
	else if ((AcOlive->OliveStatus.Morality == 0 && AcOlive->OliveStatus.Sin >= 100) || (AcOlive->OliveStatus.Morality < 30 && AcOlive->OliveStatus.Sin >= 250))
	{
		if (EstimateGrade(AcOlive->OliveStatus.Fighter) >= 1 && AcOlive->OliveStatus.Refinement >= 200 && AcOlive->OliveStatus.Charisma >= 200)
		{
			OliveEnding = Ending::SM¿©¿Õ;
		}
		else if (EstimateGrade(AcOlive->OliveStatus.Fighter) >= 1 && AcOlive->OliveStatus.Refinement >= 200 && AcOlive->OliveStatus.Charisma < 200)
		{
			OliveEnding = Ending::¾ÏÈæ°¡ÀÇº¸½º;
		}
		else if (EstimateGrade(AcOlive->OliveStatus.Fighter) >= 1)
		{
			OliveEnding = Ending::Æø·Â¹è;
		}
		else if (EstimateGrade(AcOlive->OliveStatus.Fighter) == 0 && AcOlive->OliveStatus.Charisma >= 200 && AcOlive->OliveStatus.Conversation >= 70 && AcOlive->OliveStatus.Temperament >= 70)
		{
			OliveEnding = Ending::°í±ÞÃ¢ºÎ;
		}
		else if (EstimateGrade(AcOlive->OliveStatus.Fighter) == 0 && AcOlive->OliveStatus.Charisma < 200 && AcOlive->OliveStatus.Conversation >= 70)
		{
			OliveEnding = Ending::»ç±â²Û;
		}
		else if (EstimateGrade(AcOlive->OliveStatus.Fighter) == 0)
		{
			OliveEnding = Ending::Ã¢ºÎ;
		}
	}
	else if (EstimateMaxMinusMin() < 50 && EstimateGrade(EstimateMax()) >= 2)
	{
		if (EstimateGrade(EstimateMax()) == 4 && AcOlive->OliveStatus.Refinement >= 800)
		{
			OliveEnding = Ending::¿©¿Õ;
		}
		else if (EstimateGrade(EstimateMax()) == 4 && AcOlive->OliveStatus.Refinement < 800)
		{
			OliveEnding = Ending::Àç»ó;
		}
		else if (EstimateGrade(EstimateMax()) == 3 && AcOlive->OliveStatus.Intelligence >= AcOlive->OliveStatus.Morality && AcOlive->OliveStatus.Intelligence >= AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::¹Ú»ç;
		}
		else if (EstimateGrade(EstimateMax()) == 3 && AcOlive->OliveStatus.Intelligence < AcOlive->OliveStatus.Morality && AcOlive->OliveStatus.Morality >= AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::´ë½Å;
		}
		else if (EstimateGrade(EstimateMax()) == 3 && AcOlive->OliveStatus.Intelligence < AcOlive->OliveStatus.Faith && AcOlive->OliveStatus.Morality < AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::´ëÁÖ±³;
		}
		else if (EstimateGrade(EstimateMax()) == 2 && AcOlive->OliveStatus.Intelligence >= AcOlive->OliveStatus.Morality && AcOlive->OliveStatus.Intelligence >= AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::ÇÐ»ç;
		}
		else if (EstimateGrade(EstimateMax()) == 2 && AcOlive->OliveStatus.Intelligence < AcOlive->OliveStatus.Morality && AcOlive->OliveStatus.Morality >= AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::ÀçÆÇ°ü;
		}
		else if (EstimateGrade(EstimateMax()) == 2 && AcOlive->OliveStatus.Intelligence < AcOlive->OliveStatus.Faith && AcOlive->OliveStatus.Morality < AcOlive->OliveStatus.Faith)
		{
			OliveEnding = Ending::¼ö³à;
		}
	}
	else
	{
		OliveEnding = Ending::±Ã³à;
	}
	
}

void EndingLevel::ImageLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("EndingLevel");
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("FirstSceneBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("SecondSceneBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ThirdSceneBackground.BMP"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingPortrait.BMP"));
	Dir.Move("EndingIllustration");
	std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	for (size_t i = 0; i < AllFile.size(); i++)
	{
		GameEngineResources::GetInst().ImageLoad(AllFile[i].GetFullPath());
	}
}

void EndingLevel::SoundLoad()
{
	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");

	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("30_Ending.mp3"));
}

int EndingLevel::EstimateGrade(float _Estimate)
{
	if (60 >= _Estimate)
	{
		return 0;
	}
	else if (60 < _Estimate && 160 >= _Estimate)
	{
		return 1; 
	}
	else if (160 < _Estimate && 230 >= _Estimate)
	{
		return 2;
	}
	else if (230 < _Estimate && 270 >= _Estimate)
	{
		return 3;
	}
	else if (270 < _Estimate)
	{
		return 4;
	}
}

float EndingLevel::EstimateMaxMinusMin()
{
	return EstimateMax() - EstimateMin();
}

float EndingLevel::EstimateMax()
{
	std::vector<float> Estimate = std::vector<float>();
	Estimate.reserve(4);
	Estimate.push_back(AcOlive->OliveStatus.Fighter);
	Estimate.push_back(AcOlive->OliveStatus.Magical);
	Estimate.push_back(AcOlive->OliveStatus.Social);
	Estimate.push_back(AcOlive->OliveStatus.HouseWork);

	float Max = Estimate[0];
	for (auto i : Estimate)
	{
		Max = Max > i ? Max : i;
	}
	return Max;
}

float EndingLevel::EstimateMin()
{
	std::vector<float> Estimate = std::vector<float>();
	Estimate.reserve(4);
	Estimate.push_back(AcOlive->OliveStatus.Fighter);
	Estimate.push_back(AcOlive->OliveStatus.Magical);
	Estimate.push_back(AcOlive->OliveStatus.Social);
	Estimate.push_back(AcOlive->OliveStatus.HouseWork);

	float Min = Estimate[0];
	for (auto i : Estimate)
	{
		Min = Min > i ? i : Min;
	}
	return Min;
}
