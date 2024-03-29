#include "SetOliveBloodType.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "Olive.h"
#include "Button_BloodType.h"
#include <GameEngineCore/Button.h>
#include "ContentsEnums.h"

bool SetOliveBloodType::FirstUpdate = false;
SetOliveBloodType::SetOliveBloodType()
{

}

SetOliveBloodType::~SetOliveBloodType()
{

}

void SetOliveBloodType::On()
{
	GameEngineObject::On();
	for (size_t i = 0; i < 4; i++)
	{
		BloodTypeButton[i]->On();
	}
}

void SetOliveBloodType::Off()
{
	GameEngineObject::Off();
	for (size_t i = 0; i < 4; i++)
	{
		BloodTypeButton[i]->Off();
	}
}

void SetOliveBloodType::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetOliveBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	SetExplainRender();
	SetBloodTypeButton();
	SetBloodTypeButtonRender();

	Off();
}

void SetOliveBloodType::Update(float _DeltaTime)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (ButtonState::Release == BloodTypeButton[i]->GetState())
		{
			BloodTypeButtonEffect1Render[i]->Off();
			BloodTypeButtonEffect2Render[i]->Off();
			BloodTypeButtonEffect3Render[i]->Off();

			BloodTypeButtonRender1[i]->On();
			BloodTypeButtonRender2[i]->On();
			BloodTypeButtonShadowRender[i]->On();
		}
		else
		{
			BloodTypeButtonEffect1Render[i]->On();
			BloodTypeButtonEffect2Render[i]->On();
			BloodTypeButtonEffect3Render[i]->On();

			BloodTypeButtonRender1[i]->Off();
			BloodTypeButtonRender2[i]->Off();
			BloodTypeButtonShadowRender[i]->Off();
		}
	}
}

void SetOliveBloodType::Render(float _DeltaTime)
{
}

void SetOliveBloodType::SetBloodTypeButton()
{
	GameEngineLevel* Level = GetLevel();
	float4 ButtonStartPosition = { GameEngineWindow::GetScreenSize().half().x + float4::Left.x * 3 * (ButtonScale.hx() + ButtonInterval.hx()), 360 };

	int Start = 0;

	for (size_t i = 0; i < 4; i++)
	{
		BloodTypeButton[i] = Level->CreateActor<Button_BloodType>(PM2ActorOrder::Menu0_Button);
		BloodTypeButton[i]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
		BloodTypeButton[i]->SetScale(ButtonScale);
		BloodTypeButton[i]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
		BloodTypeButton[i]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
		BloodTypeButton[i]->SetPos(ButtonStartPosition + (ButtonScale + ButtonInterval) * float4 { static_cast<float>(i), 0 });
		BloodTypeButton[i]->SetReleaseImage("SelectButton_Release.Bmp");
		BloodTypeButton[i]->SetHoverImage("SelectButton_Release.Bmp");
		BloodTypeButton[i]->SetPressImage("SelectButton_Release.Bmp");
		BloodTypeButton[i]->BloodTypeValue = static_cast<BloodType>(Start++);
		BloodTypeButton[i]->SetClickCallBack(ClickBloodType);
	}
}

