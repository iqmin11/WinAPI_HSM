#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>

class GameEngineRender;
class GlobalButton;

class StatusWindowManager;
class ConverstionSelectionMenu;
class DietSelectionMenu;
class InformationWindowManager;

class ScheduleCalendar;
class ScheduleSelectionMenu;
class MainMenu : public GameEngineActor
{
public:
	// construtor destructor
	MainMenu();
	~MainMenu();

	// delete Function
	MainMenu(const MainMenu& _Other) = delete;
	MainMenu(MainMenu&& _Other) noexcept = delete;
	MainMenu& operator=(const MainMenu& _Other) = delete;
	MainMenu& operator=(MainMenu&& _Other) noexcept = delete;

	std::vector<std::vector<GlobalButton*>> GetMainMenuButton();
	GlobalButton* GetScheduleButton() const
	{
		return ScheduleButton;
	}

	static MainMenu* GetAcMainMenu()
	{
		return AcMainMenu;
	}
	
	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	float4 ActorPos = { 700,278 };
	GameEngineRender* MainMenuRender = nullptr;
	std::vector<std::vector<GlobalButton*>> MainMenuButtons = {};
	float4 MainMenuButtonScale = { 50,40 };
	float4 FirstButtonSetPos = { -75,-40 };

	GlobalButton* ScheduleButton = nullptr;
	float4 ScheduleButtonScale = { 200,40 };
	float4 ScheduleButtonPos = { 0,40 };

	static MainMenu* AcMainMenu;
	static StatusWindowManager* AcStatusWindowManager;
	static ConverstionSelectionMenu* AcConverstionSelectionMenu;
	static DietSelectionMenu* AcDietSelectionMenu;
	static InformationWindowManager* AcInformationWindowManager;

	//Schedule
	static ScheduleCalendar* AcScheduleCalendar;
	static ScheduleSelectionMenu* AcScheduleSelectionMenu;

	void SetMainMenuButtons();
	void SetClickButton();

	static void ClickMainMenu_01(Button* _Btn);
	static void ClickMainMenu_00(Button* _Btn);
	static void ClickMainMenu_02(Button* _Btn);
	static void ClickMainMenu_03(Button* _Btn);

	static void ClickMainMenu_S(Button* _Btn);

	//static void ClickStatusWindowButton(Button* _Btn);
};

