#include "ScheduleMessageBox.h"
#include <GameEngineCore/GameEngineRender.h>
#include "SchedulePlayer.h"

ScheduleMessageBox::ScheduleMessageBox()
{

}

ScheduleMessageBox::~ScheduleMessageBox()
{

}

void ScheduleMessageBox::SetScheduleString(ScheduleLabel _ScheduleLabel)
{
	switch (_ScheduleLabel)
	{
	case ScheduleLabel::Null:
		break;
	case ScheduleLabel::자연과학:
		Schedule = "자연과학";
		break;
	case ScheduleLabel::신학:
		Schedule = "신학";
		break;
	case ScheduleLabel::군사학:
		Schedule = "군사학";
		break;
	case ScheduleLabel::검술:
		Schedule = "검술";
		break;
	case ScheduleLabel::격투술:
		Schedule = "격투술";
		break;
	case ScheduleLabel::마법:
		Schedule = "마법";
		break;
	case ScheduleLabel::시문학:
		Schedule = "시문학";
		break;
	case ScheduleLabel::예법:
		Schedule = "예법";
		break;
	case ScheduleLabel::무용:
		Schedule = "무용";
		break;
	case ScheduleLabel::미술:
		Schedule = "미술";
		break;
	case ScheduleLabel::집안일:
		Schedule = "집안일";
		break;
	case ScheduleLabel::보모:
		Schedule = "보모";
		break;
	case ScheduleLabel::여관:
		Schedule = "여관";
		break;
	case ScheduleLabel::농장:
		Schedule = "농장";
		break;
	case ScheduleLabel::교회:
		Schedule = "교회";
		break;
	case ScheduleLabel::요리점:
		Schedule = "요리점";
		break;
	case ScheduleLabel::나무꾼:
		Schedule = "나무꾼";
		break;
	case ScheduleLabel::미용실:
		Schedule = "미용실";
		break;
	case ScheduleLabel::미장이:
		Schedule = "미장이";
		break;
	case ScheduleLabel::사냥꾼:
		Schedule = "사냥꾼";
		break;
	case ScheduleLabel::묘지기:
		Schedule = "묘지기";
		break;
	case ScheduleLabel::가정교사:
		Schedule = "가정교사";
		break;
	case ScheduleLabel::주점:
		Schedule = "주점";
		break;
	case ScheduleLabel::어둠의주점:
		Schedule = "어둠의주점";
		break;
	case ScheduleLabel::어둠의전당:
		Schedule = "어둠의전당";
		break;
	default:
		break;
	}
}

void ScheduleMessageBox::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetMenuFrameScale({ Scale });
	SetPos(ActorPos);
	TextRender = CreateRender(PM2RenderOrder::Menu1_Display);
	TextRender->SetPosition(TextRenderPos);
	TextRender->SetText(" ", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);

	Off();
}

void ScheduleMessageBox::Update(float _DeltaTime)
{
	UpdateTextRender();
}


void ScheduleMessageBox::UpdateTextRender()
{
	TextRender->SetText(Schedule + std::string{ " " } + std::to_string(DayCount) + std::string{ "일째\n 서서히 성과가 나오고 있습니다." }, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
}

void ScheduleMessageBox::UpdateScheduleEndText()
{
	TextRender->SetText("스케줄이 끝났다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
}

