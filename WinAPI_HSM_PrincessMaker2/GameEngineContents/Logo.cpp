#include "Logo.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start()
{
	PM2Logo = CreateRender("TitleLogo.BMP", PM2RenderOrder::TitleLogo);
	PM2Logo->SetScaleToImage();
	SetPos({ 400,250 });
	Off();
}
