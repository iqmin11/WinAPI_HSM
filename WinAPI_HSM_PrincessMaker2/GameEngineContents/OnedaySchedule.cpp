#include "OnedaySchedule.h"
#include "RaisingSimLevel.h"


OnedaySchedule::OnedaySchedule()
{

}

OnedaySchedule::~OnedaySchedule()
{

}

void OnedaySchedule::Start()
{
	SetDayNumRender();
	IconRender = CreateRender("Icon.bmp", PM2RenderOrder::Menu1_Display_Shadow);
	IconRender->SetScale(IconRenderScale);
}

void OnedaySchedule::Update(float _DeltaTime)
{
	if (Today != dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday())
	{
		Today = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday();
		NextDate = Today.GetNextDate();
	}

	switch (ScheduleValue)
	{
	case ScheduleLabel::Null:
		IconRender->SetFrame(static_cast<int>(IconCode::��ĭ));
		break;
	case ScheduleLabel::�ڿ�����:
		IconRender->SetFrame(static_cast<int>(IconCode::�ڿ�����));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::�˼�:
		IconRender->SetFrame(static_cast<int>(IconCode::�˼�));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::�ù���:
		IconRender->SetFrame(static_cast<int>(IconCode::�ù���));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::�̼�:
		IconRender->SetFrame(static_cast<int>(IconCode::�̼�));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::���̺���));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::��ȸ:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::�丮��:
		IconRender->SetFrame(static_cast<int>(IconCode::�������));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::�̿��:
		IconRender->SetFrame(static_cast<int>(IconCode::�̿��));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::��ɲ�:
		IconRender->SetFrame(static_cast<int>(IconCode::��ɲ�));
		break;
	case ScheduleLabel::������:
		IconRender->SetFrame(static_cast<int>(IconCode::������));
		break;
	case ScheduleLabel::��������:
		IconRender->SetFrame(static_cast<int>(IconCode::��������));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	case ScheduleLabel::���������:
		IconRender->SetFrame(static_cast<int>(IconCode::���������));
		break;
	case ScheduleLabel::���������:
		IconRender->SetFrame(static_cast<int>(IconCode::���������));
		break;
	case ScheduleLabel::���μ�Ǯ����:
		IconRender->SetFrame(static_cast<int>(IconCode::�������_���λ긲����));
		break;
	case ScheduleLabel::������������:
		IconRender->SetFrame(static_cast<int>(IconCode::������������));
		break;
	case ScheduleLabel::�Ϻκ�������:
		IconRender->SetFrame(static_cast<int>(IconCode::�Ϻκ�������));
		break;
	case ScheduleLabel::���λ縷����:
		IconRender->SetFrame(static_cast<int>(IconCode::���λ縷����));
		break;
	case ScheduleLabel::�����ൿ:
		IconRender->SetFrame(static_cast<int>(IconCode::�����ൿ));
		break;
	case ScheduleLabel::��Ĳ��:
		IconRender->SetFrame(static_cast<int>(IconCode::��Ĳ��));
		break;
	case ScheduleLabel::��ȣ:
		IconRender->SetFrame(static_cast<int>(IconCode::��ȣ));
		break;
	case ScheduleLabel::���:
		IconRender->SetFrame(static_cast<int>(IconCode::���));
		break;
	case ScheduleLabel::����:
		IconRender->SetFrame(static_cast<int>(IconCode::����));
		break;
	default:
		break;
	}
	
}

void OnedaySchedule::SetDayNumRender()
{
	DayNumRender.SetOwner(this);
	DayNumRender.SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
	DayNumRender.SetAlign(Align::Right);
	DayNumRender.SetValue(10);
}

void OnedaySchedule::UpdateDayNumRender()
{
	if (DateValue.IsNullDate() || NextDate > DateValue)
	{
		DayNumRender.Off();
	}
	else
	{
		DayNumRender.On();

		if (GameEngineMath::GetLenth(DateValue.GetDay()) == 1)
		{
			DayNumRender.SetImage("Num_Age.bmp", DayNumRenderScale_1, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
			DayNumRender.SetValue(DateValue.GetDay());
			DayNumRender.SetRenderPos(DayNumRenderPos_1);
		}
		else if (GameEngineMath::GetLenth(DateValue.GetDay()) == 2)
		{
			DayNumRender.SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
			DayNumRender.SetValue(DateValue.GetDay());
			DayNumRender.SetRenderPos(DayNumRenderPos_2);
		}
	}
}
