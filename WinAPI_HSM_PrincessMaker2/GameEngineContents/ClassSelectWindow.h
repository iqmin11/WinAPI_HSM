#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "IconButton.h"
#include "ContentsEnums.h"
#include "Olive.h"

class RaisingSimLevel;
class Button;
class CubeDialog;
class ScheduleCalendar;
class SchedulingConfirmSelectionMenu;

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

class ClassSelectWindow : public GameEngineActor
{
public:
	// construtor destructor
	ClassSelectWindow();
	~ClassSelectWindow();

	// delete Function
	ClassSelectWindow(const ClassSelectWindow& _Other) = delete;
	ClassSelectWindow(ClassSelectWindow&& _Other) noexcept = delete;
	ClassSelectWindow& operator=(const ClassSelectWindow& _Other) = delete;
	ClassSelectWindow& operator=(ClassSelectWindow&& _Other) noexcept = delete;

	GlobalButton* GetPaintingButton() const
	{
		return Painting->GetButton();
	}

	void On() override;
	void Off() override;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static RaisingSimLevel* ParentLevel;
	CubeDialog* AcCubeDialog = nullptr;
	static ScheduleCalendar* AcScheduleCalendar;
	static SchedulingConfirmSelectionMenu* AcSchedulingConfirmSelectionMenu;
	static ClassSelectWindow* AcClassSelectWindow;

	static PaintingClass* AcPaintingClass;
	static DanceClass* AcDanceClass;
	static MagicClass* AcMagicClass;
	static ProtocolClass* AcProtocolClass;
	static FencingClass* AcFencingClass;
	static FightingClass* AcFightingClass;
	static TheologyClass* AcTheologyClass;
	static StrategyClass* AcStrategyClass;
	static ScienceClass* AcScienceClass;
	static PoetryClass* AcPoetryClass;

	IconButton* Painting = nullptr;
	float4 Button1Pos = { 540 , 400 };

	IconButton* Dance = nullptr;
	float4 Button2Pos = { 710 , 400 };

	IconButton* Magic = nullptr;
	float4 Button3Pos = { 540 , 340 };

	IconButton* Protocol = nullptr;
	float4 Button4Pos = { 710 , 340 };

	IconButton* Fencing = nullptr;
	float4 Button5Pos = { 540 , 280 };

	IconButton* Fighting = nullptr;
	float4 Button6Pos = { 710 , 280 };

	IconButton* Theology = nullptr;
	float4 Button7Pos = { 540 , 220 };

	IconButton* Strategy = nullptr;
	float4 Button8Pos = { 710 , 220 };

	IconButton* Science = nullptr;
	float4 Button9Pos = { 540 , 160 };

	IconButton* Poetry = nullptr;
	float4 Button10Pos = { 710 , 160 };

	void SetButtonClick();

	static void ClickPainting(Button* _Button);
	static void ClickDance(Button* _Button);
	static void ClickMagic(Button* _Button);
	static void ClickProtocol(Button* _Button);
	static void ClickFencing(Button* _Button);
	static void ClickFighting(Button* _Button);
	static void ClickTheology(Button* _Button);
	static void ClickStrategy(Button* _Button);
	static void ClickScience(Button* _Button);
	static void ClickPoetry(Button* _Button);
};

