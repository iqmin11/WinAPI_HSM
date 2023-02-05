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

	//void SetSelectionMenu(const float4& _pos, const float4& _Size, const int _style, int _Count);
	void SetSelection(int _Count, int _Order);
	//void CreateSelectionMenu(int _Order);
	//void CreateSelectionMenu(PM2RenderOrder _Order);

	const std::vector<bool> GetIsMouseCollisions()
	{
		return IsMouseCollisions;
	}



protected:
	void Start();
	void Update(float _Deltatime);
	void Render(float _Time);

private:
	std::vector<GameEngineRender*> HilightSelections = std::vector<GameEngineRender*>();
	std::vector<GameEngineCollision*> SelectionCollisions = std::vector<GameEngineCollision*>();
	std::vector<bool> IsMouseCollisions = std::vector<bool>(false);
	int CountSelection = 0;

	void CreateSelectionRender(int _Order); // 선택지 글자와 충돌시 하이라이트 셀렉션 렌더
	void CreateSelectionCollision();
	void CreateIsMouseCollisions();
};

