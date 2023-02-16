#include "SetOliveName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "CharButton.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FirstSetLevel.h"
#include "OliveCalendar.h"
#include "Olive.h"

#include "ContentsEnums.h"

bool SetOliveName::FirstUpdate = false;
std::string SetOliveName::PrintLetter = "\0";
GameEngineRender* SetOliveName::ExplainRender1 = nullptr;
GameEngineRender* SetOliveName::ExplainRender2 = nullptr;
GameEngineRender* SetOliveName::ExplainRenderShadow = nullptr;

SetOliveName::SetOliveName()
{

}

SetOliveName::~SetOliveName()
{
}


void SetOliveName::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetOliveBackground.BMP", PM2RenderOrder::BackGround);
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
	
	Off();
}

void SetOliveName::Update(float _DeltaTime)
{
	if (!FirstUpdate) // 초기화
	{
		FirstUpdate = true;
		PrintLetter = "\0";
		ExplainRender1->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
		ExplainRender2->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
		ExplainRenderShadow->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	}
	
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


	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect1Color);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect2Color);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect3Color);
}

void SetOliveName::Render(float _DeltaTime)
{
}

void SetOliveName::On()
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

void SetOliveName::Off()
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

void SetOliveName::SetPrintLetterRender()
{
	PrintLetterRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect1Color);
	float4 SetPrintLetterRenderPos = { -60,-60 };
	PrintLetterRender1->SetPosition(SetPrintLetterRenderPos);

	PrintLetterRender2 = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect2Color);
	PrintLetterRender2->SetPosition(SetPrintLetterRenderPos + float4::Up * float4{ 0,1 });

	PrintLetterRender3 = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect3Color);
	PrintLetterRender3->SetPosition(SetPrintLetterRenderPos + float4::Down * float4{ 0,1 });
}

void SetOliveName::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	float4 SetExplainRenderPos = { -36,-36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText("딸의 이름을 지어주세요 (8자이내)", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetOliveName::SetUpperCaseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 182, 312 };

	char Start = 'A';

	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			UpperCaseButton[y][x] = Level->CreateActor<CharButton>(PM2ActorOrder::Menu0_Button);
			UpperCaseButton[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			UpperCaseButton[y][x]->SetScale(ButtonScale);
			UpperCaseButton[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			UpperCaseButton[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			UpperCaseButton[y][x]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(y), static_cast<float>(x) });
			UpperCaseButton[y][x]->SetReleaseImage("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->SetHoverImage("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->SetPressImage("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->Chracter = Start++;
			UpperCaseButton[y][x]->SetClickCallBack(PushBack_Button);
		}
	}
}

void SetOliveName::SetUpperCaseRender()
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

void SetOliveName::SetLowerCaseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 422, 312 };

	char Start = 'a';

	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			LowerCaseButton[y][x] = Level->CreateActor<CharButton>(PM2ActorOrder::Menu0_Button);
			LowerCaseButton[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			LowerCaseButton[y][x]->SetScale(ButtonScale);
			LowerCaseButton[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			LowerCaseButton[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			LowerCaseButton[y][x]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(y), static_cast<float>(x) });
			LowerCaseButton[y][x]->SetReleaseImage("SelectButton_Release.Bmp");
			LowerCaseButton[y][x]->SetHoverImage("SelectButton_Release.Bmp");
			LowerCaseButton[y][x]->SetPressImage("SelectButton_Release.Bmp");
			LowerCaseButton[y][x]->Chracter = Start++;
			LowerCaseButton[y][x]->SetClickCallBack(PushBack_Button);
		}
	}
}


void SetOliveName::SetLowerCaseRender()
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

void SetOliveName::SetCompleteButton()
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
	CompleteButton->SetClickCallBack(ClickCompleteButton);
}

void SetOliveName::SetCompleteButtonRender()
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

void SetOliveName::SetLetterEraseButton()
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
	LetterEraseButton->SetClickCallBack(PopBack_PrintLetter);
}

void SetOliveName::SetLetterEraseButtonRender()
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


void SetOliveName::PushBack_Button(Button* _Button)
{
	if (8 <= PrintLetter.size())
	{
		return;
	}
	CharButton* Ptr = dynamic_cast<CharButton*>(_Button);

	PrintLetter.push_back(Ptr->Chracter);
}

void SetOliveName::PopBack_PrintLetter(Button* _Button)
{
	if (0 >= PrintLetter.size())
	{
		FirstSetLevel::SetStateValue(ActorState::SetPlayerName);
		return;
	}

	PrintLetter.pop_back();
}

void SetOliveName::ClickCompleteButton(Button* _Button)
{
	if (0 == PrintLetter.size())
	{
		ExplainRender1->SetText("이름이 필요해요", 18, "굴림", TextAlign::Center, RGB(0, 0, 0));
		ExplainRender2->SetText("이름이 필요해요", 18, "굴림", TextAlign::Center, RGB(0, 0, 0));
		ExplainRenderShadow->SetText("이름이 필요해요", 18, "굴림", TextAlign::Center, RGB(192, 120, 178));
		return;
	}
	
	FirstSetLevel::SetStateValue(ActorState::OliveCalendar);
	Olive::OlivePlayer->SetOliveFirstName(PrintLetter);
	FirstUpdate = false;

	OliveCalendar::FirstUpdate = false;
}

