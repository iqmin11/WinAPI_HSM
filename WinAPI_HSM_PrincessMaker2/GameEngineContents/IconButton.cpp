#include "IconButton.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

IconButton::IconButton()
{

}

IconButton::~IconButton()
{

}

void IconButton::SetPos(const float4& _Pos)
{
	GameEngineActor::SetPos(_Pos);
	Button->SetPos(_Pos);
}

void IconButton::SetIconButton(IconCode _IconCode, const std::string_view& _Name, const std::string_view& _Difficulty, int _Price, const float4& _Pos)
{
	Button->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	Button->SetScale(ButtonScale);
	Button->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu2_Button));
	Button->SetCollisionOrder(static_cast<int>(PM2RenderOrder::Menu2_Button));
	Button->SetPos(GetPos());
	Button->SetReleaseImage("SelectButton_Release.bmp");
	Button->SetHoverImage("IconButton_Hover.bmp");
	Button->SetPressImage("IconButton_Hover.bmp");

	ICode = _IconCode;
	Name = _Name;
	Difficulty = _Difficulty;
	Price = _Price;
	
	SetPos(_Pos);

	IconRender->SetScale(IconScale);
	IconRender->SetFrame(static_cast<int>(ICode));
	IconRender->SetPosition(IconPos);

	NameRender->SetText(Name, TextHeight, TextType, TextAlign::Left, TextColor, NameBoxScale);
	NameRender->SetPosition(NamePos);

	DifficultyRender->SetText(Difficulty, TextHeight, TextType, TextAlign::Left, TextColor, DifficultyBoxScale);
	DifficultyRender->SetPosition(DifficultyPos);

	PriceRender.SetImage("Num_Status.bmp", PriceRenderScale, static_cast<int>(PM2RenderOrder::Menu2_Display), RGB(0, 0, 0));
	PriceRender.SetAlign(Align::Right);
	PriceRender.SetValue(Price);
	PriceRender.SetRenderPos(PriceRenderPos);

	Alphabet_G->SetTransColor(RGB(0, 0, 0));
	Alphabet_G->SetScale(PriceRenderScale);
	Alphabet_G->SetFrame(2);
	Alphabet_G->SetPosition(Alphabet_GPos);
}

void IconButton::On()
{
	GameEngineObject::On();
	Button->On();
}

void IconButton::Off()
{
	GameEngineObject::Off();
	Button->Off();
}

void IconButton::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu2_Button, MenuFrameStyleEnum::Silver);
	SetMenuFrameScale(ButtonScale);
	Button = GetLevel()->CreateActor<GlobalButton>(PM2ActorOrder::Menu2_Button);
	IconRender = CreateRender("Icon.bmp", PM2RenderOrder::Menu2_Display);
	NameRender = CreateRender(PM2RenderOrder::Menu2_Display);
	DifficultyRender = CreateRender(PM2RenderOrder::Menu2_Display);
	PriceRender.SetOwner(this);
	Alphabet_G = CreateRender("Num_Status_etc.bmp", PM2RenderOrder::Menu2_Display);
}