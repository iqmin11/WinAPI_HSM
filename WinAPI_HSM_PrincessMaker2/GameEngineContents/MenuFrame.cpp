#include "MenuFrame.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>

MenuFrame::MenuFrame()
{

}

MenuFrame::~MenuFrame()
{

}

void MenuFrame::CreateMenuFrame(const float4& _centerpos, const float4& _tilesize, const int _style)
{
	SetPos(_centerpos);
	SetMenuFrameSize(_tilesize);
	SetMenuFrameStyle(_style);
}

void MenuFrame::MenuFrameRender()
{
	float4 ImagePos = GetPos() - MenuFramePixelSize.half();
	GameEngineImage* Image = nullptr;
	switch (MenuFrameStyle)
	{
	case 0:
		Image = GameEngineResources::GetInst().ImageFind("FrameSample1.bmp");
		break;

	case 1:
		Image = GameEngineResources::GetInst().ImageFind("FrameSample2.bmp");
		break;

	case 2:
		Image = GameEngineResources::GetInst().ImageFind("FrameSample3.bmp");
		break;

	default:
		break;
	}


	for (size_t y = 0; y < MenuFrameSize.y; y++)
	{
		float fy = static_cast<float>(y);
		if (0 == y)
		{
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 0, ImagePos + float4{ 0, fy * 16 }, { 16, 16 });
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 1, ImagePos + float4{ fx * 16, fy * 16 }, { 16, 16 });
			}
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 2, ImagePos + float4{ (MenuFrameSize.x - 1) * 16, fy * 16 }, { 16, 16 });
		}
		else if ((MenuFrameSize.y - 1) == y)
		{
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 6, ImagePos + float4{ 0, fy * 16 }, { 16, 16 });
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 7, ImagePos + float4{ fx * 16, fy * 16 }, { 16, 16 });
			}
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 8, ImagePos + float4{ (MenuFrameSize.x - 1) * 16, (MenuFrameSize.y - 1) * 16 }, { 16, 16 });
		}
		else
		{
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 3, ImagePos + float4{ 0, fy * 16 }, { 16, 16 });
			for (size_t x = 1; x < (MenuFrameSize.x - 1); x++)
			{
				float fx = static_cast<float>(x);
				GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 4, ImagePos + float4{ fx * 16, fy * 16 }, { 16, 16 });
			}
			GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 5, ImagePos + float4{ (MenuFrameSize.x - 1) * 16, fy * 16 }, { 16, 16 });
		}
	}
}

void MenuFrame::Start()
{
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), { 15,8 }, 0);
}

void MenuFrame::Update()
{
}

void MenuFrame::Render()
{
	MenuFrameRender();
}

//이상적 5*4 메뉴
//abbc  a : 0 // b : 1 // c : 2
//deef	d : 3 // e : 4 // f : 5
//deef
//deef
//hiij	h : 6 // i : 7 // j : 8

