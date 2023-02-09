#include "DateViewer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

DateViewer::DateViewer()
{

}

DateViewer::~DateViewer()
{

}

void DateViewer::Start()
{
	Today.SetDate(1200, 11, 30); // 날짜 설정

	SetPos({ 90,50 }); // 액터 위치
	DateViewerFrameRender = CreateRender("DateViewer.bmp", PM2RenderOrder::Menu0); // 프레임 렌더
	DateViewerFrameRender->SetScaleToImage();

	Year.SetOwner(this);
	Year.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	Year.SetAlign(Align::Center);
	Year.SetValue(Today.GetYear());
	Year.SetMove({ 0.0f, -30.0f }); // 밸류를 먼저셋해줘야 무브가되네!
	
	Month = CreateRender("Num_Month.bmp", PM2RenderOrder::Menu0_Display); // 월 렌더
	Month->SetScale({ 60.0f, 20.0f });
	Month->SetPosition({ -50.0f, 0.0f });
	Month->SetFrame(Today.GetMonth() - 1);

	WeekDay = CreateRender("Num_WeekDay.bmp", PM2RenderOrder::Menu0_Display); // 요일 렌더
	WeekDay->SetScale({ 60.0f, 20.0f });
	WeekDay->SetPosition({ -50.0f , 30.0f });
	WeekDay->SetFrame(static_cast<int>(Today.GetWeekDay()));

	Day.SetOwner(this);
	Day.SetImage("Num_Day.bmp", { 40.0f, 50.0f }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	Day.SetAlign(Align::Center);
	Day.SetValue(Today.GetDay());
	Day.SetMove({ 40.0f, 15.0f }); // 밸류를 먼저셋해줘야 무브가되네!

}

void DateViewer::Update(float _DeltaTime)
{
	//SetFrame만 업데이트하면됨 위치랑 기타 등등은 고정인데... 날짜는 위치가 바뀌니 주의해서 업데이트할것
}

void DateViewer::Render(float _Time)
{

}
