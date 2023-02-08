#include "MenuFrame.h"
#include <vector>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

MenuFrame::MenuFrame()
{

}

MenuFrame::~MenuFrame()
{

}

void MenuFrame::SetMenuFrameScale(const float4& _Scale)
{
	if (_Scale.x < 34 || _Scale.y < 34)
	{
		MsgAssert("메뉴프레임의 최소 크기는 34*34입니다")
	}

	MenuFrameScale = _Scale;

	for (int i = 0; i < 9; i++)
	{
		if (i == 0 ||
			i == 2 ||
			i == 6 ||
			i == 8)
		{
			FrameRender[i]->SetScale({ 16,16 });
		}
		else if (i == 1 ||
			i == 7)
		{
			FrameRender[i]->SetScale({ MenuFrameScale.x - 32 ,16 });
		}
		else if (i == 3 ||
			i == 5)
		{
			FrameRender[i]->SetScale({ 16, MenuFrameScale.y - 32 });
		}
		else if (i == 4)
		{
			FrameRender[i]->SetScale(MenuFrameScale - float4{ 32,32 });
		}
		
		switch (i)
		{
		case 0:
			FrameRender[i]->SetPosition({ -MenuFrameScale.hx() + 8, -MenuFrameScale.hy() + 8 });
			break;
		case 1:
			FrameRender[i]->SetPosition({ 0, -MenuFrameScale.hy() + 8 });
			break;
		case 2:
			FrameRender[i]->SetPosition({ MenuFrameScale.hx() - 8, -MenuFrameScale.hy() + 8 });
			break;
		case 3:
			FrameRender[i]->SetPosition({ -MenuFrameScale.hx() + 8, 0 });
			break;
		case 4:
			FrameRender[i]->SetPosition({ 0,0 });
			break;
		case 5:
			FrameRender[i]->SetPosition({ MenuFrameScale.hx() - 8, 0 });
			break;
		case 6:
			FrameRender[i]->SetPosition({ -MenuFrameScale.hx() + 8, MenuFrameScale.hy() - 8 });
			break;
		case 7:
			FrameRender[i]->SetPosition({ 0, MenuFrameScale.hy() - 8 });
			break;
		case 8:
			FrameRender[i]->SetPosition({ MenuFrameScale.hx() - 8, MenuFrameScale.hy() - 8 });
			break;
		default:
			break;
		}
	}
}

void MenuFrame::InitMenuFrameRender(int _Order, const int _style)
{
	FrameRenderOrder = _Order;

	for (auto i : FrameRender)
	{
		if (nullptr != i)
		{
			MsgAssert("이미 사용하고 있는 MenuFrameRender를 초기화하려고 했습니다")
		}
	}
	
	if (0 > _style || 2 < _style)
	{
		MsgAssert("프레임 스타일 인덱스 범위는 0~2 입니다. 해당하지 않는 값을 입력하였습니다")
	}
	
	MenuFrameStyle = _style;

	switch (MenuFrameStyle)
	{
	case 0:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample1.bmp", _Order);
			FrameRender[i]->SetFrame(i);
		}
		break;

	case 1:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample2.bmp", _Order);
			FrameRender[i]->SetFrame(i);
		}
		break;

	case 2:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample3.bmp", _Order);
			FrameRender[i]->SetFrame(i);
		}
		break;

	default:
		break;
	}
}

void MenuFrame::InitMenuFrameRender(PM2RenderOrder _Order, const int _style)
{
	InitMenuFrameRender(static_cast<int>(_Order), _style);
}

void MenuFrame::Start()
{

}

void MenuFrame::Update(float _Deltatime)
{

}

void MenuFrame::Render(float _Time)
{

}

void MenuFrame::FrameRenderOn()
{
	for (auto i : FrameRender)
	{
		i->On();
	}
}

void MenuFrame::FrameRenderOff()
{
	for (auto i : FrameRender)
	{
		i->Off();
	}
}

void MenuFrame::SetMoveFrameRender(const float4& _Pos)
{
	for (auto i : FrameRender)
	{
		i->SetMove(_Pos);
	}
}

void MenuFrame::SetPosFrameRender(const float4& _Pos)
{
	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0:
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameScale.hx() + 8, -MenuFrameScale.hy() + 8 });
			break;
		case 1:
			FrameRender[i]->SetPosition(_Pos + float4{ 0, -MenuFrameScale.hy() + 8 });
			break;
		case 2:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameScale.hx() - 8, -MenuFrameScale.hy() + 8 });
			break;
		case 3:
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameScale.hx() + 8, 0 });
			break;
		case 4:
			FrameRender[i]->SetPosition(_Pos + float4{ 0,0 });
			break;
		case 5:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameScale.hx() - 8, 0 });
			break;
		case 6:
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameScale.hx() + 8, MenuFrameScale.hy() - 8 });
			break;
		case 7:
			FrameRender[i]->SetPosition(_Pos + float4{ 0, MenuFrameScale.hy() - 8 });
			break;
		case 8:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameScale.hx() - 8, MenuFrameScale.hy() - 8 });
			break;
		default:
			break;
		}
	}
	
}
