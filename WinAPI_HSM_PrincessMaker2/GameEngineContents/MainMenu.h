#pragma once
#include <GameEngineCore/GameEngineActor.h>
class GameEngineRender;
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	GameEngineRender* MainMenuRender = nullptr;


};

