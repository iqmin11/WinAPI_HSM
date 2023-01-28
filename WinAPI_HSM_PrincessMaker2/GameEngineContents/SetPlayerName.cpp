#include "SetPlayerName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

SetPlayerName::SetPlayerName()
{

}

SetPlayerName::~SetPlayerName()
{

}

void SetPlayerName::Start()
{
	/*if (false == GameEngineInput::IsKey("OffPlayerNameSet"))
	{
		GameEngineInput::CreateKey("OffPlayerNameSet", 'D');
	}*/

	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetPlayerBackground.BMP", 10);
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
	/*if (GameEngineInput::IsDown("OffPlayerNameSet"))
	{
		Off();
	}*/
}

void SetPlayerName::Render(float _DeltaTime)
{
}
