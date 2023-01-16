#include "Calendar.h"
#include <vector>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>


Calendar::Calendar()
{

}

Calendar::~Calendar()
{

}

void Calendar::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	//GameEngineRender* WeekRender = CreateRender("OliveWeek.BMP");

	GameEngineRender* Background = CreateRender("SetOliveBirth.BMP", 0);
	

	std::vector<std::vector<GameEngineRender*>> CalendarNum = std::vector<std::vector<GameEngineRender*>>();
	CalendarNum.resize(6);
	for (size_t y = 0; y < CalendarNum.size(); y++)
	{
		CalendarNum[y].resize(7);
	}

	for (size_t y = 0; y < CalendarNum.size(); y++)
	{
		for (size_t x = 0; x < CalendarNum[y].size(); x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			CalendarNum[y][x] = CreateRender("OliveCalendarNum.BMP", 1);
			if (31 < (x + 1) + (y * 7))
			{
				break;
			}
			CalendarNum[y][x]->SetFrame((x+1) + (y*7));
			CalendarNum[y][x]->SetScale({ 20,15 });
			CalendarNum[y][x]->SetPosition(float4{ -105,-51 } + float4{ 30 * (fx), 20 * fy });
		}
	}
	GameEngineRender* Week = CreateRender("OliveWeek.BMP", 2);
	Week->SetScale({ 210,10 });
	Week->SetPosition(float4{ -10,-66 });


}

void Calendar::Update(float _DeltaTime)
{
}

void Calendar::Render(float _DeltaTime)
{
}
