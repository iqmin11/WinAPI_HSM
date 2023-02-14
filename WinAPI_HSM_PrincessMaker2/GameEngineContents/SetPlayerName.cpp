#include "SetPlayerName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

std::string SetPlayerName::PrintLetter = "\0";

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
	
	SetExplainRender();
	
	SetPrintLetterRender();
	
	SetUpperCaseButton();
	SetUpperCaseRender();

	SetLowerCaseButton();
	SetLowerCaseRender();

	SetCompleteButton();
	SetCompleteButtonRender();

	SetLetterEraseButton();
	SetLetterEraseButtonRender();

	UpperCaseButton[0][0]->SetClickCallBack(PushBack_A);
	UpperCaseButton[0][1]->SetClickCallBack(PushBack_B);
	UpperCaseButton[0][2]->SetClickCallBack(PushBack_C);
	UpperCaseButton[0][3]->SetClickCallBack(PushBack_D);
	UpperCaseButton[0][4]->SetClickCallBack(PushBack_E);
	UpperCaseButton[1][0]->SetClickCallBack(PushBack_F);
	UpperCaseButton[1][1]->SetClickCallBack(PushBack_G);
	UpperCaseButton[1][2]->SetClickCallBack(PushBack_H);
	UpperCaseButton[1][3]->SetClickCallBack(PushBack_I);
	UpperCaseButton[1][4]->SetClickCallBack(PushBack_J);
	UpperCaseButton[2][0]->SetClickCallBack(PushBack_K);
	UpperCaseButton[2][1]->SetClickCallBack(PushBack_L);
	UpperCaseButton[2][2]->SetClickCallBack(PushBack_M);
	UpperCaseButton[2][3]->SetClickCallBack(PushBack_N);
	UpperCaseButton[2][4]->SetClickCallBack(PushBack_O);
	UpperCaseButton[3][0]->SetClickCallBack(PushBack_P);
	UpperCaseButton[3][1]->SetClickCallBack(PushBack_Q);
	UpperCaseButton[3][2]->SetClickCallBack(PushBack_R);
	UpperCaseButton[3][3]->SetClickCallBack(PushBack_S);
	UpperCaseButton[3][4]->SetClickCallBack(PushBack_T);
	UpperCaseButton[4][0]->SetClickCallBack(PushBack_U);
	UpperCaseButton[4][1]->SetClickCallBack(PushBack_V);
	UpperCaseButton[4][2]->SetClickCallBack(PushBack_W);
	UpperCaseButton[4][3]->SetClickCallBack(PushBack_X);
	UpperCaseButton[4][4]->SetClickCallBack(PushBack_Y);
	UpperCaseButton[5][0]->SetClickCallBack(PushBack_Z);
	
	LowerCaseButton[0][0]->SetClickCallBack(PushBack_a);
	LowerCaseButton[0][1]->SetClickCallBack(PushBack_b);
	LowerCaseButton[0][2]->SetClickCallBack(PushBack_c);
	LowerCaseButton[0][3]->SetClickCallBack(PushBack_d);
	LowerCaseButton[0][4]->SetClickCallBack(PushBack_e);
	LowerCaseButton[1][0]->SetClickCallBack(PushBack_f);
	LowerCaseButton[1][1]->SetClickCallBack(PushBack_g);
	LowerCaseButton[1][2]->SetClickCallBack(PushBack_h);
	LowerCaseButton[1][3]->SetClickCallBack(PushBack_i);
	LowerCaseButton[1][4]->SetClickCallBack(PushBack_j);
	LowerCaseButton[2][0]->SetClickCallBack(PushBack_k);
	LowerCaseButton[2][1]->SetClickCallBack(PushBack_l);
	LowerCaseButton[2][2]->SetClickCallBack(PushBack_m);
	LowerCaseButton[2][3]->SetClickCallBack(PushBack_n);
	LowerCaseButton[2][4]->SetClickCallBack(PushBack_o);
	LowerCaseButton[3][0]->SetClickCallBack(PushBack_p);
	LowerCaseButton[3][1]->SetClickCallBack(PushBack_q);
	LowerCaseButton[3][2]->SetClickCallBack(PushBack_r);
	LowerCaseButton[3][3]->SetClickCallBack(PushBack_s);
	LowerCaseButton[3][4]->SetClickCallBack(PushBack_t);
	LowerCaseButton[4][0]->SetClickCallBack(PushBack_u);
	LowerCaseButton[4][1]->SetClickCallBack(PushBack_v);
	LowerCaseButton[4][2]->SetClickCallBack(PushBack_w);
	LowerCaseButton[4][3]->SetClickCallBack(PushBack_x);
	LowerCaseButton[4][4]->SetClickCallBack(PushBack_y);
	LowerCaseButton[5][0]->SetClickCallBack(PushBack_z);

	LetterEraseButton->SetClickCallBack(PopBack_PrintLetter);

	//CompleteButton->SetClickCallBack(NextActor);
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			if (y == 5 && x == 1)
			{
				break;
			}

			if (ButtonState::Release == UpperCaseButton[y][x]->GetState())
			{
				UpperCaseLetterEffect1Render[y][x]->Off();
				UpperCaseLetterEffect2Render[y][x]->Off();
				UpperCaseLetterEffect3Render[y][x]->Off();

				UpperCaseLetter1Render[y][x]->On();
				UpperCaseLetter2Render[y][x]->On();
				UpperCaseLetterShadowRender[y][x]->On();
			}
			else
			{
				UpperCaseLetterEffect1Render[y][x]->On();
				UpperCaseLetterEffect2Render[y][x]->On();
				UpperCaseLetterEffect3Render[y][x]->On();

				UpperCaseLetter1Render[y][x]->Off();
				UpperCaseLetter2Render[y][x]->Off();
				UpperCaseLetterShadowRender[y][x]->Off();
			}
		}
	}

	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			if (y == 5 && x == 1)
			{
				break;
			}

			if (ButtonState::Release == LowerCaseButton[y][x]->GetState())
			{
				LowerCaseLetterEffect1Render[y][x]->Off();
				LowerCaseLetterEffect2Render[y][x]->Off();
				LowerCaseLetterEffect3Render[y][x]->Off();

				LowerCaseLetter1Render[y][x]->On();
				LowerCaseLetter2Render[y][x]->On();
				LowerCaseLetterShadowRender[y][x]->On();
			}
			else
			{
				LowerCaseLetterEffect1Render[y][x]->On();
				LowerCaseLetterEffect2Render[y][x]->On();
				LowerCaseLetterEffect3Render[y][x]->On();

				LowerCaseLetter1Render[y][x]->Off();
				LowerCaseLetter2Render[y][x]->Off();
				LowerCaseLetterShadowRender[y][x]->Off();
			}
		}
	}

	if (ButtonState::Release == CompleteButton->GetState())
	{
		CompleteButtonEffect1Render->Off();
		CompleteButtonEffect2Render->Off();
		CompleteButtonEffect3Render->Off();

		CompleteButton1Render->On();
		CompleteButton2Render->On();
		CompleteButtonShadowRender->On();
	}
	else
	{
		CompleteButtonEffect1Render->On();
		CompleteButtonEffect2Render->On();
		CompleteButtonEffect3Render->On();

		CompleteButton1Render->Off();
		CompleteButton2Render->Off();
		CompleteButtonShadowRender->Off();
	}

	if (ButtonState::Release == LetterEraseButton->GetState())
	{
		LetterEraseButtonEffect1Render->Off();
		LetterEraseButtonEffect2Render->Off();
		LetterEraseButtonEffect3Render->Off();

		LetterEraseButton1Render->On();
		LetterEraseButton2Render->On();
		LetterEraseButtonShadowRender->On();
	}
	else
	{
		LetterEraseButtonEffect1Render->On();
		LetterEraseButtonEffect2Render->On();
		LetterEraseButtonEffect3Render->On();

		LetterEraseButton1Render->Off();
		LetterEraseButton2Render->Off();
		LetterEraseButtonShadowRender->Off();
	}
	
	
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor);
	PrintLetterShadow->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextShadowColor);
}

