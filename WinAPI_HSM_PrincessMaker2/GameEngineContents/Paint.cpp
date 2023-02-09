#include "Paint.h"

#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Paint::Paint()
{

}

Paint::~Paint()
{

}

void Paint::Start()
{
	PaintRender = CreateRender("paint_default.bmp", PM2RenderOrder::BackGroundObj);
	PaintRender->SetScaleToImage();
	SetPos({519,157});
}

void Paint::Update(float _DeltaTime)
{
}

void Paint::Render(float _Time)
{
}
