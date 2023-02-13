#include "SelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>


SelectionMenu::SelectionMenu()
{

}

SelectionMenu::~SelectionMenu()
{

}

void SelectionMenu::SetSelectionMenu(int _Count, float4 _Pos, float _xScale, int _ActorOrder, int _RenderOrder) // 이순간 세로크기는 정해지게
{
	CountButton = _Count;
	SetMenuFrameScale({ _xScale, (static_cast<float>(CountButton) * 26.0f) + 40.0f });
	SetPos(_Pos);
	SelectButtons.resize(CountButton);
	GameEngineLevel* Level = GetLevel();
	for (size_t i = 0; i < SelectButtons.size(); i++)
	{
		SelectButtons[i] = Level->CreateActor<Button>(_ActorOrder);
		SelectButtons[i]->SetReleaseImage("SelectButton_Release.bmp");
		SelectButtons[i]->SetHoverImage("SelectButton_Hover.bmp");
		SelectButtons[i]->SetPressImage("SelectButton_Hover.bmp");
		SelectButtons[i]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
		SelectButtons[i]->SetScale({ _xScale - 20, 26.0f });
		SelectButtons[i]->SetPos(_Pos + (float4::Up * SelectButtons[i]->GetButtonScale().half() * static_cast<float>(SelectButtons.size() - 1)) + float4::Down * (SelectButtons[i]->GetButtonScale() * static_cast<float>(i)));
		SelectButtons[i]->SetRenderOrder(_RenderOrder);
	}
	StringRenders.resize(CountButton);
	StringShadowRenders.resize(CountButton);
	StringHoverRenders.resize(CountButton);
}

void SelectionMenu::SetSelectionMenu(int _Count, float4 _Pos, float _xScale, PM2ActorOrder _ButtonActorOrder, PM2RenderOrder _ButtonRenderOrder)
{
	SetSelectionMenu(_Count, _Pos, _xScale, static_cast<int>(_ButtonActorOrder), static_cast<int>(_ButtonRenderOrder));
}

void SelectionMenu::SetButtonString(int _RenderOrder, int _ButtonIndex, const std::string_view& _Text)
{
	StringRenders[_ButtonIndex] = CreateRender(_RenderOrder);
	StringRenders[_ButtonIndex]->SetText(_Text, 18, "굴림", TextAlign::Left, RGB(255, 255, 255));
	float4 SetStringPosition = float4::Left * (SelectButtons[_ButtonIndex]->GetButtonScale().half()) + float4::Up * SelectButtons[_ButtonIndex]->GetButtonScale().half() * static_cast<float>(SelectButtons.size() - 1) + float4::Down * (SelectButtons[_ButtonIndex]->GetButtonScale() * static_cast<float>(_ButtonIndex)) + (float4::Up.half() * static_cast<float>(StringRenders[_ButtonIndex]->GetTextHeight()));
	StringRenders[_ButtonIndex]->SetPosition(SetStringPosition);
	
	int OrderDifference = static_cast<int>(PM2RenderOrder::Menu0_Display) - static_cast<int>(PM2RenderOrder::Menu0_Display_Shadow);
	StringShadowRenders[_ButtonIndex] = CreateRender(_RenderOrder - OrderDifference);
	StringShadowRenders[_ButtonIndex]->SetText(_Text, 18, "굴림", TextAlign::Left, RGB(0, 0, 0));
	StringShadowRenders[_ButtonIndex]->SetPosition(SetStringPosition + float4{ 0,2 });

	OrderDifference = static_cast<int>(PM2RenderOrder::Menu0_Display) - static_cast<int>(PM2RenderOrder::Menu0_Display_Effect);
	StringHoverRenders[_ButtonIndex] = CreateRender(_RenderOrder - OrderDifference);
	StringHoverRenders[_ButtonIndex]->SetText(_Text, 18, "굴림", TextAlign::Left, RGB(236, 152, 132));
	StringHoverRenders[_ButtonIndex]->SetPosition(SetStringPosition + float4{ 0,1 });

	StringHoverRenders[_ButtonIndex]->Off();
}

void SelectionMenu::Start()
{
	//사용법 예시
	//InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	//SetSelectionMenu(3, GameEngineWindow::GetScreenSize().half(), 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	//GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	//GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	//GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
	//함수는 private static으로 구현
}

void SelectionMenu::Update(float _Deltatime)
{
	for (size_t i = 0; i < SelectButtons.size(); i++)
	{
		if (ButtonState::Release == SelectButtons[i]->GetState())
		{
			StringHoverRenders[i]->Off();
			StringShadowRenders[i]->On();
		}
		else
		{
			StringHoverRenders[i]->On();
			StringShadowRenders[i]->Off();
		}
	}
}

void SelectionMenu::Render(float _Time)
{

}

