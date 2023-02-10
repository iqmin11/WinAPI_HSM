#include "GaugeRenderObject.h"
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineActor.h>

GaugeRenderObject::GaugeRenderObject()
{

}

GaugeRenderObject::~GaugeRenderObject()
{

}

void GaugeRenderObject::SetGaugeRender(int _Order, StatusName _Name, int _MaxValue, GaugeFrameStyle _Style)
{
	Name = _Name;
	Style = _Style;

	GameEngineActor* Actor = GetOwner<GameEngineActor>();
	switch (Style)
	{
	case GaugeFrameStyle::Nomal:
		StatusGaugeFrameRender_Layer1 = Actor->CreateRender("StatusGaugeFrame_Layer1.bmp", _Order);
		StatusGaugeFrameRender_Layer1->SetScaleToImage();
		StatusGaugeFrameRender_Layer2 = Actor->CreateRender("StatusGaugeFrame_Layer2.bmp", _Order + 3);
		StatusGaugeFrameRender_Layer2->SetScaleToImage();
		break;
	case GaugeFrameStyle::Detail:
		StatusGaugeFrameRender_Layer1 = Actor->CreateRender("StatusGaugeFrame_Layer1_Detail.bmp", _Order);
		StatusGaugeFrameRender_Layer1->SetScaleToImage();
		StatusGaugeFrameRender_Layer2 = Actor->CreateRender("StatusGaugeFrame_Layer2_Detail.bmp", _Order + 3);
		StatusGaugeFrameRender_Layer2->SetScaleToImage();
		break;
	case GaugeFrameStyle::Estemate:
		StatusGaugeFrameRender_Layer1 = Actor->CreateRender("StatusGaugeFrame_Layer1_Estemate.bmp", _Order);
		StatusGaugeFrameRender_Layer1->SetScaleToImage();
		StatusGaugeFrameRender_Layer2 = Actor->CreateRender("StatusGaugeFrame_Layer2_Estemate.bmp", _Order + 3);
		StatusGaugeFrameRender_Layer2->SetScaleToImage();
		break;
	case GaugeFrameStyle::Physical:
		StatusGaugeFrameRender_Layer1 = Actor->CreateRender("StatusGaugeFrame_Layer1_Physical.bmp", _Order);
		StatusGaugeFrameRender_Layer1->SetScaleToImage();
		StatusGaugeFrameRender_Layer2 = Actor->CreateRender("StatusGaugeFrame_Layer2_Physical.bmp", _Order + 3);
		StatusGaugeFrameRender_Layer2->SetScaleToImage();
		break;
	default:
		break;
	}


	StatusGaugeEmptyRender = Actor->CreateRender("StatusGauge.bmp", _Order + 1);
	StatusGaugeEmptyRender->SetFrame(1);
	StatusGaugeEmptyRender->SetScale({ 110, 14 });
	StatusGaugeEmptyRender->SetPosition({ 55.0f, -1.0 });
	StatusGaugeRender = Actor->CreateRender("StatusGauge.bmp", _Order + 2);
	StatusGaugeRender->SetFrame(0);
	StatusGaugeRender->SetScale({ 110, 14 });
	StatusGaugeRender->SetPosition({ -55.0f, -1.0 });

	Max = _MaxValue;

	StatusValueRender.SetOwner(Actor);
	StatusValueRender.SetImage("Num_Status.bmp", { 10, 20 }, _Order + 4, RGB(0, 0, 0)); // 숫자 리소스 나중에 편집
	StatusValueRender.SetAlign(Align::Right);
	StatusValueRender.SetRenderPos({5,0});
	StatusValueRender.SetValue(static_cast<int>(StatusValue));
	StatusValueRender.SetMove({ 0,0 });
	
	SetValue(StatusValue);
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
		StatusGaugeRender->Off();
	}
	else
	{
		StatusGaugeEmptyRender->On();
		StatusGaugeRender->On();
	}

	StatusValue = _Value;
	StatusValueRender.SetValue(static_cast<int>(StatusValue));
	StatusGaugeRender->SetPosition(float4::LerpClamp(StatusGaugeRender->GetPosition(), StatusGaugeEmptyRender->GetPosition(), _Value / (Max - Min)));
}

void GaugeRenderObject::SetMove(float4 _Move)
{
	StatusGaugeFrameRender_Layer1->SetMove(_Move);
	StatusGaugeEmptyRender->SetMove(_Move);
	StatusGaugeRender->SetMove(_Move);
	StatusGaugeFrameRender_Layer2->SetMove(_Move);
	StatusValueRender.SetMove(_Move);
}

void GaugeRenderObject::SetPosition(float4 _Position)
{
	StatusGaugeFrameRender_Layer1->SetPosition(_Position);
	StatusGaugeEmptyRender->SetPosition(_Position + (float4::Right * 55.0f));
	StatusGaugeRender->SetPosition(_Position + (float4::Left * 55.0f));
	StatusGaugeFrameRender_Layer2->SetPosition(_Position);
	StatusValueRender.SetRenderPos(_Position + (float4::Left * 5.0f));
	SetValue(StatusValue);
}




