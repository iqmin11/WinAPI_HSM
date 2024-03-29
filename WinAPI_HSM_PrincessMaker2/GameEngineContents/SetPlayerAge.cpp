#include "SetPlayerAge.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/Button.h>

#include "CharButton.h"
#include "FirstSetLevel.h"
#include "Olive.h"
#include "PlayerCalendar.h"
#include "ContentsEnums.h"

bool SetPlayerAge::FirstUpdate = false;
std::string SetPlayerAge::PrintLetter = std::string();

SetPlayerAge::SetPlayerAge()
{

}

SetPlayerAge::~SetPlayerAge()
{

}

void SetPlayerAge::On()
{
	GameEngineObject::On();
	for (size_t i = 0; i < 10; i++)
	{
		AgeNumButton[i]->On();
	}
	CompleteButton->On();
}

void SetPlayerAge::Off()
{
	GameEngineObject::Off();
	for (size_t i = 0; i < 10; i++)
	{
		AgeNumButton[i]->Off();
	}
	CompleteButton->Off();

}

void SetPlayerAge::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetPlayerBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	SetAgeNumButton();
	SetAgeNumRender();

	SetPrintLetterRender();
	SetExplainRender();

	SetCompleteButton();
	SetCompleteButtonRender();


	Off();
}

void SetPlayerAge::Update(float _DeltaTime)
{
	if (!FirstUpdate) 
	{
		FirstUpdate = true;
		PrintLetter = "\0";
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (ButtonState::Release == AgeNumButton[i]->GetState())
		{
			AgeNumButtonEffect1Render[i]->Off();
			AgeNumButtonEffect2Render[i]->Off();
			AgeNumButtonEffect3Render[i]->Off();

			AgeNumButtonRender1[i]->On();
			AgeNumButtonRender2[i]->On();
			AgeNumButtonShadowRender[i]->On();
		}
		else
		{
			AgeNumButtonEffect1Render[i]->On();
			AgeNumButtonEffect2Render[i]->On();
			AgeNumButtonEffect3Render[i]->On();

			AgeNumButtonRender1[i]->Off();
			AgeNumButtonRender2[i]->Off();
			AgeNumButtonShadowRender[i]->Off();
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

	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect1Color, PrintLetterBoxScale);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect2Color, PrintLetterBoxScale);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect3Color, PrintLetterBoxScale);
	
}

void SetPlayerAge::Render(float _DeltaTime)
{
}

void SetPlayerAge::SetAgeNumButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { GameEngineWindow::GetScreenSize().half().x + float4::Left.x * 9 * (ButtonScale.hx() + ButtonInterval.hx()), 360 };

	char Start = '0';

	for (size_t i = 0; i < 10; i++)
	{
		AgeNumButton[i] = Level->CreateActor<CharButton>(PM2ActorOrder::Menu0_Button);
		AgeNumButton[i]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
		AgeNumButton[i]->SetScale(ButtonScale);
		AgeNumButton[i]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
		AgeNumButton[i]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
		AgeNumButton[i]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(i), 0 });
		AgeNumButton[i]->SetReleaseImage("SelectButton_Release.Bmp");
		AgeNumButton[i]->SetHoverImage("SelectButton_Release.Bmp");
		AgeNumButton[i]->SetPressImage("SelectButton_Release.Bmp");
		AgeNumButton[i]->Chracter = Start++;
		AgeNumButton[i]->SetClickCallBack(PushBack_Button);
	}
}

void SetPlayerAge::SetAgeNumRender()
{
	int Count = 0;
	for (size_t i = 0; i < 10; i++)
	{
		std::string Start = "0";
		Start[0] += Count++;

		AgeNumButtonRender1[i] = CreateRender(PM2RenderOrder::Menu0_Display);
		AgeNumButtonRender1[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
		float4 LetterRenderPos = AgeNumButton[i]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
		AgeNumButtonRender1[i]->SetPosition(LetterRenderPos);

		AgeNumButtonRender2[i] = CreateRender(PM2RenderOrder::Menu0_Display);
		AgeNumButtonRender2[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
		AgeNumButtonRender2[i]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

		AgeNumButtonEffect1Render[i] = CreateRender(PM2RenderOrder::Menu0_Display);
		AgeNumButtonEffect1Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
		AgeNumButtonEffect1Render[i]->SetPosition(LetterRenderPos);
		AgeNumButtonEffect1Render[i]->Off();

		AgeNumButtonEffect2Render[i] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
		AgeNumButtonEffect2Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
		AgeNumButtonEffect2Render[i]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
		AgeNumButtonEffect2Render[i]->Off();

		AgeNumButtonEffect3Render[i] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
		AgeNumButtonEffect3Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
		AgeNumButtonEffect3Render[i]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
		AgeNumButtonEffect3Render[i]->Off();

		AgeNumButtonShadowRender[i] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
		AgeNumButtonShadowRender[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
		AgeNumButtonShadowRender[i]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	}
}

void SetPlayerAge::SetPrintLetterRender()
{
	PrintLetterRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect1Color, PrintLetterBoxScale);
	float4 SetPrintLetterRenderPos = -PrintLetterBoxScale.half() - float4{ 30,60 };
	PrintLetterRender1->SetPosition(SetPrintLetterRenderPos);

	PrintLetterRender2 = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect2Color, PrintLetterBoxScale);
	PrintLetterRender2->SetPosition(SetPrintLetterRenderPos + float4::Up * float4{ 0,1 });

	PrintLetterRender3 = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Right, TextEffect3Color, PrintLetterBoxScale);
	PrintLetterRender3->SetPosition(SetPrintLetterRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerAge::PushBack_Button(Button* _Button)
{
	CharButton* Ptr = dynamic_cast<CharButton*>(_Button);

	if (2 <= PrintLetter.size())
	{
		PrintLetter[0] = PrintLetter[1];
		PrintLetter[1] = Ptr->Chracter;
	}
	else
	{
		PrintLetter.push_back(Ptr->Chracter);
	}
	
	if ("00" == PrintLetter)
	{
		PrintLetter = "0";
	}
}

void SetPlayerAge::SetCompleteButton()
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
	CompleteButton->SetHoverImage("SelectButton_Release.Bmp");
	CompleteButton->SetPressImage("SelectButton_Release.Bmp");
	CompleteButton->SetClickCallBack(ClickCompleteButton);
}

void SetPlayerAge::SetCompleteButtonRender()
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

void SetPlayerAge::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	float4 SetExplainRenderPos = -ExplainTextBoxScale.half() - float4{ 0, 36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ExplainTextBoxScale);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerAge::ClickCompleteButton(Button* _Button)
{
	if (PrintLetter.size() == 0)
	{
		return;
	}
	int AgeValue = std::stoi(PrintLetter);
	if (10 > AgeValue || 99 < AgeValue)
	{
		return;
	}
	FirstSetLevel::SetStateValue(ActorState::PlayerCalendar);
	Olive::OlivePlayer->SetFatherAge(AgeValue);
	FirstUpdate = false;
	PlayerCalendar::FirstUpdate = false;
}


