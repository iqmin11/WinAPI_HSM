#include "ScheduleFinalConfirm.h"
#include "CubeDialog.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "RaisingSimLevel.h"
#include "ScheduleSelectionMenu.h"
#include "ScheduleCalendar.h"

CubeDialog* ScheduleFinalConfirm::AcCubeDialog = nullptr;
ScheduleFinalConfirm* ScheduleFinalConfirm::AcScheduleFinalConfirm = nullptr;
ScheduleSelectionMenu* ScheduleFinalConfirm::AcScheduleSelectionMenu = nullptr;
ScheduleCalendar* ScheduleFinalConfirm::AcScheduleCalendar = nullptr;

ScheduleFinalConfirm::ScheduleFinalConfirm()
{
	AcScheduleFinalConfirm = this;
}

ScheduleFinalConfirm::~ScheduleFinalConfirm()
{

}

void ScheduleFinalConfirm::Start()
{
	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetAcCubeDialog();
	AcScheduleSelectionMenu = ScheduleSelectionMenu::GetAcScheduleSelectionMenu();
	AcScheduleCalendar = ScheduleCalendar::GetAcScheduleCalendar();

	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(2, ActorPos, Xscale, PM2ActorOrder::Menu2_Button, PM2RenderOrder::Menu2_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "�������� ����");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "���");
	SetButtonClick();
	Off();
}

void ScheduleFinalConfirm::Update(float _DeltaTime)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹����� �� �����ٷ�\n�����ϱ�?");

	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		AcScheduleSelectionMenu->On();
		AcScheduleCalendar->Reset();
	}
}

void ScheduleFinalConfirm::SetButtonClick()
{
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
}

void ScheduleFinalConfirm::Click0(Button* _Button)
{
	int a = 0;
}

void ScheduleFinalConfirm::Click1(Button* _Button)
{
	AcScheduleFinalConfirm->Off();
	AcScheduleSelectionMenu->On();
	AcScheduleCalendar->Reset();
}
