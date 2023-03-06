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
	std::string TextType = "����";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 800,200 };
	float4 TextRenderPos = { -300,-200 };

	GameEngineRender* TextRenderShadow = nullptr;
	COLORREF TextShadowColor = RGB(0, 0, 0);
	float4 TextShadowRenderPos = { -300,-199 };

	std::string Script = "�ƹ���.\n\n�׵��� ���� �������� Ű���ּż� ������.\n\n���� �ƹ����� ������, �̷��� �Ǹ��ϰ� �����߾��.\n\n�ƹ����� �Բ��� �ҳ� ������ �ǵ��ƺ��� ���������� ���ö��.\n\n��� �Բ� �����Ѱ͵� ��ſ� �߾��̿���.\n\n���� ������ �ϰ� ���༭ �����ϰ� �־��.";

};



