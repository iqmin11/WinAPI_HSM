#include "BasicStatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>

BasicStatusWindow::BasicStatusWindow()
{

}

BasicStatusWindow::~BasicStatusWindow()
{

}

void BasicStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	InsertStatus(StatusName::ü��, 100);
	InsertStatus(StatusName::�ٷ�, 100);
	InsertStatus(StatusName::����, 100);
	InsertStatus(StatusName::��ǰ, 100);
	InsertStatus(StatusName::����, 100);
	InsertStatus(StatusName::������, 100);
	InsertStatus(StatusName::�ž�, 100);
	InsertStatus(StatusName::����, 100);
	InsertStatus(StatusName::������, 100);
	InsertStatus(StatusName::��Ʈ����, 100);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{0,-40} + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });
}
