#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Date.h"
#include "ContentsEnums.h"

class Olive;
class Background;
class Flower;
class Paint;

class UIManager;

class CubeDialog;
class ScheduleDialog;
class Button;

class DanceClass;
class FencingClass;
class FightingClass;
class MagicClass;
class PaintingClass;
class PoetryClass;
class ProtocolClass;
class ScienceClass;
class StrategyClass;
class TheologyClass;

class RaisingSimLevel : public GameEngineLevel
{
public:
	DanceClass* AcDanceClass = nullptr;
	FencingClass* AcFencingClass = nullptr;
	FightingClass* AcFightingClass = nullptr;
	MagicClass* AcMagicClass = nullptr;
	PaintingClass* AcPaintingClass = nullptr;
	PoetryClass* AcPoetryClass = nullptr;
	ProtocolClass* AcProtocolClass = nullptr;
	ScienceClass* AcScienceClass = nullptr;
	StrategyClass* AcStrategyClass = nullptr;
	TheologyClass* AcTheologyClass = nullptr;

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
		Today.SetDate(_Today.GetYear(), _Today.GetMonth(), _Today.GetDay());
	}

	Date& GetToday()
	{
		return Today;
	}

	void GoToNextDay()
	{
		++Today;
	}

	static CubeDialog* GetAcCubeDialog()
	{
		return AcCubeDialog;
	}

	static ScheduleDialog* GetAcScheduleDialog()
	{
		return AcScheduleDialog;
	}

	UIManager* GetUIManager()
	{
		return AcUIManager;
	}

protected:


private:
	Olive* AcOlive = nullptr;
	Date Today = {1000,10,10};

	static CubeDialog* AcCubeDialog;
	static ScheduleDialog* AcScheduleDialog;
	Background* AcBackground = nullptr;
	Flower* AcFlower = nullptr; 
	Paint* AcPaint= nullptr; 
	UIManager* AcUIManager = nullptr;

	
	float Time = 0;


	void SoundLoad();
	void ImageLoad();

	void GoToBeforBirthDay();
	void OliveAllStatMax();
	void OliveAllStatMaxExeptSin();
	void OliveStateChange();
};