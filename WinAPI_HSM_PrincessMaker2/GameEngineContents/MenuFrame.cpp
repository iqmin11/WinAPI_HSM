#include "MenuFrame.h"
#include <vector>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>

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
	std::vector<std::vector<GameEngineRender*>> RenderVec = std::vector<std::vector<GameEngineRender*>>();
	RenderVec.resize(MenuFrameSize.iy());
	for (int y = 0; y < MenuFrameSize.iy(); y++)
	{
		RenderVec[y].resize(MenuFrameSize.ix());
	}

	switch (MenuFrameStyle)
	{
	case 0:
		for (size_t y = 0; y < RenderVec.size(); ++y)
		{
			for (size_t x = 0; x < RenderVec[y].size(); ++x)
			{
				RenderVec[y][x] = CreateRender("FrameSample1.bmp", _Order);
				RenderVec[y][x]->SetScale({ 16,16 });
			}
		}
		break;

	case 1:
		for (size_t y = 0; y < RenderVec.size(); ++y)
		{
			for (size_t x = 0; x < RenderVec[y].size(); ++x)
			{
				RenderVec[y][x] = CreateRender("FrameSample2.bmp", _Order);
				RenderVec[y][x]->SetScale({ 16,16 });
			}
		}
		break;

	case 2:
		for (size_t y = 0; y < RenderVec.size(); ++y)
		{
			for (size_t x = 0; x < RenderVec[y].size(); ++x)
			{
				RenderVec[y][x] = CreateRender("FrameSample3.bmp", _Order);
				RenderVec[y][x]->SetScale({ 16,16 });
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
			RenderVec[y][0]->SetFrame(0);
			RenderVec[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				RenderVec[y][x]->SetFrame(1);
				RenderVec[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			RenderVec[y][MenuFrameSize.ix() - 1]->SetFrame(2);
			RenderVec[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
		}
		else if ((MenuFrameSize.y - 1) == y)
		{
			RenderVec[y][0]->SetFrame(6);
			RenderVec[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				RenderVec[y][x]->SetFrame(7);
				RenderVec[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			RenderVec[y][MenuFrameSize.ix() - 1]->SetFrame(8);
			RenderVec[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
		}
		else
		{
			RenderVec[y][0]->SetFrame(3);
			RenderVec[y][0]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 0, 16 * fy }));
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				RenderVec[y][x]->SetFrame(4);
				RenderVec[y][x]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * fx,16 * fy }));
			}
			RenderVec[y][MenuFrameSize.ix() - 1]->SetFrame(5);
			RenderVec[y][MenuFrameSize.ix() - 1]->SetPosition((-MenuFramePixelSize.half()) + (float4{ 16 * (MenuFrameSize.x - 1),16 * fy }));
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

