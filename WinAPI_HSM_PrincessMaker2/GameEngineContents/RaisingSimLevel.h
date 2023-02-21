#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Date.h"

class Olive;
class Background;
class Flower;
class Paint;

class MainMenu;

class BasicStatusWindow;
class EstimateStatusWindow;
class FighterAndMagicalStatusWindow;
class SocialAndHouseworkStatusWindow;

class ConverstionSelectionMenu;
class DietSelectionMenu;

class CubeDialog;
class Button;
class RaisingSimLevel : public GameEngineLevel
{
public:
	static CubeDialog* AcCubeDialog;

	// construtor destructor
	RaisingSimLevel();
	~RaisingSimLevel();

	// delete Function
	RaisingSimLevel(const RaisingSimLevel& _Other) = delete;
	RaisingSimLevel(RaisingSimLevel&& _Other) noexcept = delete;
	RaisingSimLevel& operator=(const RaisingSimLevel& _Other) = delete;
	RaisingSimLevel& operator=(RaisingSimLevel&& _Other) noexcept = delete;

	void Loading() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	void SetToday(Date _Today)
	{
		Today = _Today;
	}

	Date& GetToday()
	{
		return Today;
	}

protected:


private:
	Olive* AcOlive = nullptr;
	Date Today = Date();

	static MainMenu* AcMainMenu;
	static BasicStatusWindow* AcBasicStatusWindow;
	static EstimateStatusWindow* AcEstimateStatusWindow;
	static FighterAndMagicalStatusWindow* AcFighterAndMagicalStatusWindow;
	static SocialAndHouseworkStatusWindow* AcSocialAndHouseworkStatusWindow;
	
	static ConverstionSelectionMenu* AcConverstionSelectionMenu;
	static DietSelectionMenu* AcDietSelectionMenu;

	Background* AcBackground = nullptr;
	Flower* AcFlower = nullptr; 
	Paint* AcPaint= nullptr; 

	static void ClickStatusWindowButton(Button* _Button);
	static void ClickConversationButton(Button* _Button);
	static void ClickDietButton(Button* _Button);
	
	void SoundLoad();
	void ImageLoad();
	void ButtonAndKeyLoad();
};

