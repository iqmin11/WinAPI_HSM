#include "SetPlayerName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "CharButton.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "FirstSetLevel.h"
#include "SetOliveName.h"
#include "Olive.h"

#include "ContentsEnums.h"

bool SetPlayerName::FirstUpdate = false;

std::string SetPlayerName::PrintLetter = "\0";
GameEngineRender* SetPlayerName::ExplainRender1 = nullptr;
GameEngineRender* SetPlayerName::ExplainRender2 = nullptr;
GameEngineRender* SetPlayerName::ExplainRenderShadow = nullptr;

std::string SetPlayerName::ExplainText = "당신의 성은 무엇입니까? (8자이내)";
std::string SetPlayerName::ErrorText = "이름이 필요해요";
float4 SetPlayerName::ExplainTextBoxScale = { 300, 18 };
float4 SetPlayerName::ErrorTextBoxScale = { 200, 18 };

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
		
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
	if (!FirstUpdate)
	{
		FirstUpdate = true;
		PrintLetter = "\0";
		ExplainRender1->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
		ExplainRender2->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
		ExplainRenderShadow->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ExplainTextBoxScale);
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
	
	
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect1Color, PrintLetterBoxScale);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect2Color, PrintLetterBoxScale);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect3Color, PrintLetterBoxScale);
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
	LetterEraseButton->On();
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
	LetterEraseButton->Off();
}

void SetPlayerName::SetPrintLetterRender()
{
	PrintLetterRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor, PrintLetterBoxScale);
	float4 SetPrintLetterRenderPos = -PrintLetterBoxScale.half() - float4{ 60, 60 };
	PrintLetterRender1->SetPosition(SetPrintLetterRenderPos);

	PrintLetterRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextColor, PrintLetterBoxScale);
	PrintLetterRender2->SetPosition(SetPrintLetterRenderPos + float4::Up * float4{ 0,1 });

	PrintLetterRender3 = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextShadowColor, PrintLetterBoxScale);
	PrintLetterRender3->SetPosition(SetPrintLetterRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	float4 SetExplainRenderPos = -ExplainTextBoxScale.half() - float4{ 36, 36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText(ExplainText, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ExplainTextBoxScale);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetUpperCaseButton()
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
			UpperCaseButton[y][x]->SetHoverImage  ("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->SetPressImage  ("SelectButton_Release.Bmp");
			UpperCaseButton[y][x]->Chracter = Start++;
			UpperCaseButton[y][x]->SetClickCallBack(PushBack_Button);
		}
	}
}

void SetPlayerName::SetUpperCaseRender()
{
	int Count = 0;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			std::string Start = "A";
			Start[0] += Count++;

			UpperCaseLetter1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
			float4 LetterRenderPos = UpperCaseButton[y][x]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2)};
			UpperCaseLetter1Render[y][x]->SetPosition(LetterRenderPos);

			UpperCaseLetter2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetter2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
			UpperCaseLetter2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

			UpperCaseLetterEffect1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			UpperCaseLetterEffect1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
			UpperCaseLetterEffect1Render[y][x]->SetPosition(LetterRenderPos);
			UpperCaseLetterEffect1Render[y][x]->Off();

			UpperCaseLetterEffect2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
			UpperCaseLetterEffect2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
			UpperCaseLetterEffect2Render[y][x]->Off();

			UpperCaseLetterEffect3Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			UpperCaseLetterEffect3Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
			UpperCaseLetterEffect3Render[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			UpperCaseLetterEffect3Render[y][x]->Off();

			UpperCaseLetterShadowRender[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
			UpperCaseLetterShadowRender[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
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


void SetPlayerName::SetLowerCaseRender()
{
	int Count = 0;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			std::string Start = "a";
			Start[0] += Count++;
			LowerCaseLetter1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetter1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
			float4 LetterRenderPos = LowerCaseButton[y][x]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
			LowerCaseLetter1Render[y][x]->SetPosition(LetterRenderPos);

			LowerCaseLetter2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetter2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
			LowerCaseLetter2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

			LowerCaseLetterEffect1Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display);
			LowerCaseLetterEffect1Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
			LowerCaseLetterEffect1Render[y][x]->SetPosition(LetterRenderPos);
			LowerCaseLetterEffect1Render[y][x]->Off();

			LowerCaseLetterEffect2Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			LowerCaseLetterEffect2Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
			LowerCaseLetterEffect2Render[y][x]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
			LowerCaseLetterEffect2Render[y][x]->Off();

			LowerCaseLetterEffect3Render[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
			LowerCaseLetterEffect3Render[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
			LowerCaseLetterEffect3Render[y][x]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
			LowerCaseLetterEffect3Render[y][x]->Off();

			LowerCaseLetterShadowRender[y][x] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
			LowerCaseLetterShadowRender[y][x]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
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

	CompleteButton = Level->CreateActor<GlobalButton>(PM2ActorOrder::Menu0_Button);
	CompleteButton->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	CompleteButton->SetScale(ButtonScale2);
	CompleteButton->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
	CompleteButton->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
	CompleteButton->SetPos(ButtonStartPosition);
	CompleteButton->SetReleaseImage("SelectButton_Release.Bmp");
	CompleteButton->SetHoverImage  ("SelectButton_Release.Bmp");
	CompleteButton->SetPressImage  ("SelectButton_Release.Bmp");
	CompleteButton->SetClickCallBack(ClickCompleteButton);
}

void SetPlayerName::SetCompleteButtonRender()
{
	CompleteButton1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButton1Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale2);
	float4 ButtonStartPosition = CompleteButton->GetPos() - GetPos() - float4{ ButtonScale2.hx(), static_cast<float>(LetterRenderHeight / 2) };
	CompleteButton1Render->SetPosition(ButtonStartPosition);

	CompleteButton2Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButton2Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale2);
	CompleteButton2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });

	CompleteButtonEffect1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	CompleteButtonEffect1Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale2);
	CompleteButtonEffect1Render->SetPosition(ButtonStartPosition);
	CompleteButtonEffect1Render->Off();
	
	CompleteButtonEffect2Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CompleteButtonEffect2Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale2);
	CompleteButtonEffect2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });
	CompleteButtonEffect2Render->Off();
	
	CompleteButtonEffect3Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	CompleteButtonEffect3Render->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale2);
	CompleteButtonEffect3Render->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
	CompleteButtonEffect3Render->Off();

	CompleteButtonShadowRender = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	CompleteButtonShadowRender->SetText("완료", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale2);
	CompleteButtonShadowRender->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
}

