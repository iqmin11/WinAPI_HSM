#include "Caption.h"
#include <GameEnginePlatform/GameEngineWindow.h>
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
	CaptionRender->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextColor);
	CaptionOutline1Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor);
	CaptionOutline2Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor);
	CaptionOutline3Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor);
	CaptionOutline4Render->SetText(UpdateCaption, TextHeight, TextType, TextAlign::Center, TextOutlineColor);
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
