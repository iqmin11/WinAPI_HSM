#include "SchedulingConfirmSelectionMenu.h"

SchedulingConfirmSelectionMenu::SchedulingConfirmSelectionMenu()
{

}

SchedulingConfirmSelectionMenu::~SchedulingConfirmSelectionMenu()
{

}

void SchedulingConfirmSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(2, ActorPos, Xscale, PM2ActorOrder::Menu2_Button, PM2RenderOrder::Menu2_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "스케줄에 편성한다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "취소");
	Off();
}