void SetPlayerName::SetLetterEraseButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { 266, 448 };

	LetterEraseButton = Level->CreateActor<GlobalButton>(PM2ActorOrder::Menu0_Button);
	LetterEraseButton->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	LetterEraseButton->SetScale(ButtonScale2);
	LetterEraseButton->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
	LetterEraseButton->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
	LetterEraseButton->SetPos(ButtonStartPosition);
	LetterEraseButton->SetReleaseImage("SelectButton_Release.Bmp");
	LetterEraseButton->SetHoverImage  ("SelectButton_Release.Bmp");
	LetterEraseButton->SetPressImage  ("SelectButton_Release.Bmp");
	LetterEraseButton->SetClickCallBack(PopBack_PrintLetter);
}

void SetPlayerName::SetLetterEraseButtonRender()
{
	LetterEraseButton1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButton1Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale2);
	float4 ButtonStartPosition = LetterEraseButton->GetPos() - GetPos() - float4{ ButtonScale2.hx(), static_cast<float>(LetterRenderHeight / 2) };
	LetterEraseButton1Render->SetPosition(ButtonStartPosition);

	LetterEraseButton2Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButton2Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale2);
	LetterEraseButton2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });

	LetterEraseButtonEffect1Render = CreateRender(PM2RenderOrder::Menu0_Display);
	LetterEraseButtonEffect1Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale2);
	LetterEraseButtonEffect1Render->SetPosition(ButtonStartPosition);
	LetterEraseButtonEffect1Render->Off();

	LetterEraseButtonEffect2Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	LetterEraseButtonEffect2Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale2);
	LetterEraseButtonEffect2Render->SetPosition(ButtonStartPosition + float4::Up * float4{ 0,1 });
	LetterEraseButtonEffect2Render->Off();

	LetterEraseButtonEffect3Render = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	LetterEraseButtonEffect3Render->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale2);
	LetterEraseButtonEffect3Render->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
	LetterEraseButtonEffect3Render->Off();

	LetterEraseButtonShadowRender = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	LetterEraseButtonShadowRender->SetText("뒤로", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale2);
	LetterEraseButtonShadowRender->SetPosition(ButtonStartPosition + float4::Down * float4{ 0,1 });
}


void SetPlayerName::PushBack_Button(Button* _Btn)
{
	if (8 <= PrintLetter.size())
	{
		return;
	}
	CharButton* Ptr = dynamic_cast<CharButton*>(_Btn);

	PrintLetter.push_back(Ptr->Chracter);
}

void SetPlayerName::PopBack_PrintLetter(Button* Button)
{
	if (0 >= PrintLetter.size())
	{
		return;
	}
	PrintLetter.pop_back();
}

void SetPlayerName::ClickCompleteButton(Button* _Btn)
{
	if (0 == PrintLetter.size())
	{
		ExplainRender1->SetText(ErrorText, 18, "굴림", TextAlign::Center, RGB(0, 0, 0), ErrorTextBoxScale);
		ExplainRender2->SetText(ErrorText, 18, "굴림", TextAlign::Center, RGB(0, 0, 0), ErrorTextBoxScale);
		ExplainRenderShadow->SetText(ErrorText, 18, "굴림", TextAlign::Center, RGB(106, 170, 126), ErrorTextBoxScale);
		return;
	}
	FirstSetLevel::SetStateValue(ActorState::SetOliveName);
	Olive::OlivePlayer->SetOliveLastName(PrintLetter);
	FirstUpdate = false;

	SetOliveName::FirstUpdate = false;
}

