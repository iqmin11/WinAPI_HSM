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
	St = GaugeFrameStyle::Nomal;
	InsertStatus(StatusName::ü��, 999, St);
	InsertStatus(StatusName::�ٷ�, 100, St);
	InsertStatus(StatusName::����, 100, St);
	InsertStatus(StatusName::��ǰ, 100, St);
	InsertStatus(StatusName::����, 100, St);
	InsertStatus(StatusName::������, 100, St);
	InsertStatus(StatusName::�ž�, 100, St);
	InsertStatus(StatusName::����, 100, St);
	InsertStatus(StatusName::������, 100, St);
	InsertStatus(StatusName::��Ʈ����, 100, St);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{0,-40} + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });

	Off();
}
