#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include "ContentsEnums.h"

class RaisingSimLevel;

class MainMenu;

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
	
	MainMenu* GetMainMenu() const
	{
		return AcMainMenu;
	}
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static RaisingSimLevel* ParentLevel;

	void SetEngineRightClick();

	static MainMenu* AcMainMenu;
	static CubeDialog* AcCubeDialog;

};

