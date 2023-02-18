#include "GlobalButton.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>

GlobalButton::GlobalButton()
{

}

GlobalButton::~GlobalButton()
{

}

void GlobalButton::Render(float _DeltaTime)
{
	//µð¹ö±×
	if (GameEngineCore::GetInst()->IsDebug() && GetState() == ButtonState::Release)
	{
		HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
		float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;
		HBRUSH myBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(DoubleDC, myBrush));
		HPEN myPen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
		HPEN oldPen = static_cast<HPEN>(SelectObject(DoubleDC, myPen));


		Rectangle(DoubleDC,
			ActorPos.ix() - static_cast<int>(GetScale().hx()),
			ActorPos.iy() - static_cast<int>(GetScale().hy()),
			ActorPos.ix() + static_cast<int>(GetScale().hx()),
			ActorPos.iy() + static_cast<int>(GetScale().hy())
		);

		SelectObject(DoubleDC, oldBrush);
		DeleteObject(myBrush);
		SelectObject(DoubleDC, oldPen);
		DeleteObject(myPen);
	}
	else if (GameEngineCore::GetInst()->IsDebug() && GetState() == ButtonState::Hover)
	{
		HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
		float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;
		HBRUSH myBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(DoubleDC, myBrush));
		HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 255));
		HPEN oldPen = static_cast<HPEN>(SelectObject(DoubleDC, myPen));


		Rectangle(DoubleDC,
			ActorPos.ix() - static_cast<int>(GetScale().hx()),
			ActorPos.iy() - static_cast<int>(GetScale().hy()),
			ActorPos.ix() + static_cast<int>(GetScale().hx()),
			ActorPos.iy() + static_cast<int>(GetScale().hy())
		);

		SelectObject(DoubleDC, oldBrush);
		DeleteObject(myBrush);
		SelectObject(DoubleDC, oldPen);
		DeleteObject(myPen);
	}
	else if (GameEngineCore::GetInst()->IsDebug() && GetState() == ButtonState::Press)
	{
		HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
		float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;
		HBRUSH myBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(DoubleDC, myBrush));
		HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
		HPEN oldPen = static_cast<HPEN>(SelectObject(DoubleDC, myPen));


		Rectangle(DoubleDC,
			ActorPos.ix() - static_cast<int>(GetScale().hx()),
			ActorPos.iy() - static_cast<int>(GetScale().hy()),
			ActorPos.ix() + static_cast<int>(GetScale().hx()),
			ActorPos.iy() + static_cast<int>(GetScale().hy())
		);

		SelectObject(DoubleDC, oldBrush);
		DeleteObject(myBrush);
		SelectObject(DoubleDC, oldPen);
		DeleteObject(myPen);
	}
}
