#include "GaugeRenderObject.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineActor.h>

GaugeRenderObject::GaugeRenderObject()
{

}

GaugeRenderObject::~GaugeRenderObject()
{

}

void GaugeRenderObject::SetGaugeRender(int _Order, StatusName _Name,int _MaxValue)
{
	Name = _Name;

	GameEngineActor* Actor = GetOwner<GameEngineActor>();
	StatusGaugeFrameRender_Layer1 = Actor->CreateRender("StatusGaugeFrame_Layer1.bmp",_Order);
	StatusGaugeFrameRender_Layer1->SetScaleToImage();
	StatusGaugeEmptyRender = Actor->CreateRender("StatusGauge.bmp", _Order + 1);
	StatusGaugeEmptyRender->SetFrame(1);
	StatusGaugeEmptyRender->SetScale({ 110, 14 });
	StatusGaugeEmptyRender->SetPosition({ 55.0f, -1.0 });
	StatusGaugeRender = Actor->CreateRender("StatusGauge.bmp", _Order + 2);
	StatusGaugeRender->SetFrame(0);
	StatusGaugeRender->SetScale({ 110, 14 });
	StatusGaugeRender->SetPosition({ -55.0f, -1.0 });
	StatusGaugeFrameRender_Layer2= Actor->CreateRender("StatusGaugeFrame_Layer2.bmp", _Order + 3);
	StatusGaugeFrameRender_Layer2->SetScaleToImage();
	Max = _MaxValue;

	//StatusValueRender.SetOwner(Actor);
	//StatusValueRender.SetImage("Num_Status.bmp", { 10, 20 }, _Order + 4, RGB(0, 0, 0)); // 숫자 리소스 나중에 편집
	//StatusValueRender.SetAlign(Align::Right);
	//StatusValueRender.SetValue(static_cast<int>(StatusValue));
	//StatusValueRender.SetMove({ 0,0 });
}

void GaugeRenderObject::SetValue(float _Value)
{
	if (Min > _Value || Max < _Value)
	{
		MsgAssert("범위를 초과하는 값을 입력하였습니다.")
	}
	
	if (0 >= _Value)
	{
		StatusGaugeEmptyRender->Off();
	}
	else
	{
		StatusGaugeEmptyRender->On();
	}

	StatusValue = _Value;
	//StatusValueRender.SetValue(static_cast<int>(StatusValue));
	StatusGaugeRender->SetPosition(float4::LerpClamp(StatusGaugeRender->GetPosition(), StatusGaugeEmptyRender->GetPosition(), _Value / (Max - Min)));
}

void GaugeRenderObject::SetMove(float4 _Move)
{
	StatusGaugeFrameRender_Layer1->SetMove(_Move);
	StatusGaugeEmptyRender->SetMove(_Move);
	StatusGaugeRender->SetMove(_Move);
	StatusGaugeFrameRender_Layer2->SetMove(_Move);
	//StatusValueRender.SetMove(_Move);
}

void GaugeRenderObject::SetPosition(float4 _Position)
{
	StatusGaugeFrameRender_Layer1->SetPosition(_Position);
	StatusGaugeEmptyRender->SetPosition(_Position + (float4::Right * 55.0f));
	StatusGaugeRender->SetPosition(_Position + (float4::Left * 55.0f));
	StatusGaugeFrameRender_Layer2->SetPosition(_Position);
	//StatusValueRender.SetPosition(_Position);
}




