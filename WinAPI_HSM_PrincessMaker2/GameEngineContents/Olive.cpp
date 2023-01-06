#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>

Olive::Olive()
{

}

Olive::~Olive()
{

}

void Olive::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
}

void Olive::Update()
{
	SetMove(float4::Left * 0.0001f);
}

void Olive::Render()
{
	float4 PlayerPos = GetPos();
	Rectangle(
		GameEngineWindow::GetDrawHdc(),
		PlayerPos.ix() - 50,
		PlayerPos.iy() - 50,
		PlayerPos.ix() + 50,
		PlayerPos.iy() + 50
		);
}
