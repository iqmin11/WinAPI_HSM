#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"


class GameEngineRender;
class SecondScene : public GameEngineActor
{
public:
	// construtor destructor
	SecondScene();
	~SecondScene();

	// delete Function
	SecondScene(const SecondScene& _Other) = delete;
	SecondScene(SecondScene&& _Other) noexcept = delete;
	SecondScene& operator=(const SecondScene& _Other) = delete;
	SecondScene& operator=(SecondScene&& _Other) noexcept = delete;

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

	std::string Script = "아버지.\n\n그동안 저를 애지중지 키워주셔서 고마워요.\n\n저는 아버지의 지도로, 이렇게 훌륭하게 성장했어요.\n\n아버지와 함께한 소녀 시절을 되돌아보면 여러가지가 떠올라요.\n\n모두 함께 공부한것도 즐거운 추억이에요.\n\n좋은 경험을 하게 해줘서 감사하고 있어요.";

};



