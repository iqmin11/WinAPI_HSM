#include "SetOliveName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "FirstSetLevel.h"

SetOliveName::SetOliveName()
{

}

SetOliveName::~SetOliveName()
{

}

void SetOliveName::Start() 
{
	/*if (false == GameEngineInput::IsKey("OffOliveNameSet"))
	{
		GameEngineInput::CreateKey("OffOliveNameSet", 'S');
	}*/

	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetOliveBackground.BMP", 9);
	
	Off();
}

void SetOliveName::Update(float _DeltaTime)
{
	/*if(GameEngineInput::IsDown("OffOliveNameSet"))
	{
		Off();
	}*/
}

void SetOliveName::Render(float _DeltaTime)
{
}
