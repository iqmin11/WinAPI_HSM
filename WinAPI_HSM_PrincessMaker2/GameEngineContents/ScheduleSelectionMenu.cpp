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
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "���� �ܷý�Ų��");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "������ ���� ��Ų��");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "��������� ������");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "�޽��� �ش�");

	Off();
}
