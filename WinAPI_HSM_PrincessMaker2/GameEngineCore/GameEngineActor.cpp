#include "GameEngineActor.h"
#include "GameEngineRender.h"

GameEngineActor::GameEngineActor()
{
}

GameEngineActor::~GameEngineActor()
{
	for (GameEngineRender* _Render : RenderList)
	{
		if (nullptr == _Render)
		{
			continue;
		}

		delete _Render;
		_Render = nullptr;
	}
}

GameEngineRender* GameEngineActor::CreateRender(const std::string_view& _Image, int _Order)
{
	GameEngineRender* Render = CreateRender(_Order);
	Render->SetImage(_Image);
	return Render;
}

GameEngineRender* GameEngineActor::CreateRender(int _Order)
{
	GameEngineRender* Render = new GameEngineRender();
	Render->Owner = this;
	Render->SetOrder(_Order);
	RenderList.push_back(Render);
	return nullptr;
}

