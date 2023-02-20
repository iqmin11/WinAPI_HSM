#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class OpeningCredit;
class Cutscene;
class UpperDialog;
class BottomDialog;
class Caption;
class Logo;
class OpeningDate;
class Olive;
class OpeningLevel : public GameEngineLevel
{
public:
	// construtor destructor
	OpeningLevel();
	~OpeningLevel();

	// delete Function
	OpeningLevel(const OpeningLevel& _Other) = delete;
	OpeningLevel(OpeningLevel&& _Other) noexcept = delete;
	OpeningLevel& operator=(const OpeningLevel& _Other) = delete;
	OpeningLevel& operator=(OpeningLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
protected:


private:
	Olive* AcOlive = nullptr;
	std::string FatherName = std::string();
	
	std::string GodPicImageString = std::string();
	std::string GodName = std::string();
	bool PatronGodSex = 0;

	Caption* AcCaption = nullptr;
	Cutscene* AcCutScene = nullptr;
	UpperDialog* AcUpperDialog = nullptr;
	BottomDialog* AcBottomDialog = nullptr;
	OpeningCredit* AcOpeningCredit = nullptr;
	OpeningDate* AcOpeningDate = nullptr;
	Logo* AcLogo = nullptr;
	float Time = 0.0f;

	void SoundLoad();
	void ImageLoad();
};

