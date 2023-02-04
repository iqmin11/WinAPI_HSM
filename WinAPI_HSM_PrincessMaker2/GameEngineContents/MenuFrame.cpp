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

void MenuFrame::SetMenuFrame(const float4& _pos, const float4& _Size, const int _style)
{
	SetPos(_pos);
	SetMenuFrameSize(_Size);
	SetMenuFrameStyle(_style);
}

void MenuFrame::MenuFrameRender(const int _Order)
{
	switch (MenuFrameStyle)
	{
	case 0:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample1.bmp", _Order);
		}
		break;

	case 1:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample2.bmp", _Order);
		}
		break;

	case 2:
		for (int i = 0; i < 9; i++)
		{
			FrameRender[i] = CreateRender("FrameSample3.bmp", _Order);
		}
		break;

	default:
		break;
	}

	for (int i = 0; i < 9; i++)
	{
		FrameRender[i]->SetFrame(i);
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
			FrameRender[i]->SetScale({ MenuFrameSize.x - 32 ,16 });
		}
		else if (i == 3 ||
			i == 5)
		{
			FrameRender[i]->SetScale({ 16, MenuFrameSize.y - 32 });
		}
		else if (i == 4)
		{
			FrameRender[i]->SetScale(MenuFrameSize - float4{ 32,32 });
		}

		switch (i)
		{
		case 0:
			FrameRender[i]->SetPosition({ -MenuFrameSize.hx() + 8, -MenuFrameSize.hy() + 8 });
			break;
		case 1:
			FrameRender[i]->SetPosition({ 0, -MenuFrameSize.hy() + 8 });
			break;
		case 2:
			FrameRender[i]->SetPosition({ MenuFrameSize.hx() - 8, -MenuFrameSize.hy() + 8 });
			break;
		case 3:
			FrameRender[i]->SetPosition({ -MenuFrameSize.hx() + 8, 0 });
			break;
		case 4:
			FrameRender[i]->SetPosition({ 0,0 });
			break;
		case 5:
			FrameRender[i]->SetPosition({ MenuFrameSize.hx() - 8, 0 });
			break;
		case 6:
			FrameRender[i]->SetPosition({ -MenuFrameSize.hx() + 8, MenuFrameSize.hy() - 8 });
			break;
		case 7:
			FrameRender[i]->SetPosition({ 0, MenuFrameSize.hy() - 8 });
			break;
		case 8:
			FrameRender[i]->SetPosition({ MenuFrameSize.hx() - 8, MenuFrameSize.hy() - 8 });
			break;
		default:
			break;
		}
	}
}

void MenuFrame::MenuFrameRender(PM2RenderOrder _Order)
{
	MenuFrame::MenuFrameRender(static_cast<int>(_Order));
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
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameSize.x + 8, -MenuFrameSize.hy() + 8 });
			break;
		case 1:
			FrameRender[i]->SetPosition(_Pos + float4{ 0, -MenuFrameSize.hy() + 8 });
			break;
		case 2:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameSize.x - 8, -MenuFrameSize.hy() + 8 });
			break;
		case 3:
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameSize.x + 8, 0 });
			break;
		case 4:
			FrameRender[i]->SetPosition(_Pos + float4{ 0,0 });
			break;
		case 5:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameSize.x - 8, 0 });
			break;
		case 6:
			FrameRender[i]->SetPosition(_Pos + float4{ -MenuFrameSize.x + 8, MenuFrameSize.hy() - 8 });
			break;
		case 7:
			FrameRender[i]->SetPosition(_Pos + float4{ 0, MenuFrameSize.hy() - 8 });
			break;
		case 8:
			FrameRender[i]->SetPosition(_Pos + float4{ MenuFrameSize.x - 8, MenuFrameSize.hy() - 8 });
			break;
		default:
			break;
		}
	}
	
}
