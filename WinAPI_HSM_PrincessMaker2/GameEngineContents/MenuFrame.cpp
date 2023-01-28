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

void MenuFrame::CreateMenuFrame(const float4& _centerpos, const float4& _TileBasedSize, const int _style)
{
	SetPos(_centerpos);
	SetMenuFrameSize(_TileBasedSize);
	SetMenuFrameStyle(_style);
}

void MenuFrame::MenuFrameRender(const int _Order)
{
	FrameRender.resize(MenuFrameSize.iy());
	for (int y = 0; y < MenuFrameSize.iy(); y++)
	{
		FrameRender[y].resize(MenuFrameSize.ix());
	}

	switch (MenuFrameStyle)
	{
	case 0:
		for (size_t y = 0; y < FrameRender.size(); ++y)
		{
			for (size_t x = 0; x < FrameRender[y].size(); ++x)
			{
				FrameRender[y][x] = CreateRender("FrameSample1.bmp", _Order);
				FrameRender[y][x]->SetScale({ 16,16 });
			}
		}
		break;

	case 1:
		for (size_t y = 0; y < FrameRender.size(); ++y)
		{
			for (size_t x = 0; x < FrameRender[y].size(); ++x)
			{
				FrameRender[y][x] = CreateRender("FrameSample2.bmp", _Order);
				FrameRender[y][x]->SetScale({ 16,16 });
			}
		}
		break;

	case 2:
		for (size_t y = 0; y < FrameRender.size(); ++y)
		{
			for (size_t x = 0; x < FrameRender[y].size(); ++x)
			{
				FrameRender[y][x] = CreateRender("FrameSample3.bmp", _Order);
				FrameRender[y][x]->SetScale({ 16,16 });
			}
		}
		break;

	default:
		break;
	}

	for (size_t y = 0; y < MenuFrameSize.y; y++)
	{
		float fy = static_cast<float>(y);
		if (0 == y)
		{
			FrameRender[y][0]->SetFrame(0);
			FrameRender[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				FrameRender[y][x]->SetFrame(1);
				FrameRender[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			FrameRender[y][MenuFrameSize.ix() - 1]->SetFrame(2);
			FrameRender[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
		}
		else if ((MenuFrameSize.y - 1) == y)
		{
			FrameRender[y][0]->SetFrame(6);
			FrameRender[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				FrameRender[y][x]->SetFrame(7);
				FrameRender[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			FrameRender[y][MenuFrameSize.ix() - 1]->SetFrame(8);
			FrameRender[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
		}
		else
		{
			FrameRender[y][0]->SetFrame(3);
			FrameRender[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				FrameRender[y][x]->SetFrame(4);
				FrameRender[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			FrameRender[y][MenuFrameSize.ix() - 1]->SetFrame(5);
			FrameRender[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
		}
	}
}

void MenuFrame::Start()
{
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), {13,8}, 0);
	MenuFrameRender(1);
}

void MenuFrame::Update(float _Deltatime)
{
}

void MenuFrame::Render(float _Time)
{
	//MenuFrameRender();
}

//이상적 5*4 메뉴
//abbc  a : 0 // b : 1 // c : 2
//deef	d : 3 // e : 4 // f : 5
//deef
//deef
//hiij	h : 6 // i : 7 // j : 8

