#pragma once
#include <GameEngineCore/GameEngineObject.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnums.h"

enum class GaugeFrameStyle
{
	Null = -1,
	Nomal,
	Estemate,
	Detail,
	Physical
};

class GameEngineActor;
class GaugeRenderObject : public GameEngineObject
{
public:
	// construtor destructor
	GaugeRenderObject();
	~GaugeRenderObject();

	// delete Function
	GaugeRenderObject(const GaugeRenderObject& _Other) = delete;
	GaugeRenderObject(GaugeRenderObject&& _Other) noexcept = delete;
	GaugeRenderObject& operator=(const GaugeRenderObject& _Other) = delete;
	GaugeRenderObject& operator=(GaugeRenderObject&& _Other) noexcept = delete;

	void SetGaugeRender(int _Order, const std::string_view& _Name, float _MaxValue, GaugeFrameStyle _Style);
	void UpdateValue(float _Value);
	void SetMove(float4 _Move);
	void SetPosition(float4 _Pos);
	void SetMin(float _Min)
	{
		Min = _Min;
	}

	void SetMax(float _Max)
	{
		Max = _Max;
	}

	void SetNameRender(const std::string_view& _Name);
	
	

protected:


private:
	float Min = 0;
	float Max = 0;
	float StatusValue = 0;

	float4 StartPos = float4::Zero;
	float4 EndPos = float4::Zero;

	GaugeFrameStyle Style = GaugeFrameStyle::Null;
	
	std::string Name = std::string();
	GameEngineRender* NameRender = nullptr;
	int TextHeight = 19;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(255, 255, 255);
	float4 TextBoxScale = { 80,20 };
	float4 TextRenderPos = { -70,0 };

	GameEngineRender* StatusGaugeFrameRender_Layer1 = nullptr;
	GameEngineRender* StatusGaugeEmptyRender = nullptr;
	GameEngineRender* StatusGaugeRender = nullptr;
	GameEngineRender* StatusGaugeFrameRender_Layer2 = nullptr;
	NumberRenderObject StatusValueRender = NumberRenderObject();
	GameEngineRender* DemicalPoint = nullptr;
	NumberRenderObject StatusValueDemicalRender = NumberRenderObject();

};

