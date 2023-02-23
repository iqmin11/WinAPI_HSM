#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include "ContentsEnums.h"

class MainMenu;
class StatusWindowManager;

class ConverstionSelectionMenu;
class DietSelectionMenu;
class DietFinalConfirmSelectionMenu;
class PersonalInformationWindow;
class HelthInformationWindow;
class PhysicalStatusWindow;

class ScheduleCalendar;
class ScheduleSelectionMenu;
class ClassSelectWindow;
class CubeDialog;

class MenuManager : public GameEngineActor
{
public:
	// construtor destructor
	MenuManager();
	~MenuManager();

	// delete Function
	MenuManager(const MenuManager& _Other) = delete;
	MenuManager(MenuManager&& _Other) noexcept = delete;
	MenuManager& operator=(const MenuManager& _Other) = delete;
	MenuManager& operator=(MenuManager&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:

	void SetButtonAndKey();
	void SetEngineRightClick();

	static MainMenu* AcMainMenu;
	static void ClickMainMenu_00(Button* _Button); // �������ͽ� â
	static void ClickMainMenu_01(Button* _Button); // ��ȭâ

	static Diet DietSetConfirm;
	static void ClickMainMenu_02(Button* _Button); // �Ĵ�
	static void ClickMainMenu_02_0(Button* _Button); // �Ĵ� : ����
	static void ClickMainMenu_02_1(Button* _Button); // �Ĵ� : ưư
	static void ClickMainMenu_02_2(Button* _Button); // �Ĵ� : ����
	static void ClickMainMenu_02_3(Button* _Button); // �Ĵ� : ���̾�Ʈ
	static void ClickMainMenu_02_0_0(Button* _Button); // �Ĵ� : �̹�ħ����
	static void ClickMainMenu_02_0_1(Button* _Button); // �Ĵ� : ����
	static void ClickMainMenu_03(Button* _Button);
	//static void ClickMainMenu_10();
	//static void ClickMainMenu_11();
	//static void ClickMainMenu_12();
	//static void ClickMainMenu_13();
	static void ClickMainMenu_S(Button* _Button); // ������ â
	static void ClickMainMenu_S_0(Button* _Button); // ���� �ܷ��Ѵ�


	static StatusWindowManager* AcStatusWindowManager;

	static ConverstionSelectionMenu* AcConverstionSelectionMenu;

	static DietSelectionMenu* AcDietSelectionMenu;
	static DietFinalConfirmSelectionMenu* AcDietFinalConfirmSelectionMenu;

	static PersonalInformationWindow* AcPersonalInformationWindow;
	static HelthInformationWindow* AcHelthInformationWindow;
	static PhysicalStatusWindow* AcPhysicalStatusWindow;

	static ScheduleCalendar* AcScheduleCalendar;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;
	static ClassSelectWindow* AcClassSelectWindow;

	static CubeDialog* AcCubeDialog;

};

