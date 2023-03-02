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
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "스케줄에 편성한다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "취소");

	SetButtonClick();
	Off();
}

void SchedulingConfirmSelectionMenu::Update(float _DeltaTime)
{
	switch (ScheduleState)
	{
	case ScheduleLabel::자연과학:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "자연과학.\n미신을 부정하고, 과학적, 합리\n적인 안목을 키운다");
		break;
	case ScheduleLabel::신학:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "신학.\n신앙을 기초로 과학관의 수양.\n학문의 왕도");
		break;
	case ScheduleLabel::군사학:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "군사학.\n전투의 기술을 학문으로서 배운\n다");
		break;
	case ScheduleLabel::검술:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "검술.\n도장을 통해서 검술을 배운다");
		break;
	case ScheduleLabel::격투술:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "격투술.\n무기를 의존하지 않고, 격투술\n을 중심으로 하는 전투법을 배\n운다");
		break;
	case ScheduleLabel::마법:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "마법.\n마법의 기초부터, 강력한 주문\n까지 습득");
		break;
	case ScheduleLabel::시문학:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "시문학.\n시를 낭독하거나 창작. 시문을\n배우는 것은, 교양인의 지식의\n상징");
		break;
	case ScheduleLabel::예법:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "예법.\n숙녀의 교양부터, 오랜 세월에\n걸쳐 내려온 궁중 예법까지 전수");
		break;
	case ScheduleLabel::무용:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "무용.\n본격적인 궁중 무용을 전수");
		break;
	case ScheduleLabel::미술:
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "미술.\n그림을 그려 예술적인 센스를\n갈고 닦는다");
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
