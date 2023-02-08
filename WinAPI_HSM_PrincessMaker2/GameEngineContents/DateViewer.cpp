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
	Today.SetDate(1200, 11, 30); // ��¥ ����

	SetPos({ 90,50 }); // ���� ��ġ
	DateViewerFrameRender = CreateRender("DateViewer.bmp", PM2RenderOrder::Menu0); // ������ ����

	Year.SetOwner(this);
	Year.SetImage("Num.bmp", { 10, 20 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	Year.SetValue(Today.GetDay());

	//for (int i = 0; i < 4; i++) // �⵵ ����
	//{
	//	Year[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
	//	Year[i]->SetScale({10.0f,20.0f});
	//	Year[i]->SetPosition({ -15.0f + static_cast<float>(i) * 10.0f, -30.0f});
	//	Year[i]->SetFrame(GameEngineMath::GetDigits(Today.GetYear())[i]);
	//}
	Month = CreateRender("Num_Month.bmp", PM2RenderOrder::Menu0_Display); // �� ����
	Month->SetScale({ 60.0f, 20.0f });
	Month->SetPosition({ -50.0f, 0.0f });
	Month->SetFrame(Today.GetMonth() - 1);

	WeekDay = CreateRender("Num_WeekDay.bmp", PM2RenderOrder::Menu0_Display); // ���� ����
	WeekDay->SetScale({ 60.0f, 20.0f });
	WeekDay->SetPosition({ -50.0f , 30.0f });
	WeekDay->SetFrame(static_cast<int>(Today.GetWeekDay()));

	Day.resize(GameEngineMath::GetLenth(Today.GetDay())); // �� ����
	for (int i = 0; i < Day.size(); i++)
	{
		Day[i] = CreateRender("Num_Day.bmp", PM2RenderOrder::Menu0_Display);
		Day[i]->SetScale({ 40.0f, 50.0f });
		Day[i]->SetFrame(GameEngineMath::GetDigits(Today.GetDay())[i]);
		//if (GameEngineMath::GetLenth(Today.GetDay()) == 1)
		{
			Day[i]->SetPosition({ 40.0f + ((GameEngineMath::GetLenth(Today.GetDay()) - 1) * (-20.0f) + static_cast<float>(i) * 40.0f), 15.0f });
		}
		/*else if (GameEngineMath::GetLenth(Today.GetDay()) == 2)
		{

			Day[i]->SetPosition({ 40.0f + (-20.0f + static_cast<float>(i) * 40.0f), 15.0f });
		}*/
	}
}

void DateViewer::Update(float _DeltaTime)
{
	//SetFrame�� ������Ʈ�ϸ�� ��ġ�� ��Ÿ ����� �����ε�... ��¥�� ��ġ�� �ٲ�� �����ؼ� ������Ʈ�Ұ�
}

void DateViewer::Render(float _Time)
{

}
