#pragma once
#include <vector>
#include <string>

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnums.h"

class GameEngineRender;
class BasicInfo : public GameEngineActor
{
public:
	// construtor destructor
	BasicInfo();
	~BasicInfo();

	// delete Function
	BasicInfo(const BasicInfo& _Other) = delete;
	BasicInfo(BasicInfo&& _Other) noexcept = delete;
	BasicInfo& operator=(const BasicInfo& _Other) = delete;
	BasicInfo& operator=(BasicInfo&& _Other) noexcept = delete;

	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	float4 ActorPos = { 700, 109 };

	std::string OliveFirstName = "SeungMin";
	std::string OliveLastName = "Hwang";
	int Age = 0; // 이건 올리브
	Zodiac Star = Zodiac::Null; // 이건 올리브
	int Gold = 0; // 이건 올리브
	float Height = 0.0f; // 이건 올리브
	float Weight = 0.0f; // 이건 올리브
	float Bust = 0.0f; // 이건 올리브
	float Waist = 0.0f; // 이건 올리브
	float Hip = 0.0f; // 이건 올리브

	GameEngineRender* BasicInfoFrame = nullptr;
	
	GameEngineRender* FirstNameRender = nullptr;
	float4 FirstNameRenderPos = { -90, -98 };
	GameEngineRender* LastNameRender = nullptr;
	float4 LastNameRenderPos = { -90, -75 };

	int TextHeight = 20;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 180,20 };

	NumberRenderObject AgeRender = NumberRenderObject();
	NumberRenderObject GoldRender = NumberRenderObject();
	NumberRenderObject HeightRender = NumberRenderObject();
	NumberRenderObject WeightRender = NumberRenderObject();
	NumberRenderObject BustRender = NumberRenderObject();
	NumberRenderObject WaistRender = NumberRenderObject();
	NumberRenderObject HipRender = NumberRenderObject();

	GameEngineRender* StarRender = nullptr;
};

