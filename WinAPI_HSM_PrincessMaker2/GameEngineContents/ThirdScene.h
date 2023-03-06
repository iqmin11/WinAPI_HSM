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
	std::string TextType = "����";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 800,200 };
	float4 TextRenderPos = { -300,-200 };

	GameEngineRender* TextRenderShadow = nullptr;
	COLORREF TextShadowColor = RGB(0, 0, 0);
	float4 TextShadowRenderPos = { -300,-199 };

	std::string Script = "�ƹ�ư, ���� ��� �Ǿ����.\n\n���ݱ��� ������ �ϵ� �ƹ������� ���⸸ ������,\n\n���ú��ʹ� �� �ڽ��� ������ ��ư��ھ��.\n\n���ݱ����� ������ ����� ������ �� �״�,\n\n�����ϰ� ���Ѻ� �ּ���.";
};

