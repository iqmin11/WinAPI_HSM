#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include "ContentsEnums.h"

class RaisingSimLevel;

class MainMenu;
class StatusWindowManager;

class ConverstionSelectionMenu;
class DietSelectionMenu;
class SelectDialog;
class DietFinalConfirmSelectionMenu;
class PersonalInformationWindow;
class HelthInformationWindow;
class PhysicalStatusWindow;

class ScheduleCalendar;
class ScheduleSelectionMenu;
//class ScheduleAnimationPlayer;
class ClassSelectWindow;
class SchedulingConfirmSelectionMenu;
class ScheduleFinalConfirm;
class SchedulePlayer;
class ScheduleDialog;

class CubeDialog;

class UIManager : public GameEngineActor
{
public:
	// construtor destructor
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;
	
	MainMenu* GetMainmenu() const
	{
		return AcMainMenu;
	}
	
	ScheduleCalendar* GetScheduleCalendar() const
	{
		return AcScheduleCalendar;
	}
	

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static RaisingSimLevel* ParentLevel;

	void SetButtonAndKey();
	void SetEngineRightClick();

	static MainMenu* AcMainMenu;
	static void ClickMainMenu_00(Button* _Button); // 스테이터스 창
	static void ClickMainMenu_01(Button* _Button); // 대화창

	static Diet DietSetConfirm;
	static void ClickMainMenu_02(Button* _Button); // 식단
	static void ClickMainMenu_02_0(Button* _Button); // 식단 : 무난
	static void ClickMainMenu_02_1(Button* _Button); // 식단 : 튼튼
	static void ClickMainMenu_02_2(Button* _Button); // 식단 : 얌전
	static void ClickMainMenu_02_3(Button* _Button); // 식단 : 다이어트
	static void ClickMainMenu_02_0_0(Button* _Button); // 식단 : 이방침으로
	static void ClickMainMenu_02_0_1(Button* _Button); // 식단 : ㄴㄴ
	static void ClickMainMenu_03(Button* _Button);
	//static void ClickMainMenu_10(Button* _Button);
	//static void ClickMainMenu_11(Button* _Button);
	//static void ClickMainMenu_12(Button* _Button);
	//static void ClickMainMenu_13(Button* _Button);
	
	static ScheduleLabel ScheduleSetConfirm;
	static void ClickMainMenu_S(Button* _Button); // 스케줄 창
	static void ClickMainMenu_S_0(Button* _Button); // 딸을 단련한다
	static void ClickMainMenu_S_0_0(Button* _Button); // 미술
	//static void ClickMainMenu_S_0_1(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_2(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_3(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_4(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_5(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_6(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_7(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_8(Button* _Button); // 딸을 단련한다
	//static void ClickMainMenu_S_0_9(Button* _Button); // 딸을 단련한다
	static void ClickMainMenu_S_0_0_0(Button* _Button); // 스케줄에 편성한다
	static void ClickMainMenu_S_0_0_1(Button* _Button); // 취소
	static void ClickMainMenu_S_0_0_0_0(Button* _Button); // 스케줄 실행
	static void ClickMainMenu_S_0_0_0_1(Button* _Button); // 취소


	std::list<GameEngineActor*> AllMenu = std::list<GameEngineActor*>();
	bool IsAnyMenuUpdate();

	static StatusWindowManager* AcStatusWindowManager;

	static ConverstionSelectionMenu* AcConverstionSelectionMenu;

	static DietSelectionMenu* AcDietSelectionMenu;
	static SelectDialog* AcSelectDialog;
	static DietFinalConfirmSelectionMenu* AcDietFinalConfirmSelectionMenu;

	static PersonalInformationWindow* AcPersonalInformationWindow;
	static HelthInformationWindow* AcHelthInformationWindow;
	static PhysicalStatusWindow* AcPhysicalStatusWindow;

	static ScheduleCalendar* AcScheduleCalendar;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;
	static ClassSelectWindow* AcClassSelectWindow;
	//static ScheduleAnimationPlayer* AcScheduleAnimationPlayer;
	static SchedulingConfirmSelectionMenu* AcSchedulingConfirmSelectionMenu;
	static ScheduleFinalConfirm* AcScheduleFinalConfirm;
	static SchedulePlayer* AcSchedulePlayer;
	static ScheduleDialog* AcScheduleDialog;

	static CubeDialog* AcCubeDialog;

};

