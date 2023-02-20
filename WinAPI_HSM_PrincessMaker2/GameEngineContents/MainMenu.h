#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GameEngineRender;
class GlobalButton;
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

	void SetMainMenuButtons();
	//static void ClickStatusWindowButton(Button* _Btn);
};

