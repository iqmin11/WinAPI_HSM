#include "BasicInfo.h"
#include "ContentsEnums.h"

BasicInfo::BasicInfo()
{

}

BasicInfo::~BasicInfo()
{

}

void BasicInfo::Start()
{
	SetPos({700, 109});
	BasicInfoFrame = CreateRender("BasicInfo.bmp",PM2RenderOrder::Menu0);
}

void BasicInfo::Update(float _DeltaTime)
{
}

void BasicInfo::Render(float _Time)
{
}
