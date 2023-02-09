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

// Ό³Έν :
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

	void SetClickCallBack(void(*_ClickPtr)())
	{
		ClickPtr = _ClickPtr;
	}

	void SetTargetCollisionGroup(int _PointTargetGroup);

	void SetButtonCollisionType(CollisionType _ButtonCollisionType)
	{
		ButtonCollisionType = _ButtonCollisionType;
	}

	void SetHoverImage(const std::string_view& _Name)
	{
		HoverImageName = _Name;
	}

	void SetReleaseImage(const std::string_view& _Name)
	{
		ReleaseImageName = _Name;
	}

	void SetPressImage(const std::string_view& _Name)
	{
		PressImageName = _Name;
	}

	GameEngineRender* GetButtonRender()
	{
		return ButtonRender;
	}

	GameEngineCollision* GetButtonCollsion()
	{
		return ButtonCollision;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* ButtonRender = nullptr; 
	GameEngineCollision* ButtonCollision = nullptr;
	int PointTargetGroup = 0;
	CollisionType ButtonCollisionType = CollisionType::CT_Rect;
	void(*ClickPtr)() = nullptr;

	float4 Scale = {};
	ButtonState State = ButtonState::Release;
	std::string CurImageName = std::string();
	std::string HoverImageName = std::string();
	std::string ReleaseImageName = std::string();
	std::string PressImageName = std::string();

};

