#include "SetPlayerName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

SetPlayerName::SetPlayerName()
{

}

SetPlayerName::~SetPlayerName()
{

}

void SetPlayerName::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetPlayerBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	SetUpperCaseButton();
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
}

void SetPlayerName::Render(float _DeltaTime)
{
}

void SetPlayerName::On()
{
	GameEngineObject::On();
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			UpperCaseButton[y][x]->On();
		}
	}
}

void SetPlayerName::Off()
{
	GameEngineObject::Off();
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			UpperCaseButton[y][x]->Off();
		}
	}
}

void SetPlayerName::SetUpperCaseButton()
{
	GameEngineLevel* Level = GetLevel();
	
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			UpperCaseButton[y][x] = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
			UpperCaseButton[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			UpperCaseButton[y][x]->SetScale(ButtonScale);
			UpperCaseButton[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			UpperCaseButton[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));;
			UpperCaseButton[y][x]->SetPos(GetPos() + (ButtonScale + ButtonInterval)*float4 { static_cast<float>(x), static_cast<float>(y) });
			UpperCaseButton[y][x]->SetReleaseImage("ReleaseButton.Bmp");
			UpperCaseButton[y][x]->SetHoverImage("HoverButton.Bmp");
			UpperCaseButton[y][x]->SetPressImage("PressButton.Bmp");
		}
	}
}

void SetPlayerName::SetLowerCaseButton()
{
}
