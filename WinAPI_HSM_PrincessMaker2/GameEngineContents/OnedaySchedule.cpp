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
		IconRender->SetFrame(static_cast<int>(IconCode::빈칸));
		break;
	case ScheduleLabel::자연과학:
		IconRender->SetFrame(static_cast<int>(IconCode::자연과학));
		break;
	case ScheduleLabel::신학:
		IconRender->SetFrame(static_cast<int>(IconCode::신학));
		break;
	case ScheduleLabel::군사학:
		IconRender->SetFrame(static_cast<int>(IconCode::군사학));
		break;
	case ScheduleLabel::검술:
		IconRender->SetFrame(static_cast<int>(IconCode::검술));
		break;
	case ScheduleLabel::격투술:
		IconRender->SetFrame(static_cast<int>(IconCode::격투술));
		break;
	case ScheduleLabel::마법:
		IconRender->SetFrame(static_cast<int>(IconCode::마법));
		break;
	case ScheduleLabel::시문학:
		IconRender->SetFrame(static_cast<int>(IconCode::시문학));
		break;
	case ScheduleLabel::예법:
		IconRender->SetFrame(static_cast<int>(IconCode::예법));
		break;
	case ScheduleLabel::무용:
		IconRender->SetFrame(static_cast<int>(IconCode::무용));
		break;
	case ScheduleLabel::미술:
		IconRender->SetFrame(static_cast<int>(IconCode::미술));
		break;
	case ScheduleLabel::집안일:
		IconRender->SetFrame(static_cast<int>(IconCode::집안일));
		break;
	case ScheduleLabel::보모:
		IconRender->SetFrame(static_cast<int>(IconCode::아이보기));
		break;
	case ScheduleLabel::여관:
		IconRender->SetFrame(static_cast<int>(IconCode::여관));
		break;
	case ScheduleLabel::농장:
		IconRender->SetFrame(static_cast<int>(IconCode::농장));
		break;
	case ScheduleLabel::교회:
		IconRender->SetFrame(static_cast<int>(IconCode::신학));
		break;
	case ScheduleLabel::요리점:
		IconRender->SetFrame(static_cast<int>(IconCode::레스토랑));
		break;
	case ScheduleLabel::나무꾼:
		IconRender->SetFrame(static_cast<int>(IconCode::나무꾼));
		break;
	case ScheduleLabel::미용실:
		IconRender->SetFrame(static_cast<int>(IconCode::미용실));
		break;
	case ScheduleLabel::미장이:
		IconRender->SetFrame(static_cast<int>(IconCode::미장이));
		break;
	case ScheduleLabel::사냥꾼:
		IconRender->SetFrame(static_cast<int>(IconCode::사냥꾼));
		break;
	case ScheduleLabel::묘지기:
		IconRender->SetFrame(static_cast<int>(IconCode::묘지기));
		break;
	case ScheduleLabel::가정교사:
		IconRender->SetFrame(static_cast<int>(IconCode::가정교사));
		break;
	case ScheduleLabel::주점:
		IconRender->SetFrame(static_cast<int>(IconCode::주점));
		break;
	case ScheduleLabel::어둠의주점:
		IconRender->SetFrame(static_cast<int>(IconCode::어둠의주점));
		break;
	case ScheduleLabel::어둠의전당:
		IconRender->SetFrame(static_cast<int>(IconCode::어둠의전당));
		break;
	case ScheduleLabel::동부수풀지대:
		IconRender->SetFrame(static_cast<int>(IconCode::무사수행_동부산림지대));
		break;
	case ScheduleLabel::남부폭포지대:
		IconRender->SetFrame(static_cast<int>(IconCode::남부폭포지대));
		break;
	case ScheduleLabel::북부빙산지대:
		IconRender->SetFrame(static_cast<int>(IconCode::북부빙산지대));
		break;
	case ScheduleLabel::서부사막지대:
		IconRender->SetFrame(static_cast<int>(IconCode::서부사막지대));
		break;
	case ScheduleLabel::자유행동:
		IconRender->SetFrame(static_cast<int>(IconCode::자유행동));
		break;
	case ScheduleLabel::바캉스:
		IconRender->SetFrame(static_cast<int>(IconCode::바캉스));
		break;
	case ScheduleLabel::간호:
		IconRender->SetFrame(static_cast<int>(IconCode::간호));
		break;
	case ScheduleLabel::요양:
		IconRender->SetFrame(static_cast<int>(IconCode::요양));
		break;
	case ScheduleLabel::감시:
		IconRender->SetFrame(static_cast<int>(IconCode::감시));
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
