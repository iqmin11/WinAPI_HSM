#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class Caption : public GameEngineActor
{
public:
	// construtor destructor
	Caption();
	~Caption();

	// delete Function
	Caption(const Caption& _Other) = delete;
	Caption(Caption&& _Other) noexcept = delete;
	Caption& operator=(const Caption& _Other) = delete;
	Caption& operator=(Caption&& _Other) noexcept = delete;

	void SetUpdateText(const std::string_view& _Text);

protected:
	void Start() override;
	void Render(float _DeltaTime) override;
private:
	std::string UpdateCaption = std::string();

	GameEngineRender* CaptionRender = nullptr;
	GameEngineRender* CaptionOutline1Render = nullptr;
	GameEngineRender* CaptionOutline2Render = nullptr;
	GameEngineRender* CaptionOutline3Render = nullptr;
	GameEngineRender* CaptionOutline4Render = nullptr;

	float4 CaptionPos = {400, 500};

	int TextHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(255, 255, 255);
	COLORREF TextOutlineColor = RGB(0, 0, 0);
	float4 CaptionTextBoxScale = { 600, 100 };
};

