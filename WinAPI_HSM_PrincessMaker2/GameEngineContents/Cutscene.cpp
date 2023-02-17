#include "Cutscene.h"
#include "ContentsEnums.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

Cutscene::Cutscene()
{

}

Cutscene::~Cutscene()
{

}

void Cutscene::OnCutScene(int _index)
{
	for (size_t i = 0; i < CutScenes.size(); i++)
	{
		if (i == _index)
		{
			CutScenes[i]->On();
		}
		else
		{
			CutScenes[i]->Off();
		}
	}
}

void Cutscene::OffCutScene()
{
	for (size_t i = 0; i < CutScenes.size(); i++)
	{
		CutScenes[i]->Off();
	}
}

void Cutscene::SelectBackgroundColor(BackgroundColor _Color)
{
	if (_Color == BackgroundColor::Black)
	{
		Background[0]->On();
		Background[1]->Off();
	}
	else
	{
		Background[0]->Off();
		Background[1]->On();
	}
}

void Cutscene::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	CutScenes.resize(7);
	CutScenes[0] = CreateRender("CutScene1.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[1] = CreateRender("CutScene2.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[2] = CreateRender("CutScene3.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[3] = CreateRender("CutScene4.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[4] = CreateRender("CutScene5.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[5] = CreateRender("CutScene6.BMP", PM2RenderOrder::BackGroundObj);
	CutScenes[6] = CreateRender("CutScene7.BMP", PM2RenderOrder::BackGroundObj);
	
	Background.resize(2);
	Background[0] = CreateRender("BlackBackground.bmp", PM2RenderOrder::BackGround);
	Background[1] = CreateRender("WhiteBackground.bmp", PM2RenderOrder::BackGround);

	for (auto i : CutScenes)
	{
		i->SetScaleToImage();
	}

	for (auto i : Background)
	{
		i->SetScaleToImage();
	}

	Off();
}

void Cutscene::Update(float _DeltaTime)
{
}

void Cutscene::Render(float _time)
{
}
