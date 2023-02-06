#pragma once
#include "MenuFrame.h"
#include <GameEngineBase/GameEngineString.h>

enum class MugShotLR
{
	Non,
	Left,
	Right,
};

class Dialog : public MenuFrame
{
public:
	// construtor destructor
	Dialog();
	~Dialog();

	// delete Function
	Dialog(const Dialog& _Other) = delete;
	Dialog(Dialog&& _Other) noexcept = delete;
	Dialog& operator=(const Dialog& _Other) = delete;
	Dialog& operator=(Dialog&& _Other) noexcept = delete;

	void SetMugPic(const std::string_view& _ImageFileName);
	void SetMugLoc(int _MugLoc);
	void SetMugLoc(MugShotLR _MugLoc);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	bool IsMugShot = false; //머그샷 없는 대화창, 있는대화창
	int MugShotLoc = -1; // 왼쪽 또는 오른쪽
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;

	void SetRightMugDialog(); // 머그샷이 오른쪽에 있는 대화창
	void SetLeftMugDialog(); // 머그샷이 왼쪽에 있는 대화창
	void SetMoveMugShotRender(const float4& _Move);
	void SetPosMugShotRender(const float4& _Pos);
	void InitRenderPos();
};