void SetPlayerName::Render(float _DeltaTime)
{
}

void SetPlayerName::On()
{
	GameEngineObject::On();
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			if (y == 5 && x == 1)
			{
				break;
			}
			UpperCaseButton[y][x]->On();
			LowerCaseButton[y][x]->On();
			
		}
	}
	CompleteButton->On();
}

void SetPlayerName::Off()
{
	GameEngineObject::Off();
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			UpperCaseButton[y][x]->Off();
			LowerCaseButton[y][x]->Off();
		}
	}
	CompleteButton->Off();
}

void SetPlayerName::SetPrintLetterRender()
{
	PrintLetterRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor);
	float4 SetPrintLetterRenderPos = { -60,-60 };
	PrintLetterRender1->SetPosition(SetPrintLetterRenderPos);

	PrintLetterRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor);
	PrintLetterRender2->SetPosition(SetPrintLetterRenderPos + float4::Up * float4{ 0,1 });

	PrintLetterShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	PrintLetterShadow->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextShadowColor);
	PrintLetterShadow->SetPosition(SetPrintLetterRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText("당신의 성은 무엇입니까? (4자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	float4 SetExplainRenderPos = { -36,-36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText("당신의 성은 무엇입니까? (4자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText("당신의 성은 무엇입니까? (4자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetUpperCaseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 182, 312 };

	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			UpperCaseButton[y][x] = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
			UpperCaseButton[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			UpperCaseButton[y][x]->SetScale(ButtonScale);
			UpperCaseButton[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			UpperCaseButton[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			UpperCaseButton[y][x]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(y), static_cast<float>(x) });
			UpperCaseButton[y][x]->SetReleaseImage("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->SetHoverImage("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->SetPressImage("SelectButton_Release.Bmp");
		}
	}
}

void SetPlayerName::SetUpperCaseRender()
{
	int Count = 0;
	for (size_t y = 0; y < 6; y++) //세로정렬
	{
		for (size_t x = 0; x < 5; x++)
		{
			std::string Start = "A";
			Start[0] += Count++;

			UpperCaseLetter1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
			float4 LetterRenderPos = UpperCaseButton[y][x]->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
			UpperCaseLetter1Render[y][x]->SetPosition(LetterRenderPos);

			UpperCaseLetter2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
			UpperCaseLetter2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

			UpperCaseLetterEffect1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetterEffect1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color);
			UpperCaseLetterEffect1Render[y][x]->SetPosition(LetterRenderPos);
			UpperCaseLetterEffect1Render[y][x]->Off();

			UpperCaseLetterEffect2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
			UpperCaseLetterEffect2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
			UpperCaseLetterEffect2Render[y][x]->Off();

			UpperCaseLetterEffect3Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect3Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color);
			UpperCaseLetterEffect3Render[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			UpperCaseLetterEffect3Render[y][x]->Off();

			UpperCaseLetterShadowRender[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
			UpperCaseLetterShadowRender[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
			UpperCaseLetterShadowRender[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });

			if ("Z" == Start)
			{
				break;
			}
		}
	}
}

void SetPlayerName::SetLowerCaseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 422, 312 };

	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			LowerCaseButton[y][x] = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
			LowerCaseButton[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			LowerCaseButton[y][x]->SetScale(ButtonScale);
			LowerCaseButton[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			LowerCaseButton[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			LowerCaseButton[y][x]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(y), static_cast<float>(x) });
			LowerCaseButton[y][x]->SetReleaseImage("SelectButton_Release.Bmp");
			LowerCaseButton[y][x]->SetHoverImage("SelectButton_Release.Bmp");
			LowerCaseButton[y][x]->SetPressImage("SelectButton_Release.Bmp");
		}
	}
}


