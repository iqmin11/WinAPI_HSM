#pragma once
#include "StatusWindow.h"
class SocialAndHouseworkStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	SocialAndHouseworkStatusWindow();
	~SocialAndHouseworkStatusWindow();

	// delete Function
	SocialAndHouseworkStatusWindow(const SocialAndHouseworkStatusWindow& _Other) = delete;
	SocialAndHouseworkStatusWindow(SocialAndHouseworkStatusWindow&& _Other) noexcept = delete;
	SocialAndHouseworkStatusWindow& operator=(const SocialAndHouseworkStatusWindow& _Other) = delete;
	SocialAndHouseworkStatusWindow& operator=(SocialAndHouseworkStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = { 670, 455 };

	float Decorum = 0;
	GaugeRenderObject* DecorumRender = nullptr;
	float Art = 0;
	GaugeRenderObject* ArtRender = nullptr;
	float Conversation = 0;
	GaugeRenderObject* ConversationRender = nullptr;

	float Cooking = 0;
	GaugeRenderObject* CookingRender = nullptr;
	float Cleaning = 0;
	GaugeRenderObject* CleaningRender = nullptr;
	float Temperament = 0;
	GaugeRenderObject* TemperamentRender = nullptr;

	float Max = 100;

	GaugeFrameStyle Style = GaugeFrameStyle::Detail;
};

