#include "DateViewer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "RaisingSimLevel.h"
#include "ContentsEnums.h"

DateViewer::DateViewer()
{

}

DateViewer::~DateViewer()
{

}

void DateViewer::Start()
{
	Today.SetDate(1000, 1, 1); // 터짐 방지, 미설정시 1000년으로 뜸

	SetPos({ 90,50 }); // 액터 위치
	DateViewerFrameRender = CreateRender("DateViewer.bmp", PM2RenderOrder::Menu0); // 프레임 렌더
	DateViewerFrameRender->SetScaleToImage();

	Year.SetOwner(this);
	Year.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	Year.SetAlign(Align::Center);
	//Year.SetValue(Today.GetYear());
	Year.SetRenderPos({ 0.0f, -30.0f }); 
	
	Month = CreateRender("Num_Month.bmp", PM2RenderOrder::Menu0_Display); // 월 렌더
	Month->SetScale({ 60.0f, 20.0f });
	Month->SetPosition({ -50.0f, 0.0f });
	//Month->SetFrame(Today.GetMonth() - 1);

	WeekDay = CreateRender("Num_WeekDay.bmp", PM2RenderOrder::Menu0_Display); // 요일 렌더
	WeekDay->SetScale({ 60.0f, 20.0f });
	WeekDay->SetPosition({ -50.0f , 30.0f });
	//WeekDay->SetFrame(static_cast<int>(Today.GetWeekDay()));

	Day.SetOwner(this);
	Day.SetImage("Num_Day.bmp", { 40.0f, 50.0f }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	Day.SetAlign(Align::Center);
	//Day.SetValue(Today.GetDay());
	Day.SetRenderPos({ 40.0f, 15.0f }); 

}

void DateViewer::Update(float _DeltaTime)
{
	if (Today != dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday())
	{
		Today = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday();
		Year.SetValue(Today.GetYear());
		Month->SetFrame(Today.GetMonth() - 1);
		Day.SetValue(Today.GetDay());
		WeekDay->SetFrame(static_cast<int>(Today.GetWeekDay()));
	}
}
