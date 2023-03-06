#pragma once
#include <GameEngineCore/GameEngineLevel.h>


enum class Ending
{
	Null = -1,
	마왕,
	SM여왕,
	암흑가의보스,
	폭력배,
	고급창부,
	사기꾼,
	창부,
	광대,
	작가,
	화가,
	무용수,
	여왕,
	재상,
	박사,
	대신,
	대주교,
	학사,
	재판관,
	수녀,
	보모,
	여관직원,
	농부,
	교회직원,
	요리사,
	나무꾼,
	미용사,
	미장이,
	사냥꾼,
	묘지기,
	가정교사,
	주점직원,
	어둠의주점원,
	밤의무희,
	궁녀,
	용사,
	장군,
	근위대장,
	기사,
	무도사범,
	현상금사냥꾼,
	병사,
	용병,
	마법용사,
	왕궁마법사,
	마법사범,
	마도사,
	마법사,
	점술사,
	마술사,
	거리의광대,
	왕비,
	왕의후궁,
	백작부인,
	부호의처,
	상인의처,
	농부의처,
	지주의첩,
	이혼녀,
	신부수업,
};

class Olive;
class FirstScene;
class SecondScene;
class ThirdScene;
class FourthScene;
class EndingPortrait;
class EndingLevel : public GameEngineLevel
{
public:
	// construtor destructor
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	Ending* GetOliveEnding()
	{
		return &OliveEnding;
	}

	Olive* GetAcOlive()
	{
		return AcOlive;
	}

protected:


private:
	float Time = 0;
	Olive* AcOlive = nullptr;

	Ending OliveEnding = Ending::Null;

	FirstScene* AcFirstScene = nullptr;
	SecondScene* AcSecondScene = nullptr;
	ThirdScene* AcThirdScene = nullptr;
	FourthScene* AcFourthScene = nullptr;

	EndingPortrait* AcEndingPortrait = nullptr;
	

	void ImageLoad();
	void SoundLoad();

	int EstimateGrade(float _Estimate);
	float EstimateMaxMinusMin();
	float EstimateMax();
	float EstimateMin();
};