void SetPlayerName::SetLowerCaseRender()
{
	int Count = 0;
	for (size_t y = 0; y < 6; y++) //세로정렬
	{
		for (size_t x = 0; x < 5; x++)
		{
			std::string Start = "a";
			Start[0] += Count++;
			LowerCaseLetter1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetter1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
			float4 LetterRenderPos = LowerCaseButton[y][x]->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
			LowerCaseLetter1Render[y][x]->SetPosition(LetterRenderPos);

			LowerCaseLetter2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetter2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
			LowerCaseLetter2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

			LowerCaseLetterEffect1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetterEffect1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color);
			LowerCaseLetterEffect1Render[y][x]->SetPosition(LetterRenderPos);
			LowerCaseLetterEffect1Render[y][x]->Off();

			LowerCaseLetterEffect2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			LowerCaseLetterEffect2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
			LowerCaseLetterEffect2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
			LowerCaseLetterEffect2Render[y][x]->Off();

			LowerCaseLetterEffect3Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			LowerCaseLetterEffect3Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color);
			LowerCaseLetterEffect3Render[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			LowerCaseLetterEffect3Render[y][x]->Off();

			LowerCaseLetterShadowRender[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
			LowerCaseLetterShadowRender[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
			LowerCaseLetterShadowRender[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			if ("z" == Start)
			{
				break;
			}
		}
	}
}

void SetPlayerName::SetCompleteButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 194, 448 };

	CompleteButton = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
	CompleteButton->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	CompleteButton->SetScale(ButtonScale2);
	CompleteButton->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
	CompleteButton->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
	CompleteButton->SetPos(ButtonStartPosition);
	CompleteButton->SetReleaseImage("SelectButton_Release.Bmp");
	CompleteButton->SetHoverImage("SelectButton_Release.Bmp");
	CompleteButton->SetPressImage("SelectButton_Release.Bmp");
}

