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
	Today.SetDate(1200,11,3); // 날짜 설정
	SetPos({90,50}); // 액터 위치
	DateViewerFrameRender = CreateRender("DateViewer.bmp", PM2RenderOrder::Menu0); // 프레임 렌더
	for (int i = 0; i < 4; i++) // 년도 렌더
	{
		Year[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_1);
		Year[i]->SetScale({10.0f,20.0f});
		Year[i]->SetPosition({ -15.0f + static_cast<float>(i) * 10.0f, -30.0f});
		Year[i]->SetFrame(GameEngineMath::GetDigits(Today.GetYear())[i]);
	}
	Month = CreateRender("Num_Month.bmp", PM2RenderOrder::Menu0_1); // 월 렌더
	Month->SetScale({60.0f, 20.0f});
	Month->SetPosition({-50.0f, 0.0f});
	Month->SetFrame(Today.GetMonth()-1);
	
	WeekDay = CreateRender("Num_WeekDay.bmp", PM2RenderOrder::Menu0_1); // 요일 렌더
	WeekDay->SetScale({ 60.0f, 20.0f });
	WeekDay->SetPosition({ -50.0f , 30.0f });
	WeekDay->SetFrame(static_cast<int>(Today.GetWeekDay()));
	
	Day.resize(GameEngineMath::GetLenth(Today.GetDay())); // 일 렌더
	for (int i = 0; i < Day.size(); i++)
	{
		Day[i] = CreateRender("Num_Day.bmp", PM2RenderOrder::Menu0_1);
		Day[i]->SetScale({ 40.0f, 50.0f });
		Day[i]->SetFrame(GameEngineMath::GetDigits(Today.GetDay())[i]);
		if (GameEngineMath::GetLenth(Today.GetDay()) == 1)
		{
			Day[i]->SetPosition({40.0f + (static_cast<float>(i) * 40.0f), 15.0f });
		}
		else if (GameEngineMath::GetLenth(Today.GetDay()) == 2)
		{
		
			Day[i]->SetPosition({ 40.0f + (-20.0f + static_cast<float>(i) * 40.0f), 15.0f });
		}
	}
}

void DateViewer::Update(float _DeltaTime)
{
	//SetFrame만 업데이트하면됨 위치랑 기타 등등은 고정인데... 날짜는 위치가 바뀌니 주의해서 업데이트할것
}

void DateViewer::Render(float _Time)
{
}
