#include "Caption.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Caption::Caption()
{

}

Caption::~Caption()
{

}

void Caption::SetUpdateText(const std::string_view& _Text)
{
	UpdateCaption = _Text;
	CaptionRender->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextColor, CaptionTextBoxScale);
	CaptionOutline1Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor, CaptionTextBoxScale);
	CaptionOutline2Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor, CaptionTextBoxScale);
	CaptionOutline3Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor, CaptionTextBoxScale);
	CaptionOutline4Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor, CaptionTextBoxScale);
	CaptionOutline1Render->SetPosition(float4::Up * float4 {1,1});
	CaptionOutline2Render->SetPosition(float4::Down * float4 {1,1});
	CaptionOutline3Render->SetPosition(float4::Left * float4 {1,1});
	CaptionOutline4Render->SetPosition(float4::Right * float4 {1,1});
}

void Caption::Start()
{
	SetPos(CaptionPos);
	CaptionRender = CreateRender(PM2RenderOrder::Menu0_Display);
	CaptionOutline1Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CaptionOutline2Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CaptionOutline3Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CaptionOutline4Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);

	Off();
}

void Caption::Render(float _DeltaTime)
{
	if (GameEngineCore::GetInst()->IsDebug())
	{
		HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
		float4 ActorPos = CaptionPos - GetLevel()->GetCameraPos();
		HBRUSH myBrush = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(DoubleDC, myBrush));
		HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
		HPEN oldPen = static_cast<HPEN>(SelectObject(DoubleDC, myPen));


		Rectangle(DoubleDC,
			ActorPos.ix(),
			ActorPos.iy(),
			ActorPos.ix() + static_cast<int>(CaptionTextBoxScale.x),
			ActorPos.iy() + static_cast<int>(CaptionTextBoxScale.y)
		);

		SelectObject(DoubleDC, oldBrush);
		DeleteObject(myBrush);
		SelectObject(DoubleDC, oldPen);
		DeleteObject(myPen);
	}
}
