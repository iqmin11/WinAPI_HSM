#include "SchedulingConfirmSelectionMenu.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include "CubeDialog.h"
#include "RaisingSimLevel.h"
#include "ScheduleSelectionMenu.h"
#include "ScheduleCalendar.h"
#include "ScheduleFinalConfirm.h"

CubeDialog* SchedulingConfirmSelectionMenu::AcCubeDialog = nullptr;
ScheduleSelectionMenu* SchedulingConfirmSelectionMenu::AcScheduleSelectionMenu = nullptr;
SchedulingConfirmSelectionMenu* SchedulingConfirmSelectionMenu::AcSchedulingConfirmSelectionMenu = nullptr;
ScheduleCalendar* SchedulingConfirmSelectionMenu::AcScheduleCalendars = nullptr;
ScheduleLabel SchedulingConfirmSelectionMenu::ScheduleState = ScheduleLabel::Null;
ScheduleFinalConfirm* SchedulingConfirmSelectionMenu::AcScheduleFinalConfirm = nullptr;

SchedulingConfirmSelectionMenu::SchedulingConfirmSelectionMenu()
{
	AcSchedulingConfirmSelectionMenu = this;
}

SchedulingConfirmSelectionMenu::~SchedulingConfirmSelectionMenu()
{

}

void SchedulingConfirmSelectionMenu::Start()
{
	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetAcCubeDialog();
	AcScheduleSelectionMenu = ScheduleSelectionMenu::GetAcScheduleSelectionMenu();
	AcScheduleCalendars = ScheduleCalendar::GetAcScheduleCalendar();
	AcScheduleFinalConfirm = GetLevel()->CreateActor<ScheduleFinalConfirm>(PM2ActorOrder::Menu2);
	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(2, ActorPos, Xscale, PM2ActorOrder::Menu2_Button, PM2RenderOrder::Menu2_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "�����ٿ� ���Ѵ�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "���");

	SetButtonClick();
	Off();
}

void SchedulingConfirmSelectionMenu::Update(float _DeltaTime)
{
	switch (ScheduleState)
	{
	case ScheduleLabel::�ڿ�����:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�ڿ�����.\n�̽��� �����ϰ�, ������, �ո�\n���� �ȸ��� Ű���");
		break;
	case ScheduleLabel::����:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "����.\n�ž��� ���ʷ� ���а��� ����.\n�й��� �յ�");
		break;
	case ScheduleLabel::������:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "������.\n������ ����� �й����μ� ���\n��");
		break;
	case ScheduleLabel::�˼�:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�˼�.\n������ ���ؼ� �˼��� ����");
		break;
	case ScheduleLabel::������:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "������.\n���⸦ �������� �ʰ�, ������\n�� �߽����� �ϴ� �������� ��\n���");
		break;
	case ScheduleLabel::����:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "����.\n������ ���ʺ���, ������ �ֹ�\n���� ����");
		break;
	case ScheduleLabel::�ù���:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�ù���.\n�ø� �����ϰų� â��. �ù���\n���� ����, �������� ������\n��¡");
		break;
	case ScheduleLabel::����:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "����.\n������ �������, ���� ������\n���� ������ ���� �������� ����");
		break;
	case ScheduleLabel::����:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "����.\n�������� ���� ������ ����");
		break;
	case ScheduleLabel::�̼�:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̼�.\n�׸��� �׷� �������� ������\n���� �۴´�");
		break;
	default:
		break;
	}

	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		AcScheduleSelectionMenu->On();
	}
}

void SchedulingConfirmSelectionMenu::SetButtonClick()
{
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
}

void SchedulingConfirmSelectionMenu::Click0(Button* _Button)
{
	AcScheduleCalendars->ScheduleSetting(ScheduleState);
	if (!AcScheduleCalendars->ScheduleSetEnd)
	{
		AcSchedulingConfirmSelectionMenu->Off();
		AcScheduleSelectionMenu->On();
	}
	else
	{
		AcSchedulingConfirmSelectionMenu->Off();
		AcScheduleFinalConfirm->On();
	}
}

void SchedulingConfirmSelectionMenu::Click1(Button* _Button)
{
	AcSchedulingConfirmSelectionMenu->Off();
	AcScheduleSelectionMenu->On();
}
