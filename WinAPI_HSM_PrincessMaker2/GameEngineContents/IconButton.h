#pragma once
#include "MenuFrame.h"
#include <GameEngineCore/NumberRenderObject.h>
#include "GlobalButton.h"
#include "ContentsEnums.h"

class GameEngineRender;
class IconButton : public MenuFrame
{
public:
	// construtor destructor
	IconButton();
	~IconButton();

	// delete Function
	IconButton(const IconButton& _Other) = delete;
	IconButton(IconButton&& _Other) noexcept = delete;
	IconButton& operator=(const IconButton& _Other) = delete;
	IconButton& operator=(IconButton&& _Other) noexcept = delete;

	void SetPos(const float4& _Pos);

	void SetIconButton(IconCode _IconCode, const std::string_view& _Name, const std::string_view& _Difficulty, int _Price, const float4& _Pos);
	GlobalButton* GetButton() const
	{
		return Button;
	}

	void On() override;
	void Off() override;

protected:
	void Start() override;

private:
	float4 ButtonScale = { 160, 52 };
	GlobalButton* Button = nullptr;
	
	GameEngineRender* IconRender = nullptr;
	IconCode ICode = IconCode::Null;
	float4 IconScale = { 40, 40 };
	float4 IconPos = { -50, 0 };
	
	GameEngineRender* NameRender = nullptr;
	std::string Name = std::string();
	float4 NameBoxScale = { 90, 20 };
	float4 NamePos = { -20, -20 };

	GameEngineRender* DifficultyRender = nullptr;
	std::string Difficulty = std::string();
	float4 DifficultyBoxScale = { 90, 20 };
	float4 DifficultyPos = { -20, 0 };

	int TextHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(255, 255, 255);

	NumberRenderObject PriceRender = NumberRenderObject();
	int Price = 30;
	float4 PriceRenderPos = { 38,8 };
	float4 PriceRenderScale = { 10,20 };
	
	GameEngineRender* Alphabet_G = nullptr;
	float4 Alphabet_GPos = { 48,8 };

};

