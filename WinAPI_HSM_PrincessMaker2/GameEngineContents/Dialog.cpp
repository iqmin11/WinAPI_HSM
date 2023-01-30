#include "Dialog.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>

Dialog::Dialog()
{

}

Dialog::~Dialog()
{

}

void Dialog::MugShotRender()
{
	MugShotFrame = CreateRender("MugShotFrame_Nomal.bmp", 9);
	MugShot = CreateRender("Mug_Devil.bmp", 10);
}

void Dialog::LeftMugDialogRender()
{
	SetMoveMugShotRender({ -170, 0 });
	SetMoveFrameRenderPos(float4{ 80,0 });
}

void Dialog::RightMugDialogRender()
{
	SetMoveMugShotRender({ 170,0 });
	SetMoveFrameRenderPos(float4{ -80,0 });
}

void Dialog::SetMoveMugShotRender(const float4& _Move)
{
	MugShotFrame->SetMove(_Move);
	MugShot->SetMove(_Move);
}

void Dialog::SetMoveDialogRender(const float4& _Move)
{
	SetMoveMugShotRender(_Move);
	SetMoveFrameRenderPos(_Move);
}

void Dialog::Start()
{
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), { 20,10 });
	MenuFrameRender(PM2RenderOrder::Menu);
	MugShotRender();
	RightMugDialogRender();
	//LeftMugDialogRender();
	// 머그샷 가로 140 세로 150 / 대화창 가로 320 세로 160 /사이간격 가로 20 총 가로 480 세로 160
	// 대화창 가로로 120만큼 오른쪽으로
	// 머그샷 가로로 170만큼 왼쪽으로
	//MugShotFrame->SetPosition(float4::Left * (GetMenuFramePixelSize().half() + MugShotFrame->GetImage()->GetImageScale().half()));
}

void Dialog::Update(float _DeltaTime)
{

}

void Dialog::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	); // 디버깅용
}