void SetOliveBloodType::SetBloodTypeButtonRender()
{
	BloodTypeButtonRender1[0] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender1[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	float4 LetterRenderPos = BloodTypeButton[0]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
	BloodTypeButtonRender1[0]->SetPosition(LetterRenderPos);

	BloodTypeButtonRender2[0] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender2[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	BloodTypeButtonRender2[0]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

	BloodTypeButtonEffect1Render[0] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonEffect1Render[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
	BloodTypeButtonEffect1Render[0]->SetPosition(LetterRenderPos);
	BloodTypeButtonEffect1Render[0]->Off();

	BloodTypeButtonEffect2Render[0] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect2Render[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
	BloodTypeButtonEffect2Render[0]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
	BloodTypeButtonEffect2Render[0]->Off();

	BloodTypeButtonEffect3Render[0] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect3Render[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
	BloodTypeButtonEffect3Render[0]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	BloodTypeButtonEffect3Render[0]->Off();

	BloodTypeButtonShadowRender[0] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	BloodTypeButtonShadowRender[0]->SetText("A", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
	BloodTypeButtonShadowRender[0]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });

	BloodTypeButtonRender1[1] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender1[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	LetterRenderPos = BloodTypeButton[1]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
	BloodTypeButtonRender1[1]->SetPosition(LetterRenderPos);

	BloodTypeButtonRender2[1] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender2[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	BloodTypeButtonRender2[1]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

	BloodTypeButtonEffect1Render[1] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonEffect1Render[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
	BloodTypeButtonEffect1Render[1]->SetPosition(LetterRenderPos);
	BloodTypeButtonEffect1Render[1]->Off();

	BloodTypeButtonEffect2Render[1] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect2Render[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
	BloodTypeButtonEffect2Render[1]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
	BloodTypeButtonEffect2Render[1]->Off();

	BloodTypeButtonEffect3Render[1] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect3Render[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
	BloodTypeButtonEffect3Render[1]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	BloodTypeButtonEffect3Render[1]->Off();

	BloodTypeButtonShadowRender[1] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	BloodTypeButtonShadowRender[1]->SetText("B", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
	BloodTypeButtonShadowRender[1]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });

	BloodTypeButtonRender1[2] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender1[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	LetterRenderPos = BloodTypeButton[2]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
	BloodTypeButtonRender1[2]->SetPosition(LetterRenderPos);

	BloodTypeButtonRender2[2] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender2[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	BloodTypeButtonRender2[2]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

	BloodTypeButtonEffect1Render[2] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonEffect1Render[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
	BloodTypeButtonEffect1Render[2]->SetPosition(LetterRenderPos);
	BloodTypeButtonEffect1Render[2]->Off();

	BloodTypeButtonEffect2Render[2] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect2Render[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
	BloodTypeButtonEffect2Render[2]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
	BloodTypeButtonEffect2Render[2]->Off();

	BloodTypeButtonEffect3Render[2] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect3Render[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
	BloodTypeButtonEffect3Render[2]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	BloodTypeButtonEffect3Render[2]->Off();

	BloodTypeButtonShadowRender[2] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	BloodTypeButtonShadowRender[2]->SetText("O", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
	BloodTypeButtonShadowRender[2]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });

	BloodTypeButtonRender1[3] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender1[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	LetterRenderPos = BloodTypeButton[3]->GetPos() - GetPos() - float4{ ButtonScale.hx(), static_cast<float>(LetterRenderHeight / 2) };
	BloodTypeButtonRender1[3]->SetPosition(LetterRenderPos);

	BloodTypeButtonRender2[3] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonRender2[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ButtonScale);
	BloodTypeButtonRender2[3]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });

	BloodTypeButtonEffect1Render[3] = CreateRender(PM2RenderOrder::Menu0_Display);
	BloodTypeButtonEffect1Render[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextEffect1Color, ButtonScale);
	BloodTypeButtonEffect1Render[3]->SetPosition(LetterRenderPos);
	BloodTypeButtonEffect1Render[3]->Off();

	BloodTypeButtonEffect2Render[3] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect2Render[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextEffect2Color, ButtonScale);
	BloodTypeButtonEffect2Render[3]->SetPosition(LetterRenderPos + float4::Up * float4{ 0,1 });
	BloodTypeButtonEffect2Render[3]->Off();

	BloodTypeButtonEffect3Render[3] = CreateRender(PM2RenderOrder::Menu0_Display_Effect);
	BloodTypeButtonEffect3Render[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextEffect3Color, ButtonScale);
	BloodTypeButtonEffect3Render[3]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });
	BloodTypeButtonEffect3Render[3]->Off();

	BloodTypeButtonShadowRender[3] = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	BloodTypeButtonShadowRender[3]->SetText("AB", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ButtonScale);
	BloodTypeButtonShadowRender[3]->SetPosition(LetterRenderPos + float4::Down * float4{ 0,1 });

}

void SetOliveBloodType::SetExplainRender()
{
	ExplainRender1 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender1->SetText("���� ������ ����", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	float4 SetExplainRenderPos = -ExplainTextBoxScale.half() - float4{ 0,36 };
	ExplainRender1->SetPosition(SetExplainRenderPos);

	ExplainRender2 = CreateRender(PM2RenderOrder::Menu0_Display);
	ExplainRender2->SetText("���� ������ ����", LetterRenderHeight, TextType, TextAlign::Center, TextColor, ExplainTextBoxScale);
	ExplainRender2->SetPosition(SetExplainRenderPos + float4::Up * float4{ 0,1 });

	ExplainRenderShadow = CreateRender(PM2RenderOrder::Menu0_Display_Shadow);
	ExplainRenderShadow->SetText("���� ������ ����", LetterRenderHeight, TextType, TextAlign::Center, TextShadowColor, ExplainTextBoxScale);
	ExplainRenderShadow->SetPosition(SetExplainRenderPos + float4::Down * float4{ 0,1 });
}

void SetOliveBloodType::ClickBloodType(Button* _Button)
{
	Button_BloodType* Ptr = dynamic_cast<Button_BloodType*>(_Button);
	Olive::OlivePlayer->SetBloodType(Ptr->BloodTypeValue);
	Olive::OlivePlayer->UpdateZodiac();
	Olive::OlivePlayer->SetFirstStatus();
	Olive::OlivePlayer->SetFirstPhysicalCondition();
	GameEngineCore::GetInst()->ChangeLevel("Opening");
}
