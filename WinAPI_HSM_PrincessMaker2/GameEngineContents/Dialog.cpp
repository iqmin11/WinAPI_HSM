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

void Dialog::MugShotRender()
{
	if (nullptr == (MugShot->GetImage()))
	{
		return; // 렌더 안키는게 맞음
	}
	MugShotFrame->On();
	MugShot->On();
}

void Dialog::InitRenderPos()
{
	SetPosFrameRender({ 0,0 });
	SetPosMugShotRender({ 0,0 });
}

void Dialog::SetLeftMugDialog()
{
	InitRenderPos();
	SetMoveMugShotRender({ -170, 0 });
	SetMoveFrameRender(float4{ 80,0 });
}

void Dialog::SetRightMugDialog()
{
	InitRenderPos();
	SetMoveMugShotRender({ 170,0 });
	SetMoveFrameRender(float4{ -80,0 });
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

void Dialog::SetMugShot(const std::string_view& _ImageFileName)
{
	if (MugShotLoc == -1)
	{
		MsgAssert("대화창 설정이 선행되어야 합니다")
	}

	if (IsMugShot == false)
	{
		MsgAssert("머그샷이 없는 대화창입니다")
	}
	
	std::string Upper = GameEngineString::ToUpper(_ImageFileName);

	if (std::string::npos != Upper.find("_GOD"))  // 신의 머그샷 이미지엔 _GOD를 꼭 붙일것
	{
		MugShotFrame->SetImage("MugShotFrame_God.bmp");
	}
	else
	{
		MugShotFrame->SetImage("MugShotFrame_Nomal.bmp");
	}
	
	MugShot->SetImage(_ImageFileName);
}

void Dialog::SetDialog(int _MugShotLoc, const float4& _Pos, const std::string_view& _ImageFileName)
{
	if (_ImageFileName == "\0" && _MugShotLoc != 0)
	{
		MsgAssert("머그샷이 존재하지 않는 대화창입니다. 머그샷의 위치를 정할 수 없습니다");
	}
	
	if (_ImageFileName != "\0" && _MugShotLoc == 0)
	{
		MsgAssert("머그샷이 존재하는 대화창입니다. 머그샷의 위치를 정해야합니다");
	}

	MugShotLoc = _MugShotLoc;
	switch (MugShotLoc)
	{
	case 0:
		break;
	case 1:
		SetLeftMugDialog();
		break;
	case 2:
		SetRightMugDialog();
		break;
	default:
		break;
	}

	SetMenuFrame(_Pos, { 310,150 }); // 크기는 고정하자
	
	if (_ImageFileName == "\0")
	{
		IsMugShot = false;
		MugShot = nullptr;
		MugShotFrame = nullptr;
	}
	else
	{
		IsMugShot = true;
		SetMugShot(_ImageFileName);
	}
}

void Dialog::SetDialog(MugShotLR _MugShotLoc, const float4& _Pos, std::string_view _ImageFileName = nullptr)
{
	SetDialog(static_cast<int>(_MugShotLoc), _Pos, _ImageFileName);
}

void Dialog::Start()
{
	SetMenuFrame(GameEngineWindow::GetScreenSize().half(), { 310,150 }); // 이건 디폴트값
	MugShot = CreateRender(PM2RenderOrder::MugShot);
	MugShot->Off();
	MugShotFrame = CreateRender(PM2RenderOrder::MugShotFrame);
	MugShot->Off();
	// 머그샷 가로 140 세로 150 / 대화창 가로 320 세로 160 /사이간격 가로 20 총 가로 480 세로 160
	// 대화창 가로로 120만큼 오른쪽으로
	// 머그샷 가로로 170만큼 왼쪽으로
}

void Dialog::Update(float _DeltaTime)
{
	InitMenuFrame(PM2RenderOrder::Menu0); // 먼가...먼가잘못댐
	MugShotRender();
	if (IsMugShot)
	{
		if (static_cast<int>(MugShotLR::Left) == MugShotLoc)
		{
			SetLeftMugDialog();
		}
		else if (static_cast<int>(MugShotLR::Right) == MugShotLoc)
		{
			SetRightMugDialog();
		}
	}
}

void Dialog::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	); // 디버깅용
}
