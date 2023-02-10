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

	void SetGaugeRender(int _Order, StatusName _Name, int _MaxValue, GaugeFrameStyle _Style);
	void SetValue(float _Value);
	void SetMove(float4 _Move);
	void SetPosition(float4 _Pos);

	StatusName GetStatusName() const
	{
		return Name;
	}

protected:


private:
	StatusName Name = StatusName::Null;
	const int Min = 0;
	int Max = 0;
	float StatusValue = 12;

	GaugeFrameStyle Style = GaugeFrameStyle::Null;
	
	GameEngineRender* StatusGaugeFrameRender_Layer1 = nullptr;
	GameEngineRender* StatusGaugeEmptyRender = nullptr;
	GameEngineRender* StatusGaugeRender = nullptr;
	GameEngineRender* StatusGaugeFrameRender_Layer2 = nullptr;
	NumberRenderObject StatusValueRender = NumberRenderObject();
};