void SetPlayerName::SetCompleteButtonRender()
{
	CompleteButton1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButton1Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	float4 ButtonStartPosition = CompleteButton->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
	CompleteButton1Render->SetPosition(ButtonStartPosition);

	CompleteButton2Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButton2Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	CompleteButton2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });

	CompleteButtonEffect1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButtonEffect1Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color);
	CompleteButtonEffect1Render->SetPosition(ButtonStartPosition);
	CompleteButtonEffect1Render->Off();
	
	CompleteButtonEffect2Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CompleteButtonEffect2Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
	CompleteButtonEffect2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });
	CompleteButtonEffect2Render->Off();
	
	CompleteButtonEffect3Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CompleteButtonEffect3Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
	CompleteButtonEffect3Render->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
	CompleteButtonEffect3Render->Off();

	CompleteButtonShadowRender = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	CompleteButtonShadowRender->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	CompleteButtonShadowRender->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetLetterEraseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 266, 448 };

	LetterEraseButton = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
	LetterEraseButton->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	LetterEraseButton->SetScale(ButtonScale2);
	LetterEraseButton->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
	LetterEraseButton->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
	LetterEraseButton->SetPos(ButtonStartPosition);
	LetterEraseButton->SetReleaseImage("SelectButton_Release.Bmp");
	LetterEraseButton->SetHoverImage("SelectButton_Release.Bmp");
	LetterEraseButton->SetPressImage("SelectButton_Release.Bmp");
}

void SetPlayerName::SetLetterEraseButtonRender()
{
	LetterEraseButton1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButton1Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	float4 ButtonStartPosition = LetterEraseButton->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
	LetterEraseButton1Render->SetPosition(ButtonStartPosition);

	LetterEraseButton2Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButton2Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	LetterEraseButton2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });

	LetterEraseButtonEffect1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButtonEffect1Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color);
	LetterEraseButtonEffect1Render->SetPosition(ButtonStartPosition);
	LetterEraseButtonEffect1Render->Off();

	LetterEraseButtonEffect2Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	LetterEraseButtonEffect2Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
	LetterEraseButtonEffect2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });
	LetterEraseButtonEffect2Render->Off();

	LetterEraseButtonEffect3Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	LetterEraseButtonEffect3Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
	LetterEraseButtonEffect3Render->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
	LetterEraseButtonEffect3Render->Off();

	LetterEraseButtonShadowRender = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	LetterEraseButtonShadowRender->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	LetterEraseButtonShadowRender->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
}

void SetPlayerName::PushBack_A()
{
	//if (4 < PrintLetter.size())
	//{
	//	return;
	//}
	PrintLetter.push_back('A');
}

void SetPlayerName::PushBack_B()
{
	PrintLetter.push_back('B');
}

void SetPlayerName::PushBack_C()
{
	PrintLetter.push_back('C');
}

void SetPlayerName::PushBack_D()
{
	PrintLetter.push_back('D');
}

void SetPlayerName::PushBack_E()
{
	PrintLetter.push_back('E');
}

void SetPlayerName::PushBack_F()
{
	PrintLetter.push_back('F');
}

void SetPlayerName::PushBack_G()
{
	PrintLetter.push_back('G');
}

