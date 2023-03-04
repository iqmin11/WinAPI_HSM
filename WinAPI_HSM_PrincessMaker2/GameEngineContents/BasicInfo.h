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

	GameEngineRender* BasicInfoFrame = nullptr;
	
	std::string OliveFirstName = "Null";
	GameEngineRender* FirstNameRender = nullptr;
	float4 FirstNameRenderPos = { -90, -98 };
	std::string OliveLastName = "Null";
	GameEngineRender* LastNameRender = nullptr;
	float4 LastNameRenderPos = { -90, -75 };
	int TextHeight = 20;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 180,20 };

	PatronGod OlivePatronGod = PatronGod::Null; 
	GameEngineRender* PatronGodIconRender = nullptr;
	float4 PatronGodIconPos = { -30,-22 };
	float4 IconScale = { 39, 39 };

	BloodType OliveBloodType = BloodType::Null;
	GameEngineRender* BloodTypeRender = nullptr;
	float4 BloodTypeRenderPos = { -30,-22 };
	float4 BloodTypeRenderScale = { 39,39 };

	int Age = 0; 
	NumberRenderObject AgeRender = NumberRenderObject();
	float4 AgeRenderPos = { -70,-20 };
	float4 AgeRenderScale = { 20, 20 };

	int Gold = 0; 
	NumberRenderObject GoldRender = NumberRenderObject();
	float4 GoldRenderPos = { 65,-12 };
	float4 GoldRenderScale = { 10, 19 };

	Diet OliveDiet = Diet::무리하지_않는다;
	GameEngineRender* OliveDietRender = nullptr;
	std::string DietRenderText = std::string();
	void SetDietRenderText()
	{
		switch (OliveDiet)
		{
		case Diet::무리하지_않는다:
			DietRenderText = "무리하지 않는다";
			break;
		case Diet::어쨌든_튼튼하게:
			DietRenderText = "어쨌든 튼튼하게";
			break;
		case Diet::얌전한_아이로:
			DietRenderText = "얌전한 아이로";
			break;
		case Diet::다이어트_시킨다:
			DietRenderText = "다이어트 시킨다";
			break;
		default:
			break;
		}
	}
	float4 OliveDietRenderPos = {-90, 56 };

	float Height = 0.0f; 
	NumberRenderObject HeightRender = NumberRenderObject();
	float4 HeightRenderPos = { -75, 89 };
	float4 HeightRenderScale = { 10, 20 };

	float Weight = 0.0f; 
	NumberRenderObject WeightRender = NumberRenderObject();
	float4 WeightRenderPos = { -35, 89 };
	float4 WeightRenderScale = { 10, 20 };

	float Bust = 0.0f; 
	NumberRenderObject BustRender = NumberRenderObject();
	float4 BustRenderPos = { -5, 89 };
	float4 BustRenderScale = { 10, 20 };

	float Waist = 0.0f; 
	NumberRenderObject WaistRender = NumberRenderObject();
	float4 WaistRenderPos = { 37, 89 };
	float4 WaistRenderScale = { 10, 20 };

	float Hip = 0.0f; 
	NumberRenderObject HipRender = NumberRenderObject();
	float4 HipRenderPos = { 79, 89 };
	float4 HipRenderScale = { 10, 20 };

	bool DiseaseState = false;
	GameEngineRender* DiseaseIcon = nullptr;
	float4 DiseaseIconPos = { 0,27 };

	bool DelinquentState = false;
	GameEngineRender* DelinquentIcon = nullptr;
	float4 DelinquentIconPos = { 40,27 };
};


