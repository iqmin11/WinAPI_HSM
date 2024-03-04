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
	case ScheduleLabel::�ڿ�����:
		Schedule = "�ڿ�����";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::�˼�:
		Schedule = "�˼�";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::�ù���:
		Schedule = "�ù���";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::�̼�:
		Schedule = "�̼�";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::��ȸ:
		Schedule = "��ȸ";
		break;
	case ScheduleLabel::�丮��:
		Schedule = "�丮��";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::�̿��:
		Schedule = "�̿��";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::��ɲ�:
		Schedule = "��ɲ�";
		break;
	case ScheduleLabel::������:
		Schedule = "������";
		break;
	case ScheduleLabel::��������:
		Schedule = "��������";
		break;
	case ScheduleLabel::����:
		Schedule = "����";
		break;
	case ScheduleLabel::���������:
		Schedule = "���������";
		break;
	case ScheduleLabel::���������:
		Schedule = "���������";
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
	TextRender->SetText(Schedule + std::string{ " " } + std::to_string(DayCount) + std::string{ "��°\n ������ ������ ������ �ֽ��ϴ�." }, TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
}

void ScheduleMessageBox::UpdateScheduleEndText()
{
	TextRender->SetText("�������� ������", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale);
}

