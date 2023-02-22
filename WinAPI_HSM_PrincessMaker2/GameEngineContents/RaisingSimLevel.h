#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Date.h"
#include "ContentsEnums.h"

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
class DietFinalConfirmSelectionMenu;

class ScheduleCalendar;
class ScheduleSelectionMenu;

class CubeDialog;
class Button;
class IconButton;
class RaisingSimLevel : public GameEngineLevel
{
public:
	

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

	static CubeDialog* GetAcCubeDialog()
	{
		return AcCubeDialog;
	}

	static DietFinalConfirmSelectionMenu* GetAcDietFinalConfirmSelectionMenu()
	{
		return AcDietFinalConfirmSelectionMenu;
	}

protected:


private:
	Olive* AcOlive = nullptr;
	Date Today = {1000,10,10};

	static MainMenu* AcMainMenu;
	static BasicStatusWindow* AcBasicStatusWindow;
	static EstimateStatusWindow* AcEstimateStatusWindow;
	static FighterAndMagicalStatusWindow* AcFighterAndMagicalStatusWindow;
	static SocialAndHouseworkStatusWindow* AcSocialAndHouseworkStatusWindow;
	
	static ConverstionSelectionMenu* AcConverstionSelectionMenu;
	
	static DietSelectionMenu* AcDietSelectionMenu;
	static DietFinalConfirmSelectionMenu* AcDietFinalConfirmSelectionMenu;

	static ScheduleCalendar* AcScheduleCalendar;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;

	static CubeDialog* AcCubeDialog;
	Background* AcBackground = nullptr;
	Flower* AcFlower = nullptr; 
	Paint* AcPaint= nullptr; 
	IconButton* TestIconButton = nullptr;

	void ESCdown();

	static void ClickStatusWindowButton(Button* _Button);
	
	static void ClickConversationButton(Button* _Button);
	
	static void ClickDietButton(Button* _Button);
	
	static void ClickScheduleButton(Button* _Button);
	
	static void ClickDiet_0(Button* _Button);
	static void ClickDiet_1(Button* _Button);
	static void ClickDiet_2(Button* _Button);
	static void ClickDiet_3(Button* _Button);
	static void ClickDietFinalConfirm_0(Button* _Button);
	static void ClickDietFinalConfirm_1(Button* _Button);
	static Diet DietSetConfirm;

	void SoundLoad();
	void ImageLoad();
	void ButtonAndKeyLoad();
};