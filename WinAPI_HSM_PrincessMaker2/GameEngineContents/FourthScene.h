#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class GameEngineRender;
class FourthScene : public GameEngineActor
{
public:
	// construtor destructor
	FourthScene();
	~FourthScene();

	// delete Function
	FourthScene(const FourthScene& _Other) = delete;
	FourthScene(FourthScene&& _Other) noexcept = delete;
	FourthScene& operator=(const FourthScene& _Other) = delete;
	FourthScene& operator=(FourthScene&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 400,300 };

	GameEngineRender* BackgroundRedner = nullptr;
	GameEngineRender* TextRender = nullptr;
	int TextHeight = 20;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(0, 0, 0);
	float4 TextBoxScale = { 800,200 };
	float4 TextRenderPos = { -400,-50 };
};

