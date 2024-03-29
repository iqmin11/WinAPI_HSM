#pragma once
#include "GameEngineActor.h"
#include "GameEngineCollision.h"
#include "GameEngineRender.h"

enum class ButtonState
{
	Release, 
	Press,
	Hover,
};

// ���� :
class GameEngineRender;
class Button : public GameEngineActor
{
public:
	// constrcuter destructer
	Button();
	~Button();

	// delete Function
	Button(const Button& _Other) = delete;
	Button(Button&& _Other) noexcept = delete;
	Button& operator=(const Button& _Other) = delete;
	Button& operator=(Button&& _Other) noexcept = delete;

	void SetRenderOrder(int _Value);

	void SetScale(float4 _Scale);

	void SetClickCallBack(void(*_ClickPtr)(Button* _Button))
	{
		ClickPtr = _ClickPtr;
	}

	void SetTargetCollisionGroup(int _PointTargetGroup);

	void SetButtonCollisionType(CollisionType _ButtonCollisionType)
	{
		ButtonCollisionType = _ButtonCollisionType;
	}

	void SetHoverImage(const std::string_view& _Name, int _HoverIndex = -1)
	{
		HoverImageName = _Name;
		HoverIndex = _HoverIndex;


		switch (State)
		{
		case ButtonState::Release:
			CurImageName = ReleaseImageName;
			ButtonRender->SetImage(ReleaseImageName);
			if (-1 != ReleaseIndex)
			{
				ButtonRender->SetFrame(ReleaseIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Press:
			CurImageName = PressImageName;
			ButtonRender->SetImage(PressImageName);
			if (-1 != PressIndex)
			{
				ButtonRender->SetFrame(PressIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Hover:
			CurImageName = HoverImageName;
			ButtonRender->SetImage(HoverImageName);
			if (-1 != HoverIndex)
			{
				ButtonRender->SetFrame(HoverIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		default:
			break;
		}
	}
	void SetReleaseImage(const std::string_view& _Name, int _ReleaseIndex = -1)
	{
		ReleaseImageName = _Name;
		ReleaseIndex = _ReleaseIndex;



		switch (State)
		{
		case ButtonState::Release:
			CurImageName = ReleaseImageName;
			ButtonRender->SetImage(ReleaseImageName);
			if (-1 != ReleaseIndex)
			{
				ButtonRender->SetFrame(ReleaseIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Press:
			CurImageName = PressImageName;
			ButtonRender->SetImage(PressImageName);
			if (-1 != PressIndex)
			{
				ButtonRender->SetFrame(PressIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Hover:
			CurImageName = HoverImageName;
			ButtonRender->SetImage(HoverImageName);
			if (-1 != HoverIndex)
			{
				ButtonRender->SetFrame(HoverIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		default:
			break;
		}
	}
	void SetPressImage(const std::string_view& _Name, int _PressIndex = -1)
	{
		PressImageName = _Name;
		PressIndex = _PressIndex;



		switch (State)
		{
		case ButtonState::Release:
			CurImageName = ReleaseImageName;
			ButtonRender->SetImage(ReleaseImageName);
			if (-1 != ReleaseIndex)
			{
				ButtonRender->SetFrame(ReleaseIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Press:
			CurImageName = PressImageName;
			ButtonRender->SetImage(PressImageName);
			if (-1 != PressIndex)
			{
				ButtonRender->SetFrame(PressIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		case ButtonState::Hover:
			CurImageName = HoverImageName;
			ButtonRender->SetImage(HoverImageName);
			if (-1 != HoverIndex)
			{
				ButtonRender->SetFrame(HoverIndex);
			}
			ButtonRender->SetScale(Scale);
			break;
		default:
			break;
		}
	}

	GameEngineRender* GetButtonRender()
	{
		return ButtonRender;
	}

	GameEngineCollision* GetButtonCollision()
	{
		return ButtonCollision;
	}

	ButtonState GetState()
	{
		return State;
	}

	int GetHoverIndex()
	{
		return HoverIndex;
	}

	int GetReleaseIndex()
	{
		return ReleaseIndex;
	}

	int GetPressIndex()
	{
		return PressIndex;
	}

	void SetCollisionOrder(int _Order);

	float4 GetScale()
	{
		return Scale;
	}

	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeEnd(GameEngineLevel* _Level) override;


private:
	GameEngineRender* ButtonRender = nullptr;
	GameEngineCollision* ButtonCollision = nullptr;
	int PointTargetGroup = 0;
	CollisionType ButtonCollisionType = CollisionType::CT_Rect;
	void(*ClickPtr)(Button* _Button) = nullptr;

	float4 Scale;
	ButtonState State;
	std::string CurImageName;
	std::string HoverImageName;
	int HoverIndex = -1;
	std::string ReleaseImageName;
	int ReleaseIndex = -1;
	std::string PressImageName;
	int PressIndex = -1;

};

