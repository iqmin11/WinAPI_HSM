#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class OpeningCredit;
class Cutscene;
class UpperDialog;
class BottomDialog;
class Caption;
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
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {};
protected:


private:
	Caption* AcCaption = nullptr;
	Cutscene* AcCutScene = nullptr;
	UpperDialog* AcUpperDialog = nullptr;
	BottomDialog* AcBottomDialog = nullptr;
	OpeningCredit* AcOpeningCredit = nullptr;
	float Time = 0.0f;

	void SoundLoad();
	void ImageLoad();
};

