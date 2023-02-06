#include "Dialog.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>

Dialog::Dialog()
{

}

Dialog::~Dialog()
{

}

void Dialog::InitRenderPos()
{
	SetPosFrameRender({ 0,0 });
	SetPosMugShotRender({ 0,0 });
}

void Dialog::SetLeftMugDialog()
{
	InitRenderPos();
	SetMoveMugShotRender({ -165, 0 });
	SetPosFrameRender(float4{ 80,0 });
}

void Dialog::SetRightMugDialog()
{
	InitRenderPos();
	SetMoveMugShotRender({ 165,0 });
	SetPosFrameRender(float4{ -80,0 });
}

void Dialog::SetMoveMugShotRender(const float4& _Move)
{
	MugShotFrame->SetMove(_Move);
	MugShot->SetMove(_Move);
}

void Dialog::SetPosMugShotRender(const float4& _Pos)
{
	MugShotFrame->SetPosition(_Pos);
	MugShot->SetPosition(_Pos);
}

void Dialog::SetMugPic(const std::string_view& _ImageFileName)
{
	std::string Upper = GameEngineString::ToUpper(_ImageFileName);

	if (std::string::npos != Upper.find("_GOD"))  // 신의 머그샷 이미지엔 _GOD를 꼭 붙일것
	{
		
		if (nullptr == MugShotFrame)
		{
			MugShotFrame = CreateRender("MugShotFrame_God.bmp",PM2RenderOrder::MugShotFrame);
		}
		else
		{
			MugShotFrame->SetImage("MugShotFrame_God.bmp");
		}
		MugShotFrame->SetScale({140,195});
		
		if (nullptr == MugShot)
		{
			MugShot = CreateRender(_ImageFileName, PM2RenderOrder::MugShot);
		}
		else
		{
			MugShot->SetImage(_ImageFileName);
		}
		MugShot->SetScale({120,175});
	}
	else
	{
		if (nullptr == MugShotFrame)
		{
			MugShotFrame = CreateRender("MugShotFrame_Nomal.bmp", PM2RenderOrder::MugShotFrame);
		}
		else
		{
			MugShotFrame->SetImage("MugShotFrame_Nomal.bmp");
		}
		MugShotFrame->SetScale({ 140,150 });

		if (nullptr == MugShot)
		{
			MugShot = CreateRender(_ImageFileName, PM2RenderOrder::MugShot);
		}
		else
		{
			MugShot->SetImage(_ImageFileName);
		}
		MugShot->SetScale({120,130});
	}
	
}

void Dialog::SetMugLoc(int _MugLoc)
{


	switch (_MugLoc)
	{
	case 0:
		MugShotFrame->Off();
		MugShot->Off();
		InitRenderPos();
		break;
	case 1:
		if (nullptr == MugShot->GetImage())
		{
			MsgAssert("먼저 머그샷 이미지를 세팅해야합니다");
		}
		MugShotFrame->On();
		MugShot->On();
		SetLeftMugDialog();
		break;
	case 2:
		if (nullptr == MugShot->GetImage())
		{
			MsgAssert("먼저 머그샷 이미지를 세팅해야합니다");
		}
		MugShotFrame->On();
		MugShot->On();
		SetRightMugDialog();
		break;
	default:
		break;
	}
}

void Dialog::SetMugLoc(MugShotLR _MugLoc)
{
	SetMugLoc(static_cast<int>(_MugLoc));
}

void Dialog::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Dialog); // 고정
	SetMenuFrameScale({ 310,150 }); // 고정
	Off();
	//사용법 예시
	//SetPos({ GameEngineWindow::GetScreenSize().half()});
	//SetMugPic("Mug_Uranos_God.bmp");
	//SetMugLoc(MugShotLR::Left);
}

void Dialog::Update(float _DeltaTime)
{

}

void Dialog::Render(float _Time)
{

}
