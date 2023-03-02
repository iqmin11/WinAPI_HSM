#include "ScheduleSelectionMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ClassSelectWindow.h"
#include "CubeDialog.h"
#include "RaisingSimLevel.h"
#include "ScheduleCalendar.h"
#include "MainMenu.h"

ClassSelectWindow* ScheduleSelectionMenu::AcClassSelectWindow = nullptr;
ScheduleSelectionMenu* ScheduleSelectionMenu::AcScheduleSelectionMenu = nullptr;


ScheduleSelectionMenu::ScheduleSelectionMenu()
{
	AcScheduleSelectionMenu = this;
}

ScheduleSelectionMenu::~ScheduleSelectionMenu()
{

}

void ScheduleSelectionMenu::Start()
{
	AcClassSelectWindow = GetLevel()->CreateActor<ClassSelectWindow>(PM2ActorOrder::Menu2);
	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetAcCubeDialog();
	AcScheduleCalendar = ScheduleCalendar::GetAcScheduleCalendar();
	InitMenuFrameRender(PM2RenderOrder::Menu1, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(4, ActorPos, Xscale, PM2ActorOrder::Menu1_Button, PM2RenderOrder::Menu1_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "딸을 단련시킨다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "딸에게 일을 시킨다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "무사수행을 보낸다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "휴식을 준다");

	SetButtonClick();

	Off();
}

void ScheduleSelectionMenu::Update(float _DeltaTime)
{
	if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
	{
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
	}
	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
	{
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
	}
	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
	{
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
	}

	
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
		{
			AcScheduleCalendar->Off();
			AcCubeDialog->Off();
			Off();
			MainMenu::GetAcMainMenu()->On();
		}
		else
		{
			AcScheduleCalendar->CancelSchedule();
		}
	}
}

void ScheduleSelectionMenu::SetButtonClick()
{
	GetSelectButtons()[0]->SetClickCallBack(Click0);
}

void ScheduleSelectionMenu::Click0(Button* _Button)
{
	AcClassSelectWindow->On();
	AcScheduleSelectionMenu->Off();
}
