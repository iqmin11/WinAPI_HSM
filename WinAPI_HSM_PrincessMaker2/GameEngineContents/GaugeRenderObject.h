#pragma once
#include <GameEngineCore/GameEngineObject.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/NumberRenderObject.h>

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

	void SetGaugeRender(int _Order, std::string_view& _Name, int _MaxValue);
	void SetValue(float _Value);

protected:


private:
	std::string StatusName = std::string();
	const int Min = 0;
	int Max = 0;
	float StatusValue = 0;
	
	GameEngineRender* StatusGaugeFrameRender_Layer1 = nullptr;
	GameEngineRender* StatusGaugeEmptyRender = nullptr;
	GameEngineRender* StatusGaugeRender = nullptr;
	GameEngineRender* StatusGaugeFrameRender_Layer2 = nullptr;
	NumberRenderObject StatusValueRender = NumberRenderObject();
};

