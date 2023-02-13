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
	SetUpperCaseRender();
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
}

void SetPlayerName::Render(float _DeltaTime)
{
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			if (ButtonState::Release == UpperCaseButton[y][x]->GetState())
			{
				UpperCaseLetterEffect1Render[y][x]->Off();
				UpperCaseLetterEffect2Render[y][x]->Off();
				UpperCaseLetterEffect3Render[y][x]->Off();

				UpperCaseLetter1Render	   [y][x]->On();
				UpperCaseLetter2Render	   [y][x]->On();
				UpperCaseLetterShadowRender[y][x]->On();
			}
			else
			{
				UpperCaseLetterEffect1Render[y][x]->On();
				UpperCaseLetterEffect2Render[y][x]->On();
				UpperCaseLetterEffect3Render[y][x]->On();

				UpperCaseLetter2Render[y][x]->Off();
				UpperCaseLetter2Render[y][x]->Off();
				UpperCaseLetterShadowRender[y][x]->Off();
			}
		}
	}
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
	float4 ButtonStartPosition = { 182, 312 };
	
	for (size_t x = 0; x < 5; x++)
	{
		for (size_t y = 0; y < 6; y++)
		{
			UpperCaseButton[x][y] = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
			UpperCaseButton[x][y]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			UpperCaseButton[x][y]->SetScale(ButtonScale);
			UpperCaseButton[x][y]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			UpperCaseButton[x][y]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			UpperCaseButton[x][y]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval)*float4 { static_cast<float>(y), static_cast<float>(x) });
			UpperCaseButton[x][y]->SetReleaseImage("SelectButton_Release.Bmp");
			UpperCaseButton[x][y]->SetHoverImage("SelectButton_Release.Bmp");
			UpperCaseButton[x][y]->SetPressImage("SelectButton_Release.Bmp");
		}
	}
}

void SetPlayerName::SetUpperCaseRender()
{
	for (size_t x = 0; x < 5; x++) //¼¼·ÎÁ¤·Ä
	{
		for (size_t y = 0; y < 6; y++)
		{
			UpperCaseLetter1Render[x][y] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter1Render[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(0, 0, 0));
			float4 LetterRenderPos = UpperCaseButton[x][y]->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
			UpperCaseLetter1Render[x][y]->SetPosition(LetterRenderPos);

			UpperCaseLetter2Render[x][y] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter2Render[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(0, 0, 0));
			UpperCaseLetter2Render[x][y]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
		
			UpperCaseLetterEffect1Render[x][y] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetterEffect1Render[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(202, 184, 84));
			UpperCaseLetterEffect1Render[x][y]->SetPosition(LetterRenderPos);
			UpperCaseLetterEffect1Render[x][y]->Off();
			
			UpperCaseLetterEffect2Render[x][y] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect2Render[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(255, 255, 255));
			UpperCaseLetterEffect2Render[x][y]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
			UpperCaseLetterEffect2Render[x][y]->Off();
			
			UpperCaseLetterEffect3Render[x][y] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect3Render[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(236, 212, 98));
			UpperCaseLetterEffect3Render[x][y]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			UpperCaseLetterEffect3Render[x][y]->Off();

			UpperCaseLetterShadowRender[x][y] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
			UpperCaseLetterShadowRender[x][y]->SetText("A", LetterRenderHeight, "±¼¸²", TextAlign::Center, RGB(106, 170, 126));
			UpperCaseLetterShadowRender[x][y]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
		}
	}
}

//void SetPlayerName::SetLowerCaseButton()
//{
//
//}
