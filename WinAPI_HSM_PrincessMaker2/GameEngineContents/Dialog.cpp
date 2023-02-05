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
		return; // ���� ��Ű�°� ����
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
		MsgAssert("��ȭâ ������ ����Ǿ�� �մϴ�")
	}

	if (IsMugShot == false)
	{
		MsgAssert("�ӱ׼��� ���� ��ȭâ�Դϴ�")
	}
	
	std::string Upper = GameEngineString::ToUpper(_ImageFileName);

	if (std::string::npos != Upper.find("_GOD"))  // ���� �ӱ׼� �̹����� _GOD�� �� ���ϰ�
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
		MsgAssert("�ӱ׼��� �������� �ʴ� ��ȭâ�Դϴ�. �ӱ׼��� ��ġ�� ���� �� �����ϴ�");
	}
	
	if (_ImageFileName != "\0" && _MugShotLoc == 0)
	{
		MsgAssert("�ӱ׼��� �����ϴ� ��ȭâ�Դϴ�. �ӱ׼��� ��ġ�� ���ؾ��մϴ�");
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

	SetMenuFrame(_Pos, { 310,150 }); // ũ��� ��������
	
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
	SetMenuFrame(GameEngineWindow::GetScreenSize().half(), { 310,150 }); // �̰� ����Ʈ��
	MugShot = CreateRender(PM2RenderOrder::MugShot);
	MugShot->Off();
	MugShotFrame = CreateRender(PM2RenderOrder::MugShotFrame);
	MugShot->Off();
	// �ӱ׼� ���� 140 ���� 150 / ��ȭâ ���� 320 ���� 160 /���̰��� ���� 20 �� ���� 480 ���� 160
	// ��ȭâ ���η� 120��ŭ ����������
	// �ӱ׼� ���η� 170��ŭ ��������
}

void Dialog::Update(float _DeltaTime)
{
	InitMenuFrame(PM2RenderOrder::Menu0); // �հ�...�հ��߸���
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
	); // ������
}
