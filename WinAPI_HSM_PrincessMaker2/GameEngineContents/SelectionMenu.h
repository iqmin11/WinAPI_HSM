#pragma once
#include <vector>
#include "MenuFrame.h"
class GameEngineRender;
class GameEngineCollision;
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

	const std::vector<bool> GetIsMouseCollisions()
	{
		return IsMouseCollisions;
	}

protected:
	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);
	
	void SetButton(int _Count, int _Order);
	void SetButton(int _Count, PM2RenderOrder _Order);

private:
	std::vector<GameEngineRender*> HilightButton = std::vector<GameEngineRender*>();
	std::vector<GameEngineCollision*> ButtonCollisions = std::vector<GameEngineCollision*>();
	std::vector<bool> IsMouseCollisions = std::vector<bool>(false);
	int CountButton = 0;
};

