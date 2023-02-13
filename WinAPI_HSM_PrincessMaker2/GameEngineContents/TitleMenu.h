#pragma once
#include "SelectionMenu.h"
#include "GaugeRenderObject.h"

class TitleMenu : public SelectionMenu
{
public:
	// construtor destructor
	TitleMenu();
	~TitleMenu();

	// delete Function
	TitleMenu(const TitleMenu& _Other) = delete;
	TitleMenu(TitleMenu&& _Other) noexcept = delete;
	TitleMenu& operator=(const TitleMenu& _Other) = delete;
	TitleMenu& operator=(TitleMenu&& _Other) noexcept = delete;

protected:
	void Start() override;


private:
	GameEngineRender* TextRender = nullptr;

	static void LevelChangeToFirstSet();
	static void LevelChangeToOpening();
	static void LevelChangeToRaisingSim();
};

