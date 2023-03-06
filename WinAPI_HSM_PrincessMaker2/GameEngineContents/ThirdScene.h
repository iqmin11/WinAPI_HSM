#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class ThirdScene : public GameEngineActor
{
public:
	// construtor destructor
	ThirdScene();
	~ThirdScene();

	// delete Function
	ThirdScene(const ThirdScene& _Other) = delete;
	ThirdScene(ThirdScene&& _Other) noexcept = delete;
	ThirdScene& operator=(const ThirdScene& _Other) = delete;
	ThirdScene& operator=(ThirdScene&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 400, 300 };
	GameEngineRender* BackgroundRedner = nullptr;

	GameEngineRender* TextRender = nullptr;
	int TextHeight = 20;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 800,200 };
	float4 TextRenderPos = { -300,-200 };

	GameEngineRender* TextRenderShadow = nullptr;
	COLORREF TextShadowColor = RGB(0, 0, 0);
	float4 TextShadowRenderPos = { -300,-199 };

	std::string Script = "아무튼, 저도 어른이 되었어요.\n\n지금까지 무엇을 하든 아버지에게 기대기만 했지만,\n\n오늘부터는 저 자신의 힘으로 살아가겠어요.\n\n지금까지의 경험을 살려서 열심히 할 테니,\n\n따뜻하게 지켜봐 주세요.";
};

