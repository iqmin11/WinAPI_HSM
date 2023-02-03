#include "MousePoint.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentsEnums.h"

MousePoint::MousePoint()
{

}

MousePoint::~MousePoint()
{

}

void MousePoint::Start()
{
	MousePointCollision = CreateCollision(PM2CollisionOrder::MousePoint);
	MousePointCollision->SetScale({1,1});
}

void MousePoint::Update(float _DeltaTime)
{
	SetPos(GetLevel()->GetMousePos());
}

void MousePoint::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	); // µð¹ö±ë¿ë
}
