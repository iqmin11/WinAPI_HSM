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
	void SetUpdateText(const std::string_view& _Text);
	void SetDialogScale(const float4& _Scale)
	{
		DialogFrameScale = _Scale;
		SetMenuFrameScale(DialogFrameScale);
		TextBoxScale = _Scale - float4{20, 20};
		SetTextRender();
	}

	bool IsRenderEnd()
	{
		return RenderEnd;
	}

	std::string_view GetUpdateText() const
	{
		return UpdateText;
	}

	void Off();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	bool IsMugShot = false; //머그샷 없는 대화창, 있는대화창
	int MugShotLoc = -1; // 왼쪽 또는 오른쪽
	GameEngineRender* MugShotFrame = nullptr;
	GameEngineRender* MugShot = nullptr;

	float4 DialogFrameScale = { 310,150 };

	//std::string PrevText = std::string();
	std::string UpdateText = std::string();
	std::string RenderText = std::string();

	GameEngineRender* TextRender = nullptr;
	
	int TextHeight = 18;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 290,130 };

	float Time = 0;
	size_t RenderLen = 1;
	bool RenderEnd = false;

	void SetTextRender();
	void SetTextRenderPos(float4 _Pos);
	void SetRightMugDialog(); // 머그샷이 오른쪽에 있는 대화창
	void SetLeftMugDialog(); // 머그샷이 왼쪽에 있는 대화창
	void SetMoveMugShotRender(const float4& _Move);
	void SetPosMugShotRender(const float4& _Pos);
	void InitRenderPos();
};