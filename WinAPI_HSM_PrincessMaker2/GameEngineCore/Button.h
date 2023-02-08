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

	std::string SetHoverImage(const std::string_view& _Name)
	{
		HoverImageName = _Name;
	}

	std::string SetReleaseImage(const std::string_view& _Name)
	{
		ReleaseImageName = _Name;
	}

	std::string SetPressImage(const std::string_view& _Name)
	{
		PressImageName = _Name;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Render = nullptr; 
	GameEngineCollision* ButtonCollision = nullptr;
	int PointTargetGroup = 0;
	CollisionType ButtonCollisionType = CollisionType::CT_Rect;
	void(*ClickPtr)() = nullptr;

	ButtonState State = ButtonState::Release;
	std::string CurImageName = std::string();
	std::string HoverImageName = std::string();
	std::string ReleaseImageName = std::string();
	std::string PressImageName = std::string();

};

