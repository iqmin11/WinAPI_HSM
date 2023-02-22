#include "ScheduleSelectionMenu.h"

ScheduleSelectionMenu::ScheduleSelectionMenu()
{

}

ScheduleSelectionMenu::~ScheduleSelectionMenu()
{

}

void ScheduleSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(4, ActorPos, Xscale, PM2ActorOrder::Menu1_Button, PM2RenderOrder::Menu1_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "딸을 단련시킨다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "딸에게 일을 시킨다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "무사수행을 보낸다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "휴식을 준다");

	Off();
}
