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

void Cutscene::ChangeRenderScene(int _index)
{
	if (_index < 0 || _index >= CutScenes.size())
	{
		MsgAssert("컷신 인덱스 범위에 벗어난 인덱스를 입력하였습니다")
	}
	OffRenderScene();
	RenderScene = CutScenes[_index];
	OnRenderScene();
}

void Cutscene::OnRenderScene()
{
	RenderScene->On();
}

void Cutscene::OffRenderScene()
{
	RenderScene->Off();
}

void Cutscene::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	CutScenes.resize(7);
	CutScenes[0] = CreateRender("CutScene1.BMP", PM2RenderOrder::BackGround);
	CutScenes[1] = CreateRender("CutScene2.BMP", PM2RenderOrder::BackGround);
	CutScenes[2] = CreateRender("CutScene3.BMP", PM2RenderOrder::BackGround);
	CutScenes[3] = CreateRender("CutScene4.BMP", PM2RenderOrder::BackGround);
	CutScenes[4] = CreateRender("CutScene5.BMP", PM2RenderOrder::BackGround);
	CutScenes[5] = CreateRender("CutScene6.BMP", PM2RenderOrder::BackGround);
	CutScenes[6] = CreateRender("CutScene7.BMP", PM2RenderOrder::BackGround);
	//Render = CreateRender("titlebackground.BMP", 0);
	for (auto i : CutScenes)
	{
		i->Off();
	}
}

void Cutscene::Update(float _DeltaTime)
{
}

void Cutscene::Render(float _time)
{
}
