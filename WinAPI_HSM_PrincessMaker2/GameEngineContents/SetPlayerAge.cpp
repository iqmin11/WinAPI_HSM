#include "SetPlayerAge.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/Button.h>

#include "CharButton.h"
#include "FirstSetLevel.h"
#include "Olive.h"
#include "PlayerCalendar.h"
#include "ContentsEnums.h"

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

	PrintLetterRender1->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect1Color);
	PrintLetterRender2->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect2Color);
	PrintLetterRender3->SetText(" " + PrintLetter, LetterRenderHeight, TextType, TextAlign::Left, TextEffect3Color);
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
		AgeNumButtonRender1[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
		float4 LetterRenderPos = AgeNumButton[i]->GetPos() - GetPos() + (float4::Up.half() * (static_cast<float>(LetterRenderHeight) / 2));
		AgeNumButtonRender1[i]->SetPosition(LetterRenderPos);

		AgeNumButtonRender2[i] = CreateRender(PM2RenderOrder::Menu0_Display);
		AgeNumButtonRender2[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextColor);
		AgeNumButtonRender2[i]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

		AgeNumButtonEffect1Render[i] = CreateRender(PM2RenderOrder::Menu0_Display);
		AgeNumButtonEffect1Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color);
		AgeNumButtonEffect1Render[i]->SetPosition(LetterRenderPos);
		AgeNumButtonEffect1Render[i]->Off();

		AgeNumButtonEffect2Render[i] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
		AgeNumButtonEffect2Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color);
		AgeNumButtonEffect2Render[i]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
		AgeNumButtonEffect2Render[i]->Off();

		AgeNumButtonEffect3Render[i] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
		AgeNumButtonEffect3Render[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color);
		AgeNumButtonEffect3Render[i]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
		AgeNumButtonEffect3Render[i]->Off();

		AgeNumButtonShadowRender[i] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
		AgeNumButtonShadowRender[i]->SetText(Start, LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
		AgeNumButtonShadowRender[i]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	}
}

void SetPlayerAge::SetPrintLetterRender()
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

void SetPlayerAge::PushBack_Button(Button* _Button)
{
	CharButton* Ptr = dynamic_cast<CharButton*>(_Button);

	PrintLetter.push_back(Ptr->Chracter);
	//두자리수 가득 차있는 상태에서 번호를 input하면 뒷자리부터 수정하면서 앞자리 수를 밀어냄
}

void SetPlayerAge::SetCompleteButton()
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

void SetPlayerAge::SetCompleteButtonRender()
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

void SetPlayerAge::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	float4 SetExplainRenderPos = { 0,-36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextColor);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText("당신의 나이를 가르쳐 주세요", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetPlayerAge::ClickCompleteButton(Button* _Button)
{
	FirstSetLevel::SetStateValue(ActorState::PlayerCalendar);
	Olive::OlivePlayer->SetFatherAge(std::stoi(PrintLetter));
}


