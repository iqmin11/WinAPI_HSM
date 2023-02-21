#pragma once
#include <vector>
#include "GlobalButton.h"
#include "MenuFrame.h"

class SelectionMenu : public MenuFrame
{
public:
	// construtor destructor
	SelectionMenu();
	~SelectionMenu();

	// delete Function
	SelectionMenu(const SelectionMenu& _Other) = delete;
	SelectionMenu(SelectionMenu&& _Other) noexcept = delete;
	SelectionMenu& operator=(const SelectionMenu& _Other) = delete;
	SelectionMenu& operator=(SelectionMenu&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

protected:
	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);
	
	void SetSelectionMenu(int _Count, float4 _Pos, float _xScale, int _ActorOrder, int _RenderOrder);
	void SetSelectionMenu(int _Count, float4 _Pos, float _xScale, PM2ActorOrder _ButtonActorOrder, PM2RenderOrder _ButtonRenderOrder);

	std::vector<GlobalButton*>& GetSelectButtons()
	{
		return SelectButtons;
	}

	void SetButtonString(int _RenderOrder, int _ButtonIndex, const std::string_view& _Text);

private:
	std::vector<GlobalButton*> SelectButtons = std::vector<GlobalButton*>();

	int CountButton = 0;

	std::vector<GameEngineRender*> StringRenders = std::vector<GameEngineRender*>();
	std::vector<GameEngineRender*> StringShadowRenders = std::vector<GameEngineRender*>();
	std::vector<GameEngineRender*> StringHoverRenders = std::vector<GameEngineRender*>();
	std::vector<std::string> ButtonStrings = std::vector<std::string>();
	
};

