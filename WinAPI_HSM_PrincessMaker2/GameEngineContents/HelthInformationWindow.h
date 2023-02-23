#pragma once
#include "MenuFrame.h"
class HelthInformationWindow : public MenuFrame
{
public:
	// construtor destructor
	HelthInformationWindow();
	~HelthInformationWindow();

	// delete Function
	HelthInformationWindow(const HelthInformationWindow& _Other) = delete;
	HelthInformationWindow(HelthInformationWindow&& _Other) noexcept = delete;
	HelthInformationWindow& operator=(const HelthInformationWindow& _Other) = delete;
	HelthInformationWindow& operator=(HelthInformationWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 Scale = { 260, 184 };
	float4 ActorPos = { 154, 380 };

	float DiseaseIndex = 0; // 질병 지수
	float Delinquency = 0; // 불량화 지수
	float Popularity = 0; // 인맥

	bool DiseaseState = 0;
	bool DelinquentState = 0;

	Diet DietState = Diet::무리하지_않는다;

	GameEngineRender* interface_Disease = nullptr;
	GameEngineRender* interface_Delinquency = nullptr;
	GameEngineRender* interface_Popularity = nullptr;
	GameEngineRender* interface_DietState = nullptr;
	float4 interface_DiseasePos = { -118 , -80 };
	float4 interface_DelinquencyPos = { -118 , -57 };
	float4 interface_PopularityPos = { -118 , -34 };
	float4 interface_DietStatePos= { -118 , 58 };

	GameEngineRender* DiseaseRender = nullptr;
	GameEngineRender* DelinquencyRender = nullptr;
	GameEngineRender* PopularityRender = nullptr;
	GameEngineRender* DiseaseStateRender = nullptr;
	GameEngineRender* DelinquentStateRender = nullptr;
	GameEngineRender* DietStateRender = nullptr;
	float4 DiseaseRenderPos = { 2 , -80 };
	float4 DelinquencyRenderPos = { 2 , -57 };
	float4 PopularityRenderPos = { 2 , -34 };
	float4 DiseaseStateRenderPos = { -118 , -11 };
	float4 DelinquentStateRenderPos = { -118 , 12 };
	float4 DietStateRenderPos = { -78 , 58 };


	int TextHeight = 18;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale1 = { 160,20 };
	float4 TextBoxScale2 = { 60,20 };
	
	void UpdateHelthInformationWindow();

};

