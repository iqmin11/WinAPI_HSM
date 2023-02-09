#include "MousePoint.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

MousePoint* MousePoint::MainMouse;

MousePoint::MousePoint()
{

}

MousePoint::~MousePoint()
{

}

void MousePoint::Start()
{
	MainMouse = this;
	GameEngineInput::MouseCursorOff();
	MousePointCollision = CreateCollision(PM2CollisionOrder::MousePoint);
	MousePointCollision->SetScale({ 1,1 });
	MousePointRender = CreateRender(PM2RenderOrder::MousePoint);
	MousePointRender->SetImageToScaleToImage("Cursor.bmp");
	MousePointRender->SetPosition(MousePointRender->GetScale().half());
}

void MousePoint::Update(float _DeltaTime)
{
	SetPos(GetLevel()->GetMousePos());
}

void MousePoint::Render(float _Time)
{
}