void SetPlayerName::PushBack_H()
{
	PrintLetter.push_back('H');
}

void SetPlayerName::PushBack_I()
{
	PrintLetter.push_back('I');
}

void SetPlayerName::PushBack_J()
{
	PrintLetter.push_back('J');
}

void SetPlayerName::PushBack_K()
{
	PrintLetter.push_back('K');
}

void SetPlayerName::PushBack_L()
{
	PrintLetter.push_back('L');
}

void SetPlayerName::PushBack_M()
{
	PrintLetter.push_back('M');
}

void SetPlayerName::PushBack_N()
{
	PrintLetter.push_back('N');
}

void SetPlayerName::PushBack_O()
{
	PrintLetter.push_back('O');
}

void SetPlayerName::PushBack_P()
{
	PrintLetter.push_back('P');
}

void SetPlayerName::PushBack_Q()
{
	PrintLetter.push_back('Q');
}

void SetPlayerName::PushBack_R()
{
	PrintLetter.push_back('R');
}

void SetPlayerName::PushBack_S()
{
	PrintLetter.push_back('S');
}

void SetPlayerName::PushBack_T()
{
	PrintLetter.push_back('T');
}

void SetPlayerName::PushBack_U()
{
	PrintLetter.push_back('U');
}

void SetPlayerName::PushBack_V()
{
	PrintLetter.push_back('V');
}

void SetPlayerName::PushBack_W()
{
	PrintLetter.push_back('W');
}

void SetPlayerName::PushBack_X()
{
	PrintLetter.push_back('X');
}

void SetPlayerName::PushBack_Y()
{
	PrintLetter.push_back('Y');
}

void SetPlayerName::PushBack_Z()
{
	PrintLetter.push_back('Z');
}

void SetPlayerName::PushBack_a()
{
	PrintLetter.push_back('a');
}

void SetPlayerName::PushBack_b()
{
	PrintLetter.push_back('b');
}

void SetPlayerName::PushBack_c()
{
	PrintLetter.push_back('c');
}

void SetPlayerName::PushBack_d()
{
	PrintLetter.push_back('d');
}

void SetPlayerName::PushBack_e()
{
	PrintLetter.push_back('e');
}

void SetPlayerName::PushBack_f()
{
	PrintLetter.push_back('f');
}

void SetPlayerName::PushBack_g()
{
	PrintLetter.push_back('g');
}

void SetPlayerName::PushBack_h()
{
	PrintLetter.push_back('h');
}

void SetPlayerName::PushBack_i()
{
	PrintLetter.push_back('i');
}

void SetPlayerName::PushBack_j()
{
	PrintLetter.push_back('j');
}

void SetPlayerName::PushBack_k()
{
	PrintLetter.push_back('k');
}

void SetPlayerName::PushBack_l()
{
	PrintLetter.push_back('l');
}

void SetPlayerName::PushBack_m()
{
	PrintLetter.push_back('m');
}

void SetPlayerName::PushBack_n()
{
	PrintLetter.push_back('n');
}

void SetPlayerName::PushBack_o()
{
	PrintLetter.push_back('o');
}

void SetPlayerName::PushBack_p()
{
	PrintLetter.push_back('p');
}

void SetPlayerName::PushBack_q()
{
	PrintLetter.push_back('q');
}

void SetPlayerName::PushBack_r()
{
	PrintLetter.push_back('r');
}

void SetPlayerName::PushBack_s()
{
	PrintLetter.push_back('s');
}

void SetPlayerName::PushBack_t()
{
	PrintLetter.push_back('t');
}

void SetPlayerName::PushBack_u()
{
	PrintLetter.push_back('u');
}

void SetPlayerName::PushBack_v()
{
	PrintLetter.push_back('v');
}

void SetPlayerName::PushBack_w()
{
	PrintLetter.push_back('w');
}

void SetPlayerName::PushBack_x()
{
	PrintLetter.push_back('x');
}

void SetPlayerName::PushBack_y()
{
	PrintLetter.push_back('y');
}

void SetPlayerName::PushBack_z()
{
	PrintLetter.push_back('z');
}

void SetPlayerName::PopBack_PrintLetter()
{
	if (0 >= PrintLetter.size())
	{
		return;
	}
	PrintLetter.pop_back();
}

